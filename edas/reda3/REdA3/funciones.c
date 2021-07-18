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

/**/ /**/ /* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, H�GALO HASTA AC� */                 /**/
/**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/
#include "funciones.h"
#include <string.h>
#include <stdlib.h>

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

/** para el PUNTO 1 c.- **/
int ponerEnListaDoblNCalif_MIO(tListaDobl *lista, const void *nota,
                               size_t cantBytes, int tope)
{
    void *notaAuxiliar = (void *)nota;
    unsigned totalNotas = 0, cantNodosDistintos = 0;
    int cmp, cantElim = 0, elimineLugarAInsertar = 0, ingresoNotaDistinta = 0;
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
            if (cmp == 0)
            {
                ingresoNotaDistinta = 0;
            }
            else
            {
                ingresoNotaDistinta = 1;
            }

            if (pNodoAnterior)
            {
                if (cmp_calif(pNodoAnterior->info, pNodoActual->info) != 0)
                {
                    cantNodosDistintos++;
                }
            }

            if (cantNodosDistintos + ingresoNotaDistinta >= tope)
            {
                return NO_SE_INSERTA;
            }

            totalNotas++;
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

    while (pNodoActual && cantNodosDistintos + ingresoNotaDistinta < tope)
    {
        totalNotas++;
        if (cmp_calif(notaAuxiliar, pNodoActual->info) != 0)
        {
            cantNodosDistintos++;
        }

        if (cantNodosDistintos + ingresoNotaDistinta < tope)
        {
            notaAuxiliar = pNodoActual->info;
            pNodoActual = pNodoActual->der;
        }
    }

    while (pNodoActual)
    {
        pNodoAux = pNodoActual->der;

        if (cantElim == 0)
        {
            pUltimoNodo = pNodoActual->izq;
        }

        if (pNodoActual == pLugarDondeInserto)
        {
            elimineLugarAInsertar = 1;
        }

        cantElim--;
        free(pNodoActual->info);
        free(pNodoActual);
        pNodoActual = pNodoAux;
    }

    if (cantElim != 0)
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
        return cantElim;
    }

    pNodoActual = pLugarDondeInserto;
    pNodoAnterior = pLugarDondeInserto ? pLugarDondeInserto->izq : NULL;
    return listaDoble_insertar(lista, pNodoAnterior, pLugarDondeInserto, nota,
                               cantBytes);
}

/**                  FIN de PUNTO 1 **/
/**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/
