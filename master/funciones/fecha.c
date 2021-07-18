#include "fecha.h"

static int diasDelMes[2][12] =
{
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, //    es bisiesto
    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} // no es bisiesto
};

int esBisiesto(int anio)
{return anio%400==0 || (anio%4==0 && anio%100!=0);}

int fechaValida(Fecha fecha)
{
    return fecha.anio > ANIO_BASE && fecha.anio < ANIO_MAX &&
           fecha.mes  > 1 && fecha.mes <= 12 &&
           fecha.dia  > 1 && fecha.dia <= diasDelMes[esBisiesto(fecha.anio)][fecha.mes-1];
}

void diaSiguiente(Fecha* fecha)
{
    if(fecha->dia < diasDelMes[esBisiesto(fecha->anio)][fecha->mes-1])
    {fecha->dia++;}
    else if(fecha->mes < 12)
    {
        fecha->mes++;
        fecha->dia = 01;
    }
    else
    {
        fecha->anio++;
        fecha->mes = fecha->dia = 01;
    }
}

void sumarDias(Fecha* fecha, unsigned dias)
{
    fecha->dia += dias;

    while(fecha->dia > diasDelMes[esBisiesto(fecha->anio)][fecha->mes-1])
    {
        if(fecha->mes < 12)
        {
            fecha->dia -= diasDelMes[esBisiesto(fecha->anio)][fecha->mes-1];
            fecha->mes++;
        }
        else
        {
            fecha->dia -= diasDelMes[esBisiesto(fecha->anio)][fecha->mes-1];
            fecha->mes = 1;
            fecha->anio++;
        }
    }
}

void restarDias(Fecha* fecha, unsigned dias)
{
    int resta = dias;

    while(resta >= fecha->dia)
    {
        resta -= fecha->dia;

        if(fecha->mes == 1)
        {
            fecha->anio--;
            fecha->mes = 12;
        }
        else
        {fecha->mes--;}

        fecha->dia = diasDelMes[esBisiesto(fecha->anio)][fecha->mes-1];
    }

    fecha->dia -= resta;
}

int diasEntreFechas(Fecha fecha1, Fecha fecha2)
{
    Fecha fechaMenor, fechaMayor;
    int distancia = 0;

    // check what date entered is the minor

    // Difieren anios
    if(fecha1.anio < fecha2.anio)
    {
        fechaMenor = fecha1;
        fechaMayor = fecha2;
    }
    else if(fecha1.anio > fecha2.anio)
    {
        fechaMenor = fecha2;
        fechaMayor = fecha1;
    }
    else
    {
        // Difieren meses
        if(fecha1.mes < fecha2.mes)
        {
            fechaMenor = fecha1;
            fechaMayor = fecha2;
        }
        else if(fecha1.mes > fecha2.mes)
        {
            fechaMenor = fecha2;
            fechaMayor = fecha1;
        }
        else
        {
            // Difieren dias
            if(fecha1.mes < fecha2.mes)
            {
                fechaMenor = fecha1;
                fechaMayor = fecha2;
            }
            else if(fecha1.mes > fecha2.mes)
            {
                fechaMenor = fecha2;
                fechaMayor = fecha1;
            }
            else
            {return 0;}
        }
    }

    // Sumo anios
    while(fechaMenor.anio != fechaMayor.anio)
    {
        if(esBisiesto(fechaMenor.anio))
        {distancia += 366;}
        else
        {distancia += 365;}

        fechaMenor.anio++;
    }

    // Sumo/resto meses
    while(fechaMenor.mes != fechaMayor.mes)
    {
        if(fechaMenor.mes < fechaMayor.mes)
        {
            distancia += diasDelMes[esBisiesto(fechaMenor.anio)][fechaMenor.mes-1];
            fechaMenor.mes++;
        }
        else if(fechaMenor.mes > fechaMayor.mes)
        {
            //ya luego veremos...
            distancia -= diasDelMes[esBisiesto(fechaMenor.anio)][fechaMenor.mes-1];
            fechaMenor.mes--;
        }
    }

    // Sumo/resto dias
    while(fechaMenor.dia != fechaMayor.dia)
    {
        if(fechaMenor.dia < fechaMayor.dia)
        {
            distancia++;
            fechaMenor.dia++;
        }
        else if(fechaMenor.dia > fechaMayor.dia)
        {
            distancia--;
            fechaMenor.dia--;
        }
    }

    return distancia;
}

int diaDeSemana(Fecha fecha)
{
    int diferenciaInicioDeMes[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    fecha.anio -= fecha.mes < 3;
    return (fecha.anio + fecha.anio/4 - fecha.anio/100 + fecha.anio/400 + diferenciaInicioDeMes[fecha.mes-1] + fecha.dia) % 7;
}
