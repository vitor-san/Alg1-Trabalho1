#include "lista.h"

void create_list(List *l) {
	l->begin = 0;
	l->end = -1;
}

int empty_list(List l) {
    return (l.end == -1);
}

int full_list(List l) {
    return (l.end == size);
}

int insert_list(List* l, Toy t) {

	l->end++;
	if (l->end == size) return 1;
	l->v[l->end].id = t.id;
	l->aux[l->end] = 1;
	strcpy(l->v[l->end].name,t.name);

    return 0;
}

int remove_list(List* l,Toy* t,int* k,int* cur) {

	int aux = *cur;

	for (int i = 1; i < *k; ++i) {

		if (l->aux[aux] != 0) {
			aux++;
		}


		if (aux >= l->end+1) {
			(*k)--;
			aux = 0;
		}

	}

	while (l->aux[aux] == 0) {
		aux++;
		if (aux >= l->end+1) aux = 0;
	}

	t->id = l->v[aux].id;
	strcpy(t->name,l->v[aux].name);

	*cur = aux+1;

	while (l->aux[*cur] == 0) {
		(*cur)++;
		if (*cur >= l->end+1) *cur = 0;
	}

	l->aux[aux] = 0;

	


	return 0; 
}






