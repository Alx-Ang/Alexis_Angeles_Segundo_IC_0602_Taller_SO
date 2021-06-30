#include <stdio.h>
#include "Banco.h"
#include "EntradaDatos.h"
#include <string.h>
#include "Indices.h"
#define MOSTRAR_MENU_PRIN  0
#define LIMITE_PAISES  5
#define ALTA  1
#define BAJA  2
#define MOSTRAR_TODO  3
#define MOSTRAR_ESPECIFICO  4
#define MOSTRAR_OCUPADOS  5
#define ABONAR  6
#define RETIRAR  7
#define BUSCAR_ID_VACIO_ESTRUCTURA  8
#define ESTA_LLENA_ESTRUCTURA  9
#define ESTA_VACIA_ESTRUCTURA  10
#define IMPRIMIR_NOM_PAISES  11
#define MOSTRAR_LONGITUDES  12
#define ACTUALIZAR  13
#define SALIR  14
#define ACTUALIZAR_MOSTRAR_MENU  0
#define ACTUALIZAR_NOMBRE  1
#define ACTUALIZAR_SEXO  2
#define SALIR_ACTUALIZAR  3
char* pedirNombrePais(int inicio, char mensaje[], Banco banco[]);
bool estaNombreRepetido(int inicio, char nombrePais[], Banco banco[]);

void mostrarLongitudes(Banco banco[],int num_b){
    int i,j;
    for(i=0;i<num_b;i++){
		printf("\t--> Del Pais %s, existen %i clientes.\n",banco[i].nombrePais,getTotalClientes(banco[i]));
	}
}

void imprimirTodo(Banco banco[],int num_b){
	int i;
    for(i = 0; i < num_b; i++){
        printf("----------------------------------------------------------------------------------------------------------------\n");
        printTodosClientes(banco[i],i);
    }
    sleep(2);
    printf("----------------------------------------------------------------------------------------------------------------\n");
}

void imprimirSoloOcupados(Banco banco[],int num_b){
    int contador = 0,i;
    for(i = 0; i < num_b; i++){
        if(printSoloOcupados(banco[i],i))
            contador++;
    }
    if(contador == 0){
        printf("\t\t ---> No existen clientes que mostrar...");
    }
}
    
void introducirPaises(Banco banco[],int num_b){
	int i;
	char snum[5];
    for(i = 0; i < num_b; i++){
		char mensaje[50] = "Introduce el nombre del Pais ";		
		sprintf(snum,"%d",i);
		strcat(mensaje, snum);
		strcat(mensaje,": ");
        char pais[30];
		strcpy(pais,pedirNombrePais(i, mensaje, banco));
        char paisa[20];
        strcpy(mensaje,"\tIntroduce el total de clientes del pais ");
		strcat(mensaje,pais);
		strcat(mensaje,": ");
		strcpy(paisa,pais);
		int num_clie=validarRango(1, LIMITE_CLIENTES, mensaje);
        banco[i] = crear_banco(pais,num_clie);
    }
}

int validarRango(int inicio, int fin, char mensaje[]){
    int numero = entero(mensaje);
    while(numero < inicio || numero > fin){
    	
        if(numero < inicio || numero > fin){
            printf("\t\tNo esta dentro del Rango...");
            printf("\t\t\t--> El rango va de %i a %i",inicio,fin);
        }
        numero = entero(mensaje);
    }
    return numero;
}

char* pedirNombrePais(int inicio, char mensaje[], Banco banco[]){
    char nombrePais[30];
    printf("%s",mensaje);
    scanf("%s",&nombrePais);
    fflush(stdin);
    while(estaNombreRepetido(inicio, nombrePais, banco)){
        if(estaNombreRepetido(inicio, nombrePais, banco)){
            printf("\t\tEl nombre %s ya se encuentra registrado...",nombrePais);
            printf("\t\t\t--> Intenta de nuevo.");
        }
        printf("%s",mensaje);
    	scanf("%s",&nombrePais);
    }
    return nombrePais;

}

