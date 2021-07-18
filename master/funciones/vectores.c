#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "vectores.h"

// EJERCICIOS
void vec_ingresar(int *p_arr, unsigned *arr_size, int nro, unsigned pos, unsigned cantElem)
{
    if (cantElem <= *arr_size)
    {
        while (pos <= cantElem)
        {
            *(p_arr + cantElem) = *(p_arr + cantElem - 1);
            cantElem--;
        } // Llevo valores del array una posicion a la derecha hasta llegar a la posicion.

        *(p_arr + cantElem) = nro;
        (*arr_size)++;
    }
    else
    {
        printf("\n\tPOSICION INVALIDA!\n");
    }
}

void vec_ingresarOrdenado(int nro, int *array, unsigned *arr_size)
{
    unsigned size = *arr_size;

    while (nro <= *(array + size - 1))
    {
        *(array + size) = *(array + size - 1);
        size--;

        if (size == 0)
        {
            break;
        }
    }

    *(array + size) = nro;
    (*arr_size)++;
}

void vec_eliminar(int *array, unsigned *arr_size, unsigned position)
{
    int pos = position - 1; // array empieza en [0] // para usuario empieza en [1]

    while (pos < *arr_size)
    {
        *(array + pos) = *(array + pos + 1);
        pos++;
    }

    (*arr_size)--;
}

void vec_eliminarPrimerAparicion(int nro, int *array, unsigned *arr_size)
{
    unsigned i;
    char flag = 0;

    for (i = 0; i < (*arr_size); i++)
    {
        if (*(array + i) == nro || flag == 1)
        {
            flag = 1;
            *(array + i) = *(array + i + 1);
        }
    }

    if (flag == 0)
    {
        printf("\n\tEse numero no aparece en el array\n");
    }
    else
    {
        (*arr_size)--;
    }
}

void vec_eliminarApariciones(int nro, int *array, unsigned *arr_size)
{
    unsigned i, j;
    unsigned size = *arr_size;

    for (i = size - 1; i > 0; i--) // Desde el fin del array
    {
        if (*(array + i) == nro)
        {
            for (j = i; j < *arr_size; j++)
            {
                *(array + j) = *(array + j + 1);
            }

            (*arr_size)--;
        }
    }

    if (size == *arr_size)
    {
        printf("\n\tEL ELEMENTO NO APARECE EN EL ARRAY\n");
    }
    else
    {
        printf("\n\tSE ELIMINARON %d ELEMENTOS DEL ARRAY", size - *arr_size);
    }
}

int vec_cantElemParImpar(int *vec, int cantElem, char buscoImpar)
{
    // buscoImpar = 0 ==> Devuelve cant par
    // buscoImpar = 1 ==> Devuelve cant impar
    int i, contador = 0, checkParidad;

    if (buscoImpar)
    {
        checkParidad = (*vec % 2 != 0);
    }
    else
    {
        checkParidad = (*vec % 2 == 0);
    }

    for (i = 0; i < cantElem; i++)
    {
        contador += checkParidad ? 1 : 0;
        vec++;
    }

    return contador;
}

void vec_print(void *arr, size_t arr_size, size_t dato_size,
               void (*print)(const void *dato))
{
    while (arr_size--)
    {
        print(arr);
        arr += dato_size;
    }
}

// Array sort
void vec_bubbleSort(int *array, unsigned arr_size)
{
    unsigned i, j, k;
    int aux;
    int array_aux[arr_size];

    for (i = 0; i < arr_size; i++)
    {
        // lleno array auxiliar ANTES de ordenar.
        for (k = 0; k < arr_size; k++)
        {
            array_aux[k] = *(array + k);
        }

        // go while ordering
        for (j = 0; j < arr_size; j++)
        {
            if (array[j] > array[j + 1])
            {
                aux = array[j];
                array[j] = array[j + 1];
                array[j + 1] = aux;
            }
        }

        // back while ordering
        for (; j >= 0; j--)
        {
            if (array[j] < array[j - 1])
            {
                aux = array[j];
                array[j] = array[j - 1];
                array[j - 1] = aux;
            }
        }

        // comparing new array with the aux one
        for (k = 0; k < arr_size; k++)
        {
            // if an element has changed
            if (array_aux[k] != array[k])
            {
                break;
            }
            else if (k == arr_size - 1)
            {
                //end the main loop.
                i = arr_size;
            }
        }
    }
}

void vec_selectionSort(int array[], int arr_size)
{
    int i, j, min_position, max_position, aux_min, aux_max;

    for (i = 0; i < (arr_size - i); i++)
    {
        //initialize min and max positions
        min_position = i;
        max_position = i;

        for (j = i; j <= arr_size - 1 - i; j++)
        {
            //loop through the array looking for the min and max true positions
            if (array[j] < array[min_position])
            {
                min_position = j;
            }

            if (array[j] > array[max_position])
            {
                max_position = j;
            }
        }

        //store the min and max values in aux variables
        aux_min = array[min_position];
        aux_max = array[max_position];

        //to avoid vec_repeat the max element
        if (array[i] == array[max_position])
        {
            array[min_position] = array[(arr_size - 1) - i];
        } //...last element goes to the min position
        else
        {
            array[min_position] = array[i];
        } //...first element goes to the min position

        array[max_position] = array[(arr_size - 1) - i]; //last element goes to the max position
        //min and max values are put where they belong(first, last)
        array[i] = aux_min;
        array[(arr_size - 1) - i] = aux_max;
    }
}

