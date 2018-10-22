#include <stdlib.h>
#include <string.h>
#include "toy.h"

struct toy {
	int serial;
	char *model;
};

Toy newToy(int serial_number, const char *model) {
	Toy new = malloc(sizeof(TOY));
	new->model = malloc((strlen(model)+1)*sizeof(char));
	new->serial = serial_number;
	strcpy(new->model, model);

	return new;
}

int getSerial(Toy x) {
	return x->serial;
}

char *getModel(Toy x) {
	return x->model;
}

void delToy(Toy x) {
	free(x->model);
	free(x);
}
