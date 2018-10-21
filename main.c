#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "stack.h"
#include "queue.h"
#include "toy.h"

void freeStack(void *data) {
	Stack aux = (Stack) data;
	delStack(aux, 0);
	return;
}

void freeToy(void *data) {
	Toy aux = (Toy) data;
	delToy(aux);
	return;
}

int main (int argc, const char *argv[]) {
	
	int n = atoi(argv[1]),	//atoi eh utilizado para converter os char* do argv em inteiros
		k = atoi(argv[2]),
		p = atoi(argv[3]);

	List esteira = newList();
	Queue fila_de_caixas = newQueue();
	Stack caixa_atual = newStack();
	Toy brinquedo_atual;

	for (int i = 4; i < argc-1; i += 2) {		//comeca no 4 para ignorar os primeiros 4 argumentos no argv (./exec, n, k e p); "argc-1" pois o argv eh zero-based
		brinquedo_atual = newToy(atoi(argv[i]), argv[i+1]);	//primeiro argumento da funcao de criacao do brinquedo eh o seu numero de serie (por isso o atoi) e o segundo eh seu modelo
		listInsert(esteira, brinquedo_atual);
	}

	int posicao = 0;

	while (!listIsEmpty(esteira)) {

		brinquedo_atual = listRemove(esteira, posicao);

		if (nElemsStack(caixa_atual) < p) push(caixa_atual, brinquedo_atual);
		else {
			queueInsert(fila_de_caixas, caixa_atual);
			caixa_atual = newStack();
			push(caixa_atual, brinquedo_atual);
		}

		posicao += k;

		if (posicao > nElemsList(esteira)) {
			posicao = 0;
			k--;
		}

	}

	int numero_caixa = 1;

	while (!queueIsEmpty(fila_de_caixas)) {
		
		caixa_atual = queueRemove(fila_de_caixas);
		brinquedo_atual = topStack(caixa_atual);

		printf("caixa %d: brinquedo <%d, %s> - quantidade %d\n", numero_caixa++, getSerial(brinquedo_atual), getModel(brinquedo_atual), nElemsStack(caixa_atual));

	}

	delToy(brinquedo_atual);
	delStack(caixa_atual, freeToy);
	delQueue(fila_de_caixas, freeStack);
	delList(esteira, freeToy);

	return 0;
}