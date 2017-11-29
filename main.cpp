#include <iostream>
#include "Lexico.h"
#include "Sintatico.h"
#include "Semantico.h"

using namespace std;

int main() {
//	Sintatico sintatico("tabela.csv","gramatica.txt","erros.txt","texto.alg");

	Semantico semantico;
	semantico.executar();
	return 0;
}