#include <iostream>
#include "Lexico.h"
#include "Sintatico.h"

using namespace std;

int main() {
	Sintatico sintatico("tabela.csv","gramatica.txt","erros.txt","texto.alg");
	sintatico.executar();
	return 0;
}