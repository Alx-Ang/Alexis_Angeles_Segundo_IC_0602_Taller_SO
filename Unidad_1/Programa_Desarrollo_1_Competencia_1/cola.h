#include <stdio.h>
//#include <conio.h>
#include <stdlib.h>
#include "proceso.h"


typedef struct nodo {
    struct proceso info;
    struct nodo *sig;
}nodo;

struct nodo *raiz=NULL;
struct nodo *fondo=NULL;
int vacia()
{
    if (raiz == NULL)
        return 1;
    else
        return 0;
}
void insertar(proceso x)
{
    struct nodo *nuevo;
    nuevo=(nodo*)malloc(sizeof(struct nodo));
    nuevo->info=x;
    nuevo->sig=NULL;
    if (vacia())
    {
        raiz = nuevo;
        fondo = nuevo;
    }
    else
    {
        fondo->sig = nuevo;
        fondo = nuevo;
    }
}

proceso extraer()
{
    if (!vacia())
    {
        proceso informacion = raiz->info;
        struct nodo *bor = raiz;
        if (raiz == fondo)
        {
            raiz = NULL;
            fondo = NULL;
        }
        else
        {
            raiz = raiz->sig;
        }
        free(bor);
        return informacion;
    }
    else{
    	printf("error al desnecolar");
	}   
}

void imprimir()
{
    struct nodo *reco = raiz;
    printf("Listado de todos los elementos de la cola.\n");
    while (reco != NULL)
    {
        printf("%i - ", reco->info.pdi);
        reco = reco->sig;
    }
    printf("\n");
}

int contar()
{
	int con=0;
    struct nodo *reco = raiz;
    while (reco != NULL)
    {
        reco = reco->sig;
        con++;
    }
    return con;
}

void liberar()
{
    struct nodo *reco = raiz;
    struct nodo *bor;
    while (reco != NULL)
    {
        bor = reco;
        reco = reco->sig;
        free(bor);
    }
}
