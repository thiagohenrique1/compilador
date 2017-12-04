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
                if(nao_terminal.token == "erro"){
                    cout << "Erro semantico na linha "+sintatico.get_pos()+nao_terminal.lexema<< endl;
                    return;
                }
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
	output << "}";
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
				output << "scanf(\"%d\",&" << id.lexema << ");" << endl;
			else if(id.tipo == "double")
				output << "scanf(\"%lf\",&" << id.lexema << ");" << endl;
			else return {"erro",": Variável não declarada"};
		} break;
		case 12: {
			item_tabela ARG = simbolos.at(1);
			if(ARG.token == "literal")
				output << "printf("+ARG.lexema+");" << endl;
			else if(ARG.token == "num")
				output << "printf(\""+ARG.lexema+"\");" << endl;
			else if(ARG.token == "id") {
				if(ARG.tipo == "literal")
					output << "printf(\"%s\","+ARG.lexema+");" << endl;
				else if(ARG.tipo == "int")
					output << "printf(\"%d\","+ARG.lexema+");" << endl;
				else if(ARG.tipo == "double")
					output << "printf(\"%lf\","+ARG.lexema+");" << endl;
				else cout << "Erro: Variável não declarada" << endl;
			} else return {"erro",": Argumento não válido"};
		} break;
		case 13:
		case 14:
		case 20:
		case 15: {
			nao_terminal.token = simbolos.at(0).token;
			nao_terminal.lexema = simbolos.at(0).lexema;
			nao_terminal.tipo = simbolos.at(0).tipo;
			if(nao_terminal.token == "id" && nao_terminal.tipo.empty())
				return {"erro",": Variável não declarada"};
		} break;
		case 17: {
			item_tabela id = simbolos.at(3);
			item_tabela LD = simbolos.at(1);
			item_tabela rcb = simbolos.at(2);
			if(!id.tipo.empty()){
				if(id.tipo == LD.tipo || (LD.token == "num" && id.tipo != "literal"))
					output << id.lexema << " " << rcb.tipo << " " << LD.lexema << ";" << endl;
				else return {"erro",": Tipos diferentes para atribuicao"};
			} else return {"erro",": Variável não declarada"};
		} break;
		case 18: {
			item_tabela OPRD1 = simbolos.at(2);
			item_tabela opm = simbolos.at(1);
			item_tabela OPRD2 = simbolos.at(0);

			if((OPRD1.token == "id" && OPRD1.tipo == "literal") || (OPRD2.token == "id" && OPRD2.tipo == "literal")) {
				return {"erro",": Operandos com tipos incompativeis"};
			} else {
				nao_terminal.lexema = "T"+to_string(++var_temp_num);
				nao_terminal.token = "id";
				nao_terminal.tipo = "int";
				output << "int T" << var_temp_num << " = " <<
					   OPRD1.lexema << " " << opm.tipo << " " << OPRD2.lexema<<";"<< endl;
			}
		} break;
		case 19:
		case 21:
			nao_terminal.token = simbolos.at(0).token;
			nao_terminal.lexema = simbolos.at(0).lexema;
			nao_terminal.tipo = simbolos.at(0).tipo;
			break;
		case 23:
			output << "}" << endl;
			break;
		case 24: {
			item_tabela EXP_R = simbolos.at(2);
			output << "if("<<EXP_R.lexema<<") {" << endl;
		} break;
		case 25: {
			item_tabela OPRD1 = simbolos.at(2);
			item_tabela opr = simbolos.at(1);
			item_tabela OPRD2 = simbolos.at(0);

			if((OPRD1.token == "id" && OPRD1.tipo == "literal") || (OPRD2.token == "id" && OPRD2.tipo == "literal")) {
				return {"erro",": Operandos com tipos incompatíveis"};
			} else {
				nao_terminal.lexema = "T"+to_string(++var_temp_num);
				output << "int T" << var_temp_num << " = " <<
					   OPRD1.lexema << " " << opr.tipo << " " << OPRD2.lexema<<";"<< endl;
			}

		} break;
		default:
			return nao_terminal;
	}
	return nao_terminal;
}

Semantico::Semantico() {
	output.open("programa.c");
	output << "#include<stdio.h>" << endl << endl;
	output << "typedef char literal[256];" << endl;
	output << "void main(void) {" << endl;
};
