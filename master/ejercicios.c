/// EJERCICIOS EN CLASE :: PROGRAMACION 2020 (Ma-Vi Tarde)

/** TDA_LISTA : Ordenar lista (RESUELTO) **/
//{
int main()
{
    int i;
    tda_lista list;

    t_producto prodList[10] =
        {
            {1, 50, 5.50},
            {5, 10, 100},
            {23, 45, 1000},
            {11, 75, 25.50},
            {53, 20, 1100},
            {6, 105, 5.50},
            {9, 101, 100},
            {43, 45, 1000},
            {12, 225, 25.50},
            {77, 110, 1100}};

    lista_crear(&list);

    for (i = 0; i < sizeof(prodList) / sizeof(t_producto); i++)
    {
        lista_agregar(&list, &prodList[i], sizeof(t_producto));
    }

    printf("Antes de ordenar:\n");
    lista_mostrar(&list, print_producto);
    lista_ordenar(&list);
    printf("Despues de ordenar:\n");
    lista_mostrar(&list, print_producto);

    printf("\nFin del programa.\n");
    return 0;
}
//}

/** TDA_LISTA : Reducir lista (RESUELTO) **/
//{
int main()
{
    int i;
    float precioTotal;
    tda_lista list;

    t_producto prodList[10] =
        {
            {1, 50, 5.50},
            {5, 10, 100},
            {23, 45, 1000},
            {11, 75, 25.50},
            {53, 20, 1100},
            {6, 105, 5.50},
            {9, 101, 100},
            {43, 45, 1000},
            {12, 225, 25.50},
            {77, 110, 1100}};

    lista_crear(&list);

    for (i = 0; i < sizeof(prodList) / sizeof(t_producto); i++)
    {
        lista_agregar(&list, &prodList[i], sizeof(t_producto));
    }

    lista_mostrar(&list, print_producto);
    lista_reducir(&list, &precioTotal, acumulo_producto);
    printf("\nTotal precio en stock: %.2f\n", precioTotal);

    printf("\nFin del programa.\n");
    return 0;
}
//}

/** TDA_LISTA : Filtrar lista (RESUELTO) **/
//{
int main()
{
    int i;
    tda_lista list;

    t_producto prodList[10] =
        {
            {1, 50, 5.50},
            {5, 10, 100},
            {23, 45, 1000},
            {11, 75, 25.50},
            {53, 20, 1100},
            {6, 105, 5.50},
            {9, 101, 100},
            {43, 45, 1000},
            {12, 225, 25.50},
            {77, 110, 1100}};

    lista_crear(&list);

    for (i = 0; i < sizeof(prodList) / sizeof(t_producto); i++)
    {
        lista_agregar(&list, &prodList[i], sizeof(t_producto));
    }

    printf("Total productos:\n");
    lista_mostrar(&list, print_producto);
    lista_filtrar(&list, filtro_producto);
    puts("---------------------------------");
    printf("Filtro: CANTIDAD > 50\n");
    lista_mostrar(&list, print_producto);

    printf("\nFin del programa.\n");
    return 0;
}
//}

/** TDA_COLA : Cola del cajero (RESUELTO) **/
//{
#define ENTRADA 0
#define SALIDA 1
int getMinutos(int tipo);

/// flujo[0] --> entrada /// flujo[1] --> salida
static int flujo[2][3] = {{1, 3, 9}, {1, 3, 5}};