bool estaNombreRepetido(int inicio, char nombrePais[], Banco banco[]){
    bool se_encuentra = false;
    int i;
    for(i = inicio; i > 0; i--){
		if(strcmp(banco[i-1].nombrePais,nombrePais)==0) {
            se_encuentra = true;
            break;
        }
        
    }
    return se_encuentra;
}

int getIndicePais(char nombrePais[], Banco banco[],int tam_ban){
    int indexPais = -1,i;
    for(i = 0; i < tam_ban; i++){
        if(strcmp(banco[i].nombrePais,nombrePais)==0){
            indexPais = i;
            break;
        }
    }
    return indexPais;
}

bool hayVacioTodaEstructura(Banco banco[], int num_ban){
    bool hayLugar = false;
    int i;
    for(i=0;i<num_ban;i++){
    	if (isTodoOcupado(banco[i])) {
            hayLugar = true;
            break;
        }
	}
    return hayLugar;
}

Indices indiceVacioTodaEstructura(Banco banco[],int num_ban) {
    Indices temp = crear_indice();
    int i;
    for(i = 0; i < num_ban; i++) {
        int indice = indiceVacio(banco[i]);
        if(indice != -1) {
            temp.pais = i;
            temp.cliente = indice;
            break;
        }
    }
    return temp;
}

bool estaTodoLlenoEstructura(Banco banco[],int num_ban){
    bool all_lleno = true;
    int i;
    for (i=0;i<num_ban;i++) {
        if (existeEspacioVacio(banco[i])) {
            all_lleno = false;
            break;
        }
    }
    return all_lleno;
}

bool estaTodoVacioEstructura(Banco banco[],int num_ban){
    bool all_vacio = true;
    int i;
    for (i=0;i<num_ban;i++) {
        if (existeEspacioOcupado(banco[i])) {
            all_vacio = false;
            break;
        }
    }
	return all_vacio;
}

int indiceVacioPaisEspecifico(int pais, Banco banco[]){
        return indiceVacio(banco[pais]);
}



bool seEncuentraNombre(char nombrePais[], Banco banco[],int num_ban){
    bool se_encuntra = false;
    int i;
    for (i=0;i<num_ban;i++) {
        if (strcmp(banco[i].nombrePais,nombrePais)==0) {
            se_encuntra = true;
            break;
        }
    }
    return se_encuntra;
}

char* pedirNombrePaisString(char mensaje[], Banco banco[],int num_ban){
    char nombrePais[30];
    printf("%s",mensaje);
    scanf("%s",&nombrePais);
    while(!seEncuentraNombre(nombrePais, banco,num_ban)){
        if(!seEncuentraNombre(nombrePais, banco,num_ban)){
            printf("\t\tEl nombre %s no se encuentra registrado...",nombrePais);
            printf("\t\t\t--> Intenta de nuevo.");
        }
        printf("%s",mensaje);
    	scanf("%s",&nombrePais);
    }
    return nombrePais;
}

void instrucciones(){
    printf("\n-------------------------------\n");
    printf("---- Menú ----\n");
    printf(" 0 Mostrar menú.\n");
    printf(" 1 Dar de alta Cliente.\n");
    printf(" 2 Dar de baja Cliente.\n");
    printf(" 3 Mostrar todos los clientes.\n");
    printf(" 4 Mostrar cliente en especifico.\n");
    printf(" 5 Mostrar solo clientes dados de alta.\n");
    printf(" 6 Abonar saldo a cliente.\n");
    printf(" 7 Retirar saldo de cliente.\n");
    printf(" 8 Buscar indice vacio en toda la estructura.\n");
    printf(" 9 Mostrar si esta toda llena la estructura.\n");
    printf(" 10 Mostrar si esta toda vacia la estructura.\n");
    printf(" 11 Mostrar nombre de paises.\n");
    printf(" 12 Mostrar longitudes.\n");
    printf(" 13 Actualizar datos de cliente especifico.\n");
    printf(" 14 Salir.\n");
    printf("-------------------------------\n");
}

