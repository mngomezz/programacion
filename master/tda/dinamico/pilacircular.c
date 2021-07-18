#include "pilacircular.h"

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
/** ANOTACION
INGRESO SIEMPRE A LO ULTIMO DE LA COLA. LA PILA CIRCULAR CONSISTE DE UN PUNTERO
HACIA EL PRIMER NODO DE LA PILA. EL SIGUIENTE DE ESTE PRIMER NODO SERA POR LO
TANTO, EL ULTIMO. PARA AGREGAR, CREO EL NUEVO NODO Y INDICO QUE EL SIGUIENTE
DE ESTE NUEVO NODO ES EL ENTONCES ULTIMO NODO, Y QUE EL PRIMER NODO DE LA PILA
AHORA PASE A APUNTAR A ESTE NUEVO NODO CREADO. ASI QUEDARIA COMO ULTIMO NODO.
**/
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

    if(*p == NULL)
    {
        newNodo->sig = newNodo;
        *p = newNodo;
    }
    else
    {
        newNodo->sig = (*p)->sig;
        (*p)->sig = newNodo;
    }

    return 1;
}

int pila_desapilar(tda_pila* p, void* dato, unsigned cantBytes)
{
    t_nodo* elim;

    if(*p == NULL)
    { return PILA_VACIA; }

    elim = (*p)->sig;

    memcpy(dato, elim->info, MIN(cantBytes, elim->tamInfo));

    if(*p == elim)
    { *p = NULL; }
    else
    { (*p)->sig = elim->sig; }

    free(elim->info);
    free(elim);

    return 1;
}

int pila_verTope(const tda_pila* p, void* dato, unsigned cantBytes)
{

    if(*p == NULL)
    { return PILA_VACIA; }


    memcpy(dato, (*p)->sig->info, MIN( (*p)->sig->tamInfo, cantBytes) );

    return 1;
}

void pila_vaciar(tda_pila* p)
{
    t_nodo* elim;

    while(*p)
    {
        elim = (*p)->sig;

        if(*p == elim)
        { *p = NULL; }
        else
        { (*p)->sig = elim->sig; }

        free(elim->info);
        free(elim);
    }
}

//Funcion recorrer
int pila_mostrar(tda_pila* p, void (mostrar)(const void* dato))
{
    t_nodo* aux;

    if(*p == NULL)
    { return PILA_VACIA; }

    //creo un puntero y lo apunto al ultimo nodo de la pila
    aux = (*p)->sig;

    // si el ultimo nodo es, al mismo tiempo, el primero
    if(*p == aux)
    { mostrar((aux)->info); }
    else // si hay mas de uno
    {
        do
        {
            //muestro la informacion
            mostrar((aux)->info);
            aux = (aux)->sig;
        }
        while(aux != *p); // mientras no sea el primer nodo

        mostrar((aux)->info);
    }

    return 1;

}
