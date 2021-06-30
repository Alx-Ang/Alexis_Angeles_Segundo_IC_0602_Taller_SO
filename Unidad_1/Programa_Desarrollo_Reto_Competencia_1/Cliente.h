#include <stdio.h>
#include <string.h>
#include<stdbool.h>
typedef struct Cliente
{
	char nombre[30];
	char sexo;
	double saldo;
	bool ocupado;
}Cliente;
char validarSexo(char sexo);
double validarSaldo(double saldo);
bool setOcupado(Cliente c);
Cliente crear_cliente(char nombre[],char sexo, double saldo){
	Cliente cliente_c;
	if (strlen(nombre)==0 && sexo=='\0' && !saldo)
	{
		strcpy(cliente_c.nombre,"");
		cliente_c.sexo='\0';
		cliente_c.saldo=0.0;
		cliente_c.ocupado=false;
		
	}else{
		
		
        strcpy(cliente_c.nombre,nombre);
		cliente_c.sexo=validarSexo(sexo);
		cliente_c.saldo=validarSaldo(saldo);
		cliente_c.ocupado=true;
	}
	return cliente_c;
}

Cliente setTodosDatos(Cliente origen,Cliente cliente){
        strcpy(origen.nombre,cliente.nombre);
        origen.sexo=validarSexo(cliente.sexo);
        origen.saldo=validarSaldo(cliente.saldo);
        origen.ocupado=setOcupado(origen);
        return origen;
}

char validarSexo(char sexo){
	if(sexo!='M' && sexo!='F'){
    	sexo ='\0';
    }
    return sexo;
}
double validarSaldo(double saldo){
        if(saldo <= 0.0){
            saldo = 0.0;
        }
        return saldo;
}

bool tieneSaldo(Cliente c){
        return c.saldo > 0.0;
    }
bool  tieneDatos(Cliente c){
	if( strlen(c.nombre)==0|| c.sexo == '\0' || strcmp(c.nombre," ")==0){
		return false;	
	}else
	{
		return true;
	}
}
bool setOcupado(Cliente c){
	if(tieneDatos(c)==false){
        	strcpy(c.nombre,"");
			c.sexo='\0';
			c.saldo=0.0;
			return false;       
        }
        else{
            return true;
        }
}
bool isOcupado(Cliente c) {
	return c.ocupado;
}
Cliente eliminar(Cliente c){
	strcpy(c.nombre,"");
	c.sexo='\0';
	c.saldo=0.0;
	c.ocupado=false;
    return c;
}
Cliente cambiarNombre(Cliente c,  char nuevoNombre[]){
        if(strlen(nuevoNombre) != 0 && strcmp(nuevoNombre," ")!=0){
            strcpy(c.nombre,nuevoNombre);
        }
       c.ocupado=setOcupado(c);
       return c;
}
Cliente cambiarSexo(Cliente c ,char sexo){
        if(sexo == 'M' || sexo == 'F'){
            c.sexo = sexo;
        }
        c.ocupado=setOcupado(c);
        return c;
}

Cliente abonarSaldo(Cliente c, double cuanto){
    if(tieneDatos(c)) {
	    if(cuanto > 0.0){
            c.saldo += cuanto;
        }
        else{
            printf("\tImposible, no puedes abonar saldos negativos o nada.");
        }
    }
    return c;
}
Cliente retirarSaldo(Cliente c, double cuanto){
    if(tieneDatos(c)){
        if(cuanto > 0.0){
            if(tieneSaldo(c)){
      	        if(c.saldo >= cuanto)
	        		    c.saldo -= cuanto;
    	        else
                     printf("\tImposible, tu saldo es insuficiente para retirar %f.",cuanto);
            }
            else
                printf("\tImposible, no hay saldo.");
        }
        else
            printf("\tImposible, no puedes retirar saldos negativos o nada.");
    }
    return c;
}
void imprimirCliente(Cliente c){
	printf("-> Nombre: |%s\n| -> Sexo: |%c\n| -> Saldo: |%f\n| -> Ocupado: |%d|\n",c.nombre,c.sexo,c.saldo,c.ocupado);
}
