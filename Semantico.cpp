//
// Created by thiago on 29/11/17.
//

#include <vector>
#include "Semantico.h"
#include "Sintatico.h"

vector<item_tabela> simbolos_reduzidos;

void Semantico::executar(){
	Sintatico sintatico("tabela.csv","gramatica.txt","erros.txt","texto.alg");
	sintatico_acao retorno;
	do {
		retorno = sintatico.executar();
		switch(retorno.acao) {
			case 'S':
				pilha.push(retorno.simbolo);
				break;
			case 'R':
				for (int i = 0; i < retorno.num_reduzidos; ++i) {
					item_tabela simbolo = pilha.top();
					simbolos_reduzidos.push_back(simbolo);
					pilha.pop();
				}
				pilha.push(retorno.simbolo);
				break;
			case 'A':
				break;
			case 'E':
				break;
			default:
				break;
		}
	} while(retorno.acao != 'A' && retorno.acao != 'E');
}

Semantico::Semantico() {

};
