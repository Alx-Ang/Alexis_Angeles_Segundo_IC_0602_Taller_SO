#include "scheduler.h"
#include <pthread.h>
#include <stdlib.h>

void reproducir_musica(void);
void abrir_youtube(void);
void escribir_texto_word(void);
void descargar_archivo(void);
void subiendo_archivo(void);
void compilando_programa(void);
void ejecutando_programa(void);
void usando_terminal(void);

int main(int argc, char const *argv[]){
	process *p1 = crear_Proceso(1, UN_SEGUNDO, "Proceso_1", reproducir_musica, ACTIVO); 		//<--
	
	process *p2 = crear_Proceso(6, DOS_SEGUNDOS, "Proceso_1", abrir_youtube, ACTIVO);
	process *p3 = crear_Proceso(5, TRES_SEGUNDOS, "Proceso_2", escribir_texto_word, NO_ACTIVO); 	//<--
	process *p4 = crear_Proceso(4, TRES_SEGUNDOS, "Proceso_3", descargar_archivo, NO_ACTIVO);   	//<--
	process *p5 = crear_Proceso(3, TRES_SEGUNDOS, "Proceso_4", subiendo_archivo, NO_ACTIVO);		
	process *p6 = crear_Proceso(4, TRES_SEGUNDOS, "Proceso_5", compilando_programa, NO_ACTIVO);
	process *p7 = crear_Proceso(0, TRES_SEGUNDOS, "Proceso_6", ejecutando_programa, ACTIVO);	//<--	
	process *p8 = crear_Proceso(2, CUATRO_SEGUNDOS, "Proceso_7", usando_terminal, ACTIVO);		//<--
	process *p9 = crear_Proceso(5, CUATRO_SEGUNDOS, "Proceso_8", usando_terminal, NO_ACTIVO);	//<--


/*	pthread_t thread_id;
	pthread_create(&thread_id, NULL, reproducir_musica, NULL);
	Los atributos al crear un thread son:.
		-> Puntero al Identificador
		-> Atributos
		-> Función que ejecutará el Hilo
		-> Argumento que reciba la función
	Si el hilo fue creado con éxito la función devuelve pthread_create devolverá un 0
	Se puede comprobar usando un if
		if (0 != pthread(&thread_id, NULL, FUNCTION, NULL))
			return -1 // en caso de fallar, devuelve -1
	pthread_create(&thread_id, NULL, abrir_youtube, NULL);
	pthread_create(&thread_id, NULL, escribir_texto_word, NULL);
	pthread_join(thread_id, NULL);
	pthread_exit(NULL);
*/

	array_procesos *array = crear_ArrayProcesos();

	agregar_Proceso(array, *p1);
	agregar_Proceso(array, *p2);
	agregar_Proceso(array, *p3);
	agregar_Proceso(array, *p4);
	agregar_Proceso(array, *p5);
	agregar_Proceso(array, *p6);
	agregar_Proceso(array, *p7);
	agregar_Proceso(array, *p8);
	agregar_Proceso(array, *p9);

	ejecutar_Procesos(array);

	free(array);
	free(p1);
	free(p2);
	free(p3);
	free(p4);
	free(p5);
	free(p6);
	free(p7);
	free(p8);
	free(p9);

	return 0;
}

void reproducir_musica(void){
	printf("Reproduciendo Música\n");
	system("gnome-terminal -- bash -c qmmp");
	printf("PID: %i\n", getpid());
}

void abrir_youtube(void){
	printf("Usando Youtube\n");
	system("xdg-open http://www.youtube.com");
	printf("PID: %i\n", getpid());
}

void escribir_texto_word(void){
	printf("Escribiendo Texto en Word\n");
	system("gnome-terminal -- bash -c vim test.txt");
	printf("PID: %i\n", getpid());
}

void descargar_archivo(void){
	printf("Descargando Archivo\n");
	printf("PID: %i\n", getpid());
}

void subiendo_archivo(void){
	printf("Subiendo Archivo\n");
	printf("PID: %i\n", getpid());
}

void compilando_programa(void){
	printf("Compilando programa\n");
	printf("PID: %i\n", getpid());
}

void ejecutando_programa(void){
	printf("Ejecutando Python\n");
	system("gnome-terminal -- bash -c python3");
	printf("PID: %i\n", getpid());
}

void usando_terminal(void){
	printf("Usando la terminal\n");
	system("gnome-terminal");
	printf("PID: %i\n", getpid());
}
