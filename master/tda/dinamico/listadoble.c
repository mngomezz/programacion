#include "listadoble.h"


void lista_crear(tda_lista* l)
{
    *l = NULL;
}

/** 0 si esta llena, 1 si hay espacio **/
int lista_vacia(const tda_lista* l)
{
    return *l == NULL;
}

/** 0 si esta llena, 1 si hay espacio **/
int lista_llena(const tda_lista* l, unsigned cantBytes)
{
    t_nodo* aux = (t_nodo*)malloc(sizeof(t_nodo));
    void* info = malloc(cantBytes);

    free(aux);
    free(info);
    return aux == NULL || info == NULL;
}

int lista_agregarOrdenado(tda_lista* l, const void* info, unsigned cantBytes,
                          int (*cmp)(const void* v1, const void* v2) )
{
    t_nodo* newNodo,
            *nodoActual,
            *auxAnt,
            *auxSig;

    // Si la lista no esta vacia, asigno nodo actual al nodo al cual apunta.
    // Esto lo hago para moverme por la lista sin perder el puntero a lista.
    if(!(nodoActual = *l))
    {
        // Si esta vacia, asigno anterior y siguiente a NULL
        auxAnt = NULL;
        auxSig = NULL;
    }
    else // En caso que haya algo en la lista
    {
        // Mientras haya un SIGUIENTE y el dato a ingresar sea MAYOR a la info
        // del nodo actual, me muevo hacia la DERECHA
        while(nodoActual->siguiente && cmp(info, nodoActual->info) > 0)
        { nodoActual=nodoActual->siguiente; }

        // Mientras haya un ANTERIOR y el dato a ingresar sea MENOR a la info
        // del nodo actual, me muevo hacia la IZQUIERDA
        while(nodoActual->anterior && cmp(info, nodoActual->info) < 0)
        { nodoActual=nodoActual->anterior; }

        /**
        AQUI YA ME ENCUENTRO SOBRE EL NODO EN EL CUAL DEBO AGREGAR LA INFO. EL
        SIGUIENTE PASO ES AVERIGUAR SI ES A LA IZQUIERDA O A LA DERECHA DE ESTE.
        **/

        // Si la info a ingresar es mayor a la del nodo actual, va a la derecha
        if(cmp(info, nodoActual->info)>0)
        {
            auxAnt=nodoActual;
            auxSig=nodoActual->siguiente;
        }
        else // Caso contrario, si es menor, va a la izquierda.
        {
            auxAnt=nodoActual->anterior;
            auxSig=nodoActual;
        }

    }

    /** AQUI YA SE CUAL ES EL SIGUIENTE Y EL ANTERIOR AL NODO NUEVO. **/

    /* CREO Y ASIGNO INFO A NODO */
    if( !(newNodo = (t_nodo*)malloc(sizeof(t_nodo))) )
    { return SIN_MEMORIA; }

    if( !(newNodo->info = malloc(cantBytes)) )
    {
        free(newNodo);
        return SIN_MEMORIA;
    }

    memcpy(newNodo->info, info, cantBytes);
    newNodo->tamInfo = cantBytes;
    /* CREO Y ASIGNO INFO A NODO */

    // Conecto nodo a la lista indicando quienes son el anterior y el siguiente.
    newNodo->anterior = auxAnt;
    newNodo->siguiente = auxSig;


    // En caso de existir, indico a los nodos anterior y siguiente que pasan
    // por el nuevo nodo creado. Esto es, indicar que el nuevo nodo es ahora el
    // anterior del siguiente y el siguiente del anterior.
    if(auxAnt)
    { auxAnt->siguiente = newNodo; }

    if(auxSig)
    { auxSig->anterior = newNodo; }

    // Por ultimo, ahora la lista apunta hacia el ultimo nodo agregado.
    (*l) = newNodo;

    return 1;
}

int lista_mostrarIzqDer(const tda_lista* l, void(*mostrar)(const void* dato))
{
    t_nodo* nodoActual;

    if(!(nodoActual = *l))
    { return LISTA_VACIA; }

    // Llevo puntero hacia el primer elemento de la lista
    while(nodoActual->anterior)
    { nodoActual=nodoActual->anterior; }

    // Recorro hacia la derecha hasta el final, mostrando los elementos.
    while(nodoActual)
    {
        mostrar(nodoActual->info);
        nodoActual=nodoActual->siguiente;
    }

    return 1;
}

int lista_mostrarDerIzq(const tda_lista* l, void(*mostrar)(const void*))
{
    t_nodo* nodoActual;

    if(!(nodoActual=*l))
    { return LISTA_VACIA; }

    // Llevo puntero hacia el ultimo elemento de la lista
    while(nodoActual->siguiente)
    { nodoActual=nodoActual->siguiente; }

    // Recorro hacia la izquierda hasta el principio, mostrando los elementos.
    while(nodoActual)
    {
        mostrar(nodoActual->info);
        nodoActual=nodoActual->anterior;
    }

    return 1;
}

int  lista_buscarOrdenada(const tda_lista* l, void* info,
                          int (*cmp)(const void* v1, const void* v2))
{
    t_nodo* nodoActual;

    // Si la lista no esta vacia, asigno nodo actual al nodo al cual apunta.
    // Esto lo hago para moverme por la lista sin perder el puntero a lista.
    if(!(nodoActual = *l))
    { return LISTA_VACIA; }

    // Mientras haya un siguiente y el dato buscado sea MAYOR a la info del
    // nodo actual, me muevo hacia la DERECHA.
    while( nodoActual->siguiente && cmp(info, nodoActual->info) > 0 )
    { nodoActual = nodoActual->siguiente; }

    // Mientras haya un anterior y el dato a ingresar sea MENOR a la info
    // del nodo actual, me muevo hacia la IZQUIERDA.
    while( nodoActual->anterior && cmp(info, nodoActual->info) < 0)
    { nodoActual = nodoActual->anterior; }

    if(cmp(info, nodoActual->info) != 0)
    { return 0; }

    memcpy(info, nodoActual->info, nodoActual->tamInfo);

    return 1;
}