int main()
{
    int contColasVacias = 0, proxLlegaEn = 0, proxSaleEn = 0, contMinutos = 0,
        tardaEnSalir = 0, minutosDeColaVacia = 0;
    tda_cola colaCajero;
    cola_crear(&colaCajero);

    while (contColasVacias < 5 || contMinutos > 256)
    {
        if (proxLlegaEn == 0)
        {
            tardaEnSalir = getMinutos(SALIDA);
            cola_agregar(&colaCajero, &tardaEnSalir, sizeof(int));
            proxLlegaEn = getMinutos(ENTRADA);
        }

        if (proxSaleEn <= 0)
        {
            if (cola_sacar(&colaCajero, &proxSaleEn, sizeof(int)))
            {
                minutosDeColaVacia = 0;
            }
            else
            {
                minutosDeColaVacia++;
                //NO ME INTERESA SI ESTA VACIA POR LARGOS RATOS
                if (minutosDeColaVacia == 1)
                {
                    contColasVacias++;
                }
            }
        }

        proxSaleEn--;
        proxLlegaEn--;
        contMinutos++;
    }

    printf("La cola se vacio 5 veces en %d minutos", contMinutos);
}

int getMinutos(int tipo)
{
    return flujo[tipo][rand() % 3];
}

//}

/** TDA_PILA : Ordenamiento de vectores con pilas (SIN RESOLVER)**/
//{
#define INT_MAXVALUE 256
int main()
{

    tda_pila pilaMayor, pilaMenor;
    int arr[10] = {4, 6, 5, 9, 6, 8, 2, 6, 9, 1};
    int topeMayor, topeMenor, arr_size, index = 0, value;
    int menor = 0;

    pila_crear(&pilaMayor);
    pila_crear(&pilaMenor);

    arr_size = sizeof(arr) / sizeof(int);

    value = arr[index];

    vec_print(arr, arr_size, sizeof(int), print_int);

    while (index < arr_size)
    {
        topeMenor = -1;
        topeMayor = INT_MAXVALUE;
        pila_verTope(&pilaMayor, &topeMayor, sizeof(int));
        pila_verTope(&pilaMenor, &topeMenor, sizeof(int));

        if (topeMayor != INT_MAXVALUE && topeMenor != -1)
        {

            if (value > topeMayor && topeMenor != -1)
            {
                pila_desapilar(&pilaMayor, &topeMayor, sizeof(int));
                pila_apilar(&pilaMenor, &topeMayor, sizeof(int));
            }
            else if (value < topeMenor && topeMayor != INT_MAXVALUE)
            {
                pila_desapilar(&pilaMenor, &topeMenor, sizeof(int));
                pila_apilar(&pilaMayor, &topeMenor, sizeof(int));
            }
            else
            {
                if (topeMenor == -1)
                {
                    pila_apilar(&pilaMayor, &value, sizeof(int));
                }
                else
                {
                    pila_apilar(&pilaMenor, &value, sizeof(int));
                }

                index++;
                value = arr[index];
            }
        }
    }

    if (menor)
    {
        while (pila_desapilar(&pilaMayor, &topeMayor, sizeof(int)))
        {
            pila_apilar(&pilaMenor, &topeMayor, sizeof(int));
        }
    }
    else
    {
        while (pila_desapilar(&pilaMenor, &topeMenor, sizeof(int)))
        {
            pila_apilar(&pilaMayor, &topeMenor, sizeof(int));
        }
    }

    printf("\n");

    while (pila_desapilar(&pilaMayor, &topeMayor, sizeof(int)))
    {
        printf("%d", topeMayor);
    }
    return 0;
}

//}

