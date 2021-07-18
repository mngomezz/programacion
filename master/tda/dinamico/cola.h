#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED
/**  ANOTACION
LA COLA SIMPLE ES UN TDA MUY SIMILAR A LA PILA. ASI COMO EN ESE TDA SOLO SE
PERMITE VER EL TOPE (ES DECIR EL ULTIMO INGRESADO), EN ESTE TDA SOLO SE PERMITE
VER EL PRIMERO DE LA COLA, Y AL QUITAR DE LA COLA UN NODO, EL UNICO QUE SE PODRA
SACAR SERA EL PRIMERO. SIN EMBARGO, EL GRAN PUNTO QUE LOS DIFERENCIA ES QUE AL
AGREGAR UN NODO, ESTE SE AGREGA AL FINAL, NO AL PRINCIPIO.
EJEMPLO: COLA DE UN SUPERMERCADO.
**/
#include <stdlib.h>
#include <string.h>
#include "../../funciones/utiles.h"

typedef struct s_nodo
{
    void*    info;
    unsigned tamInfo;
    struct   s_nodo* siguiente;
} t_nodo;

typedef struct
{
    t_nodo* primero;
    t_nodo* ultimo;
} tda_cola;

void cola_crear(tda_cola* p);
int  cola_llena(const tda_cola* p, unsigned cantBytes);
int  cola_agregar(tda_cola* p, const void* dato, unsigned cantBytes);
int  cola_verPrimero(const tda_cola* p, void* dato, unsigned cantBytes);
int  cola_vacia(const tda_cola* p);
int  cola_sacar(tda_cola* p, void* dato, unsigned cantBytes);
void cola_vaciar(tda_cola* p);


#endif // COLA_H_INCLUDED
