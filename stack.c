#include <stdlib.h>
#include "stack.h"
#include "node.h"

struct stack {
	Node top;
	int size;
};


Stack newStack () {
	Stack new = malloc(sizeof(STACK));
	new->top = NULL;
	new->size = 0;
	return new;
}

void push(Stack x, elem data, size_t data_size) {

	if (stackIsEmpty(x)) {
		x->top = newNode();
		setInfo(x->top, data, data_size);
	}

	else {
		Node aux = newNode();
		setPrev(x->top, aux);
		x->top = aux;
		setInfo(x->top, data, data_size);
	}

	x->size++;

	return;
}

elem pop(Stack x) {

	if (stackIsEmpty) return NULL;

	elem info = getInfo(x->top);

	x->top = getNext(x->top);
	deleteNode(getPrev(x->top));

	x->size--;

	return info;
}

elem topStack(Stack x) {
	return (getInfo(x->top));
}

int stackSize(Stack x) {
	return x->size;
}

int stackIsEmpty(Stack x) {
	return (x->top == NULL);
}

void delete(Node x) {
	
	if (getNext(x) == NULL) {
		deleteNode(x);
		return;
	}

	delete(getNext(x));

	deleteNode(x);
	
	return;
}

void printStack(Stack x, void (*print_function)(elem)) {

	Node aux = x->top;

	while (getNext(aux) != NULL) {
		printInfo(aux, print_function);
		aux = getNext(aux);
	}

	printInfo(aux, print_function);

	return;
}

void deleteStack(Stack x) {
	delete(x->top);
	free(x);
	return;
}