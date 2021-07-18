#ifndef MATRICES_H_INCLUDED
#define MATRICES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "vectores.h"
#define N 5

/// Llena matriz con X filas e Y columnas de manera generica.
void mat_fill(int**, unsigned X, unsigned Y);

/// Imprime matriz con X filas e Y columnas.
void mat_print(void**, unsigned X, unsigned Y, unsigned cantBytes,
               void(*print)(const void* dato));

/// Imprime diagonal principal de una matriz con X filas e Y columnas.
void mat_diagonal(int[][N], unsigned X, unsigned Y);

/// Imprime triangulo superior de una matriz de X filas con Y columnas.
void mat_trianguloSuperior(int[][N], unsigned X, unsigned Y);

/// Imprime triangulo inferior de una matriz con X filas e Y columnas.
void mat_trianguloInferior(int[][N], unsigned X, unsigned);

/// Imprime triangulo superior (con diagonal incluida) de una matriz con X filas
/// e Y columnas.
void mat_trianguloSuperior_conDiag(int[][N], unsigned X, unsigned);

/// Imprime triangulo inferior (con diagonal incluida) de una matriz con X filas
/// e Y columnas.
void mat_trianguloInferior_conDiag(int[][N], unsigned X, unsigned);

/// Imprime diagonal secundaria de una matriz con X filas e Y columnas.
void mat_diagonalSecundaria(int[][N], unsigned X, unsigned);

/// Imprime triangulo superior secundario de una matriz de X filas con Y
/// columnas.
void mat_trianguloSuperiorSec(int[][N], unsigned X, unsigned);

/// Imprime triangulo inferior secundario de una matriz de X filas con Y
/// columnas.
void mat_trianguloInferiorSec(int[][N], unsigned X, unsigned);

/// Imprime triangulo superior secundario (con diagonal incluida) de una matriz
/// de X filas con Y columnas.
void mat_trianguloSuperiorSec_conDiag(int[][N], unsigned X, unsigned);

/// Imprime triangulo inferior secundario (con diagonal incluida) de una matriz
/// de X filas con Y columnas.
void mat_trianguloInferiorSec_conDiag(int[][N], unsigned X, unsigned);

/// Imprime cruce superior de una matriz de X filas con Y columnas.
void mat_CruceSuperior(int[][N], unsigned X, unsigned Y);

/// Imprime cruce inferior de una matriz de X filas con Y columnas.
void mat_CruceInferior(int[][N], unsigned X, unsigned Y);

/// Imprime cruce izquierdo de una matriz de X filas con Y columnas.
void mat_CruceIzquierdo(int[][N], unsigned X, unsigned Y);

/// Imprime cruce derecho de una matriz de X filas con Y columnas.
void mat_CruceDerecho(int[][N], unsigned X, unsigned Y);

/// Rota 180 grados una matriz de X filas con Y columnas.
void mat_rotate180(int[][N], unsigned X, unsigned Y);

/// Se realiza el producto de dos matrices en caso que se cumpla la condicion de
/// que la matriz A tenga tantas columnas como filas la matriz B.
int mat_producto(int matA[][N], unsigned X, unsigned Y, int matB[][N],
                 unsigned W, unsigned Z, int matResultado[][N]);

/// Se traspone una matriz de X filas con Y columnas siempre y cuando X = Y.
int mat_transponer(int[][N], unsigned X, unsigned Y);

/// Indica si una matriz es o no simetrica.
int mat_esSimetrica(int[][N], unsigned, int);

/// Recorre matriz en forma de espiral
int mat_espiral(int[][N], unsigned, unsigned);

/// Segun un punto dentro de la matriz, calculo maxima matriz que tenga a dicho
/// punto como centro.
int mat_maxMatriz(int matriz[][N], int fil, int col, int newFil, int newCol);


//void* mat_create(int filas, int colum);


//************************SUBINDICES DE MATRICES********************************
//
//               k  j
//              [0][0]|[0][1]|[0][2]
//  i  k        [1][0]|[1][1]|[1][2]
// [0][0] [0][1]______|______|______|
// [1][0] [1][1]______|______|______|
// [2][0] [2][1]______|______|______|
//
// matriz de orden = 7
// [0][0] [0][1] [0][2] [0][3] [0][4] [0][5] [0][6]
// [1][0] [1][1] [1][2] [1][3] [1][4] [1][5] [1][6]
// [2][0] [2][1] [2][2] [2][3] [2][4] [2][5] [2][6]
// [3][0] [3][1] [3][2] [3][3] [3][4] [3][5] [3][6]
// [4][0] [4][1] [4][2] [4][3] [4][4] [4][5] [4][6]
// [5][0] [5][1] [5][2] [5][3] [5][4] [5][5] [5][6]
// [6][0] [6][1] [6][2] [6][3] [6][4] [6][5] [6][6]
//
//************************SUBINDICES DE MATRICES********************************

#endif // MATRICES_H_INCLUDED
