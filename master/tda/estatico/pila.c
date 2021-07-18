#include "pila.h"

void pila_crear(tda_pila *p)
{
    p->tope = TAM_PILA;
}

int pila_estaLlena(const tda_pila *p, unsigned cantBytes)
{
    return p->tope < cantBytes + sizeof(unsigned);
}

int pila_apilar(tda_pila *p, const void *dato, unsigned cantBytes)
{
    if (p->tope < cantBytes + sizeof(unsigned))
    {
        return SIN_MEMORIA;
    }

    p->tope -= cantBytes;
    memcpy(p->pila + p->tope, dato, cantBytes);

    p->tope -= sizeof(unsigned);
    memcpy(p->pila + p->tope, &cantBytes, sizeof(unsigned));

    return 1;
}

int pila_verTope(const tda_pila *p, void *dato, unsigned cantBytes)
{
    unsigned info_size;

    if (p->tope == TAM_PILA)
    {
        return PILA_VACIA;
    }

    memcpy(&info_size, p->pila + p->tope, sizeof(unsigned));

    memcpy(dato, p->pila + p->tope + sizeof(unsigned),
           (info_size < cantBytes) ? info_size : cantBytes);

    return 1;
}

int pila_estaVacia(const tda_pila *p)
{
    return p->tope == TAM_PILA;
}

int pila_desapilar(tda_pila *p, void *dato, unsigned cantBytes)
{
    unsigned info_size;

    if (p->tope == TAM_PILA)
    {
        return PILA_VACIA;
    }

    memcpy(&info_size, p->pila + p->tope, sizeof(unsigned));
    p->tope += sizeof(unsigned);

    memcpy(dato, p->pila + p->tope, (info_size < cantBytes) ? info_size : cantBytes);
    p->tope += info_size;

    return 1;
}

void pila_vaciar(tda_pila *p)
{
    p->tope = TAM_PILA;
}
