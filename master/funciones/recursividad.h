#ifndef RECURSIVIDAD_H_INCLUDED
#define RECURSIVIDAD_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

unsigned rec_factorial(unsigned nro);
size_t rec_strlen(const char* cadena);
void rec_mostrarInvertido(const char* cadena);
char* rec_toUpper(char* cadena);
int rec_esPalindromo(const char* pIni, const char* pFin);
int esPalindromo(const char* cadena);
int busquedaBinariaINT(int clave, int* vec, unsigned cantElem);
int busquedaBinariaINT(int clave, int* vec, unsigned cantElem);
void* Rbsearch(const void *clave, const void *base, size_t nmemb, size_t tamanyo,
               int (*comparar)(const void *, const void *) );
#endif // RECURSIVIDAD_H_INCLUDED
