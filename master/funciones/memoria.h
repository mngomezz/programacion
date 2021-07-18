#ifndef MEMORIA_H_INCLUDED
#define MEMORIA_H_INCLUDED
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

void* mem_copy(void* destino, const void* origen, size_t tam);

void* mem_move(void* destino, const void* origen, size_t tam);

char* mem_strcpy(const char* cadena);

char* mem_strcat(char* cadena1, const char* cadena2);

void* mem_createMat(int filas, int colum);

#endif // MEMORIA_H_INCLUDED
