#include <iostream>
#include <unordered_map>
#include "Lexico.h"
#include "Sintatico.h"

using namespace std;

int main() {
	Sintatico sintatico("tabela.csv","gramatica.txt","texto.alg");
	sintatico.executar();

//	while(true) {
//		item_tabela item = lexico.prox_token();
//		if(tabela_simbolos.count(item.lexema) == 0 && item.token != "erro"){
//			if(item.token == "id") tabela_simbolos.insert({item.lexema,item});
//			cout << "Token: " + item.token + ", ";
//			cout << "Lexema: " + item.lexema << endl;
//		} else if(item.token == "erro"){
//            cout << item.lexema;
//			break;
//		} else {
////            item.token = tabela_simbolos[item.lexema].token;
//			cout << "Token: " + item.token + ", ";
//			cout << "Lexema: " + item.lexema << endl;
//		}
//		if(item.token == "$") break;
//	}
	return 0;
}
