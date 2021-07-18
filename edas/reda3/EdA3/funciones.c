/**/ /*             en los siguientes macroreemplazos indique:             */ /**/
/**/ /*    su(s)         APELLIDO(S)     completo(s)                       */ /**/
/**/ /*    su(s)         Nombre(S)       completo(s)                       */ /**/
/**/ /*    su legajo     N�MERO DE DNI   con los puntos de mill�n y de mil */ /**/
/**/ /*    COMISI�N                                                        */ /**/
/**/ /*              reemplazando los que est�n como ejemplo               */ /**/
#define APELLIDO "*****"
#define NOMBRE "mngomezz"
#define DOCUMENTO "**.***.***"
#define COMISION "**(****)"
/**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/
/** aqu� insertaremos nuestras observaciones y / o correcciones              **/
/**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/
#undef APELLIDO
#undef NOMBRE
#undef DOCUMENTO
#undef COMISION
/**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/
/**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/
/**/ /**/ /* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, H�GALO DESDE AC� */                 /**/
#include <stdlib.h>

/**/ /**/ /* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, H�GALO HASTA AC� */                 /**/
/**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/
#include "funciones.h"
#include <string.h>

int cmp_clave(const void *nota1, const void *nota2)
{
    return strcmp(((tEvalua *)nota1)->clave, ((tEvalua *)nota2)->clave);
}

int cmp_calif(const void *nota1, const void *nota2)
{
    return ((tEvalua *)nota2)->calif - ((tEvalua *)nota1)->calif;
}

int listaDoble_insertar(tListaDobl *l, tNodoDobl *pNodoAnt, tNodoDobl *pNodoSig,
                        const void *nota, unsigned cantBytes)
{
    tNodoDobl *nue;
    if ((nue = (tNodoDobl *)malloc(sizeof(tNodoDobl))) == NULL ||
        (nue->info = malloc(cantBytes)) == NULL)
    {
        free(nue);
        return SIN_MEMORIA;
    }

    memcpy(nue->info, nota, cantBytes);
    nue->tamInfo = cantBytes;
    nue->der = pNodoSig;
    nue->izq = pNodoAnt;

    if (pNodoAnt)
    {
        pNodoAnt->der = nue;
    }

    if (pNodoSig)
    {
        pNodoSig->izq = nue;
    }

    *l = nue;
    return TODO_BIEN;
}

/** para el PUNTO 1 a.- **/
int ponerEnListaDoblNMejores_MIO(tListaDobl *lista, const void *nota,
                                 size_t cantBytes, int tope)
{
    void *notaAuxiliar = (void *)nota;
    unsigned totalNotas = 0, repeticionUltimo = 0;
    int cmp, cantEliminados = 0, elimineLugarAInsertar = 0, nodosSinRepetir = 0;
    tNodoDobl *pUltimoNodo = NULL, *pNodoActual = *lista, *pNodoAnterior = NULL,
              *pLugarDondeInserto = NULL, *pNodoAux;

    while (pNodoActual && pNodoActual->izq)
    {
        pNodoActual = pNodoActual->izq;
    }

    while (pNodoActual && !pLugarDondeInserto)
    {
        if ((cmp = cmp_calif(nota, pNodoActual->info)) > 0 ||
            (cmp == 0 && cmp_clave(nota, pNodoActual->info) > 0))
        {
            totalNotas++;
            if (cmp == 0)
            {
                repeticionUltimo++;
            }
            else
            {
                repeticionUltimo = 0;
                if (totalNotas >= tope)
                {
                    return NO_SE_INSERTA;
                }
            }
            pNodoAnterior = pNodoActual;
            pNodoActual = pNodoActual->der;
        }
        else
        {
            pLugarDondeInserto = pNodoActual;
            pNodoAnterior = pLugarDondeInserto->izq;
        }
    }

    if (!pLugarDondeInserto)
    {
        return listaDoble_insertar(lista, pNodoAnterior, pNodoActual, nota,
                                   cantBytes);
    }

    while (pNodoActual && nodosSinRepetir < tope)
    {
        totalNotas++;
        if ((cmp = cmp_calif(notaAuxiliar, pNodoActual->info)) < 0)
        {
            repeticionUltimo = 0;
        }
        else
        {
            repeticionUltimo++;
        }

        if ((nodosSinRepetir = totalNotas - repeticionUltimo) < tope)
        {
            notaAuxiliar = pNodoActual->info;
            pNodoActual = pNodoActual->der;
        }
    }

    while (pNodoActual)
    {
        pNodoAux = pNodoActual->der;

        if (cantEliminados == 0)
        {
            pUltimoNodo = pNodoActual->izq;
        }

        if (pNodoActual == pLugarDondeInserto)
        {
            elimineLugarAInsertar = 1;
        }

        cantEliminados--;
        free(pNodoActual->info);
        free(pNodoActual);
        pNodoActual = pNodoAux;
    }

    if (cantEliminados != 0)
    {
        if (pUltimoNodo)
        {
            pUltimoNodo->der = NULL;
        }
        else
        {
            *lista = NULL;
        }

        pNodoAux = pNodoAnterior ? pNodoAnterior->der : pLugarDondeInserto;

        if (elimineLugarAInsertar)
        {
            pNodoAux = NULL;
        }

        listaDoble_insertar(lista, pNodoAnterior, pNodoAux, nota, cantBytes);
        return cantEliminados;
    }

    pNodoActual = pLugarDondeInserto;
    pNodoAnterior = pLugarDondeInserto ? pLugarDondeInserto->izq : NULL;
    return listaDoble_insertar(lista, pNodoAnterior, pLugarDondeInserto, nota,
                               cantBytes);
}

