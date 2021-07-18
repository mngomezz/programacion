#include "ejercicios.h"
#include <math.h>

unsigned factorial(unsigned nro)
{
    unsigned j, fact = 1;

    for (j = 2; j <= nro; j++)
    {
        fact *= j;
    }

    return fact;
}

unsigned factorialRecursivo(unsigned nro)
{
    if (nro == 0)
    {
        return 1;
    }

    return nro * factorial(nro - 1);
}

double ealax(double num, float TOL)
{
    double e_x = 1.00, termino = 1;
    int i;

    for (i = 1; termino > TOL; i++)
    {
        termino *= num / i;
        e_x += termino;
    }

    return e_x;
}

int esFibonacci(int numero)
{
    int x = 1, y = 1, z = 0, i = 1;

    for (i = 0; z < numero; i++)
    {
        z = x + y;
        x = y;
        y = z;

        if (z == numero)
        {
            return 1;
        }
    }

    return 0;
}

float seno(int x, float tol)
{
    float term = x, sen = 0;
    int flag = 0, f = 2;

    while (fabs(term) > tol)
    {
        if (flag == 0)
        {
            flag += 3;
        }
        else
        {
            //term = (float)MIN(x, flag)/factorial((unsigned)flag);
            flag += 2;
        }

        if (f % 2 == 0)
        {
            sen += term;
        }
        else
        {
            sen -= term;
        }

        f++;
    }

    return sen;
}

int multiplicacionRusa(int nro1, int nro2)
{
    int i, j, k, nro_divisiones, resultado, resultado_total;
    i = j = k = nro_divisiones = resultado = resultado_total = 0;

    if (nro1 == 1)
    {
        return nro2;
    }

    if (nro2 == 1)
    {
        return nro1;
    }

    for (i = nro1; i >= 1; i /= 2)
    {
        if (i % 2 != 0)
        {
            resultado = nro2;

            for (k = 0; k < nro_divisiones; k++)
            {
                resultado *= 2;
            }

            resultado_total += resultado;
        }

        nro_divisiones++;
    }

    return resultado_total;
}

int parteEntera(float nroReal)
{
    int nroEntero = (int)(nroReal + 0.5);
    return nroEntero;
}

int esPalindr(char string[])
{
    int left = 0;
    int right = strlen(string);

    while (left < right)
    {
        if (string[left] != string[right - 1])
        {
            return 0;
            break;
        }
        else
        {
            left++;
            right--;
        }
    }

    return 1;
}

int valorNumericoDeCadena(char string[])
{
    int int_val = 0;
    int decimal_pos = 1;
    int str_length = strlen(string);
    int i, str_val;

    for (i = str_length - 1; i >= 0; i--)
    {
        switch (string[i])
        {
        case 45:
        {
            if (i == 0)
            {
                int_val = -int_val;
                break;
            }
            else
            {
                return 0;
            }
        }

        case 48:
        {
            str_val = 0;
            break;
        }

        case 49:
        {
            str_val = 1;
            break;
        }

        case 50:
        {
            str_val = 2;
            break;
        }

        case 51:
        {
            str_val = 3;
            break;
        }

        case 52:
        {
            str_val = 4;
            break;
        }

        case 53:
        {
            str_val = 5;
            break;
        }

        case 54:
        {
            str_val = 6;
            break;
        }

        case 55:
        {
            str_val = 7;
            break;
        }

        case 56:
        {
            str_val = 8;
            break;
        }

        case 57:
        {
            str_val = 9;
            break;
        }

        default:
        {
            return 0;
        }
        }

        if (string[i] != 45)
        {
            int_val += (str_val * decimal_pos);
            str_length--;
            decimal_pos *= 10;
        }
    }

    return int_val;
}
