#include "src/lista.h"
#include "src/pila.h"
#include "src/cola.h"
#include <stdio.h>
#include <stdlib.h>
#include "pa2m.h"


void listaSeCreaVacia()
{
	//crear una lista y ver si se crea vacía?
	lista_t *lista = lista_crear();
	pa2m_afirmar(lista_primero(lista) == NULL && lista_ultimo(lista) == NULL && lista_tamanio(lista) == 0, "Se crea una lista vacía");
	lista_destruir_todo(lista, free);
}

void listaSeInsertaUnElemento()
{
	//crear una lista y ver si se inserta un elemento?
	lista_t *lista = lista_crear();
	int *elemento = malloc(sizeof(int));
	*elemento = 5;
	lista_insertar(lista, elemento);
	pa2m_afirmar(lista_primero(lista) == elemento && lista_ultimo(lista) == elemento && lista_tamanio(lista) == 1, "Se inserta un elemento en la lista");
	lista_destruir_todo(lista, free);
}

void listaSeInsertaElementoNull()
{
	//crear una lista y ver si se inserta un elemento null?
	lista_t *lista = lista_crear();
	lista_insertar(lista, NULL);
	pa2m_afirmar(lista_primero(lista) == NULL && lista_ultimo(lista) == NULL && lista_tamanio(lista) == 0, "No se inserta un elemento null en la lista");
	lista_destruir_todo(lista, free);
}

void listaSeInsertaElementoNullEnListaNull()
{
	//crear una lista y ver si se inserta un elemento null?
	lista_t *lista = NULL;
	lista_insertar(lista, NULL);
	pa2m_afirmar(lista == NULL, "No se inserta un elemento null en una lista null");
}


void listaSeInsertaElementoEnPosicion()
{
	//crear una lista y ver si se inserta un elemento en una posición?
	lista_t *lista = lista_crear();
	int *elemento = malloc(sizeof(int));
	*elemento = 5;
	lista_insertar(lista, elemento);
	int *elemento2 = malloc(sizeof(int));
	*elemento2 = 6;
	lista_insertar(lista, elemento2);
	int *elemento3 = malloc(sizeof(int));
	*elemento3 = 7;
	lista_insertar_en_posicion(lista, elemento3, 1);
	pa2m_afirmar(lista_primero(lista) == elemento && lista_ultimo(lista) == elemento2 && lista_tamanio(lista) == 3,
		"Se inserta un elemento en una posicion de la lista");
	lista_destruir_todo(lista, free);
}

void listaSeInsertaElementoEnPosicionInvalida()
{
	//crear una lista y ver si se inserta un elemento en una posición inválida?
	lista_t *lista = lista_crear();
	int *elemento = malloc(sizeof(int));
	*elemento = 5;
	int *elemento2 = malloc(sizeof(int));
	*elemento2 = 6;
	int *elemento3 = malloc(sizeof(int));
	*elemento3 = 7;
	lista_insertar(lista, elemento);
	lista_insertar(lista, elemento2);
	lista_insertar_en_posicion(lista, elemento3, 3);
	pa2m_afirmar(lista_primero(lista) == elemento && lista_ultimo(lista) == elemento3 && lista_tamanio(lista) == 3, 
		"No se inserta un elemento en una posición inválida");
	lista_destruir_todo(lista, free);
}

void listaQuitarUltimoElemento()
{
	lista_t *lista = lista_crear();
	int *elemento = malloc(sizeof(int));
	*elemento = 1;
	int *elemento2 = malloc(sizeof(int));
	*elemento2 = 2;
	int *elemento3 = malloc(sizeof(int));
	*elemento2 = 3;
	lista_insertar(lista, elemento);
	lista_insertar(lista, elemento2);
	lista_insertar(lista, elemento3);
	lista_quitar(lista);
	pa2m_afirmar(lista_primero(lista) == elemento && lista_ultimo(lista) == elemento2 && lista_tamanio(lista) == 2, 
		"Se quita el último elemento de la lista");
	lista_destruir_todo(lista, free);
}

