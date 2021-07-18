#ifndef UTILES_H_INCLUDED
#define UTILES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define TRUE 1
#define EXITO 1
#define FALSE 0
#define SIN_MEMORIA 0
#define NO_ENCONTRADO 0

#define MAX(X,Y) ((X)>(Y)?(X):(Y))
#define MIN(X,Y) ((X)<(Y)?(X):(Y))
#define ABS(X) (X)<0?-(X):(X)
#define PARTE_ENTERA(X) (int)(X)
#define PARTE_DECIMAL(X) (X)-(int)(X)
#define REDONDEO(X) (PARTE_DECIMAL(X)>0.5?(int)(++(X)):(int)(X)
#define ES_LETRA(X) (((X)>='a'&&(X)<='z')||((X)>='A'&&(X)<='Z'))
#define ES_DIGITO(X) ((X)>=0&&(X)<=9)
#define ES_MAYUS(X) ((X)>='A'&&(X)<='Z')
#define ES_MINUS(X) ((X)>='a'&&(X)<='z')

typedef struct
{
    unsigned dni;
    char nombre[28];
    int edad;
    float promedio;
    char sexo;
} t_alumno;

typedef struct
{
    unsigned id;
    char nombre[28];
    int edad;
    float salario;
} t_empleado;

typedef struct
{
    char nombre[25];
    unsigned dni;
    unsigned saldo;
} t_cliente;

typedef struct
{
    int id;
    int cantidad;
    float precio;
} t_producto;

typedef struct
{
    t_cliente cliente;
    char tipo;
} t_novedad;

void swapVal(void* dato1, void* dato2, size_t datasize);
void cls();
void print_int(unsigned formato, const void* entero);
void print_char(unsigned formato, const void* caracter);
void print_float(unsigned formato, const void* flotante);
void print_empleado(const void* emp);
void print_alumno(const void* alu);
void print_producto(const void* prod);
int cmp_int(const void* entero1, const void* entero2);
int cmp_float(const void* flotante1, const void* flotante2);
int cmp_char(const void* caracter1, const void* caracter2);
int cmp_string(const void* cadena1, const void* cadena2);
int cmp_alu(const void* alumno1, const void* alumno2);
int cmp_emp(const void* empleado1, const void* empleado2);
int cmp_cli(const void* cliente1, const void* cliente2);
int cmp_producto(const void* producto1, const void* producto2);
int cmp_alu_emp(const t_alumno* alu, const t_empleado* emp);
int cmp_cli_nov(const t_cliente* cli, const t_novedad* nov);


/** \brief Busco '|' en cadena, si no encuentro, retorno puntero a NULL,
 *         sino, cambio por un '\0' y retorno puntero a siguiente posicion de memoria.
 * \param cad char* : cadena a analizar
 * \return char*    : puntero a ultima cadena parseada
 *
 */
char* parse_data_alumno(char* cad);

/** \brief Ingreso data parseada por '|' en alu1 (id,nombre,edad,promedio,sexo)
 *
 * \param cadena char*   : cadena con datos
 * \param alu1 t_alumno* : estructura a llenar
 * \return int : 1 si tuvo exito, 0 si ocurrio error
 *
 */
int cargarAlumno(char* cadena, t_alumno* alu1);

/** \brief Ingreso data sabiendo su tamaño en alu1(id,nombre,edad,promedio,sexo)
 *
 * \param cadena char*   : cadena con datos
 * \param alu1 t_alumno* : estructura a llenar
 * \return int : 1 si tuvo exito y 0 si ocurrio error
 *
 */
int cargarAlumno2(char* cadena, t_alumno* alu1);

int filtro_producto(const void* info);
void acumulo_producto(const void* prod, void* acum);
#endif // UTILES_H_INCLUDED


//****************************CUADRO EXPLICATIVO********************************
//                                          |
//           _______________________________|__________________
//          |El modulo(%) lo aplicamos ya que nos pueden pedir |
//          |un desplazamiento mayor a la cant. de caracteres  |
//          |en el diccionario. Entonces el modulo parte en pa-|
//          |rtes iguales a este despl que pasamos y lo que    |
//          |sobra, es el desplazamiento que aplicamos         |
//          |__________________________________________________|
//
//****************************CUADRO EXPLICATIVO********************************



//************************PASAR PUNTEROS A FUNCIONES****************************
//
// EN EL MAIN:
// char *pIni, *pFin
//        h   o   l   a  \0   <-- *pIni
//      |___|___|___|___|___|  <--- cadena
//       100 101 102 103 104  <-- pIni
//                              NULL   NULL  <-- pIni // *pInicio
//                             |____| |____| <- pIni y pFin
//                               200    300  <-- &pIni
// DENTRO DE LA FUNCION:
// parametros(copias): pInicio, pFinal
//
//         100    200    300 <-- pInicio
//        |___|  |___|  |___|
//         400    500    600 <-- &pInicio
//
//************************PASAR PUNTEROS A FUNCIONES****************************









