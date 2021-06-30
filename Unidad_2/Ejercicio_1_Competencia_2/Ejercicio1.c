#include<stdio.h>

int main(){
	char x;
	char *p;

	char y;
	char *puntero;
	
	// Inicializar x con el char x
	x = 'x';

	//Asignar la direccion en memoria de la variable "x" al puntero "p"
	p = &x;
	
	// Imprimir el contenido del puntero "p"
	printf("Contenido del puntero p = %c", *p);
	
	// Sumarle 1 al contenido del punter "p"
	*p = *p + 1;
	// Imprimir el contenido del puntero "p"
	printf("\nContenido del puntero p = %c", *p);

	// Sumar 2 al contenido del puntero "p" y almacenarlo en el mismo puntero "p"
	*p = *p + 2;

	// Imprimir el contenido del puntero "p"
	printf("\nContenido del puntero p = %c", *p);

	// Inicializar la variable y con valor 'y'
	y = 'y';
	
	// Asignar la direccion en memoria de la variable "y" al puntero "puntero"
	puntero = &y;

	printf("\nContenido del puntero 'puntero' = %c\n", *puntero);
}
