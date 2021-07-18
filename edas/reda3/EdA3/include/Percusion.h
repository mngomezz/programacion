#ifndef PERCUSION_H_INCLUDED
#define PERCUSION_H_INCLUDED

#include "Instrumento.h"

class Percusion : public Instrumento
{
public:
    Percusion(const string &nombre, char escala='X');
    ~Percusion();
    char &operator ++(int);
    char &operator ++();
    char &operator --(int);
    char &operator --();
    string getDetalles()const;
};
#endif // PERCUSION_H_INCLUDED
