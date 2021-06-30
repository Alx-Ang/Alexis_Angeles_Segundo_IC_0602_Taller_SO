#include <stdio.h>
#include "cola.h"

void asignar_es(int num_pro,proceso arreglo[],int pdi,char estado){
	int i=0;
	for(i=0;i<num_pro;i++){
		if(arreglo[i].pdi==pdi){
			arreglo[i].estatus=estado;
        }
	}
}

void verificar(int reloj_time, proceso arreglo[],int num_pro){
	int i=0;
	for(i=0;i<num_pro;i++){
		if(arreglo[i].llegada==reloj_time){
			insertar(arreglo[i]);
    	}
	}
}

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
    
	int reloj=0;
	int cont=1;
	proceso p_uso;

	if(num_pro!=0){
		while(verificar_todos_finalizado(cola,num_pro)==-1){
			verificar(reloj,cola,num_pro);
			
			if(contar()!=0&&cont-1==0){	
				p_uso=extraer();
				
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
						
					}
					
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
						
					}
					else {
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
			
			reloj++;
		}
	}else{
		printf("\nNO SE ENCONTRARON PROCESOS.");
		
	}
	printf("\n");
	
	return 0;
}
