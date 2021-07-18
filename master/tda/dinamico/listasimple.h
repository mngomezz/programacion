#ifndef LISTASIMPLE_INCLUDED
#define LISTASIMPLE_INCLUDED

#include "../../funciones/utiles.h"

/**  ANOTACION
LA LISTA SIMPLE PERMITE AGREGAR/QUITAR NODOS DE LA POSICION QUE DESEEMOS, YA QUE
ESTA TIENE MUCHAS PRIMITIVAS. SIN EMBARGO, ESTA SOLO SE PUEDE RECORRER DESDE EL
PRINCIPIO HACIA EL FINAL. ESTO SE DEBE A QUE LA LISTA SIMPLE SOLO CONSISTE DE UN
PUNTERO A UN NODO (EL PRIMERO). LUEGO, TIENE TODAS LAS FUNCIONALIDADES DE UNA
LISTA, COMO LO SON LA DE FILTRAR, ORDENAR, REDUCIR(PROMEDIO, SUMA), Y MAS.
EJEMPLO: ...
**/

typedef struct s_nodo
{
    void* info;
    unsigned tamInfo;
    struct s_nodo* siguiente;
} t_nodo;

typedef t_nodo* tda_lista;

void lista_crear(tda_lista* l);
int lista_agregar(tda_lista* l, const void* info, unsigned cantBytes);
int lista_mostrar(tda_lista* l, void (*accion)(const void* dato));
int lista_buscar(const tda_lista* l, void* info,
                 int (*cmp)(const void* val1, const void* val2));
int lista_eliminar(tda_lista* l, void* info,
                   int (*cmp)(const void* val1, const void* val2));
void lista_filtrar( tda_lista* l, int filtro(const void* dato) );
void lista_ordenar(tda_lista* l, int (*cmp)(const void* val1, const void* val2));
t_nodo** _buscoMenor(const tda_lista* l,
                     int (*cmp)(const void* val1, const void* val2));
int lista_reducir(const tda_lista* l, void* dato,
                  void operacion(const void* dato, void* acumulador));
int lista_agregarEnPosicion(tda_lista* l, int pos, const void* info, unsigned tam);
int lista_mostrarR(tda_lista* l, void (*mostrar)(const void* dato));
t_nodo** lista_getNodo(tda_lista* l, void* info,
                       int cmp(const void* val1, const void* val2));
size_t lista_contarNodos(tda_lista* l);

#endif // LISTASIMPLE_INCLUDED
