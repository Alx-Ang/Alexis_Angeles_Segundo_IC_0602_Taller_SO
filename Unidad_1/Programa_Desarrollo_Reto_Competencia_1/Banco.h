#include "Cliente.h"
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define LIMITE_CLIENTES 10
typedef struct Banco
{
	char nombrePais[30];
	
	struct Cliente *clientes;
	int tam_clientes;
}Banco;
Cliente* construirClientes(Banco ban, int tam_cliente);
int getTotalClientes(Banco ban);
bool getIsOcupadoCliente(Banco ban,int index);
void printCliente(Banco ban ,int index);
void imprimirEspecifico(Banco ban,int cliente);
Banco crear_banco(char nombrePais[], int tam_cliente){
	Banco ban;
	ban.tam_clientes=tam_cliente;
	strcpy(ban.nombrePais,nombrePais);
	ban.clientes= (Cliente *)malloc (tam_cliente*sizeof(ban.clientes));
	ban.clientes=construirClientes(ban,tam_cliente);
	return ban;
}
Cliente* construirClientes(Banco ban ,int tam_cliente){
	int i;
	Cliente c[tam_cliente];
	char nombre[30]="\0";
    for(i = 0; i <ban.tam_clientes; i++){
        c[i] = crear_cliente(nombre,'\0',0.0);
    }
    return c;
}
//----
int getTotalClientes(Banco ban){
        return ban.tam_clientes;
}

bool isTodoOcupado(Banco ban){
    bool todo_ocupado = false;
    int contador = 0,i;
    for(i = 0; i < ban.tam_clientes; i++){
        if(getIsOcupadoCliente(ban,i)){
            contador++;
        }
    }
    if(contador == ban.tam_clientes)
        todo_ocupado = true;
    return todo_ocupado;

}

bool getIsOcupadoCliente(Banco ban,int index){
        return isOcupado(ban.clientes[index]);
}

bool isTodoVacio(Banco ban){
        bool todo_vacio = false;
        int contador = 0,i;
        for(i = 0; i < ban.tam_clientes; i++){
            if(getIsOcupadoCliente(ban,i)){
                contador++;
            }
        }
        if(contador == ban.tam_clientes)
            todo_vacio = true;
        return todo_vacio;
    }

bool existeEspacioVacio(Banco ban){
        bool existeVacio = false;
        int i=0;
        for(i = 0; i < getTotalClientes(ban); i++){
            if(!getIsOcupadoCliente(ban,i)){
                existeVacio = true;
                break;
            }
        }
        return existeVacio;
}

bool existeEspacioOcupado(Banco ban){
        bool existeOcupado = false;
        int i;
        for(i = 0; i < getTotalClientes(ban); i++){
            if(getIsOcupadoCliente(ban,i)){
                existeOcupado = true;
                break;
            }
        }
        return existeOcupado;
}

int indiceVacio(Banco ban){
        int index_vacio = -1;
        int i;
        for(i = 0; i < ban.tam_clientes; i++){
            if(!getIsOcupadoCliente(ban,i)){
                index_vacio = i;
                break;
            }
        }
        return index_vacio;
}

bool printSoloOcupados(Banco ban,int pais){
    bool imprimio = false;
    if(existeEspacioOcupado(ban)){
        imprimio = true;
        printf("----------------------------------------------------------------------------------------------------------------\n");
        printf("\tDel pais [%i] %s los clientes disponibles son: ",pais,ban.nombrePais);
        int i;
        for(i = 0; i < getTotalClientes(ban); i++){
            if(getIsOcupadoCliente(ban,i)){
                printf("El cliente %i es: ",i);
                printCliente(ban,i);
            }
        }
        printf("----------------------------------------------------------------------------------------------------------------\n");
    }
    return imprimio;
}

void printTodosClientes(Banco ban,int pais){
    printf("\tDel pais [%i] %s: \n",pais,ban.nombrePais);
    int i;
    for(i = 0; i < ban.tam_clientes; i++){
        printf("El cliente %i es: \n",i);
        printCliente(ban,i);
    }
}

void imprimirEspecifico(Banco ban,int cliente){
    printf("----------------------------------------------------------------------------------------------------------------\n");
    printf("\tDel pais %s: ",ban.nombrePais);
    printCliente(ban,cliente);
    printf("----------------------------------------------------------------------------------------------------------------\n");
}
void printCliente(Banco ban ,int index){
        imprimirCliente(ban.clientes[index]);
}

char* getNombrePais(Banco ban) {
	char* nom;
	strcpy(nom,ban.nombrePais);
    return nom;
}

void setNombrePais(Banco ban,char nombrePais[]) {
    strcpy(ban.nombrePais,nombrePais);
}

Cliente getEspecificoCliente(Banco ban,int index){
    return ban.clientes[index];
}

Cliente* setEspecificoCliente(Banco ban,int index, Cliente cliente){
    Cliente *c=ban.clientes;
    int i;
	for(i = 0; i <ban.tam_clientes; i++){
    	
		if(i==index){
    		c[i]=setTodosDatos(c[index],cliente);
		}
    }	
    return c;
}

char* getNombreCliente(Banco ban,int index){
	char*nom;
	strcpy(nom,ban.clientes[index].nombre);
    return nom;
}

char getSexoCliente(Banco ban,int index){
    return ban.clientes[index].sexo;
}

double getSaldoCliente(Banco ban,int index){
	 return ban.clientes[index].saldo;
}


void eliminarCliente(Banco ban,int index){
	eliminar(ban.clientes[index]);
}
void cambiarNombreCliente(Banco ban,int index, char nuevoNombre[]){
    cambiarNombre(ban.clientes[index],nuevoNombre);
}

void cambiarSexoCliente(Banco ban,int index, char nuevoSexo){
	cambiarSexo(ban.clientes[index],nuevoSexo);
}

void abonarSaldoCliente(Banco ban,int index, double cuanto){
        abonarSaldo(ban.clientes[index],cuanto);
}

void retirarSaldoCliente(Banco ban,int index, double cuanto){
    retirarSaldo(ban.clientes[index],cuanto);
}
