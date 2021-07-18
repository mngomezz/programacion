#include "colacircular.h"

void cola_crear(tda_cola* c)
{
    *c = NULL;
}

int cola_vacia(const tda_cola* c)
{
    return *c == NULL;
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
/** ANOTACION
INGRESO A LO ULTIMO DE LA COLA Y HAGO QUE ESTE NODO RECIEN INGRESADO AHORA
APUNTE HACIA EL PRIMER NODO (EL SIGUIENTE DEL ENTONCES ULTIMO) Y QUE EL ULTIMO
NODO HASTA ESE ENTONCES, AHORA APUNTE AL NUEVO NODO INGRESADO. LA LISTA AHORA
APUNTA HACIA EL NUEVO NODO CREADO, YA QUE ESTE PASO A SER EL ULTIMO.
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

    if(*c == NULL)
    {
        newNodo->sig = newNodo;
    }
    else
    {
        newNodo->sig = (*c)->sig;
        (*c)->sig = newNodo;
    }

    *c = newNodo;
    return 1;
}

int cola_sacar(tda_cola* c, void* dato, unsigned cantBytes)
/** ANOTACION
PARA SACAR, SACO SIEMPRE EL SIGUIENTE AL QUE APUNTA LA COLA YA QUE LA COLA
APUNTA AL ULTIMO DE LA COLA, Y LA COLA SACA SIEMPRE EL PRIMERO QUE ENTRO, NO EL
ULTIMO.
**/
{
    t_nodo* elim;

    if(*c == NULL)
    { return COLA_VACIA; }

    elim = (*c)->sig;

    memcpy(dato, elim->info, MIN(cantBytes, elim->tamInfo));

    if(*c == elim) // Si es el ultimo nodo
    { *c = NULL; } // ahora apunta a NULL.
    else
    { (*c)->sig = elim->sig; } // sino, apunta al siguiente del que elimino

    free(elim->info);
    free(elim);

    return 1;
}

int cola_verPrimero(const tda_cola* c, void* dato, unsigned cantBytes)
{

    if(*c == NULL)
    { return COLA_VACIA; }


    memcpy(dato, (*c)->sig->info, MIN( (*c)->sig->tamInfo, cantBytes) );

    return 1;
}

void cola_vaciar(tda_cola* c)
{
    t_nodo* elim;

    while(*c)
    {
        elim = (*c)->sig;

        if(*c == elim)
        { *c = NULL; }
        else
        { (*c)->sig = elim->sig; }

        free(elim->info);
        free(elim);
    }
}

int cola_mostrar(tda_cola* c, void (mostrar)(const void* dato))
{
    t_nodo* aux;

    if(*c == NULL)
    { return COLA_VACIA; }

    //creo un puntero y lo apunto al primer nodo de la cola
    aux = (*c)->sig;

    // si el primer nodo es, al mismo tiempo, el ultimo
    if(*c == aux)
    { mostrar((aux)->info); }
    else // si hay mas de uno
    {
        do
        {
            //muestro la informacion
            mostrar((aux)->info);
            aux = (aux)->sig;
        }
        while(aux != *c);  // mientras no sea el ultimo nodo

        mostrar((aux)->info);
    }

    return 1;

}
