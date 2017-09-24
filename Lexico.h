#ifndef COMPILADOR_LEXICO_H
#define COMPILADOR_LEXICO_H

#include <fstream>
#include <unordered_map>
#include "structs.h"

using std::string;
using std::unordered_map;

class Lexico {

	private:
		uint8_t tabela_prox_estado[22][256] = {{0}};
		std::ifstream file;
		string linha;
		string buffer;
		int linha_num = 0;
		int estado_atual;
		string tokens[22];
		const char *char_ptr;

		void proxima_linha();
		void preencher_tabela();
		bool is_final(int estado);
		string get_token();
    	string get_erro(int estado, string buffer);

	public:
		Lexico(string arquivo);
		item_tabela prox_token();

};

#endif //COMPILADOR_LEXICO_H