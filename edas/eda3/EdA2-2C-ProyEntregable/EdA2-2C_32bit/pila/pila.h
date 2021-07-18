/* --------------------------------o---x---o--------------------------------
 *          pila.h     TDA PILA con asignación dinámica de memoria
 * --------------------------------o---x---o-------------------------------- */

#ifndef PILA_H_
#define PILA_H_

#include <stdlib.h>
#include <string.h>


typedef struct sNodo
{
    void           *info;
    unsigned        tamInfo;
    struct sNodo   *sig;
} tNodo;
typedef tNodo *tPila;

void crearPila(tPila *p);

int  pilaLlena(const tPila *p, unsigned cantBytes);

int  ponerEnPila(tPila *p, const void *d, unsigned cantBytes);

int  verTope(const tPila *p, void *d, unsigned cantBytes);

int  pilaVacia(const tPila *p);

int  sacarDePila(tPila *p, void *d, unsigned cantBytes);

void vaciarPila(tPila *p);

#endif

