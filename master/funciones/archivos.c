#include "archivos.h"

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
int abrirArchivo(FILE** fp, const char* nombre, const char* modo, int mostrarError)
{
    *fp = fopen(nombre, modo);

    if(*fp)
    {return 1;}
    else  // si hubo error
    {
        if(mostrarError)
        {fprintf(stderr, "Error abriendo \"%s\" en modo \"%s\".", nombre, modo);}

        return 0;
    }
}








