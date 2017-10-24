#include "Sintatico.h"

using namespace std;

Sintatico::Sintatico(string arquivo_tabela, string arquivo_gramatica, string fonte) : lexico(fonte,&tabela_simbolos) {
	file_tab.open(arquivo_tabela);
	file_gram.open(arquivo_gramatica);
	ler_arquivos();
	inserir_palavras_chave();
}

void Sintatico::executar() {
	string entrada = lexico.prox_token().token;
	pilha.push(0);
	while (1) {
		uint8_t estado_topo = pilha.top();
		int entrada_indice = get_indice_terminal(entrada);
		action acao = tabela_actions[estado_topo][entrada_indice];
		if (acao.acao == 'S') {
			pilha.push(acao.estado);
			entrada = lexico.prox_token().token;
		} else if (acao.acao == 'R') {
			gram_item regra = tabela_gram[acao.estado];
			for (int i = 0; i < regra.size; ++i) pilha.pop();
			estado_topo = pilha.top();
			int nao_terminal_indice = get_indice_nao_terminal(regra.symb);
			pilha.push(tabela_goto[estado_topo][nao_terminal_indice]);
			cout << regra.line << endl;
		} else if (acao.acao == 'A') {
			cout << "Aceito" << endl;
			break;
		} else {
			cout << "Erro" << endl;
			break;
		}
	}
}

int Sintatico::get_indice_terminal(string simbolo){
	for (int i = 0; i < num_terminais; ++i) {
		if(terminais[i] == simbolo) return i;
	}
	return -1;
}

int Sintatico::get_indice_nao_terminal(string simbolo){
	for (int i = 0; i < num_nao_terminais; ++i) {
		if(nao_terminais[i] == simbolo) return i;
	}
	return -1;
}

void Sintatico::ler_arquivos() {
	string linha;
	getline(file_tab,linha);
	const char *char_ptr = linha.c_str();
	char_ptr++;

	for (int i = 0; i < num_terminais; ++i) {
		string terminal;
		while(*char_ptr != ',') terminal += *char_ptr++;
		terminais[i] = terminal;
		char_ptr++;
	}

	for (int i = 0; i < num_nao_terminais; ++i) {
		string nao_terminal;
		while(*char_ptr != ',' && *char_ptr != '\r') nao_terminal += *char_ptr++;
		nao_terminais[i] = nao_terminal;
		char_ptr++;
	}

	for (int i = 0; i < num_estados; ++i) {
		getline(file_tab,linha);
		char_ptr = linha.c_str();
		while(*char_ptr != ',') char_ptr++;
		char_ptr++;

		for (int j = 0; j < num_terminais; ++j) {
			string num;
			if(*char_ptr != ',') tabela_actions[i][j].acao = *char_ptr++;
			while(*char_ptr != ',') num += *char_ptr++;
			if(!num.empty()) tabela_actions[i][j].estado = (uint8_t) stoi(num);
			char_ptr++;
		}
		for (int j = 0; j < num_nao_terminais; ++j) {
			string num;
			while(*char_ptr != ',' && *char_ptr != '\r' && *char_ptr != '\0') num += *char_ptr++;
			if(!num.empty()) tabela_goto[i][j] = (uint8_t) stoi(num);
			char_ptr++;
		}
	}

	for (int i = 1; i <= num_reducoes; ++i) {
		getline(file_gram,linha);
		char_ptr = linha.c_str();
		tabela_gram[i].line = linha;
		while(*char_ptr != '-') tabela_gram[i].symb += *char_ptr++;
		char_ptr += 2;
		tabela_gram[i].size = 0;
		while(*char_ptr != '\0'){
			while(*char_ptr != ' ' && *char_ptr != '\0') char_ptr++;
			if(*char_ptr == ' ') char_ptr++;
			tabela_gram[i].size++;
		}
	}
}

void Sintatico::inserir_palavras_chave() {
	string palavras[12] = {"inicio","varinicio","varfim","escreva","leia", "se",
						   "entao","fimse","fim","real"};
	for (int i = 0; i < 10; ++i) {
		tabela_simbolos.insert({palavras[i],{palavras[i],palavras[i]}});
	}
	tabela_simbolos.insert({"literal",{"lit","literal"}});
	tabela_simbolos.insert({"inteiro",{"int","inteiro"}});
}
