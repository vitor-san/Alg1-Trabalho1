#ifndef QUEUE_H
	#define QUEUE_H

	typedef void* elem;
	typedef struct queue QUEUE;
	typedef QUEUE* Queue;

	Queue newQueue();
	void queueInsert(Queue x, elem data);	//elem data is always an ADDRESS
	elem queueRemove(Queue x);
	elem firstQueue(Queue x);
	int nElemsQueue(Queue x);
	size_t sizeofQueue(Queue x);
	int queueIsEmpty(Queue x);
	void printQueue(Queue x, void (*print_function)(elem));
	void delQueue(Queue x, void (*free_function)(elem));	//if second argument is NULL(0), the function will use the default free function [free()]

#endif