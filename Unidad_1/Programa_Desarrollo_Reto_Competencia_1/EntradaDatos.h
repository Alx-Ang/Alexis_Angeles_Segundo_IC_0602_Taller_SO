#include <stdio.h>
#include <stdbool.h>

int entero(char mensaje[]){
	bool control=false;
	int entero=-1;
	while(!control){
		printf(" %s ",mensaje);
        scanf("%i",&entero);
        fflush( stdin );
        control = true;
	}
	return entero;
}
char* cadena(char mensaje[]){
        printf(" %s ",mensaje);
        char* cadenas;
		scanf("%s",&cadenas);
		fflush( stdin );
        return cadenas;
}

double doble(char mensaje[]){
    bool control = false;
    double dobles = -1.0;
    while(!control){
    	printf(" %s ",mensaje);
        scanf("%lf",&dobles);
        control = true;
    }
    return dobles;
}
