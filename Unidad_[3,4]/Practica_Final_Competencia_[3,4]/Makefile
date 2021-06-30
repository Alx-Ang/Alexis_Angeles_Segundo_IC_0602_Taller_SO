all:
	gcc -g -c -Wall servidor_funciones.c -o servidor_funciones.o
	gcc -g -c -Wall servidor.c -o servidor.o
	gcc -g -Wall servidor.o servidor_funciones.o -o servidor
	gcc -g -c -Wall cliente_funciones.c -o cliente_funciones.o
	gcc -g -c -Wall cliente.c -o cliente.o
	gcc -g -Wall cliente.o cliente_funciones.o -o cliente
clean:
	rm *.o
	rm cliente
	rm servidor
