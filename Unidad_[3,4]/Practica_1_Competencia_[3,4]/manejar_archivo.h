#ifndef __MANEJAR_ARCHIVO_H
#define __MANEJAR_ARCHIVO_H

#include "lista_enlazada.h"

int existe_archivo(char *nombre);
void crear_archivo(char *nombre);
void escribir_archivo(char *nombre, lista *l);
int leer_archivo_asignar(char *nombre,lista *l);
int leer_archivo(char *nombre);
int tiene_archivos(char *nombre);
void cerrar_archivo(FILE *archivo);
#endif