int listaSimple_insertar(tListaSimp *l, const void *nota, unsigned cantBytes)
{
    tNodoSimp *nue;
    if ((nue = (tNodoSimp *)malloc(sizeof(tNodoSimp))) == NULL ||
        (nue->info = malloc(cantBytes)) == NULL)
    {
        free(nue);
        return 0;
    }

    memcpy(nue->info, nota, cantBytes);
    nue->tamInfo = cantBytes;
    nue->sig = *l;
    *l = nue;
    return TODO_BIEN;
}

/** para el PUNTO 1 b.- **/
int ponerEnListaSimpNMejores_MIO(tListaSimp *lista, const void *nota,
                                 size_t cantBytes, int tope)
{
    void *notaAuxiliar = (void *)nota;
    unsigned totalNotas = 0, repeticionUltimo = 0;
    int cmp, cantEliminados = 0, nodosSinRepetir = 0;
    tNodoSimp **pLugarDondeInserto = NULL;
    tNodoSimp *pNodoAEliminar = NULL;

    while (*lista && !pLugarDondeInserto)
    {
        if ((cmp = cmp_calif(nota, (*lista)->info)) > 0 ||
            (cmp == 0 && cmp_clave(nota, (*lista)->info) > 0))
        {
            if (cmp == 0)
            {
                repeticionUltimo++;
            }
            else
            {
                repeticionUltimo = 0;
                if ((totalNotas + 1) >= tope)
                {
                    return NO_SE_INSERTA;
                }
            }
        }
        else
        {
            pLugarDondeInserto = &(*lista);
        }

        if (!pLugarDondeInserto)
        {
            lista = &(*lista)->sig;
            totalNotas++;
        }
    }

    if (!pLugarDondeInserto)
    {
        return listaSimple_insertar(lista, nota, cantBytes);
    }

    while (*lista && nodosSinRepetir < tope)
    {
        totalNotas++;

        if ((cmp = cmp_calif(notaAuxiliar, (*lista)->info)) == 0)
        {
            repeticionUltimo++;
        }
        else
        {
            repeticionUltimo = 0;
        }

        if ((nodosSinRepetir = totalNotas - repeticionUltimo) < tope)
        {
            notaAuxiliar = (*lista)->info;
            lista = &(*lista)->sig;
        }
    }

    while (*lista)
    {
        cantEliminados--;
        pNodoAEliminar = *lista;
        *lista = pNodoAEliminar->sig;
        free(pNodoAEliminar->info);
        free(pNodoAEliminar);
    }

    lista = pLugarDondeInserto;

    if (cantEliminados != 0)
    {
        listaSimple_insertar(lista, nota, cantBytes);
        return cantEliminados;
    }

    return listaSimple_insertar(lista, nota, cantBytes);
}
