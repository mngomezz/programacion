#ifndef CUERDAS_H_INCLUDED
#define CUERDAS_H_INCLUDED

#include "Instrumento.h"

class Cuerdas : public Instrumento
{
public:
    Cuerdas(const string &nombre, char escala);
    ~Cuerdas();
    char &operator ++(int);
    char &operator ++();
    char &operator --(int);
    char &operator --();
    string getDetalles()const;
};
#endif // CUERDAS_H_INCLUDED
