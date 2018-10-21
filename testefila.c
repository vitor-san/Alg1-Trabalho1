#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

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

	Queue filadeToys = newQueue();

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
		queueInsert(filadeToys, listaDeToys[i]);
	}

	for (int i = 0; i < 6; i++) queueRemove(filadeToys);

	printQueue(filadeToys, printToy);
	delQueue(filadeToys, 0);

	return 0;
}