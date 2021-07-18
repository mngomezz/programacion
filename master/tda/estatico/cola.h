#ifndef COLAESTATICA_H_INCLUDED
#define COLAESTATICA_H_INCLUDED

#include <string.h>
#include <stdlib.h>
#include "../../funciones/utiles.h"
#define TAM_COLA 300
#define SIN_MEMORIA 0
#define COLA_VACIA 0

typedef struct
{
    char cola[TAM_COLA];
    unsigned primero;
    unsigned ultimo;
    unsigned disponible;
} tda_cola;

void cola_crear(tda_cola *c);
int cola_llena(const tda_cola *c, unsigned cantBytes);
int cola_agregar(tda_cola *c, const void *dato, unsigned cantBytes);
int cola_verPrimero(const tda_cola *c, void *dato, unsigned cantBytes);
int cola_vacia(const tda_cola *c);
int cola_sacar(tda_cola *c, void *dato, unsigned cantBytes);
void cola_vaciar(tda_cola *c);

#endif // COLAESTATICA_H_INCLUDED
