debug:
	gcc -g node.c stack.c teste.c -std=c99
all:
	gcc -o exec node.c stack.c teste.c -std=c99
run:
	./exec