#include "cadenas.h"

char *str_character(const char *cadena, char caracter)
{
    while (*cadena && *cadena != caracter)
    {
        cadena++;
    }

    return *cadena == caracter ? (char *)cadena : NULL;
}

int str_compare(const char *cad1, const char *cad2)
{
    while (*cad1 && *(cad1) == *(cad2))
    {
        cad1++;
        cad2++;
    }

    return *cad1 - *cad2;
}

char *str_concat(char *destino, const char *origen, unsigned sizeof_destino)
{
    if (sizeof_destino < (strlen(destino) + strlen(origen)))
    {
        return NULL;
    } // valido que me alcance el tama�o en destino

    char *aux = destino; // creo puntero a principio de destino

    while (*aux)
    {
        aux++; // recorro hasta encontra un '\0'
    }

    while (*origen) // recorro origen copiandola al final de destino
    {
        *aux = *origen;
        aux++;
        origen++;
    }

    *aux = '\0';    // marco el final de la cadena con un '\0'
    return destino; // retorno cadena modificada
}

char *str_copy(char *destino, const char *origen)
{
    char *aux = destino;

    while ((*destino = *origen))
    {
        destino++;
        origen++;
    }

    return aux;
}

size_t str_length(const char *cadena)
{
    size_t length = 0;

    while (*(cadena++))
    {
        length++;
    }

    return length;
}

char *str_corrimiento(const char *cadena, int despl)
{
    size_t strLength = str_length(cadena);
    char cadenaAux[strLength + 1], *pChar = (char *)cadena;
    str_copy(cadenaAux, cadena);                                                               // Copio en cadena auxiliar la cadena a modificar
    int desplazamiento = (despl > 0) ? strLength - (despl % strLength) : (-despl) % strLength; // contemplo que despl sea > 0

    while (*pChar)
    {
        *pChar = *(cadenaAux + ((pChar - cadena + desplazamiento) % strLength));
        pChar++;
    }

    return (char *)cadena;
}

char str_desplazamiento(char c, int despl)
{
    char dic[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ;.,";
    char *cpos;

    if ((cpos = str_character(dic, c)))
    {
        return *(dic + ((cpos - dic + despl) % str_length(dic)));
    }

    return c;
}

char *str_normalizada(char *cadena)
{
    char *pProxPal = cadena, *pAux = cadena;
    int cantCaracts;
    int primeraVez = 1;

    while ((pProxPal = str_proxPalabra(pProxPal, &cantCaracts)))
    {
        while (cantCaracts)
        {
            if (primeraVez)
            {
                if (*pProxPal >= 'a' && *pProxPal <= 'z')
                {
                    *pProxPal -= 32;
                }

                primeraVez = 0;
            }
            else
            {
                if (*pProxPal >= 'A' && *pProxPal <= 'Z')
                {
                    *pProxPal += 32;
                }
            }

            *cadena = *pProxPal;
            pProxPal++;
            cadena++;
            cantCaracts--;
        }

        *cadena = ' ';
        cadena++;
    }

    *cadena = '\0';
    return pAux;
}

unsigned str_ocurrencias(const char *cadena, char *palBuscada, int solapamiento)
{
    char *pBusq, *pCad;
    unsigned contOcurrencias = 0;

    while ((cadena = strchr(cadena, *palBuscada)))
    {
        pCad = (char *)cadena; // apunto prox ubicacion de cadena
        pBusq = palBuscada;    // apunto a principio de palabra a buscar

        do // recorro cadenas hasta que sean diferentes
        {
            pCad++;
            pBusq++;
        } while (*pCad == *pBusq);

        if (!(*pBusq)) // si las palabras coinciden
        {
            if (!solapamiento) // apunto a proxima posicion luego de la palabra encontrada
            {
                cadena = pCad;
            }

            contOcurrencias++;
        }
        else
        {
            cadena++;
        }
    }

    return contOcurrencias;
}

char *str_proxPalabra(const char *cadena, int *cantCaract)
{
    char *aux = (char *)cadena;

    //asigno puntero inicio
    while (*cadena && !((*cadena >= 'a' && *cadena <= 'z') || (*cadena >= 'A' && *cadena <= 'Z')))
    {
        cadena++;
    } // recorro siempre y cuando el valor chequeado sea != a una letra

    if (*cadena) // si encontro una letra
    {
        aux = (char *)cadena;
    }
    else
    {
        return NULL;
    }

    //asigno puntero fin
    while (*cadena && ((*cadena >= 'a' && *cadena <= 'z') || (*cadena >= 'A' && *cadena <= 'Z')))
    {
        cadena++;
    }

    *cantCaract = cadena - aux;
    return aux;
}

float str_toFloat(char *cadena)
{
    int float_val = 0;
    return float_val;
}

int str_toInt(char *cadena)
{
    int int_val = 0;
    return int_val;
}

char *str_toLower(char *cadena)
{
    char *aux = cadena;

    while (*cadena)
    {
        if (*cadena > 64 && *cadena < 91)
        {
            *cadena += 32;
        }

        cadena++;
    }

    return aux;
}

char *str_toUpper(char *cadena)
{
    char *aux = cadena;

    while (*cadena)
    {
        if (*cadena >= 'a' && *cadena <= 'z')
        {
            *cadena -= 32;
        }

        cadena++;
    }

    return aux;
}
