#include "pila.h"
#include "lista.h"

pila_t *pila_crear()
{
	return (pila_t *)lista_crear();
}

pila_t *pila_apilar(pila_t *pila, void *elemento)
{
	if(!pila || !elemento)
		return NULL;
	

	return (pila_t *)lista_insertar((lista_t *)pila, elemento);
	
}

void *pila_desapilar(pila_t *pila)
{
	if(!pila)
		return NULL;
	
	return (pila_t *)lista_quitar_de_posicion((lista_t *)pila, 0);
	
}

void *pila_tope(pila_t *pila)
{
	if(!pila)
		return NULL;
	
	return (lista_t *)lista_elemento_en_posicion((lista_t *)pila, 0);
	
}

size_t pila_tamanio(pila_t *pila)
{
	if(!pila)
		return 0;
	
	return lista_tamanio((lista_t *)pila);
	
}

bool pila_vacia(pila_t *pila)
{

	if (!pila || (lista_t *)lista_vacia((lista_t *)pila))
		return true;
	
	return false;
	
}

void pila_destruir(pila_t *pila)
{
	if(!pila)
		return;

	lista_destruir((lista_t *)pila);

}
