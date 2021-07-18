#include "../include/Vientos.h"

Vientos::Vientos(const string &name, char scale, const string &material)
    :Instrumento(name, scale), material(material)
{}

Vientos::~Vientos()
{}

char &Vientos::operator ++(int)
{
    this->escala=='G' ? this->escala-=6 : this->escala++;
    return this->escala ;
}

char &Vientos::operator ++()
{
    this->escala=='G' ? this->escala-=6 : this->escala++;
    return this->escala ;
}

char &Vientos::operator --()
{
    this->escala=='A' ? this->escala+=6 : this->escala--;
    return this->escala ;
}

char &Vientos::operator --(int)
{
    this->escala=='A' ? this->escala+=6 : this->escala--;
    return this->escala ;
}

string Vientos::getDetalles()const
{
    return "material:" + this->material;
}
