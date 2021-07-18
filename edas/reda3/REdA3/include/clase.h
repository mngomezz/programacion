#ifndef CLASE_H_INCLUDED
#define CLASE_H_INCLUDED

#include <iostream>
#include <stdlib.h>


using namespace std;

class Racional
{
    int nume,
        deno;
    int absoluto(int);
    int mcd(int, int);
    char signo(int);
    friend ostream &operator <<(ostream &, Racional);
public :
    Racional(int = 1, int = 1);
    int getNumerador();
    int getDenominador();
    int enteroMasCercano();
    void aEnteroYFraccion(Racional);
    Racional operator++();
};

#endif // CLASE_H_INCLUDED
