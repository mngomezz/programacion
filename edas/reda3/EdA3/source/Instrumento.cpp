#include "../include/Instrumento.h"

Instrumento::Instrumento(const string &nombre, char escala)
    :nombre(nombre), escala(escala)
{}

string Instrumento::getNombre()const
{ return this->nombre; }

char Instrumento::getEscala()const
{ return this->escala; }
