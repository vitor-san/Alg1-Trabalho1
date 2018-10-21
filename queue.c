#include <stdlib.h>
#include "node.h"
#include "queue.h"

struct queue {
	Node beg;
	Node end;
	int size;
};


Queue newQueue () {
	Queue new = malloc(sizeof(QUEUE));
	new->beg = NULL;
	new->end = NULL;
	new->size = 0;
	return new;
}

void queueInsert(Queue x, elem data) {

	if (queueIsEmpty(x)) {
		x->beg = newNode();
		x->end = x->beg;
	}

	else {
		Node aux = newNode();
		setNext(x->end, aux);
		x->end = aux;
	}

	setInfo(x->end, data);
	x->size++;

	return;
}

elem queueRemove(Queue x) {

	if (queueIsEmpty(x)) return NULL;

	Node next = getNext(x->beg);

	elem info = getInfo(x->beg);

	free(x->beg);

	if (nElemsQueue(x) == 1) {
		x->beg = NULL;
		x->end = NULL;
		x->size--;
		return info;
	}

	x->beg = next;
	setPrev(x->beg, NULL);

	x->size--;

	return info;
}

elem queueElem(Queue x, int pos) {
	return (getInfo(x->beg));
}

int nElemsQueue(Queue x) {
	return x->size;
}

size_t sizeofQueue(Queue x) {
	return nElemsQueue(x)*sizeofNode();
}

int queueIsEmpty(Queue x) {
	return (x->beg == NULL);
}

void delete3(Node x, void (*free_function)(elem)) {
	
	if (getNext(x) == NULL) {
		delNode(x, free_function);
		return;
	}

	delete3(getNext(x), free_function);

	delNode(x, free_function);
	
	return;
}

void printQueue(Queue x, void (*print_function)(elem)) {

	Node aux = x->beg;

	while (aux != NULL) {
		printInfo(aux, print_function);
		aux = getNext(aux);
	}

	return;
}

void delQueue(Queue x, void (*free_function)(elem)) {
	if (x->beg == NULL) return;
	delete3(x->beg, free_function);
	free(x);
	return;
}