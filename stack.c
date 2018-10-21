#include <stdlib.h>
#include "node.h"
#include "stack.h"

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

void push(Stack x, elem data) {

	if (stackIsEmpty(x)) {
		x->top = newNode();
	}

	else {
		Node aux = newNode();
		setPrev(x->top, aux);
		x->top = aux;
	}

	setInfo(x->top, data);
	x->size++;

	return;
}

elem pop(Stack x) {

	if (stackIsEmpty(x)) return NULL;

	elem info = getInfo(x->top);

	Node aux = getNext(x->top);
	free(x->top);
	x->top = aux;

	x->size--;

	return info;
}

elem topStack(Stack x) {
	return (getInfo(x->top));
}

int nElemsStack(Stack x) {
	return x->size;
}

size_t sizeofStack(Stack x) {
	return nElemsStack(x)*sizeofNode();
}

int stackIsEmpty(Stack x) {
	return (x->top == NULL);
}

void delete(Node x, void (*free_function)(elem)) {
	
	if (getNext(x) == NULL) {
		delNode(x, free_function);
		return;
	}

	delete(getNext(x), free_function);

	delNode(x, free_function);
	
	return;
}

void printStack(Stack x, void (*print_function)(elem)) {

	Node aux = x->top;

	while (aux != NULL) {
		printInfo(aux, print_function);
		aux = getNext(aux);
	}

	return;
}

void delStack(Stack x, void (*free_function)(elem)) {
	if (x->top == NULL) return;
	delete(x->top, free_function);
	free(x);
	return;
}