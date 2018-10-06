#ifndef NODE_H
	#define NODE_H

	typedef struct node NODE;
	typedef NODE* Node;

	Node newNode();
	void setNext(Node self, Node next);
	Node getNext(Node x);
	void setPrev(Node self, Node prev);
	Node getPrev(Node x);
	void setInfo(Node x, void *data_ad, size_t data_size);
	void *getInfo(Node x);
	void printInfo(Node x, void (*print_function)(void *));
	void deleteNode(Node x);

#endif