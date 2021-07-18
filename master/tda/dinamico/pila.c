#include "pila.h"

void pila_crear(tda_pila* p)
{
    *p = NULL;
}

int pila_estaVacia(const tda_pila* p)
{
    return *p == NULL;
}

int pila_estaLlena(const tda_pila* p, unsigned cantBytes)
{
    t_nodo* aux = (t_nodo*)malloc(sizeof(t_nodo));
    void* info = malloc(cantBytes);

    free(aux);
    free(info);
    return aux == NULL || info == NULL;
}

int pila_apilar(tda_pila* p, const void* dato, unsigned cantBytes)
{
    t_nodo* newNodo = (t_nodo*)malloc(sizeof(t_nodo));

    if(!(newNodo))
    { return SIN_MEMORIA; }

    if(!(newNodo->info = malloc(cantBytes)))
    {
        free(newNodo);
        return SIN_MEMORIA;
    }

    memcpy(newNodo->info, dato, cantBytes);
    newNodo->tamInfo = cantBytes;
    newNodo->sig = *p;
    *p = newNodo;

    return 1;
}

int pila_desapilar(tda_pila* p, void* dato, unsigned cantBytes)
{
    t_nodo* aux = *p;

    if(aux == NULL)
    { return PILA_VACIA; }

    *p = aux->sig;
    memcpy(dato, aux->info, MIN(cantBytes, aux->tamInfo));
    free(aux->info);
    free(aux);
    return 1;
}

int pila_verTope(const tda_pila* p, void* dato, unsigned cantBytes)
{
    if(*p == NULL)
    { return PILA_VACIA; }

    memcpy(dato, (*p)->info, cantBytes);
    return 1;
}

void pila_vaciar(tda_pila* p)
{
    t_nodo* aux;

    while(*p)
    {
        aux = *p;
        *p = aux->sig;
        free(aux->info);
        free(aux);
    }
}
