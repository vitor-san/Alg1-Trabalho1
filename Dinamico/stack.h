#ifndef STACK_H
	#define STACK_H

	typedef void* elem;
	typedef struct stack STACK;
	typedef STACK* Stack;

	Stack newStack();
	void push(Stack x, elem data);	//elem data is always an ADDRESS
	elem pop(Stack x);
	elem topStack(Stack x);
	int nElemsStack(Stack x);
	size_t sizeofStack(Stack x);
	int stackIsEmpty(Stack x);
	void printStack(Stack x, void (*print_function)(elem));
	void delStack(Stack x);	//be sure Stack is empty before deleting it. Otherwise, memory leak may occur.

#endif