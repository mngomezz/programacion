#ifndef VECTORES_H_INCLUDED
#define VECTORES_H_INCLUDED

#include <stdlib.h>

// Ejercicios
void vec_ingresar(int*, unsigned*, int, unsigned, unsigned);
void vec_ingresarOrdenado(int, int*, unsigned*);
void vec_eliminar(int*, unsigned*, unsigned);
void vec_eliminarPrimerAparicion(int, int*, unsigned*);
void vec_eliminarApariciones(int, int*, unsigned*);
void vec_print(void*, size_t, size_t, void (*print)(const void* dato));
int  vec_cantElemParImpar(int*, int, char);
// Array sort
void vec_bubbleSort(int*, unsigned);
void vec_selectionSort(int*, int);
void vec_insertionSort(int*, int);
void vec_quickSort(int*, int, int);
void vec_mergeSort(int*, int, int, int);
void vec_merge(int*, int, int, int);
// Array search
int vec_busquedaLineal(int*, int, int);
int vec_busquedaBinaria(int*, int, int, int);


#endif // VECTORES_H_INCLUDED
