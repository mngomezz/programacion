#ifndef CAMBIOESCALAEXCEPTION_H_INCLUDED
#define CAMBIOESCALAEXCEPTION_H_INCLUDED

#include <iostream>
using namespace std;

class CambioEscalaException : public exception
{
public:
    virtual const char* what() const noexcept
    { return "No permite cambio de escala"; }
};
#endif // CAMBIOESCALAEXCEPTION_H_INCLUDED
