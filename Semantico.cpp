//
// Created by thiago on 29/11/17.
//

#include "Semantico.h"
#include "Sintatico.h"

void Semantico::executar(){
	Sintatico sintatico("tabela.csv","gramatica.txt","erros.txt","texto.alg");
	while(sintatico.executar().acao != 'A');
}

Semantico::Semantico() {

};
