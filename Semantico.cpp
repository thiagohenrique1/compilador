#include <vector>
#include "Semantico.h"
#include "Sintatico.h"

using namespace std;

void Semantico::executar(){
	Sintatico sintatico(&tabela_simbolos,"tabela.csv","gramatica.txt","erros.txt","texto.alg");
	sintatico_acao retorno;
	do {
		retorno = sintatico.executar();
		switch(retorno.acao) {
			case 'S':
				pilha.push(retorno.simbolo);
				break;
			case 'R': {
				vector<item_tabela> simbolos_reduzidos;
				for (int i = 0; i < retorno.num_reduzidos; ++i) {
					item_tabela simbolo = pilha.top();
					simbolos_reduzidos.push_back(simbolo);
					pilha.pop();
				}
				item_tabela nao_terminal = regra_semantica(retorno.regra,retorno.simbolo, simbolos_reduzidos);
				pilha.push(nao_terminal);
			} break;
			case 'A':
				break;
			case 'E':
				break;
			default:
				break;
		}
	} while(retorno.acao != 'A' && retorno.acao != 'E');
}

item_tabela Semantico::regra_semantica(int reducao, item_tabela nao_terminal, vector<item_tabela> simbolos) {
	switch(reducao) {
		case 5:
			output << "\n\n\n";
			break;
		case 6: {
			item_tabela id = simbolos.at(2);
			item_tabela TIPO = simbolos.at(1);
			id.tipo = TIPO.tipo;
			tabela_simbolos[id.lexema] = id;
			output << TIPO.tipo << " " << id.lexema << ";" << endl;
		} break;
		case 7:
		case 8:
		case 9: {
			item_tabela tipo_var = simbolos.at(0);
			nao_terminal.tipo = tipo_var.tipo;
		} break;
		case 11: {
			item_tabela id = simbolos.at(1);
			if(id.tipo == "literal")
				output << "scanf(\"%s\"," << id.lexema << ");" << endl;
			else if(id.tipo == "int")
				output << "scanf(\"%d\"," << id.lexema << ");" << endl;
			else if(id.tipo == "double")
				output << "scanf(\"%lf\"," << id.lexema << ");" << endl;
			else cout << "Erro: Variável não declarada" << endl;
		} break;
		case 12: {
			item_tabela ARG = simbolos.at(1);
			if(ARG.tipo == "literal")
				output << "printf("+ARG.lexema+");" << endl;
			else if(ARG.tipo == "num")
				output << "printf(\""+ARG.lexema+"\");" << endl;
		} break;
		case 13:
		case 14:
		case 15: {
			nao_terminal.lexema = simbolos.at(0).lexema;
			nao_terminal.tipo = simbolos.at(0).tipo;
		} break;
		default:
			return nao_terminal;
	}
	return nao_terminal;
}

Semantico::Semantico() {
	output.open("programa.c");
};
