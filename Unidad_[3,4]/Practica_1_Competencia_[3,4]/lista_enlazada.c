#include "lista_enlazada.h"

int esta_vacia(lista *l){
	if (l->fin==NULL)
	{
		return 1;
	}else{
		
		return 0;
	}
}

void ingresar_dato(lista *l,char palabras[100]){
	nodo *nuevo;
	nuevo=(nodo*)malloc(sizeof(struct nodo));
	strcpy(nuevo->palabra,palabras);
	nuevo->ant=NULL;
	nuevo->sig=NULL;	
	if (esta_vacia(l)==1)
	{
		l->ini=nuevo;
		l->fin=nuevo;
	}else{
		nuevo->ant=l->fin;
		l->fin->sig=nuevo;
		l->fin=nuevo;
	}
}

void imprimir_lista(lista *l){
	nodo *temp=l->ini;
	while(temp!=NULL){
		printf("%s->",temp->palabra);
		temp=temp->sig;
	}
	printf("\n");
}
void imprimir_lista_r(lista *l){
	nodo *temp=l->fin;
	while(temp!=NULL){
		printf("%s->",temp->palabra);
		temp=temp->ant;
	}
	printf("\n");
}

void limpiar_nodo(nodo *n){
	free(n);
}

void limpiar_lista(lista *l){
	free(l);
}

void ordenar(lista *l,int n){
	int z,v;
	nodo *aux,*aux2,*aux3,*temp,*temp2;
	temp=l->ini;
	temp2=l->ini->sig;
	for (z = 1; z < n; ++z)
	{
		temp=l->ini;
		temp2=l->ini->sig;
		for (v = 0; v <(n-z); ++v)
		{
			if (strcasecmp(temp->palabra,temp2->palabra)>0)
			{
				aux2=temp->ant; 
				aux3=temp2->sig;
				aux=temp;
				temp=temp2;
				temp2=aux;
				if (aux2==NULL)
				{
					temp->sig=aux;
					temp->ant=NULL;
					temp2->ant=temp;
					temp2->sig=aux3;
					if (aux3==NULL)
					{
						temp2->sig=NULL;
					}else{
						temp2->sig=aux3;
						aux3->ant=temp2;
					}
				}else{
					aux2->sig=temp;
					temp->sig=aux;
					temp->ant=aux->ant;
					temp2->ant=temp;
					if (aux3==NULL)
					{
						temp2->sig=NULL;
					}else{
						temp2->sig=aux3;
						aux3->ant=temp2;
					}
				}
			}
			if(v==0){
				l->ini=temp;
			}
			if(temp2->sig!=NULL){
				temp=temp2;
				temp2=temp2->sig;
			}
		}
		if (z==1)
		{
			l->fin=temp2;
		}
	}

}
