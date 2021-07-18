#include "matrices.h"

void mat_fill(int **matriz, unsigned fil, unsigned col)
{
    int nro = 1, i, j;
    for (i = 0; i < fil; i++)
    {
        for (j = 0; j < col; j++)
        {
            *(*(matriz + i) + j) = nro++;
        }
    }
}

void mat_print(void **matriz, unsigned fil, unsigned col, unsigned dato_size,
               void (*print)(const void *dato))
{
    while (fil--)
    {
        vec_print(*matriz, col, dato_size, print);
        matriz += col;

        printf("\n");
    }
}

//Diagonal principal
void mat_diagonal(int matriz[][N], unsigned fil, unsigned col)
{
    unsigned i, max = (fil < col) ? fil : col;

    for (i = 0; i < max && i < col; i++)
    {
        printf("[%d][%d]=%d\t", i, i, matriz[i][i]);
    }
}

void mat_trianguloSuperior(int matriz[][N], unsigned fil, unsigned col)
{
    unsigned i, j;

    for (i = 0; i < fil; i++)
    {
        printf("\n");

        for (j = i + 1; j < col; j++)
        {
            printf("[%d][%d] = %d\t", i, j, matriz[i][j]);
        }
    }
}

void mat_trianguloInferior(int matriz[][N], unsigned fil, unsigned col)
{
    unsigned i, j;

    for (i = 0; i < fil; i++)
    {
        printf("\n");

        for (j = 0; j < i && j < col; j++)
        {
            printf("[%d][%d] = %d\t", i, j, matriz[i][j]);
        }
    }
}

void mat_trianguloSuperior_conDiag(int matriz[][N], unsigned fil, unsigned col)
{
    unsigned i, j;

    for (i = 0; i < fil; i++)
    {
        printf("\n");

        for (j = i; j < col; j++)
        {
            printf("[%d][%d] = %d\t", i, j, matriz[i][j]);
        }
    }
}

void mat_trianguloInferior_conDiag(int matriz[][N], unsigned fil, unsigned col)
{
    unsigned i, j;

    for (i = 0; i < fil; i++)
    {
        printf("\n");

        for (j = 0; j <= i && j < col; j++)
        {
            printf("[%d][%d] = %d\t", i, j, matriz[i][j]);
        }
    }
}

//Diagonal secundaria
void mat_diagonalSecundaria(int matriz[][N], unsigned fil, unsigned col)
{
    unsigned i, j = col;

    for (i = 0; i < fil && j > 0; i++)
    {
        j = col - 1 - i;
        printf("[%d][%d] = %d\t", i, j, matriz[i][j]);
    }
}

void mat_trianguloSuperiorSec(int matriz[][N], unsigned fil, unsigned col)
{
    unsigned i, j;

    for (i = 0; i < fil; i++)
    {
        printf("\n");

        for (j = 0; i + j > col - 1; j++)
        {
            printf("[%d][%d] = %d\t", i, j, matriz[i][j]);
        }
    }
}

void mat_trianguloSuperiorSec_conDiag(int matriz[][N], unsigned fil, unsigned col)
{
    unsigned i, j;

    for (i = 0; i < fil; i++)
    {
        printf("\n");

        for (j = 0; i + j > col; j++)
        {
            printf("[%d][%d] = %d\t", i, j, matriz[i][j]);
        }
    }
}

void mat_trianguloInferiorSec(int matriz[][N], unsigned fil, unsigned col)
{
    unsigned i, j;

    for (i = 0; i < fil; i++)
    {
        printf("\n");

        for (j = (col - i >= 0) ? (col - i) : (0); j < col; j++)
        {
            printf("[%d][%d] = %d\t", i, j, matriz[i][j]);
        }
    }
}

void mat_trianguloInferiorSec_conDiag(int matriz[][N], unsigned fil, unsigned col)
{
    unsigned i, j;

    for (i = 0; i < fil; i++)
    {
        printf("\n");

        for (j = (col - 1 - i >= 0) ? (col - 1 - i) : (0); j < col; j++)
        {
            printf("[%d][%d] = %d\t", i, j, matriz[i][j]);
        }
    }
}

