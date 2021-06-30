#include "manejar_archivo.h"

int main(int argc, char const *argv[])
{
	lista *lis;
	lis=(lista *)malloc(sizeof(struct lista));
	int i=0;
	if ((char *)argv[1]==NULL){
		printf("Archivo de entrada no especificado\n");
	}else if (existe_archivo((char *)argv[1])==1){
		if (tiene_archivos((char *)argv[1])>0)
		{
			printf("El archivo [%s] si existe el archivo\n",argv[1]);

			i=leer_archivo_asignar((char *)argv[1],lis);

			ordenar(lis,i+1);
			if (existe_archivo((char *)argv[2])==1)
			{
				printf("El archivo [%s] de salida ya existe -> se proseguira a escribir\n",argv[1]);
			}else if((char *)argv[2]==NULL){
				printf("El archivo de salida no esta especificados\n");
			}else{
				printf("El archivo [%s] de salida no existe -> se creara\n",argv[1]);
				crear_archivo((char *)argv[2]);
				printf("--->Se procegira a escribir en el archivo...\n");
			}
			if (existe_archivo((char *)argv[2])==1){
				escribir_archivo((char*)argv[2],lis);
				printf("Leyendo Archivo [%s] ...\n",argv[2]);
				leer_archivo((char*)argv[2]);
				printf("\n");
			}
		}else{
			printf("El archivo [%s] se encutra vacio\n",argv[1]);
		}
	}else{
		printf("El archivo [%s] de entrada especificado no existe\n",argv[1]);
	}
	return 0;
}
