#include "arbolbinario.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../../funciones/utiles.h"

void arbol_crear(tda_arbol *a)
{
    *a = NULL;
}

int arbol_ingresar(tda_arbol *a, void *info, unsigned cantBytes,
                   int (*cmp)(const void *val1, const void *val2))
{
    int comparacion;
    t_nodoA *newNodo;

    // Mientras el nodo tenga un valor asignado
    while (*a)
    {
        if (!(comparacion = cmp(info, (*a)->info))) // Si son iguales
        {
            return 0;
        } // NO ADMITO DUPLICADOS.

        if (comparacion > 0)
        {
            a = &(*a)->der;
        }
        else
        {
            a = &(*a)->izq;
        }
    }

    /* CREO Y ASIGNO INFO A NODO */
    if (!(newNodo = (t_nodoA *)malloc(sizeof(t_nodoA))))
    {
        return SIN_MEMORIA;
    }

    if (!(newNodo->info = malloc(cantBytes)))
    {
        free(newNodo);
        return SIN_MEMORIA;
    }

    newNodo->der = NULL;
    newNodo->izq = NULL;
    memcpy(newNodo->info, info, cantBytes);
    newNodo->tamInfo = cantBytes;
    /* CREO Y ASIGNO INFO A NODO */

    *a = newNodo;

    return EXITO;
}

void arbol_inorden(tda_arbol *a, void (*acc)(unsigned, const void *))
{
    if (!(*a))
    {
        return;
    }

    //Izq Raiz Der
    arbol_inorden(&(*a)->izq, acc);

    acc(1, (*a)->info);

    arbol_inorden(&(*a)->der, acc);
}

void arbol_preorden(tda_arbol *a, void (*acc)(unsigned, const void *))
{
    if (!(*a))
    {
        return;
    }

    //Raiz Izq Der
    acc(1, (*a)->info);

    arbol_preorden(&(*a)->izq, acc);

    arbol_preorden(&(*a)->der, acc);
}

void arbol_postorden(tda_arbol *a, void (*acc)(unsigned, const void *))
{
    if (!(*a))
    {
        return;
    }

    //Izq Der Raiz
    arbol_postorden(&(*a)->izq, acc);

    arbol_postorden(&(*a)->der, acc);

    acc(1, (*a)->info);
}

int arbol_buscar(tda_arbol *a, void *info, unsigned cantBytes,
                 int (*cmp)(const void *val1, const void *val2))
{
    int comparacion;

    if (!(*a))
    {
        return ARBOL_VACIO;
    }

    while (*a)
    {
        if (!(comparacion = cmp(info, (*a)->info)))
        {
            memcpy(info, (*a)->info, MIN(cantBytes, (*a)->tamInfo));
            return EXITO;
        }

        if (comparacion > 0)
        {
            a = &(*a)->der;
        }
        else
        {
            a = &(*a)->izq;
        }
    }

    return 0;
}

void arbol_mostrar(tda_arbol *a, unsigned contador,
                   void (*print)(unsigned format, const void *dato))
{
    if (!(*a))
    {
        return;
    }

    //Izq Raiz Der
    arbol_mostrar(&(*a)->der, contador + 1, print);

    print(contador * 7, (*a)->info);
    printf("\n");

    arbol_mostrar(&(*a)->izq, contador + 1, print);
}

unsigned arbol_cantNodos(tda_arbol *a)
{
    if (!(*a))
    {
        return ARBOL_VACIO;
    }

    return arbol_cantNodos(&(*a)->izq) + arbol_cantNodos(&(*a)->der) + 1;
}

unsigned arbol_altura(tda_arbol *a)
{
    if (!(*a))
    {
        return ARBOL_VACIO;
    }

    return MAX(arbol_altura(&(*a)->izq), arbol_altura(&(*a)->der)) + 1;
}

int arbol_esCompleto(tda_arbol *a)
{
    unsigned nivel = arbol_altura(a);

    return arbol_chequeoCompleto(a, nivel - 1);
}

