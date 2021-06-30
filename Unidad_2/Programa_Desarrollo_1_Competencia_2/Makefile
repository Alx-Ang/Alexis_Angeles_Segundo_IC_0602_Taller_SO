all:
	gcc -g -c -Wall main.c -o main.o -lpthread
	gcc -g -c -Wall scheduler.c -o scheduler.o -lpthread
	gcc -g -Wall main.o scheduler.o -o application -lpthread

clean:
	rm *.o
	rm application
