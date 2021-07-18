/**/ /*             en los siguientes macroreemplazos indique:             */ /**/
/**/ /*    su(s)         APELLIDO(S)     completo(s)                       */ /**/
/**/ /*    su(s)         Nombre(S)       completo(s)                       */ /**/
/**/ /*    su legajo     NÚMERO DE DNI   con los puntos de millón y de mil */ /**/
/**/ /*    COMISIÓN                                                        */ /**/
/**/ /*              reemplazando los que están como ejemplo               */ /**/
#define APELLIDO "*****"
#define NOMBRE "mngomezz"
#define DOCUMENTO "**.***.***"
#define COMISION "**(****)"
/**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/
/** aquí insertaremos nuestras observaciones / correcciones                  **/
/**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/
#undef APELLIDO
#undef NOMBRE
#undef DOCUMENTO
#undef COMISION
/**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/
/**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/
/**/ /**/ /* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, HÁGALO DESDE ACÁ */                 /**/

#define MAX_BUFFER 198
/**/ /**/ /* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, HÁGALO HASTA ACÁ */                 /**/
/**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/
#include "funciones.h"

/** para el PUNTO 1 a.- **/
int leerTxtGrabarBin_MIO(const char *nomSinExt, int campos[][9], int filaTope,
                         const char *txt, const char *bin)
{
    FILE *pfTxt;
    FILE *pfBin;
    char nombreTxt[10];
    char nombreBin[10];
    char buffer[MAX_BUFFER];
    char *pChar;
    int fila;
    int tam_campos[4];
    int campo = 4;
    void *miembro;
    unsigned cantReg = 0;
    tPedido pedido;
    pfTxt = fopen(strcat(strcpy(nombreTxt, nomSinExt), TXT), "rt");
    pfBin = fopen(strcat(strcpy(nombreBin, nomSinExt), BIN), "wb");

    if (!pfTxt)
    {
        if (!pfBin)
        {
            return -3;
        }
        else
        {
            fclose(pfBin);
            return -1;
        }
    }
    else if (!pfBin)
    {
        fclose(pfTxt);
        return -2;
    }

    // Leo primer linea.
    fgets(buffer, MAX_BUFFER, pfTxt);
    pChar = strchr(buffer, atoi("_"));
    pChar++;
    fila = (int)(*pChar - 65);

    if (fila > filaTope)
    {
        fclose(pfTxt);
        fclose(pfBin);
        return -4;
    }

    fgets(buffer, MAX_BUFFER, pfTxt); // salteo linea 2
    fgets(buffer, MAX_BUFFER, pfTxt); // leo linea 3

    while (campo--)
    {
        pChar = strrchr(buffer, atoi(" "));
        if (!pChar)
        {
            pChar = buffer;
        }
        else
        {
            pChar = '\0';
            pChar++;
        }

        tam_campos[campo] = strlen(pChar);
    }

    while (fgets(buffer, MAX_BUFFER, pfTxt))
    {
        pChar = buffer;

        while (campo < sizeof(tam_campos) / sizeof(int))
        {
            switch (campos[fila][campo])
            {
            case 1:
            {
                miembro = &(pedido.codClie);
                break;
            }
            case 2:
            {
                miembro = &(pedido.claProd);
                break;
            }
            case 3:
            {
                miembro = &(pedido.cantPed);
                break;
            }
            case 4:
            {
                miembro = &(pedido.precUni);
                break;
            }
            default:
            {
                fclose(pfTxt);
                fclose(pfBin);
                return -10;
            }
            }

            memcpy(miembro, pChar, tam_campos[campos[fila][campo] - 1]);
            pChar += tam_campos[campos[fila][campo] - 1];

            campo++;
        }

        campo = 0;
    }

    fclose(pfTxt);
    fclose(pfBin);
    return cantReg;
}

/** para el PUNTO 1 b.- **/
int leerPedsYAgrupar_MIO(const char *nomSal, const char *nomEnt1,
                         const char *nomEnt2)
{
    FILE *pfSal;
    FILE *pfEnt1;
    FILE *pfEnt2;
    unsigned cantReg = 0;

    if (!(pfSal = fopen(nomSal, "wb")))
    {
        return -1;
    }

    if (!(pfEnt1 = fopen(nomEnt1, "rb")))
    {
        fclose(pfSal);
        return -2;
    }

    if (!(pfEnt2 = fopen(nomEnt2, "rb")))
    {
        fclose(pfSal);
        fclose(pfEnt1);
        return -3;
    }

    fclose(pfSal);
    fclose(pfEnt1);
    fclose(pfEnt2);
    return cantReg;
}

/** para el PUNTO 1 c.- **/
int leerPedsYResumir_MIO(const char *nomSal, const char *nomEnt)
{
    FILE *pfSal;
    FILE *pfEnt;
    unsigned cantReg = 0;

    pfSal = fopen(nomSal, "wb");

    pfEnt = fopen(nomEnt, "rb");

    if (!pfSal)
    {
        if (!pfEnt)
        {
            return -3;
        }
        else
        {
            fclose(pfEnt);
            return -1;
        }
    }
    else if (!pfEnt)
    {
        fclose(pfSal);
        return -2;
    }

    fclose(pfSal);
    fclose(pfEnt);
    return cantReg;
}

/** para el PUNTO 1 d.- **/
int despacharPedidos_MIO(const char *nomOka, const char *nomBlk,
                         const char *nomUnk, const char *nomPagos,
                         const char *nomResu)
{
    return 1;
}

/**                  FIN de PUNTO 1 **/
/**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/
/**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/
/** para crear y mostrar los datos de PUNTO 2 **/

/** HASTA ACÁ NO VA EN EL "ENTREGABLE"                                       **/

/**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/