/** ARCHIVOS : Resultados de la eleccion (SIN RESOLVER) **/
//{
/* Explicacion
     24 provincias(1-24), c/ provincia dividad :
                                         mesas (muchas)
                                         4 partidos (van del 1-4),

     archivo con los votos de cada pcia, region, partido, cant votos.
     esta desordenado.

     1) se pide: conocer al ganador de la votacion    (PANTALLA)
     2) que provincia hubo mas votos del partido ganador (PANTALLA)
     3) total de votos por partido   (PANTALLA)
     4) total de votos por provincia (PANTALLA)
     5) crear archivo .txt con info del partido ganador y el perdedor(menos votos obtuvo)
        con los datos normalizados del partido. (ArchivoTexto)

     Tengo archivo .txt con los datos de los candidatos por cada partido.
     archivo ordenado por partido
     presidente
     vice

     NORMALIZAR el nombre del candidato.
     eliminar blancos iniciales, finales, 1 espacio entre palabras
     primera letra en mayus ---> Perez, Juan I.

     queda:  Pte: Perez, Juan I. - Vice: Alvarez, Ana C.
*/
#define ARCHIVO_PROVINCIAS "data_provincias.dat"
#define ARCHIVO_PARTIDOS "data_partidos.txt"
#define ARCHIVO_NUEVO "data_nuevo.dat"
#define ARCHIVO_ERRORES "data_errores.txt"
int main()
{
    int comparacion, i, j;
    FILE *fpProv, *fpPart, *fpNew, *fpErr;

    int votos_por_provincia[5][25] =
        {
            //[partido]:[prov1],[prov2],[prov3]...
            {0, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00},
            {0, 25, 30, 15, 25, 30, 35, 40, 43, 32, 66, 30, 50, 45, 25, 16, 18, 30, 29, 40, 50, 55, 60, 55, 45},
            {0, 50, 60, 65, 50, 20, 25, 20, 47, 32, 26, 30, 30, 25, 45, 34, 38, 40, 39, 40, 40, 25, 30, 25, 45},
            {0, 15, 05, 10, 10, 20, 25, 20, 03, 12, 06, 25, 10, 10, 05, 26, 18, 10, 19, 10, 20, 25, 10, 15, 15},
            {0, 10, 05, 10, 15, 30, 15, 20, 07, 24, 02, 15, 10, 20, 25, 24, 18, 30, 29, 10, 01, 05, 06, 05, 05}
            // primer columna y primer fila para acumular subtotales
        };

    t_partido partidos[] =
        {
            {1, "FRENTE PROGRESISTA", "Daniel Perez", "Jorge Alvarez"},
            {2, "FRENTE IZQUIERDA", "Gabriel Gonzalez", "Juan Sanchez"},
            {3, "PRO", "Facundo Diaz", "Diego Gomez"},
            {4, "FPV", "Ignacio Martinez", "Agustin Ruiz"}},
              partido;

    if (!abrirArchivo(&fpProv, ARCHIVO_PROVINCIAS, "rb", 1))
    {
        return 0;
    }

    if (!abrirArchivo(&fpPart, ARCHIVO_PARTIDOS, "rt", 1))
    {
        fclose(fpProv);
        return 0;
    }

    if (!abrirArchivo(&fpNew, ARCHIVO_NUEVO, "wb", 1))
    {
        fclose(fpProv);
        fclose(fpPart);
        return 0;
    }

    if (!abrirArchivo(&fpErr, ARCHIVO_ERRORES, "wt", 1))
    {
        fclose(fpProv);
        fclose(fpPart);
        fclose(fpNew);
        return 0;
    }

    //////////////////////////////LOTE DE PRUEBA////////////////////////////////////
    //    //BINARIO
    //    fwrite(&votos_por_provincia, sizeof(int)*25, 5, fpProv);
    //    fwrite(&partidos, sizeof(t_partido), sizeof(partidos)/sizeof(t_partido), fpPart);
    //    //TEXTO
    //    for(i=0; i < sizeof(partidos)/sizeof(t_partido) ;i++)
    //    {fprintf(fpPart,"%d|%s|%s|%s",partidos[i].id,partidos[i].nombre,partidos[i].presidente,partidos[i].vice);}
    //////////////////////////////LOTE DE PRUEBA////////////////////////////////////

    //    fread(&cliente, sizeof(t_cliente), 1, fpCli);
    //    fread(&novedad, sizeof(t_novedad), 1, fpNov);
    //    while(!feof(fpNov))
    //    {
    //        //busco en clientes que coincida
    //        comparacion = cmp_cliente_novedad(&cliente, &novedad);
    //
    //        while(comparacion < 0) // siempre que clave cliente sea menor
    //        {
    //            fwrite(&cliente, sizeof(t_cliente), 1, fpNew); // agrego cliente a nuevo archivo
    //            fread(&cliente, sizeof(t_cliente), 1, fpCli); // leo nuevo cliente
    //            comparacion = cmp_cliente_novedad(&cliente, &novedad);
    //        }
    //
    //        if(comparacion) // si comparacion no es 0, no existe ese cliente
    //        {
    //            if(novedad.tipo != 'A') // agrego cliente a archivo errores
    //            { fwrite(&novedad, sizeof(t_cliente), 1, fpErr); }
    //            else // agrego cliente a nuevo archivo
    //            {fwrite(&cliente, sizeof(t_cliente), 1, fpNew);}
    //        }
    //        else // si es 0, existe el cliente
    //        {
    //            if(novedad.tipo == 'A') // indico error
    //            {fwrite(&novedad, sizeof(t_cliente), 1, fpErr);}
    //            else if(novedad.tipo == 'B') // leo otro cliente
    //            {fread(&cliente, sizeof(t_cliente), 1, fpCli);}
    //            else // == 'M'
    //            {
    //                // actualizo datos, cargo a nuevo archivo y leo nuevo cliente
    //                cliente.saldo = novedad.cliente.saldo;
    //                fwrite(&cliente, sizeof(t_cliente), 1, fpNew);
    //                fread(&cliente, sizeof(t_cliente), 1, fpCli);
    //            }
    //
    //        }
    //
    //        fread(&novedad, sizeof(t_novedad), 1, fpNov);
    //    }
    //
    //    while(!feof(fpCli)) // si no termine de cargar clientes
    //    {
    //        fwrite(&cliente, sizeof(t_cliente), 1, fpNew); // agrego cliente
    //        fread(&cliente, sizeof(t_cliente), 1, fpCli); // leo nuevo cliente
    //    }

    fclose(fpProv);
    fclose(fpPart);
    //    fclose(fpNew);
    //    fclose(fpErr);
}

