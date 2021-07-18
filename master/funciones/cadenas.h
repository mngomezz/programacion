#ifndef CADENAS_H_INCLUDED
#define CADENAS_H_INCLUDED
#define DOC1 "documentoOfuscado.txt"
#define DOC2 "documentoDesofuscado.txt"
#include <stddef.h>
#include <stdio.h>
#include <string.h>

/// Para mas info sobre esta funcion revisar la funcion strchr en el ANSI C
char* str_character(const char* cadena, char caracter);

/// Para mas info sobre esta funcion revisar la funcion strcmp en el ANSI C
int str_compare(const char* cad1, const char* cad2);

/// Para mas info sobre esta funcion revisar la funcion strcat en el ANSI C
char* str_concat(char* cad1, const char* cad2, unsigned sizeof_cad1);

/// Para mas info sobre esta funcion revisar la funcion strcpy en el ANSI C
char* str_copy(char* destino, const char* origen);

/// Para mas info sobre esta funcion revisar la funcion strlen en el ANSI C
size_t str_length(const char* cadena);

/// Para mas info sobre esta funcion revisar la funcion atof en el ANSI C
float str_toFloat(char* cadena);

/// Para mas info sobre esta funcion revisar la funcion atoi en el ANSI C
int str_toInt(char* cadena);

/// Para mas info sobre esta funcion revisar la funcion strlwr en el ANSI C
char* str_toLower(char* cadena);

/// Para mas info sobre esta funcion revisar la funcion strupr en el ANSI C
char* str_toUpper(char* cadena);


/********************************************//**
 * \brief Recibo una cadena y aplico un cierto desplazamiento a la misma.
 *
 * \param cadena const char* : cadena a ser desplazada
 * \param despl int          : cantidad de lugares a desplazarse
 * \return char* : cadena modificada
 *
 ***********************************************/
char* str_corrimiento(const char* cadena, int nro);

/********************************************//**
 * \brief Recibe un char y lo desplaza x veces en el diccionario (si pertenece).
 *
 * \param c char    : char a desplazar
 * \param despl int : cantidad de lugares a desplazar
 * \return char     : char desplazado si existe en diccionario
 *
 ***********************************************/
char str_desplazamiento(char c, int despl);


/********************************************//**
 * \brief Quita espacios iniciales y finales y dobles y
 *        pasa a minusculas todas las letras menos la primera.
 * \param cadena char* : cadena a normalizar.
 * \return char*       : cadena normalizada
 *
 ***********************************************/
char* str_normalizada(char* cadena);

/********************************************//**
 * \brief Cuenta cantidad de ocurrencias de una cadena dentro de otra.
 *
 * \param cadena char*      : cadena a analizar.
 * \param palBuscada char*  : cadena a buscar.
 * \param solapamiento int  : 1 -> con ; 0 -> sin
 * \return unsigned         : retorno cant de ocurrencias.
 *
 ***********************************************/
unsigned str_ocurrencias(const char* cadena, char* busqueda, int solapamiento);

/********************************************//**
 * \brief Busco proxima palabra en una cadena
 *
 * \param cadena const char* : cadena a analizar.
 * \param cantCaract int*    : puntero a cant de caracteres.
 * \return char* : devuelvo puntero al inicio de la prox palabra.
 *
 ***********************************************/
char* str_proxPalabra(const char* cadena, int* cantCaract);

/********************************************//**
 * \brief Reemplazo ocurrencias de una palabra en una cadena.
 *
 * \param cadena char*    : cadena a analizar.
 * \param reemplazo char* : cadena reemplazo.
 * \param busqueda char*  : cadena a reemplazar.
 * \return char* : cadena ya modificada.
 *
 ***********************************************/
unsigned str_reemplazo(char* cadena, char* reemplazo, char* busqueda);


#endif // CADENAS_H_INCLUDED

