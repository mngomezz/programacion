#include <string.h>
#include "../include/Cuerdas.h"

Cuerdas::Cuerdas(const string &name, char scale)
    :Instrumento(name, scale)
{}

Cuerdas::~Cuerdas()
{}

char &Cuerdas::operator ++(int)
{
    this->escala=='G' ? this->escala-=6 : this->escala++;
    return this->escala ;
}

char &Cuerdas::operator ++()
{
    this->escala=='G' ? this->escala-=6 : this->escala++;
    return this->escala ;
}

char &Cuerdas::operator --(int)
{
    this->escala=='A' ? this->escala+=6 : this->escala--;
    return this->escala ;
}

char &Cuerdas::operator --()
{
    this->escala=='A' ? this->escala+=6 : this->escala--;
    return this->escala ;
}

string Cuerdas::getDetalles()const
{return "";}