void listaQuitarUltimoElementoDeListaVacia()
{
	lista_t *lista = lista_crear();
	lista_quitar(lista);
	pa2m_afirmar(lista_primero(lista) == NULL && lista_ultimo(lista) == NULL && lista_tamanio(lista) == 0, 
		"No se quita un elemento de una lista vacía");
	lista_destruir_todo(lista, free);
}

void listaQuitarElementoEnPosicion()
{
	lista_t *lista = lista_crear();
	int *elemento = malloc(sizeof(int));
	*elemento = 1;
	int *elemento2 = malloc(sizeof(int));
	*elemento2 = 2;
	int *elemento3 = malloc(sizeof(int));
	*elemento2 = 3;
	lista_insertar(lista, elemento);
	lista_insertar(lista, elemento2);
	lista_insertar(lista, elemento3);
	lista_quitar_de_posicion(lista, 1);
	pa2m_afirmar(lista_primero(lista) == elemento && lista_ultimo(lista) == elemento3 && lista_tamanio(lista) == 2,
		"Se quita un elemento de una posición de la lista");
	lista_destruir_todo(lista, free);
}


void listaQuitarElementoEnPosicionInvalida()
{
	lista_t *lista = lista_crear();
	int *elemento = malloc(sizeof(int));
	*elemento = 1;
	int *elemento2 = malloc(sizeof(int));
	*elemento2 = 2;
	int *elemento3 = malloc(sizeof(int));
	*elemento2 = 3;
	lista_insertar(lista, elemento);
	lista_insertar(lista, elemento2);
	lista_insertar(lista, elemento3);
	lista_quitar_de_posicion(lista, 3);
	pa2m_afirmar(lista_primero(lista) == elemento && lista_ultimo(lista) == elemento2 && lista_tamanio(lista) == 2,
		"Al ingresar una posición inválida se quita el ultimo elemento de la lista");
	lista_destruir_todo(lista, free);
}

void listaQuitarElementoEnPosicionDeListaVacia()
{
	lista_t *lista = lista_crear();
	lista_quitar_de_posicion(lista, 0);
	pa2m_afirmar(lista_primero(lista) == NULL && lista_ultimo(lista) == NULL && lista_tamanio(lista) == 0,
		"No se quita un elemento de una posición de una lista vacía");
	lista_destruir_todo(lista, free);
}
void listaQuitarPenultimoElemento()
{
	lista_t *lista = lista_crear();
	int *elemento = malloc(sizeof(int));
	*elemento = 1;
	int *elemento2 = malloc(sizeof(int));
	*elemento2 = 2;
	int *elemento3 = malloc(sizeof(int));
	*elemento2 = 3;
	lista_insertar(lista, elemento);
	lista_insertar(lista, elemento2);
	lista_insertar(lista, elemento3);
	pa2m_afirmar(lista_elemento_en_posicion(lista, (lista_tamanio(lista) - 2)) == elemento2, "Se obtiene el penultimo elemento de la lista");
	lista_destruir_todo(lista, free);
}


void listaSeObtieneElementoEnPosicion()
{
	lista_t *lista = lista_crear();
	int *elemento = malloc(sizeof(int));
	*elemento = 1;
	int *elemento2 = malloc(sizeof(int));
	*elemento2 = 2;
	int *elemento3 = malloc(sizeof(int));
	*elemento2 = 3;
	lista_insertar(lista, elemento);
	lista_insertar(lista, elemento2);
	lista_insertar(lista, elemento3);
	pa2m_afirmar(lista_elemento_en_posicion(lista, 1) == elemento2, 
		"Se obtiene un elemento de una posición de la lista");
	lista_destruir_todo(lista, free);
}

void listaSeObtieneElementoDeListaVacia()
{
	lista_t *lista = lista_crear();
	pa2m_afirmar(lista_elemento_en_posicion(lista, 1) == NULL, 
		"No se obtiene un elemento de una posición de una lista vacía");
	lista_destruir_todo(lista, free);
}

