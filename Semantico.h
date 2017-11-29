//
// Created by thiago on 29/11/17.
//

#ifndef COMPILADOR_SEMANTICO_H
#define COMPILADOR_SEMANTICO_H

#include <stack>
#include <fstream>
#include <unordered_map>
#include <vector>
#include "structs.h"

using std::string;
using std::vector;
using std::unordered_map;

class Semantico {
	private:
		stack<item_tabela> pilha;
		unordered_map<string, item_tabela> tabela_simbolos;
		std::ofstream output;
		item_tabela regra_semantica(int reducao, item_tabela nao_terminal, vector<item_tabela> simbolos);

		int var_temp_num;

	public:
		void executar();
		Semantico();

};


#endif //COMPILADOR_SEMANTICO_H
