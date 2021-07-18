#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
/**  ANOTACION
LA PILA SIMPLE TIENE LA PARTICULARIDAD DE QUE SOLO SE PUEDE AGREGAR UN NODO AL
FINAL DE ESTA, ES DECIR, EN EL TOPE. ADEMAS, DE LA MISMA MANERA, SOLO SE PUEDE
QUITAR DE LA PILA EL NODO QUE ESTE EN EL TOPE, NO ASI LOS DEMAS. COMO ULTIMA
PARTICULARIDAD DE ESTE TDA SE TIENE QUE SOLO SE PUEDE ACCEDER AL TOPE DE ESTA,
ESTO ES, NO SE PUEDE VER UN NODO QUE NO SEA EL ULTIMO INGRESADO.
EJEMPLO: UNA PILA DE PLATOS.
**/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../../funciones/utiles.h"
#define SIN_MEMORIA 0
#define PILA_VACIA 0
typedef struct s_nodo
{
    void* info;
    unsigned tamInfo;
    struct s_nodo* sig;
} t_nodo;

typedef t_nodo* tda_pila;

void pila_crear(tda_pila* p);
int  pila_estaLlena(const tda_pila* p, unsigned cantBytes);
int  pila_apilar(tda_pila* p, const void* dato, unsigned cantBytes);
int  pila_verTope(const tda_pila* p, void* dato, unsigned cantBytes);
int  pila_estaVacia(const tda_pila* p);
int  pila_desapilar(tda_pila* p, void* dato, unsigned cantBytes);
void pila_vaciar(tda_pila* p);

#endif // PILA_H_INCLUDED


/** EJERCICIO SUMA CON PILAS **/
/*
#define NOMBRE_ARCHIVO "sumaconpilas.txt"
#define PILAS_NO_VACIAS 1

int main()
{
    FILE* pf;
    tda_pila pila1, pila2, pila3, *pPila;
    char str[TAM], *pChar;
    int int_value, aux1 = 0, aux2 = 0, strlength, carry = 0, pilas_vacias;

    if(!abrirArchivo(&pf, NOMBRE_ARCHIVO, "rt", 1))
    {return 0;}

    pila_crear(&pila1);
    pila_crear(&pila2);

    pPila = &pila1;

    while(fgets(str, TAM, pf))
    {
        pChar = str;
        strlength = strlen(str)-1;

        while(strlength--)
        {
            int_value = ((int)*pChar) - 48;//atoi(&char_value);

            if(!pila_apilar(pPila, &int_value, sizeof(int)))
            {
                fprintf(stdout, "%s", "ERR#1 - Error al apilar datos");
                fclose(pf);
                return -1;
            }

            pChar++;
        }

        pPila = &pila2;
    }

    pila_crear(&pila3);

    // SOLO SERA FALSA CUANDO TENGA AMBAS PILAS VACIAS, EN ESE CASO HAGO break;
    while(PILAS_NO_VACIAS)
    {
        // SETEO LA BANDERA pilas_vacias EN 0 EN CADA PASADA
        // Y EN CASO DE NO PODER SACAR DE PILA, ENTONCES INDICO QUE LO OBTENIDO
        // DE ESA PILA ES IGUAL A 0
        pilas_vacias = 0;
        if(!pila_desapilar(&pila1, &aux1, sizeof(int)))
        {
            aux1 = 0;
            pilas_vacias++;
        }

        if(!pila_desapilar(&pila2, &aux2, sizeof(int)))
        {
            aux2 = 0;
            pilas_vacias++;
        }

        if(pilas_vacias==2)
        {break;}
        else // EN CASO DE TENER ALMENOS ALGUNA PILA NO VACIA
        {
            // AGREGO OVERFLOW DE CUENTA ANTERIOR Y SUMO NUMEROS DE CADA PILA
            aux1 += aux2 + carry;
            carry = 0;

            if(aux1>9) // EN CASO DE OVERFLOW, USO EL MODULO Y CARGO EL carry
            {
                aux1 = aux1%10;
                carry++;
            }

            // APILO DATOS EN NUEVA PILA, LA CUAL OBTENDRA EL RESULTADO FINAL
            if(!pila_apilar(&pila3, &aux1, sizeof(int)))
            {
                fprintf(stdout, "%s", "ERR#2 - Error al apilar datos");
                fclose(pf);
                return -2;
            }
        }
    }

    if(carry)  // SI LA ULTIMA CUENTA GENERO OVERFLOW, AGREGO ESE 1 A LA PILA
    {
        if(!pila_apilar(&pila3, &carry, sizeof(int)))
        {
            fprintf(stdout, "%s", "ERR#5 - Error al apilar datos");
            fclose(pf);
            return -5;
        }
    }

    while(pila_desapilar(&pila3, &aux1, sizeof(int)))
    {fprintf(stdout, "%d", aux1);} // MUESTRO PILA CON RESULTADO FINAL

    fclose(pf);
    return 0;
}
*/


