#ifndef LIST_H
	#define LIST_H

	typedef void* elem;
	typedef struct list LIST;
	typedef LIST* List;

	List newList();		//the list will be 1-based
	void listInsert(List x, elem data);		//elem data is always an ADDRESS
	elem listRemove(List x, int pos);
	elem listElem(List x, int pos);
	int nElemsList(List x);
	size_t sizeofList(List x);
	int listIsEmpty(List x);
	void printList(List x, void (*print_function)(elem));
	void delList(List x, void (*free_function)(elem));	//if second argument is NULL(0), the function will use the default free function [free()]

#endif