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
	void delQueue(Queue x);	//be sure Queue is empty before deleting it. Otherwise, memory leak may occur.

#endif