void instrucciones_actualizar(){
    printf("\n-------------------------------\n");
    printf("---- Menú Actualizar ----\n");
    printf(" 0 Mostrar menú.\n");
    printf(" 1 Actualizar Nombre.\n");
    printf(" 2 Actualizar Sexo.\n");
    printf(" 3 Regresar a ménu principal.\n");
    printf("-------------------------------\n");
}

void imprimirPaises(Banco banco[],int tam_ban){
    printf("---------------------------------------------------------------------\n");
    printf("\tLos paises son: ");
    int i;
    for(i = 0; i < tam_ban; i++){
        printf("País [%i] %s",i,banco[i].nombrePais);
    }
    printf("---------------------------------------------------------------------\n");
}

void saltoLinea(){
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int eleccion,tam_ban;
    
    Banco banco[tam_ban=validarRango(1, LIMITE_PAISES, "Introduce el numero de paises: ")];
    introducirPaises(banco,tam_ban);
    saltoLinea();
    mostrarLongitudes(banco,tam_ban);
    saltoLinea();
    instrucciones();
    eleccion = entero(" Elija una opción: ");
    fflush(stdin);
    while(eleccion != SALIR){
		switch(eleccion){
			case ALTA:
                printf(" --- Opción alta ---\n");
                if(hayVacioTodaEstructura(banco,tam_ban)){
                    char nombre_pais[30];
					strcpy(nombre_pais,pedirNombrePaisString("\tIntroduce el nombre del pais: ", banco,tam_ban));
                    int id_pais = getIndicePais(nombre_pais, banco,tam_ban);
                    int cliente = indiceVacioPaisEspecifico(id_pais, banco);
                    if(cliente != -1){
                    	char clientenom[30];
                    	char sexo2;
                    	printf("Introduce nombre del cliente: ");
                    	scanf("%s",&clientenom);
                    	fflush(stdin);
                    	printf("Introduce el Sexo: ");
                    	scanf("%c",&sexo2);
                    	fflush(stdin);
                    	
                        double sueldo=doble("Introduce el Sueldo: ");
                        Cliente temp = crear_cliente(clientenom,sexo2,sueldo);
                        banco[id_pais].clientes=setEspecificoCliente(banco[id_pais],cliente, temp);
                    }
                    else
                        printf("No existe indice vacio en el pais %s.\n",banco[id_pais].nombrePais);
                }
                else {
                    printf("---------------------------------------------------------------------\n");
                    printf("\t\t La estructura esta completamente llena.");
                    printf("---------------------------------------------------------------------\n");
                }
                break;
            case BAJA:
                printf(" --- Opción baja ---\n");
                if(!estaTodoVacioEstructura(banco,tam_ban)){
                    char nombre_pais3[30];
					strcpy(nombre_pais3,pedirNombrePaisString("\tIntroduce el nombre del pais: ", banco,tam_ban));
                    int pais3 = getIndicePais(nombre_pais3, banco,tam_ban);
                    int cliente3 = validarRango(0, (banco[pais3].tam_clientes)-1, "\tIntroduce el indice del cliente: ");
                    if(getIsOcupadoCliente(banco[pais3],cliente3)){
                        printf("\t--> Cliente %s dado de baja.\n",getNombreCliente(banco[pais3],cliente3));
                        eliminarCliente(banco[pais3],cliente3);
                    }
                    else
                        printf("\tEl cliente %i del pais %s no tiene datos.\n",cliente3,banco[pais3].nombrePais );
                }
                else {
                    printf("---------------------------------------------------------------------\n");
                    printf("\t\t La estructura esta toda vacia.\n");
                    printf("---------------------------------------------------------------------\n");
                }
                break;
            case MOSTRAR_TODO:
                printf(" --- Opción mostrar todo ---\n");
                imprimirTodo(banco,tam_ban);
                break;
            case MOSTRAR_MENU_PRIN:
                instrucciones();
                break;
		}
		eleccion = entero(" Elija una opción: ");	
    }
	printf("--- Fin de la Ejecución del Sistema ---\n");
    return 0;
}
