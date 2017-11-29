#ifndef COMPILADOR_STRUCTS_H
#define COMPILADOR_STRUCTS_H

#include <iostream>
using namespace std;

struct item_tabela {
	string token;
	string lexema;
	string tipo;
};

struct action {
	char acao;
	uint8_t num;
};

struct gram_item {
	string symb;
	uint8_t size;
	string line;
	int regra_num;
};

struct sintatico_acao {
	char acao;
	item_tabela simbolo;
	int num_reduzidos;
	int regra;
};

#endif //COMPILADOR_STRUCTS_H