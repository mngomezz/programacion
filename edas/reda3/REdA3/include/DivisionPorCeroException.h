#ifndef DIVISIONPORCEROEXCEPTION_H_INCLUDED
#define DIVISIONPORCEROEXCEPTION_H_INCLUDED

#include <iostream>
using namespace std;

class DivisionPorCeroException : public exception
{
public:
    virtual const char* what() const noexcept
    { return "No se puede dividir por 0"; }
};

#endif // DIVISIONPORCEROEXCEPTION_H_INCLUDED
