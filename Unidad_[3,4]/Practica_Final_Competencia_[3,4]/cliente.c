#include "cliente_funciones.h"

int main(int argc, char const *argv[])
{
    if (argc ==3)
    {
        int puerto=atoi(argv[2]),cliente_conexion;
        char *num;
        char *ip=(char *)argv[1];
        cliente_conexion=conectar_cliente_servidor(ip,puerto);
        printf("Ingrese el primer numero: ");
        num=optener_numero();
        enviar_datos(cliente_conexion, num);
        fflush(stdin);
        printf("Ingrese el segundo numero: ");
        num=optener_numero();
        enviar_datos(cliente_conexion, num);
        recibir_datos(cliente_conexion);
        close(cliente_conexion);
    }else{
        printf("Faltan parametros <host(ip)> <puerto>\n");
    }
    return 0;
}
