#include <string.h>
#include "../include/Percusion.h"
#include "../include/CambioEscalaException.h"

Percusion::Percusion(const string &nombre, char escala)
    :Instrumento(nombre, escala)
{}

Percusion::~Percusion()
{}

char &Percusion::operator ++(int)
{ throw CambioEscalaException(); }

char &Percusion::operator ++()
{ throw CambioEscalaException(); }

char &Percusion::operator --(int)
{ throw CambioEscalaException(); }

char &Percusion::operator --()
{ throw CambioEscalaException(); }

string Percusion::getDetalles()const
{return "";}
