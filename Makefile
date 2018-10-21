all:
	gcc -o exec toy.c node.c list.c stack.c queue.c main.c -std=c99
run:
	./exec 13 5 4 25 carro 999 boneca 12982 exodia 92382 urso 123 carro 992 urso 62176 aviao 9121 caminhonete 1212 bola 2732 corneta 1213 bola 1 obelisco 27 slifer