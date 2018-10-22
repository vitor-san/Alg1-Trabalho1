#include <string.h>
#include "stack.h"

void create_stack(Stack* s) {
	s->top = -1;
}

void push_stack(Stack* s, Toy t) {
	s->top++;
	s->v[s->top].id = t.id;
	strcpy(s->v[s->top].name,t.name);
}

int isempty_stack(Stack* s) {
	return s->top < 0;
}

int pop_stack(Stack* s,Toy* t) {

	if (!isempty_stack(s)) {

		int pos = s->top;
		s->top--;

		t->id = s->v[pos].id;
		strcpy(t->name,s->v[pos].name);

		return 0;
	}

	return 1;
}

int size_of_stack(Stack* s) {
	return (s->top)+1;
}