void listaSeObtieneElementoEnPosicionInvalida()
{
	lista_t *lista = lista_crear();
	int *elemento = malloc(sizeof(int));
	*elemento = 1;
	int *elemento2 = malloc(sizeof(int));
	*elemento2 = 2;
	int *elemento3 = malloc(sizeof(int));
	*elemento2 = 3;
	lista_insertar(lista, elemento);
	lista_insertar(lista, elemento2);
	lista_insertar(lista, elemento3);
	pa2m_afirmar(lista_elemento_en_posicion(lista, 3) == NULL, 
		"No se obtiene un elemento de una posición inválida");
	lista_destruir_todo(lista, free);
}

void listaSeObtieneElementoEnPrimerPosicion()
{
	lista_t *lista = lista_crear();
	int *elemento = malloc(sizeof(int));
	*elemento = 1;
	int *elemento2 = malloc(sizeof(int));
	*elemento2 = 2;
	int *elemento3 = malloc(sizeof(int));
	*elemento2 = 3;
	lista_insertar(lista, elemento);
	lista_insertar(lista, elemento2);
	lista_insertar(lista, elemento3);
	pa2m_afirmar(lista_elemento_en_posicion(lista, 0) == elemento, 
		"Se obtiene el elemento en la primera posicion de la lista");
	lista_destruir_todo(lista, free);
}

void listaSeObtieneElementoEnUltimaPosicion()
{
	lista_t *lista = lista_crear();
	int *elemento = malloc(sizeof(int));
	*elemento = 1;
	int *elemento2 = malloc(sizeof(int));
	*elemento2 = 2;
	int *elemento3 = malloc(sizeof(int));
	*elemento2 = 3;
	lista_insertar(lista, elemento);
	lista_insertar(lista, elemento2);
	lista_insertar(lista, elemento3);
	pa2m_afirmar(lista_elemento_en_posicion(lista, (lista_tamanio(lista) - 1)) == elemento3, 
		"Se obtiene el elemento en la ultima posicion de la lista");
	lista_destruir_todo(lista, free);
}

void listaPrimerElemento()
{
	lista_t *lista = lista_crear();
	int *elemento = malloc(sizeof(int));
	*elemento = 1;
	int *elemento2 = malloc(sizeof(int));
	*elemento2 = 2;
	int *elemento3 = malloc(sizeof(int));
	*elemento2 = 3;
	lista_insertar(lista, elemento);
	lista_insertar(lista, elemento2);
	lista_insertar(lista, elemento3);
	pa2m_afirmar(lista_primero(lista) == elemento, "Se obtiene el primer elemento de la lista");
	lista_destruir_todo(lista, free);
}

void listaUltimoElemento()
{
	lista_t *lista = lista_crear();
	int *elemento = malloc(sizeof(int));
	*elemento = 1;
	int *elemento2 = malloc(sizeof(int));
	*elemento2 = 2;
	int *elemento3 = malloc(sizeof(int));
	*elemento2 = 3;
	lista_insertar(lista, elemento);
	lista_insertar(lista, elemento2);
	lista_insertar(lista, elemento3);
	pa2m_afirmar(lista_ultimo(lista) == elemento3, "Se obtiene el ultimo elemento de la lista");
	lista_destruir_todo(lista, free);
}

void listaSeObtieneUltimoElemento()
{
	lista_t *lista = lista_crear();
	int *elemento = malloc(sizeof(int));
	*elemento = 1;
	int *elemento2 = malloc(sizeof(int));
	*elemento2 = 2;
	int *elemento3 = malloc(sizeof(int));
	*elemento2 = 3;
	lista_insertar(lista, elemento);
	lista_insertar(lista, elemento2);
	lista_insertar(lista, elemento3);
	pa2m_afirmar(lista_elemento_en_posicion(lista, 2) == elemento3,
		 "Se obtiene el último elemento de la lista");
	lista_destruir_todo(lista, free);
}

void listaSeObtienePenultimoElemento()
{
	lista_t *lista = lista_crear();
	int *elemento = malloc(sizeof(int));
	*elemento = 1;
	int *elemento2 = malloc(sizeof(int));
	*elemento2 = 2;
	int *elemento3 = malloc(sizeof(int));
	*elemento2 = 3;
	lista_insertar(lista, elemento);
	lista_insertar(lista, elemento2);
	lista_insertar(lista, elemento3);
	pa2m_afirmar(lista_elemento_en_posicion(lista, (lista_tamanio(lista) - 2)) == elemento2, 
		"Se obtiene el penultimo elemento de la lista");
	lista_destruir_todo(lista, free);
}

