#ifndef PILAESTATICA_H_INCLUDED
#define PILAESTATICA_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define TAM_PILA 500

#define SIN_MEMORIA 0
#define PILA_VACIA 0

typedef struct
{
    char pila[TAM_PILA];
    unsigned tope;
} tda_pila;

void pila_crear(tda_pila *p);
int pila_estaLlena(const tda_pila *p, unsigned cantBytes);
int pila_apilar(tda_pila *p, const void *dato, unsigned cantBytes);
int pila_verTope(const tda_pila *p, void *dato, unsigned cantBytes);
int pila_estaVacia(const tda_pila *p);
int pila_desapilar(tda_pila *p, void *dato, unsigned cantBytes);
void pila_vaciar(tda_pila *p);

#endif // PILAESTATICA_H_INCLUDED
