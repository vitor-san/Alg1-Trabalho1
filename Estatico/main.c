#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(int argc, char* argv[]) {

	List l;
	Queue q;
	Stack s;

	Toy t;
	int cur = 0, k,aux = 1,p,n;
	int aux2 = 0;

    n = atoi(argv[1]);
    k = atoi(argv[2]);
    p = atoi(argv[3]);

	create_queue(&q);
	create_list(&l);

    for (int i = 0; i < 2 * n; i+=2) {
        t.id = atoi(argv[4+i]);
        strcpy(t.name,argv[4+i+1]);
		insert_list(&l,t);
    }
    
    remove_list(&l,&t,&aux,&cur);
   	create_stack(&s);
    push_stack(&s,t);
   	aux2++;
    	
    for (int i = 0; i < n-1; ++i) {

    	remove_list(&l,&t,&k,&cur);
    	
    	aux2++;
    	if (aux2 == p) {
    		push_stack(&s,t);
    		push_queue(&q,s);
    		create_stack(&s);

    		aux2 = 0;
    	}

    	else {
    		push_stack(&s,t);
    	}
		
    }

    if (!isempty_stack(&s)) {
    	push_queue(&q,s);
    }

    
    int count = 1;
    
    while(!isempty_queue(&q)) {
		
		
    	pop_queue(&q,&s);

    	int quant = size_of_stack(&s);
    	pop_stack(&s,&t);
    	printf("caixa %d: brinquedo <%d, %s> - quantidade %d\n",count ,t.id, t.name, quant);	
    		
    	count++;

    }
	
    	

	return 0;
}

