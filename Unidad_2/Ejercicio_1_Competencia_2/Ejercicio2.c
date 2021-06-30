#include<stdio.h>

int main(){
	// Crear un array de tipo caracter de tamaño 5 y de nombre arrayChar
	char arrayChar[5];
	int i = 0;

	// Iniciarlizarlo de a-e
	for(int car = 97; car < 102; car++){
		arrayChar[i] = car;
		i++;
	}
	
	// Crear un puntero hacia un char de nombre punteroChar e inicializarlo con arrayChar
	char *punteroChar;
       	punteroChar = &arrayChar[0];
	
	// printf("\nDireccion de punteroChar = %p", &punteroChar);
	// printf("\nContenido de PunteroChar = %c", punteroChar);
	
	// punteroChar = punteroChar + 1;
	// printf("\nContenido de PunteroChar = %c", punteroChar);

	
	// Crear un puntero hacia un char de nombre punteroCharDos e inicializarlo con la direccion del primer elemento (index) del array "arrayChar"	
	char *punteroCharDos;
       	punteroCharDos = &arrayChar[0];

	// Imprimir el contenido del primer elemento del array "arrayChar"
	printf("\nContenido [0] de arrayChar = %c", arrayChar[0]);


	// Imprimir el contenido del primer elemento del puntero punteroChar
	printf("\nContenido del primer elemento de punteroChar = %c", *punteroChar);

	// Imprimir el contenido del primer elemento del puntero punteroCharDos
	printf("\nContenido del primer elemento de punteroCharDos = %c", *punteroCharDos);

	// Imprimir el contenido del quinto elemento del array "arrayChar"
	printf("\nContenido del quinto elemento de arrayChar = %c", arrayChar[4]);

	//Imprimir el contendo del quinto elemento del puntero "punteroChar" con aritmetica de punteros
	// punteroChar = *(punteroChar + 4);
	printf("\nContenido del quinto elemento de punteroChar con aritmetica de punteros = %c", *(punteroChar + 4));

	// Imprimir el contenido del quinto elemento del puntero "punteroCharDos" con aritmética de punteros
	// punteroCharDos = *(punteroCharDos + 4);
	printf("\nContenido del quinto elemento de punteroCharDos con arimética de punteros = %c", *(punteroCharDos + 4));

	// Usar una estructura repetitiva para imprimir el contenido de todos los elementos de "punteroCharDos" con aritmética de punteros
	for (i = 0; i < 5; i++){
		printf("\nContenido [%i] de punteroCharDos = %c", i, *(punteroCharDos + i));
	}
	printf("\n");

	// Usar una estructura repetitiva para imprimir el contenido de todos los elementos del puntero punteroCharDos con aritmética de punteros
	for (int i = 0; i < 5; i++){
		printf("\nContenido [%i] de punteroCharDos = %c", i, *(punteroCharDos + i));
	}
	// No entendí esto ultimo de imprimirlo dos veces
	
	printf("\n");
	return 0;
}
