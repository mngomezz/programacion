#include "recursividad.h"

unsigned rec_factorial(unsigned nro)
{
    if(nro == 0)
    { return 1; }

    return nro * rec_factorial(nro-1);
}

size_t rec_strlen(const char* cadena)
{
    if(!(*cadena))
    { return 0; }

    return rec_strlen(cadena+1) + 1;
}

void rec_mostrarInvertido(const char* cadena)
{
    if(!(*cadena))
    { return; }

    rec_mostrarInvertido(cadena+1);

    printf("%c", *cadena);

}

char* rec_toUpper(char* cadena)
{
    if(!(*cadena))
    { return cadena; }

    if(*cadena > 96 && *cadena < 123)
    {*cadena -= 32;}

    return rec_toUpper(cadena+1)-1;
}


int rec_esPalindromo(const char* pIni, const char* pFin)
{
    if(pFin <= pIni) //YA RECORRIO LA CADENA
    { return 1; }

    if(*pIni == ' ')
    { return rec_esPalindromo(pIni+1, pFin); }

    if(*pFin == ' ')
    { return rec_esPalindromo(pIni, pFin-1); }

    if(*pFin == *pIni)
    { return rec_esPalindromo(pIni+1, pFin-1); }

    return 0;

}

int esPalindromo(const char* cadena)
{
    char* pIni =  (char*)cadena;
    char* pFin = pIni + rec_strlen(cadena) - 1;

    return rec_esPalindromo(pIni, pFin);
}


int busquedaBinariaINT(int clave, int* vec, unsigned cantElem)
{
    int* pVec = vec + (cantElem/2);

    if(!cantElem)
    { return 0; }

    if(clave == *pVec)
    { return 1; }

    if(clave > *pVec)
    { return busquedaBinariaINT(clave, pVec+1, (cantElem-1)/2 ); }
    else
    { return busquedaBinariaINT(clave, vec, (cantElem)/2 ); }
}

void* Rbsearch(const void* clave, const void* base, size_t nmemb, size_t tamanyo,
               int (*comparar)(const void*, const void*) )
{
    int comparacion;

    if(!nmemb)
    { return NULL; }

    if( (comparacion = comparar(clave, base+(nmemb*tamanyo)/2)) == 0)
    { return (void*)base+(nmemb*tamanyo)/2; }

    if(comparacion > 0)
    {
        return Rbsearch(clave, (base+(nmemb*tamanyo)/2)+tamanyo,
                        (nmemb-1)/2, tamanyo, comparar);
    }

    return Rbsearch(clave, base, nmemb/2, tamanyo, comparar);
}







