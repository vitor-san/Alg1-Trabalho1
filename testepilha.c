#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

typedef struct toy {
	int serial_number;
	char model[46];
} Toy;


void printToy (void *toyAd) {
	Toy *toy = (Toy *)toyAd;
	printf("O modelo do brinquedo eh: %s\n", toy->model);
	printf("O numero de serie do brinquedo eh: %d\n", toy->serial_number);
	return;
}

int main (int argc, const char *argv[]) {

	Stack pilhadeToys = newStack();

	Toy *listaDeToys[5];

	for (int i = 0; i < 5; i++) {
		listaDeToys[i] = malloc(sizeof(Toy));
	}

	listaDeToys[0]->serial_number = rand();
	strcpy(listaDeToys[0]->model, "Batman Figure");
	listaDeToys[1]->serial_number = rand();
	strcpy(listaDeToys[1]->model,"Yu-Gi-Oh Card");
	listaDeToys[2]->serial_number = rand();
	strcpy(listaDeToys[2]->model, "Flash Figure");
	listaDeToys[3]->serial_number = rand();
	strcpy(listaDeToys[3]->model, "Honney Poney");
	listaDeToys[4]->serial_number = rand();
	strcpy(listaDeToys[4]->model, "O Boss");

	for (int i = 0; i < 5; i++) {
		push(pilhadeToys, listaDeToys[i]);
	}

	for (int i = 0; i < 3; i++) pop(pilhadeToys);

	printStack(pilhadeToys, printToy);
	delStack(pilhadeToys, NULL);

	return 0;
}