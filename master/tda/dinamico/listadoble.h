#ifndef LISTADOBLE_H_INCLUDED
#define LISTADOBLE_H_INCLUDED

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "../../funciones/utiles.h"

#define SIN_MEMORIA 0
#define LISTA_VACIA 0

typedef struct s_nodo
{
    void* info;
    unsigned tamInfo;
    struct s_nodo* anterior;
    struct s_nodo* siguiente;
} t_nodo;

typedef t_nodo* tda_lista;

void lista_crear(tda_lista* l);
int lista_agregarOrdenado(tda_lista* l, const void* info, unsigned cantBytes,
                          int (*cmp)(const void* val1, const void* val2) );
int lista_llena(const tda_lista* l, unsigned cantBytes);
int lista_vacia(const tda_lista* l);
int lista_mostrar(tda_lista* l, void (*accion)(const void* dato));
int lista_buscar(const tda_lista* l, void* info,
                 int (*cmp)(const void* val1, const void* val2));
int lista_eliminar(tda_lista* l, void* info, unsigned cantBytes,
                   int (*cmp)(const void* val1, const void* val2));
void lista_filtrar( tda_lista* l, int filtro(const void* dato) );
void lista_ordenar(tda_lista* l, int (*cmp)(const void* val1, const void* val2));
t_nodo* _buscoMenor(const t_nodo* nodoActual,
                    int (*cmp)(const void* val1, const void* val2));
int lista_reducir(const tda_lista* l, void* dato,
                  void operacion(const void*, void*));
int lista_mostrarIzqDer(const tda_lista* l, void(*mostrar)(const void*));
int lista_mostrarDerIzq(const tda_lista* l, void(*mostrar)(const void*));
#endif // LISTADOBLE_H_INCLUDED
/**


#include <stdlib.h>
#include <string.h>

typedef struct snodo
{
    unsigned tam;
    void* info;
    struct snodo* ant;
    struct snodo* sig;

} t_nodo;

typedef t_nodo* t_lista;

void crearLista(t_lista* l);

int ponerEnListaOrdenado(t_lista* l, const void* info, unsigned tam, int(*cmp)(const void* pVal1, const void* pVal2));

//listaLlena();
//
//listaVacia();
//
//insertar sin duplicar claves (acumulando cantidades)
//
//eliminar

void mostrarLista_IzqADer(const t_lista* l, void(*mostrar)(const void*));

void mostrarLista_DerAIzq(const t_lista* l, void(*mostrar)(const void*));

**/
