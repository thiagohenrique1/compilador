#include <iostream>
#include <unordered_map>
#include <time.h>
#include "Lexico.h"
using namespace std;

int main() {
	unordered_map<string, item_tabela> symbol_table;
	Lexico lexico("texto.alg", &symbol_table);

//	item_tabela it1 = { "ab", "a123"};
//	symbol_table.insert(	{ "Third", it1 });

	clock_t t;
	t = clock();
	while(true) {
		item_tabela item = lexico.prox_token();
		if(symbol_table.count(item.lexema) == 0 && item.token != "erro"){
			symbol_table.insert({item.lexema,item});
			cout << "Token: " + item.token + ", ";
			cout << "Lexema: " + item.lexema << endl;
		} else if(item.token == "erro"){
			cout << "Erro na linha " + item.lexema << endl;
			break;
		}
		if(item.token == "eof") break;
	}
	t = clock() - t;
	cout << "Tempo gasto: " + to_string(((float) t)/(1e-3*CLOCKS_PER_SEC)) + " ms" << endl;

//	symbol_table["Third"] = 8;

//	cout << symbol_table["Third"].lexema << endl;

	return 0;
}