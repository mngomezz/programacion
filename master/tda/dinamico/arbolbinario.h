#ifndef ARBOLBINARIO_H_INCLUDED
#define ARBOLBINARIO_H_INCLUDED

#define ARBOL_VACIO 0

typedef struct s_nodoA
{
    void* info;
    unsigned tamInfo;
    struct s_nodoA* izq;
    struct s_nodoA* der;
} t_nodoA;

typedef t_nodoA* tda_arbol;

void arbol_crear(tda_arbol* a);

int arbol_ingresar(tda_arbol* a, void* info, unsigned cantBytes,
                   int (*cmp)(const void* val1, const void* val2) );

void arbol_inorden(tda_arbol* a, void (*acc)(unsigned, const void*) );
void arbol_preorden(tda_arbol* a, void (*acc)(unsigned, const void*) );
void arbol_postorden(tda_arbol* a, void (*acc)(unsigned, const void*) );

void arbol_mostrar(tda_arbol* a, unsigned contador,
                   void (*print)(unsigned format, const void* dato) );

unsigned arbol_cantNodos(tda_arbol* a);
unsigned arbol_altura(tda_arbol* a);

int arbol_esBalanceado(tda_arbol* a);
int arbol_esAVL(tda_arbol* a);
int arbol_esCompleto(tda_arbol* a);
int arbol_chequeoCompleto(tda_arbol* a, unsigned altura);

int arbol_vaciar(tda_arbol* a);
int arbol_buscar(tda_arbol* a, void* info, unsigned cantBytes,
                 int (*cmp)(const void* val1, const void* val2));

int arbol_eliminarRaiz(tda_arbol* a);
t_nodoA** arbol_buscoMayor(tda_arbol* a);
t_nodoA** arbol_buscoMenor(tda_arbol* a);
t_nodoA** arbol_buscarNodo(const tda_arbol* a, void* info,
                           int (*cmp)(const void* val1, const void* val2));
int eliminarNodoBin(tda_arbol* a, void* info, unsigned tamInfo,
                    int (*cmp)(const void* val1, const void* val2));
#endif // ARBOLBINARIO_H_INCLUDED