//Cruces de diagonales
void mat_CruceSuperior(int matriz[][N], unsigned fil, unsigned col)
{
    unsigned i, j;

    for (i = 0; i <= fil / 2; i++)
    {
        printf("\n");

        for (j = i + 1; i + j < col - 1; j++)
        {
            printf("[%d][%d] = %d\t", i, j, matriz[i][j]);
        }
    }
}

void mat_CruceDerecho(int matriz[][N], unsigned fil, unsigned col)
{
    unsigned i, j;

    for (i = 1; i < fil; i++)
    {
        printf("\n");

        for (j = (i <= fil / 2) ? (fil - i) : (i + 1); j < col; j++)
        {
            printf("[%d][%d] = %d\t", i, j, matriz[i][j]);
        }
    }
}

void mat_CruceInferior(int matriz[][N], unsigned fil, unsigned col)
{
    unsigned i, j;

    for (i = (fil + 1) / 2; i < fil; i++)
    {
        printf("\n");

        for (j = col - i; j < i; j++)
        {
            printf("[%d][%d] = %d\t", i, j, matriz[i][j]);
        }
    }
}

void mat_CruceIzquierdo(int matriz[][N], unsigned fil, unsigned col)
{
    unsigned i, j;

    for (i = 1; i < fil; i++)
    {
        printf("\n");

        for (j = 0; j < i && i + j < col - 1; j++)
        {
            printf("[%d][%d] = %d\t", i, j, matriz[i][j]);
        }
    }
}

void mat_rotate180(int matriz[][N], unsigned fil, unsigned col)
{
    int i, j, limit;

    // adapto filas y columnas a subindices
    fil--;
    col--;

    for (i = 0; i < fil - i; i++) // fil-i ya que debo ir a la mitad.
    {
        for (j = 0; j <= col; j++)
        {
            limit = matriz[i][j];
            matriz[i][j] = matriz[fil - i][col - j];
            matriz[fil - i][col - j] = limit;
        }
    }
}

int mat_producto(int mat_a[][N], unsigned fil_a, unsigned col_a,
                 int mat_b[][N], unsigned fil_b, unsigned col_b, int mat_c[][N])
{
    if (col_a != fil_b)
    {
        return 0;
    }

    unsigned i, j, k;

    for (i = 0; i < fil_a; i++)
    {
        for (j = 0; j < col_b; j++)
        {
            mat_c[i][j] = 0;

            for (k = 0; k < col_a; k++)
            {
                mat_c[i][j] += mat_a[i][k] * mat_b[k][j];
            }
        }
    }

    return 1;
}

int mat_transponer(int matriz[][N], unsigned fil, unsigned col)
{
    if (col != fil)
    {
        return 0;
    }

    int limit;
    unsigned i, j;

    for (i = 0; i < fil; i++)
    {
        for (j = i + 1; j < col; j++)
        {
            limit = matriz[i][j];
            matriz[i][j] = matriz[j][i];
            matriz[j][i] = limit;
        }
    }

    return 1;
}

int mat_esSimetrica(int matriz[][N], unsigned orden, int diagonalSecundaria)
{
    unsigned i, j;

    if (diagonalSecundaria)
    {
        for (i = 0; i < orden; i++)
        {
            // j va hasta la diagonal secundaria
            for (j = 0; j < orden - i - 1; j++)
            {
                if (matriz[i][j] != matriz[j][i])
                {
                    return 0;
                }
            }
        }
    }
    else
    {
        // i parte de 1 ya que no hay necesidad
        // de chequear la diagonal prinicpal
        for (i = 1; i < orden; i++)
        {
            // j va hasta i (no choca con diagonal principal)
            for (j = 0; j < i; j++)
            {
                if (matriz[i][j] != matriz[j][i])
                {
                    return 0;
                }
            }
        }
    }

    return 1;
}