int lista_eliminar(tda_lista* l, void* info, unsigned cantBytes,
                   int (*cmp)(const void* v1, const void* v2))
{
    t_nodo* nodoActual,
            *auxAnt,
            *auxSig;

    // Si la lista no esta vacia, asigno nodo actual al nodo al cual apunta.
    // Esto lo hago para moverme por la lista sin perder el puntero a lista.
    if(!(nodoActual = *l))
    { return LISTA_VACIA; }

    // Mientras haya un siguiente y el dato buscado sea MAYOR a la info del
    // nodo actual, me muevo hacia la DERECHA.
    while( nodoActual->siguiente && cmp(info, nodoActual->info) > 0 )
    { nodoActual = nodoActual->siguiente; }

    // Mientras haya un anterior y el dato a ingresar sea MENOR a la info
    // del nodo actual, me muevo hacia la IZQUIERDA.
    while( nodoActual->anterior && cmp(info, nodoActual->info) < 0)
    { nodoActual = nodoActual->anterior; }

    if(cmp(info, nodoActual->info) != 0)
    { return 0; }

    auxAnt = nodoActual->anterior;
    auxSig = nodoActual->siguiente;

    if(auxAnt)
    {
        auxAnt->siguiente = auxSig;
        *l = auxAnt;
    }

    if(auxSig)
    {
        auxSig->anterior = auxAnt;
        *l = auxSig;
    }

    memcpy(info, nodoActual->info, MIN(cantBytes, nodoActual->tamInfo));

    free(nodoActual->info);
    free(nodoActual);

    return 1;
}

void lista_ordenar(tda_lista* l, int (*cmp)(const void* v1, const void* v2))
{
    t_nodo* nodoActual,
            *auxSig,
            *auxAnt,
            *menor;

    if(!(nodoActual = *l))
    { return; }

    // Llevo puntero hacia el primer elemento de la lista
    while(nodoActual->anterior)
    { nodoActual = nodoActual->anterior; }

    while(nodoActual)
    {
        menor = _buscoMenor(nodoActual, cmp);
        if( menor != nodoActual )
        {
            auxAnt = menor->anterior;
            auxSig = menor->siguiente;
            ///QUITO NODO DE DONDE ESTA.
            if(auxAnt)
            { auxAnt->siguiente = auxSig; }

            if(auxSig)
            { auxSig->anterior = auxAnt; }

            /// CONECTO NODO AL PRINCIPIO
            if(nodoActual->anterior)
            {
                auxAnt = nodoActual->anterior;
                auxAnt->siguiente = menor;
            }
            else
            { auxAnt = NULL; }

            if(nodoActual->siguiente)
            {
                auxSig = nodoActual;

            }
            else
            { auxSig = NULL; }

            /// CONECTO EL PRINCIPIO DE LA LISTA AL NODO
        }

        nodoActual = nodoActual->siguiente;
    }

}

t_nodo* _buscoMenor(const t_nodo* nodoActual,
                    int (*cmp)(const void* v1, const void* v2))
/** ANOTACIONES
"l" es una direccion de un puntero a un nodo. Por lo tanto, pMenor debe ser un
 puntero a puntero. Ya que deberia apuntar a l. El cual tiene una direccion de
 un puntero a nodo.
**/
{
    t_nodo* pMenor = (t_nodo*)nodoActual;

    while(nodoActual)
    {
        if( cmp(nodoActual->info, pMenor->info) < 0 )
        { pMenor = (t_nodo*)nodoActual; }

        nodoActual = nodoActual->siguiente;
    }

    return pMenor;
}

int  lista_buscar(const tda_lista* l, void* info,
                  int (*cmp)(const void* v1, const void* v2))
{
    int comparacion;
    t_nodo* nodoActual;

    // Si la lista no esta vacia, asigno nodo actual al nodo al cual apunta.
    // Esto lo hago para moverme por la lista sin perder el puntero a lista.
    if(!(nodoActual = *l))
    { return LISTA_VACIA; }

    // Mientras haya un siguiente y el dato buscado sea MAYOR a la info del
    // nodo actual, me muevo hacia la DERECHA.
    while( (comparacion = cmp(info, nodoActual->info)) != 0 && nodoActual->siguiente )
    { nodoActual = nodoActual->siguiente; }

    if(!comparacion) // Si lo encontre
    {
        memcpy(info, nodoActual->info, nodoActual->tamInfo);
        return 1;
    }

    nodoActual = *l; // Vuelvo a situar el nodo actual al nodo donde ingrese

    // Mientras haya un anterior y el dato a ingresar sea MENOR a la info
    // del nodo actual, me muevo hacia la IZQUIERDA.
    while( (comparacion = cmp(info, nodoActual->info)) != 0 && nodoActual->anterior )
    { nodoActual = nodoActual->anterior; }

    if(!comparacion) // Si lo encontre
    {
        memcpy(info, nodoActual->info, nodoActual->tamInfo);
        return 1;
    }

    return 0;
}




/*
int  lista_eliminar(tda_lista* l, void* info, int (*cmp)(const void* v1, const void* v2));
void lista_filtrar( tda_lista* l, int filtro(const void* dato) );
int  lista_reducir(const tda_lista* l, void* dato, void operacion(const void*, void*));
t_nodo** _buscoMenor(const tda_lista* l, int (*cmp)(const void* dato, const void* acumulador));
*/
