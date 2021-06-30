#ifndef __LISTA_ENLAZADA_H
#define __LISTA_ENLAZADA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo{
	char palabra[100];
	struct nodo *ant;
	struct nodo *sig;
}nodo;

typedef struct lista
{
	struct nodo *ini;
	struct nodo *fin;
}lista;

int esta_vacia(lista *l);
void ingresar_dato(lista *l,char palabras[100]);
void imprimir_lista(lista *l);
void imprimir_lista_r(lista *l);
void limpiar_nodo(nodo *n);
void limpiar_lista(lista *l);
void ordenar(lista *l,int n);

#endif