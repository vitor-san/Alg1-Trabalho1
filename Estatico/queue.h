#include "stack.h"

#define sizeq 500

typedef struct queue {
	Stack v[sizeq];
	int begin, end,total;
} Queue;


void create_queue(Queue*);
int push_queue(Queue*,Stack);
int isempty_queue(Queue*);
int pop_queue(Queue*,Stack*);

