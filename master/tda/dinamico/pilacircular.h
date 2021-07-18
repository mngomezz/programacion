#ifndef CIRCULAR_H_INCLUDED
#define CIRCULAR_H_INCLUDED
/**  ANOTACION
LA PILA CIRCULAR TIENE LA PARTICULARIDAD DE QUE APUNTA SIEMPRE AL PRIMER NODO DE
LA PILA Y PARA QUITAR EL ULTIMO NODO (YA QUE ASI SE COMPORTA UNA PILA) HAY QUE
ELIMINAR EL SIGUIENTE DEL PRIMER NODO.
**/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../../funciones/utiles.h"

#define SIN_MEMORIA 0
#define PILA_VACIA 0


typedef struct s_nodo
{
    void* info;
    unsigned tamInfo;
    struct s_nodo* sig;
} t_nodo;

typedef t_nodo* tda_pila;

void pila_crear(tda_pila* p);
int  pila_estaLlena(const tda_pila* p, unsigned cantBytes);
int  pila_apilar(tda_pila* p, const void* dato, unsigned cantBytes);
int  pila_verTope(const tda_pila* p, void* dato, unsigned cantBytes);
int  pila_estaVacia(const tda_pila* p);
int  pila_desapilar(tda_pila* p, void* dato, unsigned cantBytes);
void pila_vaciar(tda_pila* p);
int  pila_recorrer(tda_pila* p, void (mostrar)(const void* dato));

#endif // CIRCULAR_H_INCLUDED
