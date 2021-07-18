#ifndef VIENTOS_H_INCLUDED
#define VIENTOS_H_INCLUDED

#include "Instrumento.h"

class Vientos : public Instrumento
{
private:
    string material;
public:
    Vientos(const string &nombre, char escala, const string &material);
    ~Vientos();
    char &operator ++(int);
    char &operator ++();
    char &operator --(int);
    char &operator --();
    string getDetalles()const;
};
#endif // VIENTOS_H_INCLUDED
