#include "listasimple.h"
#include "../../funciones/utiles.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#define LISTA_VACIA 0

void lista_crear(tda_lista *l)
{
    *l = NULL;
}

int lista_agregar(tda_lista *l, const void *info, unsigned cantBytes)
{
    t_nodo *nuevo = (t_nodo *)malloc(sizeof(t_nodo));

    if (!(nuevo))
    {
        return 0;
    }

    nuevo->info = malloc(cantBytes);

    if (!(nuevo->info))
    {
        free(nuevo);
        return 0;
    }

    memcpy(nuevo->info, info, cantBytes);
    nuevo->tamInfo = cantBytes;
    nuevo->siguiente = *l;
    *l = nuevo;

    return 1;
}

int lista_eliminar(tda_lista *l, void *info,
                   int (*cmp)(const void *val1, const void *val2))
{
    int comparacion;
    t_nodo *aux;

    while (*l) // Recorro lista chequeando si es el dato que quiero eliminar
    {
        comparacion = cmp((*l)->info, info);

        if (!comparacion)
        {
            memcpy(info, (*l)->info, (*l)->tamInfo); // Devuelvo dato
            aux = *l;                                // Dejo nodo a eliminar en auxiliar
            *l = aux->siguiente;                     // Conecto lista
            free(aux->info);                         // Libero info
            free(aux);                               // Libero nodo
            return 1;
        }

        //Direcciono el puntero a lista(nodo) hacia el siguiente de la lista.
        //Esto lo hago para moverme por la lista en la funcion y no cambiar el
        //puntero del main.
        l = &(*l)->siguiente;
    }

    return 0;
}

int lista_mostrar(tda_lista *l, void (*mostrar)(const void *dato))
{
    if (*l == NULL)
    {
        return 0;
    }

    while ((*l) != NULL)
    {
        mostrar((*l)->info);
        l = &(*l)->siguiente;
    }

    return 1;
}

int lista_buscar(const tda_lista *l, void *info,
                 int (*cmp)(const void *val1, const void *val2))
{
    int comparacion;

    while (*l)
    {
        comparacion = cmp((*l)->info, info);

        if (!comparacion)
        {
            memcpy(info, (*l)->info, (*l)->tamInfo);
            return 1;
        }

        l = &(*l)->siguiente;
    }

    return 0;
}

void lista_filtrar(tda_lista *l, int filtro(const void *dato))
{
    t_nodo *aux;

    while (*l)
    {

        if (filtro((*l)->info)) // si pasa el filtro
        {
            l = &(*l)->siguiente;
        }    // muevo al siguiente
        else // elimino
        {
            aux = (t_nodo *)*l;  // Dejo nodo a eliminar en auxiliar
            *l = aux->siguiente; // Conecto lista
            free(aux->info);     // Libero info
            free(aux);           // Libero nodo
        }
    }
}

int lista_reducir(const tda_lista *l, void *dato,
                  void operacion(const void *dato, void *acumulador))
{
    while (*l)
    {
        operacion((*l)->info, dato); // acumulo, calculo promedio, etc...
        l = &(*l)->siguiente;        // muevo al siguiente
    }

    return 1;
}

void lista_ordenar(tda_lista *l, int (*cmp)(const void *val1, const void *val2))
{
    t_nodo **menor = l;
    t_nodo *aux;

    while (*l)
    {
        menor = _buscoMenor(l, cmp);
        if (*menor != *l)
        {
            ///QUITO NODO DE DONDE ESTA.
            // Guardo la direccion del nodo menor en un auxiliar.
            aux = *menor;
            // Conecto el anterior del menor con el proximo (sacando el menor).
            *menor = aux->siguiente;

            ///PONGO NODO AL PRINCIPIO.
            // El siguiente del menor es el que hasta entonces era el primero.
            aux->siguiente = *l;
            // Ahora el menor es el primero en la lista.
            *l = aux;
        }

        l = &(*l)->siguiente;
    }
}

t_nodo **_buscoMenor(const tda_lista *l,
                     int (*cmp)(const void *val1, const void *val2))
/** ANOTACIONES
"l" es una direccion de un puntero a un nodo. Por lo tanto, pMenor debe ser un
 puntero a puntero. Ya que deberia apuntar a l. El cual tiene una direccion de
 un puntero a nodo.
**/
{
    t_nodo **pMenor = (t_nodo **)l;

    while (*l)
    {
        if (cmp((*l)->info, (*pMenor)->info) < 0)
        {
            pMenor = (t_nodo **)l;
        }

        l = &(*l)->siguiente;
    }

    return pMenor;
}

int lista_agregarEnPosicion(tda_lista *l, int pos, const void *info,
                            unsigned cantBytes)
{
    t_nodo *nue = malloc(sizeof(t_nodo));

    if (!nue)
    {
        return LISTA_VACIA;
    }

    nue->info = malloc(cantBytes);

    if (!(nue->info))
    {
        free(nue);
        return SIN_MEMORIA;
    }

    memcpy(nue->info, info, cantBytes);
    nue->tamInfo = cantBytes;

    while ((*l) && (pos > 0))
    {
        l = &(*l)->siguiente;
        pos--;
    }

    nue->siguiente = *l;
    *l = nue;

    return EXITO;
}

size_t lista_contarNodos(tda_lista *l)
{
    if (!*l)
    {
        return LISTA_VACIA;
    }

    return lista_contarNodos(&(*l)->siguiente) + 1;
}

int lista_mostrarR(tda_lista *l, void (*mostrar)(const void *dato))
{
    if (!(*l))
    {
        return LISTA_VACIA;
    }

    mostrar((*l)->info);

    lista_mostrarR(&(*l)->siguiente, mostrar);

    return EXITO;
}

t_nodo **lista_getNodo(tda_lista *l, void *info,
                       int cmp(const void *val1, const void *val2))
{
    while ((*l) && (cmp((*l)->info, info) != 0))
    {
        l = &(*l)->siguiente;
    }

    if (!(*l))
    {
        return NULL;
    }

    memcpy(info, (*l)->info, (*l)->tamInfo);
    return l;
}
