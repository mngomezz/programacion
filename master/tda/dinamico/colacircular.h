#ifndef COLACIRCULAR_H_INCLUDED
#define COLACIRCULAR_H_INCLUDED
/**  ANOTACION
LA COLA CIRCULAR TIENE LA PARTICULARIDAD DE QUE APUNTA SIEMPRE AL ULTIMO NODO DE
LA COLA Y PARA QUITAR EL PRIMER NODO (YA QUE ASI SE COMPORTA UNA COLA) HAY QUE
ELIMINAR EL SIGUIENTE DEL ULTIMO NODO.
**/

#include <stdlib.h>
#include <string.h>
#include "../../funciones/utiles.h"

#define SIN_MEMORIA 0
#define COLA_VACIA 0

typedef struct s_nodo
{
    void*    info;
    unsigned tamInfo;
    struct   s_nodo* sig;
} t_nodo;

typedef t_nodo* tda_cola;

void cola_crear(tda_cola* p);
int  cola_llena(const tda_cola* p, unsigned cantBytes);
int  cola_agregar(tda_cola* p, const void* dato, unsigned cantBytes);
int  cola_verPrimero(const tda_cola* p, void* dato, unsigned cantBytes);
int  cola_vacia(const tda_cola* p);
int  cola_sacar(tda_cola* p, void* dato, unsigned cantBytes);
void cola_vaciar(tda_cola* p);
int  cola_mostrar(tda_cola* c, void (mostrar)(const void* dato));

#endif // COLACIRCULAR_H_INCLUDED
