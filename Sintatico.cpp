#include <vector>
#include "Sintatico.h"

using namespace std;

Sintatico::Sintatico(unordered_map<string, item_tabela> *tabela_simb,
					 string arquivo_tabela, string arquivo_gramatica, string erros, string fonte)
						: tabela_simbolos(tabela_simb), lexico(fonte,tabela_simbolos) {
	file_tab.open(arquivo_tabela);
	file_gram.open(arquivo_gramatica);
	file_erros.open(erros);
	ler_arquivos();
	inserir_palavras_chave();

	entrada = lexico.prox_token();
	if(entrada.token == "erro") {
		cout << entrada.lexema << endl;
		return;
	}
	pilha.push(0);
}

sintatico_acao Sintatico::executar() {
	uint8_t estado_topo = pilha.top();
	int entrada_indice = get_indice_terminal(entrada.token);
	action action = tabela_actions[estado_topo][entrada_indice];
	if (action.acao == 'S') {
		pilha.push(action.num);
		sintatico_acao retorno {'S',entrada,0};
		entrada = lexico.prox_token();
		if(entrada.token == "erro") {
			cout << entrada.lexema << endl;
			return {'E'};
		} else return retorno;
	} else if (action.acao == 'R') {
		gram_item regra = tabela_gram[action.num];
		for (int i = 0; i < regra.size; ++i) pilha.pop();
		estado_topo = pilha.top();
		int nao_terminal_indice = get_indice_nao_terminal(regra.symb);
		pilha.push(tabela_goto[estado_topo][nao_terminal_indice]);
		cout << regra.line << endl;
		item_tabela nao_terminal = {regra.symb,regra.symb};
		return {'R',nao_terminal,regra.size,regra.regra_num};
	} else if (action.acao == 'A') {
		cout << "Aceito" << endl;
		return {'A'};
	} else if (action.acao == 'E'){
		cout << "Erro sintático na linha " + to_string(lexico.get_pos()) + ": " + erros[action.num]<< endl;
		return {'E'};
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
	char_ptr = linha.c_str();
	char_ptr++;

	for (string &terminal : terminais) terminal = prox_valor(',');

	for (string &nao_terminal : nao_terminais) nao_terminal = prox_valor(',');

	for (int i = 0; i < num_estados; ++i) {
		getline(file_tab,linha);
		char_ptr = linha.c_str();
		prox_valor(',');

		for (int j = 0; j < num_terminais; ++j) {
			string acao = prox_valor(',');
			tabela_actions[i][j].acao = acao[0];
			if(!acao.erase(0,1).empty()) tabela_actions[i][j].num = (uint8_t) stoi(acao);
		}

		for (int j = 0; j < num_nao_terminais; ++j) {
			string estado = prox_valor(',');
			if(!estado.empty()) tabela_goto[i][j] = (uint8_t) stoi(estado);
		}
	}

	int regra_num = 1;
	for (int i = 1; i <= num_reducoes; ++i) {
		getline(file_gram, tabela_gram[i].line);
		char_ptr = tabela_gram[i].line.c_str();
		tabela_gram[i].symb = prox_valor('-');
		char_ptr++;
		tabela_gram[i].size = 0;
		tabela_gram[i].regra_num = regra_num++;
		while(!prox_valor(' ').empty()) tabela_gram[i].size++;
	}

	getline(file_erros, linha);
	while(!file_erros.eof()) {
		char_ptr = linha.c_str();
		int pos = stoi(prox_valor(','));
		erros[pos] = prox_valor('\0');
		getline(file_erros, linha);
	}

}

string Sintatico::prox_valor(char delim){
	string valor;
	while(*char_ptr != delim && *char_ptr != '\r' && *char_ptr != '\0') valor += *char_ptr++;
	if(*char_ptr != '\0') char_ptr++;
	return valor;
}

void Sintatico::inserir_palavras_chave() {
	string palavras[11] = {"inicio","varinicio","varfim","escreva","leia", "se",
						   "entao","fimse","fim","real"};
	for (int i = 0; i < 9; ++i) {
		tabela_simbolos->insert({palavras[i],{palavras[i],palavras[i]}});
	}
	tabela_simbolos->insert({"literal",{"lit","literal","literal"}});
	tabela_simbolos->insert({"inteiro",{"int","inteiro","int"}});
	tabela_simbolos->insert({"real",{"real","real","double"}});

}

string Sintatico::get_pos(){
    return to_string(lexico.get_pos());
}
