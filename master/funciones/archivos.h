#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED
#include <stdio.h>
#include <string.h>


/********************************************//**
 * \brief Funcion que abre archivo segun nombre y modo de apertura
 *        en caso de error decido si mostrar o no un mensaje.
 * \param fp FILE**          : puntero hacia el archivo a abrir.
 * \param nombre const char* : nombre del archivo a abrir.
 * \param modo const char*   : modo de apertura del archivo.
 * \param mostrarError int   : bandera indicando si debo mostrar error.
 * \return int : devuelvo 1 si tuvo exito y 0 si ocurrio error.
 *
 ***********************************************/
int abrirArchivo(FILE** fp, const char* name, const char* modo, int showError);

#endif // ARCHIVOS_H_INCLUDED



/*****************************PRUEBA LEO BINARIO*******************************/
//    FILE *fpPrueba;
//
//    if(!abrirArchivo(&fpPrueba, "nombre_archivo.dat", "rb", 1))
//    {
//        return 0;
//    }
//    else
//    {
//        fread(&cliente, sizeof(t_cliente), 1, fpPrueba);
//        while(!feof(fpPrueba))
//        {
//            fprintf(stdout,"%25s%8u%10u\n",cliente.nombre,cliente.dni,cliente.saldo);
//            fread(&cliente, sizeof(t_cliente), 1, fpPrueba);
//        }
//        fclose(fpPrueba);
//    }

/******************************PRUEBA LEO TEXTO********************************/
//    FILE *fpPrueba;
//    char cadena[TAM];
//
//    if(!abrirArchivo(&fpPrueba, "data_errores.txt", "rt", 1))
//    {return 0;}
//    else
//    {
//        while( fgets(cadena,TAM,fpPrueba) )
//        {
//            fprintf(stdout,cadena);
//            fread(&cliente, sizeof(t_cliente), 1, fpPrueba);
//        }
//        fclose(fpPrueba);
//    }

/****************************PRUEBA CAMBIAR NOMBRE*****************************/
//    if(!(remove(ARCHIVO_CLIENTES)))
//    {
//        if(!(rename(ARCHIVO_NUEVO, ARCHIVO_CLIENTES)))
//        {
//            if(!(remove(ARCHIVO_NUEVO)))
//            {
//                printf("TODO SALIO BIEN\n");
//            }
//            else
//            {
//                printf("ERROR #1\n");
//            }
//        }
//        else
//        {
//            printf("ERROR #2\n");
//        }
//    }
//    else
//    {
//        printf("ERROR #3\n");
//    }