//}

/** CADENAS : Reemplazar una string en una cadena (SIN RESOLVER) **/
//{
unsigned str_reemplazo(char *cadena, int tam, char *reemplazo, char *busqueda)
{
    //"A ana le gusta anana"    TAM       "REEMPLAZO"   >   "ana"
    int sonDistintas, tam_restante;
    unsigned contReemplazos = 0;
    char *pBusq, *pCad, *pRemp;
    if (reemplazo > busqueda)
    {
        //
    }
    else
    {
    }

    while ((cadena = strchr(cadena, *busqueda)))
    {
        // si queda en la cadena almenos un caracter que coincida
        // con el primer caracter de la palabra a reemplazar.
        pCad = cadena;
        pBusq = busqueda;

        if (strlen(cadena) == strlen(pBusq))
        {
            sonDistintas = strcmp(cadena, pBusq);
        }
        else
        {
            do // recorro cadenas hasta que sean diferentes.
            {
                pCad++;
                pBusq++;
            } while (*pCad && *pCad == *pBusq);

            sonDistintas = *pBusq;
            // si son iguales solo difieren en el caracter nulo ('\0')
            //reasigno posiciones a punteros
            pCad = cadena;
            pBusq = busqueda;
        }

        if (sonDistintas)
        {
            cadena++;
        }
        else //si son iguales reemplazo
        {
            pRemp = reemplazo;

            // salgo del loop cuando reemplazo o busqueda terminen.
            while (*pBusq && *pRemp)
            {
                *pCad = *pRemp; // reemplazo palabra en cadena
                pCad++;
                pBusq++;
                pRemp++;
            }

            cadena = pCad; // asigno puntero a siguiente pos. de memoria

            // En caso que haya quedado algo en pBusq (reemplazo < busqueda)
            while (*pBusq)
            {
                // ajusto tamaño de la cadena.
                while (*pCad)
                {
                    *pCad = *(pCad + 1);
                    pCad++;
                }

                pCad = cadena;
                pBusq++;
            }

            // En caso que haya quedado algo en pRemp (reemplazo > busqueda)
            while (*pRemp)
            {
                pBusq = pCad + strlen(pCad); // reutilizo puntero

                // ajusto tamaño de la cadena.
                while (pCad <= pBusq)
                {
                    *(pBusq + 1) = *pBusq;
                    pBusq--;
                }

                *pCad = *pRemp;
                pCad++;
                pRemp++;
            }
        }

        contReemplazos++;
    }

    return contReemplazos;
}
//}