bool mostrar_elementos(void *elemento, void *contador)
{
	if(elemento && contador){
		printf("Elemento: %d - Contador: %d \n", *(int*)elemento, *(int*)contador);
		(*(int*)contador)++;
		return true;
	}

	return false;
}

void listaSeRecorreConIteradorExterno()
{
	lista_t *lista = lista_crear();
	char *a = malloc(sizeof(char));
	*a = 'a';
	char *b = malloc(sizeof(char));
	*b = 'b';
	char *c = malloc(sizeof(char));
	*c = 'c';
	char *d = malloc(sizeof(char));
	*d = 'd';
	char *w = malloc(sizeof(char));
	*w = 'w';
	lista_insertar(lista, a);
	lista_insertar(lista, c);
	lista_insertar_en_posicion(lista, d, 100);
	lista_insertar_en_posicion(lista, b, 1);
	lista_insertar_en_posicion(lista, w, 3);


	printf("Elementos en la lista: ");
	for (size_t i = 0; i < lista_tamanio(lista); i++)
		printf("%c ", *(char *)lista_elemento_en_posicion(lista, i));

	printf("\n\n");

	printf("Imprimo TODOS LOS ELEMENTOS DE LA LISTA usando el iterador externo: \n");
	lista_iterador_t *it = NULL;

	for (it = lista_iterador_crear(lista);
	     lista_iterador_tiene_siguiente(it); lista_iterador_avanzar(it))
		printf("%c ", *(char *)lista_iterador_elemento_actual(it));

	printf("\n\n");

	pa2m_afirmar(i == 5, "Se recorrio la lista con el iterador externo");

	lista_iterador_destruir(it);

	lista_destruir_todo(lista, free);
}

void listaSeRecorreConIteradorInterno()
{
	lista_t *lista = lista_crear();
	char *elemento = malloc(sizeof(char));
	*elemento = '1';
	char *elemento2 = malloc(sizeof(char));
	*elemento2 = '2';
	char *elemento3 = malloc(sizeof(char));
	*elemento3 = '3';
	lista_insertar(lista, elemento);
	lista_insertar(lista, elemento2);
	lista_insertar(lista, elemento3);
	int contador = 0;
	lista_con_cada_elemento(lista, mostrar_elementos, &contador);
	pa2m_afirmar(contador == 3, "Se recorrio la lista con el iterador interno");
	lista_destruir_todo(lista, free);
}

int main()
{
	pa2m_nuevo_grupo("Pruebas de creación de lista");
	listaSeCreaVacia();

	pa2m_nuevo_grupo("Pruebas de inserción de elementos en lista");
	listaSeInsertaUnElemento();
	listaSeInsertaElementoEnPosicion();
	listaSeInsertaElementoEnPosicionInvalida();

	pa2m_nuevo_grupo("Pruebas de insercion/eliminacion de elementos en lista");
	listaQuitarUltimoElemento();
	listaQuitarElementoEnPosicion();
	listaQuitarPenultimoElemento();
	listaQuitarUltimoElementoDeListaVacia();
	listaQuitarElementoEnPosicionInvalida();
	listaQuitarElementoEnPosicionDeListaVacia();

	pa2m_nuevo_grupo("Pruebas de obtención de elementos en lista");
	listaSeObtieneElementoEnPosicion();
	listaSeObtieneElementoEnPosicionInvalida();
	listaSeObtieneElementoDeListaVacia();
	listaSeObtieneElementoEnPrimerPosicion();
	listaSeObtieneElementoEnUltimaPosicion();
	listaSeObtienePenultimoElemento();
	
	pa2m_nuevo_grupo("Pruebas de iterador externo");
	listaSeRecorreConIteradorExterno();
	pa2m_nuevo_grupo("Pruebas de iterador externo");
	

	

	

	return pa2m_mostrar_reporte();
}
