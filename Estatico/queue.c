#include <string.h>
#include "queue.h"

void create_queue(Queue* q) {
	q->end = 0;
	q->begin = 0;
	q->total = 0;
}

int push_queue(Queue* q, Stack s) {

	//if (isfull_queue(q)) return 1;
    q->v[q->end] = s;
    q->total++;
    q->end++;
    return 0;
}

int isempty_queue(Queue* q) {
	return (q->total <= 0);
}

int pop_queue(Queue* q,Stack* s) {

	if (isempty_queue(q)) return 1;
	*s = q->v[q->begin];
	q->total--;
	q->begin++;
	return 0;
}