/** EJERCICIO CHEQUEO EXPRESION **/
/*
#define NOMBRE_ARCHIVO "chequeoExpresion.txt"
#define PILAS_NO_VACIAS 1

int main()
{
    FILE* pf;
    tda_pila pila1, pila2, pila3, *pPila;
    char str[TAM], *pChar;
    int int_value, aux1 = 0, aux2 = 0, strlength, carry = 0, pilas_vacias;

    if(!abrirArchivo(&pf, "sumaconpilas.txt", "rt", 1))
    {return 0;}

    pila_crear(&pila1);
    pila_crear(&pila2);

    pPila = &pila1;

    while(fgets(str, TAM, pf))
    {
        pChar = str;
        strlength = strlen(str)-1;

        while(strlength--)
        {
            int_value = ((int)*pChar) - 48;//atoi(&char_value);

            if(!pila_apilar(pPila, &int_value, sizeof(int)))
            {
                fprintf(stdout, "%s", "ERR#1 - Error al apilar datos");
                fclose(pf);
                return -1;
            }

            pChar++;
        }

        pPila = &pila2;
    }

    pila_crear(&pila3);

    // SOLO SERA FALSA CUANDO TENGA AMBAS PILAS VACIAS, EN ESE CASO HAGO break;
    while(PILAS_NO_VACIAS)
    {
        // SETEO LA BANDERA pilas_vacias EN 0 EN CADA PASADA
        // Y EN CASO DE NO PODER SACAR DE PILA, ENTONCES INDICO QUE LO OBTENIDO
        // DE ESA PILA ES IGUAL A 0
        pilas_vacias = 0;
        if(!pila_desapilar(&pila1, &aux1, sizeof(int)))
        {
            aux1 = 0;
            pilas_vacias++;
        }

        if(!pila_desapilar(&pila2, &aux2, sizeof(int)))
        {
            aux2 = 0;
            pilas_vacias++;
        }

        if(pilas_vacias==2)
        {break;}
        else // EN CASO DE TENER ALMENOS ALGUNA PILA NO VACIA
        {
            // AGREGO OVERFLOW DE CUENTA ANTERIOR Y SUMO NUMEROS DE CADA PILA
            aux1 += aux2 + carry;
            carry = 0;

            if(aux1>9) // EN CASO DE OVERFLOW, USO EL MODULO Y CARGO EL carry
            {
                aux1 = aux1%10;
                carry++;
            }

            // APILO DATOS EN NUEVA PILA, LA CUAL OBTENDRA EL RESULTADO FINAL
            if(!pila_apilar(&pila3, &aux1, sizeof(int)))
            {
                fprintf(stdout, "%s", "ERR#2 - Error al apilar datos");
                fclose(pf);
                return -2;
            }
        }
    }

    if(carry)  // SI LA ULTIMA CUENTA GENERO OVERFLOW, AGREGO ESE 1 A LA PILA
    {
        if(!pila_apilar(&pila3, &carry, sizeof(int)))
        {
            fprintf(stdout, "%s", "ERR#5 - Error al apilar datos");
            fclose(pf);
            return -5;
        }
    }

    while(pila_desapilar(&pila3, &aux1, sizeof(int)))
    {fprintf(stdout, "%d", aux1);} // MUESTRO PILA CON RESULTADO FINAL

    fclose(pf);
    return 0;
}
*/