int mat_espiral(int matriz[][N], unsigned fil, unsigned col)
{
    if (fil != col)
    {
        return 0;
    }

    unsigned i = 0, j = 0, limit = fil - 1, count = 1;

    for (i = 1; i < fil; i++)
    {
        for (j = i - 1; j < limit; j++)
        {
            matriz[fil - (limit + 1)][j] = count;
            count++;
        }

        for (j = i - 1; j < limit; j++)
        {
            matriz[j][limit] = count;
            count++;
        }

        for (j = limit; j >= (i - 1); j--)
        {
            matriz[limit][j] = count;
            count++;
        }

        limit--;
        for (j = limit; j >= i; j--)
        {
            matriz[j][fil - (limit + 2)] = count;
            count++;
        }
    }

    return 1;
}

int mat_maxMatriz(int matriz[][N], int fil, int col, int newFil, int newCol)
{
    if (newCol > col || newFil > fil)
    {
        return 0;
    }

    int i, j;
    int iDist = ((fil - 1) - newFil < newFil) ? fil - 1 - newFil : newFil;
    int jDist = ((col - 1) - newCol < newCol) ? col - 1 - newCol : newCol;

    for (i = newFil - iDist; i <= (newFil + iDist); i++)
    {
        for (j = newCol - jDist; j <= (newCol + jDist); j++)
        {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }

    return 1;
}
//
//void* mat_create(int filas, int colum)
//{
//    int i;
//    int** vectorFila;
//    // PUNTERO A PUNTERO
//    // UN PUNTERO A UN VECTOR DE FILAS
//    // CADA FILA ES UN PUNTERO A UNA X CANTIDAD DE ESPACIO DE MEMORIA
//    // (X = COLUMNAS)
//
//    //             (PUNTERO A PUNTEROS)
//    // CREO MATRIZ (VECTOR DE VECTORES)
//    vectorFila = (int**)malloc(filas*sizeof(int*));
//
//    if(!vectorFila)// SI NO PUEDO ALOJAR FILAS, SALGO
//    {return NULL;}
//    else // SI PUEDO, EMPIEZO A ALOJAR MEMORIA PARA LAS COLUMNAS
//    {
//        // RECORRO FILAS ASIGNANDO CANTIDAD DE COLUMNAS PARA C/FILA.
//        for(i = 0; i < filas; i++)
//        {
//            // ASIGNO MEMORIA (COLUMNAS) Y DESIGNO UN PUNTERO DEL VECTOR DE
//            // FILAS HACIA ESA DIRECCION
//            *(vectorFila+i) = (int*)malloc(colum*sizeof(int));
//
//            if(!*(vectorFila+i)) // NULL SI NO PUDO ALOJAR MEMORIA
//            {
//                // RECORRO FILAS HACIA ATRAS MIENTRAS LIBERO MEMORIA
//                while(i--)
//                {free(*(vectorFila+i));}
//                free(vectorFila); // LIBERO MEMORIA DEL VECTOR DE VECTORES
//                return NULL; // RETORNO NULL PARA INDICAR UN ERROR
//            }
//        }
//
//        //DEVUELVO DIRECCION DEL PRINCIPIO DE LA MATRIZ (DOBLE PUNTERO)
//        return vectorFila;
//    }
//}
//
//void mostrarMatrizDinamica(int** pMatriz, int fil, int col)
//{
//    int i, j;
//    for(i = 0; i < fil; ++i)
//        for(j = 0; j < col; ++j)
//        {
//            printf("%d  ", pMatriz[i][j]);
//            if(j == col - 1)
//            { printf("n"); }
//        }
//
//    //libero
//    for(i = 0; i < fil; i++)
//    { free(pMatriz[i]); }
//
//    free(pMatriz);
//}

////funcion para probar error de alojamiento de memoria
//void* mmalloc(size_t tam)
//{
//    if(rand() %10 == 5)
//    { return NULL; }
//
//    return malloc(tam);
//}
