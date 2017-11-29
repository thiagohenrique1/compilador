//
// Created by thiago on 29/11/17.
//

#ifndef COMPILADOR_SEMANTICO_H
#define COMPILADOR_SEMANTICO_H

#include <stack>
#include "structs.h"

class Semantico {
	private:
		stack<item_tabela> pilha;
	public:
		void executar();
		Semantico();
};


#endif //COMPILADOR_SEMANTICO_H
