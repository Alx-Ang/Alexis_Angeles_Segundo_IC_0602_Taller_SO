#include "servidor_funciones.h"
int main(int argc, char const *argv[])
{
	if (argc==2)
	{
		int servidor,cliente,c=0,i;
		servidor=iniciar_socket_puerto(atoi(argv[1]));
		cliente=aceptar(servidor);
		char *cadena,*num1,*num2,*res;
		cadena=leer(cliente,1024);
		while(cadena[c]!='\0'){
			c++;
		}
		num1=(char*)malloc(c);
		for (i = 0; i <= c; ++i)
		{
			num1[i]=cadena[i];
		}
		printf("Primer valor recibido= %s\n", num1);
		fflush(stdin);
		cadena=leer(cliente,1024);
		while(cadena[c]!='\0'){
			c++;
		}
		num2=(char*)malloc(c);
		for (i = 0; i <= c; ++i)
		{
			num2[i]=cadena[i];
		}
		printf("Segundo valor recibido= %s\n", num2);
		res=hacer_suma(num1,num2);
		enviar(cliente,res);
		free(res);
		close(servidor);
		close(cliente);	
	}else{
		printf("Falta puerto <PUERTO>\n");
	}
	return 0;
}
