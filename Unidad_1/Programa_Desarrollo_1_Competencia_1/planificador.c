#include <stdio.h>
//#include <windows.h>
//#include "proceso.h"
#include "cola.h"
/*typedef struct proceso
{
	int pdi;
	char estatus;
	int llegada;
	int tim_uso;
} proceso;

proceso crear(int pdi, char estatus,int llegada, int uso){
	proceso pros;
	pros.estatus=estatus;
	pros.llegada=llegada;
	pros.pdi=pdi;
	pros.tim_uso=uso;
	return pros;
}*/
//asignar estado en el que se encuentra
void asignar_es(int num_pro,proceso arreglo[],int pdi,char estado){
	int i=0;
	for(i=0;i<num_pro;i++){
		if(arreglo[i].pdi==pdi){
			arreglo[i].estatus=estado;
        }
	}
}
//buscar si hay llegada en el timpo que el reloj va
void verificar(int reloj_time, proceso arreglo[],int num_pro){
	int i=0;
	for(i=0;i<num_pro;i++){
		if(arreglo[i].llegada==reloj_time){
			insertar(arreglo[i]);
    	}
	}
}
//verificar que todos ahn terminado
int verificar_todos_finalizado(proceso arreglo[],int num_pro){
	int i=0,v=0;
	for(i=0;i<num_pro;i++){
		if(arreglo[i].estatus=='T'){
			v++;
    	}
	}
	if(v==num_pro){
		return 1;
	}else{
		return -1;
	}
}



