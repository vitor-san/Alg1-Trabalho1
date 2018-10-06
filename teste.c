#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"


void printaString (void *string) {
	puts((char *)string);
	return;
}

int main (int argc, const char *argv[]) {

	Stack pilhadeStrings = newStack();

	char word1[] = "Primeiro Elemento";
	char word2[] = "Segundo Elemento";
	char word3[] = "Terceiro Elemento";
	char word4[] = "Quarto Elemento";
	char word5[] = "Quinto Elemento";
	char word6[] = "Penultimo Elemento";
	char word7[] = "Ultimo Elemento";

	push(pilhadeStrings, word1, strlen(word1));
	push(pilhadeStrings, word2, strlen(word2));
	push(pilhadeStrings, word3, strlen(word3));
	push(pilhadeStrings, word4, strlen(word4));
	push(pilhadeStrings, word5, strlen(word5));
	push(pilhadeStrings, word6, strlen(word6));
	push(pilhadeStrings, word7, strlen(word7));

	printStack(pilhadeStrings, printaString);
	deleteStack(pilhadeStrings);

	return 0;
}