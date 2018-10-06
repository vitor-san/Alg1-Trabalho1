#ifndef STACK_H
	#define STACK_H

	typedef void* elem;
	typedef struct stack STACK;
	typedef STACK* Stack;

	Stack newStack();
	void push(Stack x, elem data, size_t data_size);	//elem data is always an ADDRESS
	elem pop(Stack x);
	elem topStack(Stack x);
	int stackSize(Stack x);
	int stackIsEmpty(Stack x);
	void printStack(Stack x, void (*print_function)(elem));
	void deleteStack(Stack x);

#endif