#ifndef COMPILADOR_SINTATICO_H
#define COMPILADOR_SINTATICO_H

#include <fstream>
#include <stack>
#include "structs.h"
#include "Lexico.h"

#define num_terminais 22
#define num_nao_terminais 15
#define num_estados 59
#define num_reducoes 30

using std::string;

class Sintatico {

	private:
		string terminais[num_terminais];
		string nao_terminais[num_nao_terminais];
		action tabela_actions[num_estados][num_terminais];
		uint8_t tabela_goto[num_estados][num_nao_terminais];
		gram_item tabela_gram[num_reducoes+1];
		stack<uint8_t > pilha;
		unordered_map<string, item_tabela> tabela_simbolos;

		std::ifstream file_tab;
		std::ifstream file_gram;

		Lexico lexico;

		void ler_arquivos();
		void inserir_palavras_chave();
		int get_indice_terminal(string simbolo);
		int get_indice_nao_terminal(string simbolo);

	public:
		Sintatico(string arquivo_tabela, string arquivo_gramatica, string fonte);
		void executar();
};

#endif //COMPILADOR_SINTATICO_H
