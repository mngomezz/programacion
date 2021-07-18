#include "memoria.h"

void *mem_copy(void *destino, const void *origen, size_t tam)
{
    void *aux = destino;
    while (tam--)
    {
        *(char *)destino++ = *(char *)origen++;
    }
    return aux;
}

void *mem_move(void *destino, const void *origen, size_t tam)
{
    void *aux = destino;
    if (origen >= destino) // Si muevo hacia atras (No puedo pisar memoria)
    {
        while (tam--)
        {
            *(char *)destino++ = *(char *)origen++;
        }
    }
    else // Si muevo hacia delante (Puedo pisar memoria)
    {
        destino += tam - 1;
        origen += tam - 1;
        while (tam--)
        {
            *(char *)destino-- = *(char *)origen--;
        }
    }

    return aux;
}

//char *mem_strcpy(const char *cadena)
//{
//    // consigo tama�o de la cadena
//    // si tama�o es 0
//    // devuelvo NULL
//    // si no
//    // asigno memoria
//    // copio cadena
//    // agrego caracter \0
//    // retorno inicio de nueva cadena
//    // ** queda a deber del programador que utilize la funcion
//    // ** acordarse de liberar la memoria con free(nuevaCadena)
//    return cadena;
//}

//char *mem_strcat(char *cadena1, const char *cadena2)
//{
//    char *aux = cadena1, *mem_aux;
//    size_t cad1_size = strlen(cadena1);
//    size_t cad2_size = strlen(cadena2);
//
//    cadena1 = (char *)realloc(cadena1,12);
//    strcpy(cadena1,"Hola mundo");
//    return cadena1;
//}
//    if(cadena1)
//    {2
//        cadena1 += cad1_size-1;
//        while(cad2_size--)
//        {*cadena1++ = *cadena2++;}
//        cadena1 = 0;
//
//    }
//    else
//    {
//        mem_aux = (char *)malloc(cad1_size+cad2_size);
//        aux = mem_aux;
//        while(cad1_size--)
//        {*mem_aux++ = *cadena1++;}
//        while(cad2_size--)
//        {*mem_aux++ = *cadena2++;}
//        mem_aux = 0;
//    }
//
//    return aux;
// consigo tama�os de cadenas
// busco asignar memoria contigua a la cadena
// si pude
// concateno
// si no pude
// asigno nuevo bloque de memoria
// concateno
// devuelvo nueva posicion de cadena
//void* mem_createMat(int filas,int columnas)
//{
//    int i,j;
//    int** pm;
//    /*
//        puntero a puntero a int
//        es un *puntero* que posee un puntero como valor
//
//        con malloc, se hace espacio para los N punteros determinados por filas
//    */
//
//    int** vectorFila;
//
//    //Creo el vector de punteros (vectorFila) identificado por **
//    vectorFila = (int**)malloc(filas* sizeof(int*));
//
//    //Si no puedo alojar las filas que necesito directamente salgo
//    if(!vectorFila)
//        return NULL;
//    //Si me dej�, debo empezar a alojar memoria para las columnas
//    else
//    {
//        //Voy alojando mi vector de columnas dinamicamente
//
//        pm = vectorFila;
//
//        for(i = 0; i < filas; i++)
//        {
//            *(vectorFila+i) = (int*)malloc(columnas * sizeof(int));
//
//            //Si no se pudo alojar memoria para la columna
//            //Dejo de iterar
//            if(!*(vectorFila+i))
//                break;
//        }
//
//        if(!*(vectorFila+i))
//        {
//            //Utilizo el I del for anterior para ir desalojando
//            //desde el ultimo vector fila que se pudo alojar.
//            for(j = i; j > 0; j--)
//                free(*(vectorFila+j));
//
//            free(vectorFila);
//
//            //No puedo continuar, salgo de la funcion
//            return NULL;
//        }
//
//        //Devuelvo un doble puntero. tener en cuenta en el main.
//        return pm;
//    }
//}
//
//void cargarMatriz(int** pMatriz, int fil, int col)
//{
//    // Carga la matriz seg�n la cantidad de filas y columnas que tenga.
//    int i, j;
//    long int numero = 0;
//    for(i = 0; i < fil; i++)
//        for(j = 0; j < col; j++)
//            pMatriz[i][j] = ++numero;
//}
//
//void mostrarMatrizDinamica(int** pMatriz, int fil, int col)
//{
//    int i,j;
//    for (i = 0; i < fil; ++i)
//        for (j = 0; j < col; ++j)
//        {
//            printf("%d  ", pMatriz[i][j]);
//            if (j == col - 1)
//                printf("n");
//        }
//
//    //libero
//    for(i = 0; i < fil; i++)
//        free(pMatriz[i]);
//
//    free(pMatriz);
//}
//
////funcion para probar error de alojamiento de memoria
//void* mmalloc(size_t tam)
//{
//    if(rand() %10 == 5)
//        return NULL;
//
//    return malloc(tam);
//}
