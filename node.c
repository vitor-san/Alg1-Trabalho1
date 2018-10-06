#include <stdlib.h>
#include "node.h"

struct node {
	void *info; 	//memory adress
	size_t size;	//size (in bytes) of "info"
	Node prev;
	Node next;
};

Node newNode() {
	Node new = malloc(sizeof(NODE));
	
	new->info = NULL;
	new->size = 0;
	new->prev = NULL;
	new->next = NULL;

	return new;
}

void setNext(Node self, Node next) {
	self->next = next;
	return;
}

Node getNext(Node x) {
	return x->next;
}

void setPrev(Node self, Node prev) {
	self->prev = prev;
	return;
}

Node getPrev(Node x) {
	return x->prev;
}

void setInfo(Node x, void *data_ad, size_t data_size) {
	x->info = data_ad;
	x->size = data_size;
	return;
}

void *getInfo(Node x) {
	return x->info;
}

void printInfo(Node x, void (*print_function)(void *)) {
	print_function(x->info);
	return;
}

void deleteNode(Node x) {
	if (x->prev != NULL)  x->prev->next = NULL;
	if (x->next != NULL)  x->next->prev = NULL;
	if (x->info != NULL)  free(x->info);
	free(x);

	return;
}