#include "Sintatico.h"

using namespace std;

Sintatico::Sintatico(string arquivo_tabela, string arquivo_gramatica) {
	file_tab.open(arquivo_tabela);
	file_gram.open(arquivo_gramatica);
	ler_arquivos();
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
