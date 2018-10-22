#include <string.h>

#include "toy.h"

#define size 1000

typedef struct list {
	Toy v[size];
	int aux[size];
	int begin, end;
}List;

void create_list(List*);
int insert_list(List*, Toy);
int remove_list(List*,Toy*,int*,int*);
int empty_list(List);
int full_list(List);
