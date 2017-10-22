#include <iostream>
#include <unordered_map>
#include "Lexico.h"
#include "Sintatico.h"

using namespace std;

void inserir_palavras_chave(unordered_map<string, item_tabela> *tabela_simbolos);

int main() {
	unordered_map<string, item_tabela> tabela_simbolos;
	Lexico lexico("texto.alg");

	inserir_palavras_chave(&tabela_simbolos);

	Sintatico sintatico("tabela.csv","gramatica.txt");

	while(true) {
		item_tabela item = lexico.prox_token();
		if(tabela_simbolos.count(item.lexema) == 0 && item.token != "erro"){
			if(item.token == "id") tabela_simbolos.insert({item.lexema,item});
			cout << "Token: " + item.token + ", ";
			cout << "Lexema: " + item.lexema << endl;
		} else if(item.token == "erro"){
            cout << item.lexema;
			break;
		} else {
            item.token = tabela_simbolos[item.lexema].token;
			cout << "Token: " + item.token + ", ";
			cout << "Lexema: " + item.lexema << endl;
		}
		if(item.token == "eof") break;
	}
	return 0;
}

void inserir_palavras_chave(unordered_map<string, item_tabela> *tabela_simbolos) {
	string palavras[12] = {"inicio","varinicio","varfim","escreva","leia", "se",
						   "entao","fimse","fim","Inteiro","literal","real"};
	for (int i = 0; i < 12; ++i) {
		tabela_simbolos->insert({palavras[i],{palavras[i],palavras[i]}});
	}
}