int arbol_chequeoCompleto(tda_arbol *a, unsigned nivel)
{
    if (!(*a))
    {
        return ARBOL_VACIO;
    }

    if (!nivel)
    {
        return EXITO;
    }

    return arbol_chequeoCompleto(&(*a)->der, nivel - 1) &&
           arbol_chequeoCompleto(&(*a)->izq, nivel - 1);
}

int arbol_esAVL(tda_arbol *a)
{
    if (!(*a))
    {
        return EXITO;
    }

    if (ABS(arbol_altura(&(*a)->der) - arbol_altura(&(*a)->izq)) > 1)
    {
        return 0;
    }

    return arbol_esAVL(&(*a)->der) && arbol_esAVL(&(*a)->izq);
}

int arbol_esBalanceado(tda_arbol *a)
{
    unsigned nivel = arbol_altura(a);

    return arbol_chequeoCompleto(a, nivel - 2);
}

int arbol_vaciar(tda_arbol *a)
{
    int contador = 0;

    if (!(*a))
    {
        return ARBOL_VACIO;
    }

    //Izq Der Raiz
    contador += arbol_vaciar(&(*a)->izq);

    contador += arbol_vaciar(&(*a)->der);

    free((*a)->info);
    free(*a);

    *a = NULL;

    return contador + 1;
}

int arbol_eliminarRaiz(tda_arbol *a)
{
    int hIzq,
        hDer;
    t_nodoA *elim,
        **temp;

    if (!*a)
    {
        return ARBOL_VACIO;
    }

    free((*a)->info);

    hIzq = arbol_altura(&(*a)->izq);
    hDer = arbol_altura(&(*a)->der);
    if (!(hIzq + hDer))
    {
        free(*a);
        *a = NULL;
        return EXITO;
    }

    if (hIzq > hDer)
    {
        temp = arbol_buscoMayor(&(*a)->izq);
    }
    else
    {
        temp = arbol_buscoMenor(&(*a)->der);
    }

    elim = *temp;
    (*a)->info = elim->info;
    (*a)->tamInfo = elim->tamInfo;

    *temp = elim->izq ? elim->izq : elim->der;
    free(elim);
    return EXITO;
}

t_nodoA **arbol_buscoMayor(tda_arbol *a)
{
    if ((*a)->der)
    {
        return arbol_buscoMayor(&(*a)->der);
    }

    return a;
}

t_nodoA **arbol_buscoMenor(tda_arbol *a)
{
    if ((*a)->izq)
    {
        return arbol_buscoMenor(&(*a)->izq);
    }

    return a;
}

t_nodoA **arbol_buscarNodo(const tda_arbol *a, void *info,
                           int (*cmp)(const void *val1, const void *val2))
{
    int comparacion = 0;

    if (!*a)
    {
        return NULL;
    }

    comparacion = cmp(info, (*a)->info);

    //Si la info por parametro es menor que la info del nodo
    //Como es un binary search, busco por izquierda
    if (comparacion < 0)
    {
        return arbol_buscarNodo(&(*a)->izq, info, cmp);
    }

    //Si la info por parametro es mayor que la info del nodo
    //como es binary search lo tengo que buscar por derecha
    if (comparacion > 0)
    {
        return arbol_buscarNodo(&(*a)->der, info, cmp);
    }

    //Chequeo si el nodo donde estoy parado corresponde al dato que busco
    //si es así devuelvo 1, encontrado
    return (tda_arbol *)a;
}

int arbol_eliminar(tda_arbol *a, void *info, unsigned tamInfo,
                   int (*cmp)(const void *val1, const void *val2))
{
    t_nodoA **elim;

    if (!(elim = arbol_buscarNodo(a, info, cmp)))
    {
        return 0;
    } //en caso de no encontrarlo retorna 0
    memcpy(info, (*elim)->info, MIN(tamInfo, (*elim)->tamInfo));

    return arbol_eliminarRaiz(elim);
}
