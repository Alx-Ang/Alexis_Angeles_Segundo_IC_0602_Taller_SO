#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
int conectar_cliente_servidor(char *ip,int puerto);
void enviar_datos(int conexion, char *numero);
void recibir_datos(int conexion);
char * optener_numero();