int main(int argc, char const *argv[])
{
	int pdi;
	char estatus;
	// I=iniciado E= en ejcucion, S= espera, T=terminado
	int llegada;
	int tim_uso;
	int num_pro=0;
	int quantum;
	int i;
	//--------------------------------------
	printf("NUMERO DE PROCESOS A SIMULAR: ");
	scanf("%i",&num_pro);
	fflush(stdin);
	proceso cola[num_pro];
	printf("INGRESA EL VALOR DEL QUANTUM: ");
	scanf("%i",&quantum);
	fflush(stdin);
	for(i=0;i<num_pro;i++){
		printf("\n\nINGRESA EL 'PDI' O IDENTIFICADOR DEL PROCESO %i: ",i+1);
		scanf("%i",&pdi);
		fflush(stdin);
		printf("INGRESA EL TIEMPO DE LLEGADA DEL PROCESO %i: ",i+1);		
		scanf("%i",&llegada);
		fflush(stdin);
		printf("INGRESA EL TIEMPO DE USO DEL PROCESO %i: ",i+1);
		scanf("%i",&tim_uso);
		fflush(stdin);
		estatus='I';
		cola[i]=crear(pdi,estatus,llegada,tim_uso);
	}
	
	//ordenado de la cola resceptora de datos
	int z,v,comparaciones=0,aux;
	for(z = 1; z < num_pro; ++z) {
      for( v = 0; v < (num_pro - z); v++) {
         comparaciones++;
         if(cola[v].llegada > cola[v+1].llegada){
            aux = cola[v].llegada;
            cola[v].llegada = cola[v + 1].llegada;
            cola[v + 1].llegada = aux;
         }
      }
    }
    
	
	///inciar con el proceso
	int reloj=0;
	int cont=1;
	proceso p_uso;
	//printf("xdxd%i",p_uso.pdi);
	if(num_pro!=0){
		while(verificar_todos_finalizado(cola,num_pro)==-1){
			verificar(reloj,cola,num_pro);
			//printf("\n");
			//imprimir();
			if(contar()!=0&&cont-1==0){	
				p_uso=extraer();
				//printf("\n\nEJECUTANDO EL PROCESO %i EN EL LAPSO DE TIEMPO %i-%i",p_uso.pdi,reloj,reloj+1);
				//Sleep(2000);
				//cont++;
			}
			if(p_uso.estatus!='\0'){
				if(p_uso.tim_uso>quantum){
					if(cont==quantum){
						printf("\nMAYOR FINAL EJECUTANDO EL PROCESO %i EN EL LAPSO DE TIEMPO %i-%i\n",p_uso.pdi,reloj,reloj+1);
						p_uso.tim_uso-=cont;
						p_uso.estatus='S';
						asignar_es(num_pro,cola,p_uso.pdi,'S');
						insertar(p_uso);
						cont=1;
						p_uso.estatus='\0';
						sleep(2);
						/*for(i=0;i<num_pro;i++){
							printf("\n\nPDI= %i",cola[i].pdi);
							printf("\nTIEMPO DE USO= %i",cola[i].tim_uso);		
							printf("\nTIEMPO DE LLEGADA = %i",cola[i].llegada);
							printf("\nESTATUS = %c",cola[i].estatus);
							printf("\n\n\n");
						}*/
					}
					/*//validacion cuando es un Q de 1
					else if(cont > quantum){
						p_uso.tim_uso-=cont-1;
						p_uso.estatus='E';
						asignar_es(num_pro,cola,p_uso.pdi,'E');
						insertar(p_uso);
						cont=1;
						p_uso.estatus='\0';
					}*/
					else{
						printf("\nMAYOR EJECUTANDO EL PROCESO %i EN EL LAPSO DE TIEMPO %i-%i",p_uso.pdi,reloj,reloj+1);
						asignar_es(num_pro,cola,p_uso.pdi,'E');
						sleep(2);
						cont++;
					}
				}else if(p_uso.tim_uso<=quantum){
					if(cont==p_uso.tim_uso){
						printf("\nMENOR FINAL EJECUTANDO EL PROCESO %i EN EL LAPSO DE TIEMPO %i-%i\n",p_uso.pdi,reloj,reloj+1);
						p_uso.tim_uso-=cont;
						p_uso.estatus='T';
						asignar_es(num_pro,cola,p_uso.pdi,'T');
						cont=1;
						p_uso.estatus='\0';
						sleep(2);
						/*for(i=0;i<num_pro;i++){
							printf("\n\nPDI= %i",cola[i].pdi);
							printf("\nTIEMPO DE USO= %i",cola[i].tim_uso);		
							printf("\nTIEMPO DE LLEGADA = %i",cola[i].llegada);
							printf("\nESTATUS = %c",cola[i].estatus);
							printf("\n\n\n");
						}*/
					}
					/*//validacion cuando es un Q de 1
					else if(cont > quantum){
						p_uso.tim_uso-=cont-1;
						p_uso.estatus='T';
						asignar_es(num_pro,cola,p_uso.pdi,'T');
						cont=1;
						p_uso.estatus='\0';
					}*/else {
						printf("\nMENOR EJECUTANDO EL PROCESO %i EN EL LAPSO DE TIEMPO %i-%i",p_uso.pdi,reloj,reloj+1);
						asignar_es(num_pro,cola,p_uso.pdi,'E');
						sleep(2);
						cont++;
					}					
				}
			}else
			{
				printf("\nEN ESPERA DE NUEVO PROCESO ...");
				sleep(2);
			}
			/*if(cola[0].tim_uso<=quantum){
				if()
			}*/
			reloj++;
		}
	}else{
		printf("\nNO SE ENCONTRARON PROCESOS.");
		
	}
	printf("\n");
	//imprimir();
	
	//-------------------------------------------
	//imprimir datos
	/*for(i=0;i<num_pro;i++){
		printf("\n\nPDI= %i",cola[i].pdi);
		printf("\nTIEMPO DE USO= %i",cola[i].tim_uso);		
		printf("\nTIEMPO DE LLEGADA = %i",cola[i].llegada);
		printf("\nESTATUS = %c",cola[i].estatus);
		printf("\n\n\n");
	}*/
	
	
	
	
	
	/*
	//ejemplo
	proceso pro;
	pro.estatus='F';
	pro.llegada=2;
	pro.pdi=23;
	pro.tim_uso=4;
	//ejemplo de uso de cola con proceso
	insertar(pro);
	
	
    imprimir();
    printf("\n");
    //proceso per= extraer();
    //printf("%c",per.estatus);
    printf("%i",contar());*/
    
	/*cola[0].pdi=5;
	cola[0].estatus='I';
	cola[0].llegada=0;
	cola[0].tim_uso=5;*/
	/*cola[1]=crear(7,'L',3,9);
	Sleep(1000);
	printf("El estado de la cola es de %c\n",cola[0].estatus);
	Sleep(1000);
	printf("hola\n");
	Sleep(1000);
	printf("El estado de la cola es de %c\n",cola[1].estatus);*/
	return 0;
}