/** MEMORIA : Mi version de strcpy con funciones de memoria (SIN RESOLVER) **/
//{
char *mem_strcpy(const char *cadena)
{
    // consigo tamaño de la cadena
    // si tamaño es 0
    // devuelvo NULL
    // si no
    // asigno memoria
    // copio cadena
    // agrego caracter \0
    // retorno inicio de nueva cadena
    // ** queda a deber del programador que utilize la funcion
    // ** acordarse de liberar la memoria con free(nuevaCadena)
    return cadena;
}
//}

/** MEMORIA : Mi version de strcat con funciones de memoria (SIN RESOLVER) **/
//{

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
// consigo tamaños de cadenas
// busco asignar memoria contigua a la cadena
// si pude
// concateno
// si no pude
// asigno nuevo bloque de memoria
// concateno
// devuelvo nueva posicion de cadena

//}

/** MEMORIA : Asignar espacio para una matriz (SIN RESOLVER) **/
//{

void *mem_createMat(int filas, int columnas)
{
    int i, j;
    int **pm;
    /*
        puntero a puntero a int
        es un *puntero* que posee un puntero como valor

        con malloc, se hace espacio para los N punteros determinados por filas
    */

    int **vectorFila;

    //Creo el vector de punteros (vectorFila) identificado por **
    vectorFila = (int **)malloc(filas * sizeof(int *));

    //Si no puedo alojar las filas que necesito directamente salgo
    if (!vectorFila)
    {
        return NULL;
    }
    //Si me dejó, debo empezar a alojar memoria para las columnas
    else
    {
        //Voy alojando mi vector de columnas dinamicamente

        pm = vectorFila;

        for (i = 0; i < filas; i++)
        {
            *(vectorFila + i) = (int *)malloc(columnas * sizeof(int));

            //Si no se pudo alojar memoria para la columna
            //Dejo de iterar
            if (!*(vectorFila + i))
            {
                break;
            }
        }

        if (!*(vectorFila + i))
        {
            //Utilizo el I del for anterior para ir desalojando
            //desde el ultimo vector fila que se pudo alojar.
            for (j = i; j > 0; j--)
            {
                free(*(vectorFila + j));
            }

            free(vectorFila);

            //No puedo continuar, salgo de la funcion
            return NULL;
        }

        //Devuelvo un doble puntero. tener en cuenta en el main.
        return pm;
    }
}

//}

/** MEMORIA : Cargar matriz con punteros (SIN RESOVLER) **/
//{

void cargarMatriz(int **pMatriz, int fil, int col)
{
    // Carga la matriz según la cantidad de filas y columnas que tenga.
    int i, j;
    long int numero = 0;
    for (i = 0; i < fil; i++)
        for (j = 0; j < col; j++)
        {
            pMatriz[i][j] = ++numero;
        }
}

//}

/** MEMORIA : Mostrar matriz usando punteros (SIN RESOLVER) **/
//{
void mostrarMatrizDinamica(int **pMatriz, int fil, int col)
{
    int i, j;
    for (i = 0; i < fil; ++i)
        for (j = 0; j < col; ++j)
        {
            printf("%d  ", pMatriz[i][j]);
            if (j == col - 1)
            {
                printf("n");
            }
        }

    //libero
    for (i = 0; i < fil; i++)
    {
        free(pMatriz[i]);
    }

    free(pMatriz);
}
//}

////funcion para probar error de alojamiento de memoria
//void* mmalloc(size_t tam)
//{
//    if(rand() %10 == 5)
//        return NULL;
//
//    return malloc(tam);
//}
