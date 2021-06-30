#include "manejar_archivo.h"
int existe_archivo(char *nombre){
	FILE *archivo;
	int  i=0;
	archivo= fopen(nombre,"r");
	if (archivo==NULL){
	}else{
		i=1;
	}
	return i;
}
void crear_archivo(char *nombre){
	FILE *archivo;
	archivo=fopen(nombre,"w");
	if (archivo==NULL)
	{
		printf("----Archivo no creado----\n");
	}else{
		printf("----Archivo creado-----\n");
		cerrar_archivo(archivo);
	}
}
void escribir_archivo(char *nombre, lista *l){
	FILE *archivo;
	archivo=fopen(nombre,"w");
	if (archivo==NULL)
	{
		printf("No se pudo escribir en el archivo\n");
	}else{
		nodo *temp=l->ini;
		while(temp!=NULL){
			fputs(temp->palabra,archivo);
			if (temp->sig!=NULL)
			{
				fputs("\n",archivo);	
			}
			temp=temp->sig;
		}

		printf("<--Se termino de escribir-->\n");
	}
	cerrar_archivo(archivo);
}
int leer_archivo_asignar(char *nombre, lista *l){
	FILE *archivo;
	archivo=fopen(nombre,"r");
	char cadena[100];
	int i=0,c=0;
	if (archivo==NULL)
	{
		printf("No se pudo leer el archivo\n");
	}else{
		char caracter;
		while((caracter=fgetc(archivo))!=EOF){
			
			if (caracter!=' '&& caracter!='\n' && caracter!=0)
			{
				cadena[i]=caracter;
				i++;
			}else{
				cadena[i]='\0';
				i=0;
				if(cadena[0]!=0){
					c++;
					ingresar_dato(l,cadena);
				}
			}
		}
		cadena[i]='\0';
		if(cadena[0]!=0){
			ingresar_dato(l,cadena);
		}
	}
	cerrar_archivo(archivo);
	return c;
}
int leer_archivo(char *nombre){
	FILE *archivo;
	archivo=fopen(nombre,"r");
	int i=0;
	if (archivo==NULL)
	{
		printf("No se pudo leer el archivo\n");
	}else{
		char caracter;
		while((caracter=fgetc(archivo))!=EOF){
			printf("%c",caracter);
		}
	}
	cerrar_archivo(archivo);
	return i;
}
int tiene_archivos(char *nombre){
	FILE *archivo;
	archivo=fopen(nombre,"r");
	int i=1;
	fseek( archivo, 0, SEEK_END );
	if (ftell( archivo ) == 0 )
	{
  		i--;
	}
	cerrar_archivo(archivo);
	return i;
}
void cerrar_archivo(FILE *archivo){
	fclose(archivo);
}