void vec_insertionSort(int array[], int arr_size)
{
    int i, pos, valor;

    for (i = 0; i < arr_size; i++)
    {
        //store element and position to order in aux variables
        pos = i;
        valor = array[i];

        // move elements one position to the right if they are greater than our value
        while (pos > 0 && valor < array[pos - 1])
        {
            array[pos] = array[pos - 1];
            pos--;
        }

        array[pos] = valor; //store element in the right position.
    }
}

void vec_quickSort(int array[], int left_limit, int right_limit)
{
    int left, right, pivot, aux;
    left = right = pivot = aux = 0;
    //left and right variables go over the array, NOT the limits.
    left = left_limit;
    right = right_limit;
    //set the pivot in the middle of the array
    pivot = array[((left + right) / 2)];

    do
    {
        //loop until a greater element is found on the left side
        while (array[left] < pivot && left < right_limit)
        {
            left++;
        }

        //loop until a minor element is found on the right side
        while (array[right] > pivot && right > left_limit)
        {
            right--;
        }

        //swap if left is not equal to right
        if (left <= right)
        {
            aux = array[left];
            array[left] = array[right];
            array[right] = aux;
            left++;
            right--;
        }
    } while (left <= right);

    // if more than one element are less/greater than pivot --> execute QuickSort() to that sublist.
    if (left_limit < right)
    {
        vec_quickSort(array, left_limit, right);
    }

    if (right_limit > left)
    {
        vec_quickSort(array, left, right_limit);
    }
}

void vec_mergeSort(int array[], int arr_size, int left_pos, int right_pos)
{
    int middle_pos;

    //if array length > 1
    if (left_pos < right_pos)
    {
        //find the middle position
        middle_pos = (right_pos + left_pos) / 2;
        //1. Divide arrays into small ones
        vec_mergeSort(array, arr_size, left_pos, middle_pos);
        vec_mergeSort(array, arr_size, middle_pos + 1, right_pos);
        //2. Sort and Merge arrays
        int i, j, k;
        //calculate arrays length
        int arr_length_1 = middle_pos - left_pos + 1;
        int arr_length_2 = right_pos - middle_pos;
        //create temp arrays
        int L[arr_length_1], R[arr_length_2];

        //copy data to temp arrays
        for (i = 0; i < arr_length_1; i++)
        {
            L[i] = array[left_pos + i];
        }

        for (j = 0; j < arr_length_2; j++)
        {
            R[j] = array[middle_pos + 1 + j];
        }

        //merge the temp arrays
        i = 0;
        j = 0;
        k = left_pos;

        //loop until L[] or R[] ends
        while (i < arr_length_1 && j < arr_length_2)
        {
            //fill arr[k] with ordered data from L[i] or R[j]
            if (L[i] <= R[j])
            {
                array[k] = L[i];
                i++;
            }
            else
            {
                array[k] = R[j];
                j++;
            }

            k++;
        }

        //copy the remaining elements of L[]
        while (i < arr_length_1)
        {
            array[k] = L[i];
            i++;
            k++;
        }

        //copy the remaining elements of R[]
        while (j < arr_length_2)
        {
            array[k] = R[j];
            j++;
            k++;
        }
    }

    //it is not necessary to return nothing because we work with the array MEMORY position
}

/*
void vec_bucketSort(int array[],int arr_size){
    int casilleros = colección de n listas

    for(i = 0; i < arr_size ;i++){

    }
    hacer
    c ← buscar el casillero adecuado
    insertar elementos[i] en casillero[c]
  fin para
  para i = 1 hasta n hacer
    ordenar(casilleros[i])
  fin para
  devolver la concatenación de casilleros[1],..., casilleros[n]
}
*/

//array search
int vec_busquedaLineal(int array[], int valorBuscado, int arr_size)
{
    int i;

    for (i = 0; i < arr_size; i++)
    {
        if (array[i] == valorBuscado)
        {
            return i;
        }
    }

    return -1;
    //useful with disordered arrays
}

int vec_busquedaBinaria(int array[], int valorBuscado, int minimo, int maximo)
{
    int middle_pos = 0;

    while (minimo <= maximo)
    {
        middle_pos = (minimo + maximo) / 2;

        if (valorBuscado == array[middle_pos])
        {
            return middle_pos;
        }
        else if (valorBuscado < array[middle_pos])
        {
            maximo = middle_pos - 1;
        }
        else if (valorBuscado > array[middle_pos])
        {
            minimo = middle_pos + 1;
        }
    }

    return -1;
    //applicable only to ordered arrays
}
