all:
	gcc -g -c -Wall principal.c -o principal.o
	gcc -g -c -Wall lista_enlazada.c -o lista_enlazada.o
	gcc -g -c -Wall manejar_archivo.c -o manejar_archivo.o
	gcc -g -Wall principal.o lista_enlazada.o manejar_archivo.o -o ejecutable
clean:
	rm *.o
	rm ejecutable
