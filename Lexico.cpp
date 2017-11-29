#include "Lexico.h"

using namespace std;

Lexico::Lexico(const string arquivo, unordered_map<string, item_tabela> *tabela_simbolos){
	this->tabela_simbolos = tabela_simbolos;
	file.open(arquivo);
	proxima_linha();
	estado_atual = 1;

	preencher_tabela();
}

item_tabela Lexico::prox_token() {
	if(file.eof()) return {"$","eof"};
	int proximo_estado = tabela_prox_estado[estado_atual][*char_ptr];
	while (proximo_estado != 0) {
		if(proximo_estado != 1) buffer += *char_ptr;
		estado_atual = proximo_estado;
		char_ptr++;
		if(*char_ptr == '\0') proxima_linha();
		proximo_estado = tabela_prox_estado[estado_atual][*char_ptr];
		if(proximo_estado > 1) linha_ultimo_token = linha_num;
	}
	if(is_final(estado_atual)) {
		string token = get_token();
		item_tabela item = {token,buffer,};
		if(token == "opr" || token == "opm") item.tipo = item.lexema;
		if(token == "rcb") item.tipo = "=";
		if(token == "lit") item.tipo = "literal";
		if(token == "int") item.tipo = "int";
		if(token == "real") item.tipo = "double";
		buffer = "";
		estado_atual = 1;
		if(token != "comentario") {
			if(tabela_simbolos->count(item.lexema) == 0) {
				if(item.token == "id") (*tabela_simbolos)[item.lexema] = item;
			} else return (*tabela_simbolos)[item.lexema];
			return item;
		}
		else return prox_token();
	}
	string erro = get_erro(estado_atual,buffer);
	return {"erro","Erro léxico na linha "+to_string(linha_num)+": "+erro};
}

void Lexico::proxima_linha() {
	do {
		getline(file, linha);
		linha_num++;
	} while(linha.empty() && !file.eof());
	if(estado_atual == 2 || estado_atual == 6) {
		buffer += '\n';
	}
	char_ptr = linha.c_str();
}

string Lexico::get_token() {
	if(estado_atual >= 7 && estado_atual <= 21){
		if(tabela_simbolos->count(buffer) != 0 && (*tabela_simbolos)[buffer].token != "id")
			return (*tabela_simbolos)[buffer].token;
		return tokens[estado_atual];
	}
	return "erro";
}

void Lexico::preencher_tabela() {
//	Insere os proximos estados ao ler um digito
	for (int i = '0'; i <= '9'; ++i) {
		tabela_prox_estado[1][i] = 7;
		tabela_prox_estado[3][i] = 8;
		tabela_prox_estado[4][i] = 9;
		tabela_prox_estado[5][i] = 9;
		tabela_prox_estado[7][i] = 7;
		tabela_prox_estado[8][i] = 8;
		tabela_prox_estado[9][i] = 9;
		tabela_prox_estado[12][i] = 12;
	}

//	Insere os proximos estados ao ler uma letra
	for (int i = 'A'; i <= 'Z'; ++i) {
		tabela_prox_estado[1][i] = 12;
		tabela_prox_estado[12][i] = 12;
	}
	for (int i = 'a'; i <= 'z'; ++i) {
		tabela_prox_estado[1][i] = 12;
		tabela_prox_estado[12][i] = 12;
	}

//	Insere os estados que repetem para quase qualquer caracter
	for (int i = 0; i < 255; ++i) {
		tabela_prox_estado[2][i] = 2;
		tabela_prox_estado[6][i] = 6;
	}
	tabela_prox_estado[2]['"'] = 10;
	tabela_prox_estado[6]['}'] = 11;

//	Insere os outros estados
	tabela_prox_estado[1][' '] = 1;
	tabela_prox_estado[1]['\n'] = 1;
	tabela_prox_estado[1]['\t'] = 1;
	tabela_prox_estado[1]['\0'] = 1;
	tabela_prox_estado[1]['"'] = 2;
	tabela_prox_estado[1]['{'] = 6;
	tabela_prox_estado[1]['+'] = 17;
	tabela_prox_estado[1]['-'] = 17;
	tabela_prox_estado[1]['<'] = 13;
	tabela_prox_estado[1]['>'] = 14;
	tabela_prox_estado[1]['='] = 15;
	tabela_prox_estado[1]['*'] = 17;
	tabela_prox_estado[1]['/'] = 17;
	tabela_prox_estado[1]['('] = 18;
	tabela_prox_estado[1][')'] = 19;
	tabela_prox_estado[1][';'] = 20;
	tabela_prox_estado[4]['+'] = 5;
	tabela_prox_estado[4]['-'] = 5;
	tabela_prox_estado[7]['.'] = 3;
	tabela_prox_estado[7]['E'] = 4;
	tabela_prox_estado[8]['E'] = 4;
	tabela_prox_estado[12]['{'] = 12;
	tabela_prox_estado[12]['_'] = 12;
	tabela_prox_estado[13]['-'] = 16;
	tabela_prox_estado[13]['>'] = 15;
	tabela_prox_estado[13]['='] = 15;
	tabela_prox_estado[14]['='] = 15;
	tabela_prox_estado[2]['\0'] = 2;
	tabela_prox_estado[6]['\0'] = 6;


//	Relaciona estado final com o token classificado
//	string temp[15] = {"Num","Num","Num", "Literal", "Comentario",
//					   "id", "OPR", "OPR", "OPR", "RCB", "OPM",
//					   "AB_P", "FC_P", "PT_V","EOF"};
	string temp[15] = {"num","num","num", "literal", "comentario",
					   "id", "opr", "opr", "opr", "rcb", "opm",
					   "(", ")", ";","$"};
	for (int i = 7; i <= 21; ++i) {
		tokens[i] = temp[i - 7];
	}
}

string Lexico::get_erro(int estado, string buffer){
    string erro;
    switch(estado){
		case 1:
			erro = "Caractere invalido\n";
			break;
		case 3:
			erro = "Depois do ponto deve ser inserido um digito em \""+buffer+"\"\n";
			break;
		case 4:
			erro = "O expoente deve iniciar com um digito ou um sinal de + ou de -\n";
			break;
		case 5:
			erro = "O valor do expoente nao foi inserido em \""+buffer+"\"\n";
			break;
		default: erro = "Caractere invalido\n";
	}
	return erro;
}

bool Lexico::is_final(int estado){
	return estado >= 7 && estado <= 21;
}

int Lexico::get_pos(){
	return linha_ultimo_token;
}


