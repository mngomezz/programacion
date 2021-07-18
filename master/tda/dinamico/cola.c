#include "cola.h"

void cola_crear(tda_cola* c)
{
    c->primero = NULL;
    c->ultimo  = NULL;
}

int cola_llena(const tda_cola* c, unsigned cantBytes)
{
    t_nodo* aux = (t_nodo*)malloc(sizeof(t_nodo));
    void* info = malloc(cantBytes);

    free(aux);
    free(info);

    return aux == NULL || info == NULL;
}

int cola_agregar(tda_cola* c, const void* dato, unsigned cantBytes)
{
    t_nodo* nuevo = (t_nodo*)malloc(sizeof(t_nodo));

    if(nuevo == NULL || (nuevo->info = malloc(cantBytes)) == NULL)
    {
        free(nuevo);
        return 0;
    }

    memcpy(nuevo->info, dato, cantBytes);
    nuevo->tamInfo = cantBytes;
    nuevo->siguiente = NULL;

    if(c->primero)
    { c->ultimo->siguiente = nuevo; }
    else
    { c->primero = nuevo; }

    c->ultimo = nuevo;

    return 1;
}

int cola_verPrimero(const tda_cola* c, void* dato, unsigned cantBytes)
{
    if(c->primero == NULL)
    { return 0; }

    memcpy(dato, c->primero->info, MIN(cantBytes, c->primero->tamInfo));

    return 1;
}

int cola_vacia(const tda_cola* c)
{
    return c->primero == NULL;
}

int cola_sacar(tda_cola* c, void* dato, unsigned cantBytes)
{
    t_nodo* aux = c->primero;

    if(aux == NULL)
    { return 0; }

    c->primero = aux->siguiente;

    memcpy(dato, aux->info, MIN(aux->tamInfo, cantBytes));

    free(aux->info);
    free(aux);

    if(c->primero == NULL)
    { c->ultimo = NULL; }

    return 1;
}

void cola_vaciar(tda_cola* c)
{
    while(c->primero)
    {
        t_nodo* aux = c->primero;
        c->primero = aux->siguiente;

        free(aux->info);
        free(aux);
    }

    c->ultimo = NULL;
}



