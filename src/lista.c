#include "lista.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

nodo_t *nodo_crear(void *elemento) 
{
	if(!elemento){
		return NULL;
	}

	nodo_t *nodo = malloc(sizeof(nodo_t));

	if(!nodo){
		return NULL;
	}

	nodo->elemento = elemento;
	nodo->siguiente = NULL;

	return nodo;
}

lista_t *lista_crear()
{
	lista_t *lista = calloc(1, sizeof(lista_t));

	if(!lista)
		return NULL;

	lista->nodo_inicio = NULL;
	lista->nodo_fin = NULL;
	lista->cantidad = 0;

	return lista;
}

lista_t *lista_insertar(lista_t *lista, void *elemento)
{
	if(!lista || !elemento)
		return NULL;
	
	nodo_t *nodo = nodo_crear(elemento);
	
	if(!nodo)
		return NULL;

	if(!lista->nodo_inicio){
		lista->nodo_inicio = nodo;
		lista->nodo_fin = nodo;
		lista->cantidad++;
	}
		
	else{
		lista->nodo_fin->siguiente = nodo;
		lista->nodo_fin = nodo;
		lista->cantidad++;
	}

	return lista;
}

lista_t *lista_insertar_en_posicion(lista_t *lista, void *elemento,
				    size_t posicion)
{
	if(!lista || !elemento)
		return NULL;
	// si la posicion no existe en la lista inserto al final
	if(posicion > lista->cantidad - 1)
		return lista_insertar(lista, elemento);
	
	nodo_t *nodo = nodo_crear(elemento);

	if(!nodo)
		return NULL;

	if(posicion == lista->cantidad){
		lista->nodo_fin->siguiente = nodo;
		lista->nodo_fin = nodo;
		lista->cantidad++;

		return lista;
	}
	else if(posicion == 0){
		nodo->siguiente = lista->nodo_inicio;
		lista->nodo_inicio = nodo;
		lista->cantidad++;

		return lista;
	}
	else{
		nodo_t *nodo_actual = lista->nodo_inicio;
		nodo_t *nodo_anterior = NULL;
		size_t i = 0;
		
		while(i < posicion){
			nodo_anterior = nodo_actual;
			nodo_actual = nodo_actual->siguiente;
			i++;
		}
		
		nodo_anterior->siguiente = nodo;
		nodo->siguiente = nodo_actual;
		lista->cantidad++;
		
		return lista;
	}

}

void *lista_quitar(lista_t *lista)
{
	if(!lista || lista_vacia(lista))
		return NULL;
	
	nodo_t *nodo_actual = lista->nodo_inicio;
	nodo_t *nodo_anterior = NULL;
	void *elemento = NULL;

	while(nodo_actual->siguiente){
		nodo_anterior = nodo_actual;
		nodo_actual = nodo_actual->siguiente;
	}

	elemento = nodo_actual->elemento;
	free(nodo_actual->elemento);
	free(nodo_actual);
	lista->nodo_fin = nodo_anterior;
	lista->cantidad--;
	

	return elemento;
	
}

void *lista_quitar_de_posicion(lista_t *lista, size_t posicion)
{
	if(!lista || lista_vacia(lista))
		return NULL;
	
	if(posicion >= lista->cantidad)

		return lista_quitar(lista);
	
	if(posicion == 0 || posicion > lista->cantidad - 1){
		nodo_t *nodo_actual = lista->nodo_inicio;
		void *elemento = nodo_actual->elemento;
		lista->nodo_inicio = nodo_actual->siguiente;
		free(nodo_actual);
		lista->cantidad--;

		return elemento;
	}
	else{
		nodo_t *nodo_actual = lista->nodo_inicio;
		nodo_t *nodo_anterior = NULL;
		size_t i = 0;
		void *elemento = NULL;

		while(i < posicion){
			nodo_anterior = nodo_actual;
			nodo_actual = nodo_actual->siguiente;
			i++;
		}

		elemento = nodo_actual->elemento;
		nodo_anterior->siguiente = nodo_actual->siguiente;
		free(nodo_actual->elemento);
		free(nodo_actual);
		lista->cantidad--;

		return elemento;
	}
	
}

