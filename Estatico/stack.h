#include "list.h"

#define sizes 500

typedef struct stack {
	Toy v[sizes];
	int top;
} Stack;


void create_stack(Stack*);
void push_stack(Stack*,Toy);
int isempty_stack(Stack*);
int pop_stack(Stack*,Toy*);
int size_of_stack(Stack*);