void *lista_elemento_en_posicion(lista_t *lista, size_t posicion)
{
	if(!lista || lista_vacia(lista))
		return NULL;
	
	if(posicion >= lista->cantidad)
		return NULL;

	nodo_t *nodo_actual = lista->nodo_inicio;

	for(size_t i = 0; i < posicion; i++){
		nodo_actual = nodo_actual->siguiente;
	}

	return nodo_actual->elemento;

}

void *lista_buscar_elemento(lista_t *lista, int (*comparador)(void *, void *),
			    void *contexto)
{
	if(!lista || lista_vacia(lista) || !comparador)
		return NULL;

	nodo_t *nodo_actual = lista->nodo_inicio;

	for(size_t i = 0; i < lista->cantidad; i++){
		if(comparador(nodo_actual->elemento, contexto) == 0)
			return nodo_actual->elemento;
		nodo_actual = nodo_actual->siguiente;
	}

	return NULL;
}

void *lista_primero(lista_t *lista)
{
	if(!lista || lista_vacia(lista))
    	return NULL;
	
	return lista->nodo_inicio->elemento;
}

void *lista_ultimo(lista_t *lista)
{
	if(!lista || lista_vacia(lista))
		return NULL;
	
	return lista->nodo_fin->elemento;
}

bool lista_vacia(lista_t *lista)
{
	if(!lista || lista->cantidad == 0)
		return true;
	
	return false;

}

size_t lista_tamanio(lista_t *lista)
{
	if(!lista)
		return 0;
	
	return lista->cantidad;
}

void lista_destruir(lista_t *lista)
{
	if(!lista)
		return;

	nodo_t *nodo_actual = lista->nodo_inicio;
	nodo_t *nodo_siguiente = NULL;

	for(size_t i = 0; i < lista->cantidad; i++){
		nodo_siguiente = nodo_actual->siguiente;
		free(nodo_actual);
		nodo_actual = nodo_siguiente;
	}

	free(lista);

}

void lista_destruir_todo(lista_t *lista, void (*funcion)(void *))
{
	if(!lista || !funcion) 
		return;

	nodo_t *nodo_actual = lista->nodo_inicio;
	nodo_t *nodo_siguiente = NULL;

	for(size_t i = 0; i < lista->cantidad; i++){
		funcion(nodo_actual->elemento);
		nodo_siguiente = nodo_actual->siguiente;
		nodo_actual = nodo_siguiente;
	}

	lista_destruir(lista);

}

lista_iterador_t *lista_iterador_crear(lista_t *lista)
{
	if(!lista)
		return NULL;
	
	lista_iterador_t *iterador = malloc(sizeof(lista_iterador_t));

	if(!iterador)
		return NULL;

	iterador->lista = lista;
	iterador->corriente = lista->nodo_inicio;

	return iterador;
}

bool lista_iterador_tiene_siguiente(lista_iterador_t *iterador)
{
	if(!iterador)
		return false;

	if(!iterador->corriente)
		return false;
	
	if(iterador->corriente->siguiente)
		return true;

	return true;
}

bool lista_iterador_avanzar(lista_iterador_t *iterador)
{
	if(!iterador)
		return false;
	
	if(!iterador->corriente)
		return false;

	iterador->corriente = iterador->corriente->siguiente;

	return true;
}

void *lista_iterador_elemento_actual(lista_iterador_t *iterador)
{
	if(!iterador)
		return NULL;
	
	if(!iterador->corriente)
		return NULL;
	
	return iterador->corriente->elemento;
}

void lista_iterador_destruir(lista_iterador_t *iterador)
{
	if(!iterador)
		return;

	free(iterador);
}

size_t lista_con_cada_elemento(lista_t *lista, bool (*funcion)(void *, void *),
			       void *contexto)
{
	if(!lista || !funcion || lista_vacia(lista) || !contexto)
		return 0;
	
	nodo_t *nodo_actual = lista->nodo_inicio;
	size_t cantidad = 0;

	for(size_t i = 0; i < lista->cantidad; i++){
		if(funcion(nodo_actual->elemento, contexto) == true)
			cantidad++;
		nodo_actual = nodo_actual->siguiente;
	}

	return cantidad;

}