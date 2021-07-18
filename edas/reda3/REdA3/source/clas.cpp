#include "../include/clase.h"
#include "../include/DivisionPorCeroException.h"

int Racional::absoluto(int n)
{ return signo(n) ? -n : n; }

char Racional::signo(int n)
{ return n<0 ? '-' : '\0'; }

int Racional::mcd(int a, int b)
{
    try
    {
        if(b == 0)
        { throw DivisionPorCeroException(); }
    }
    catch(DivisionPorCeroException &cee)
    {
        cout << "Error - racional con denominador 0: " << cee.what();
        throw;
    }

    int resto = a%b;

    while(resto)
    {
        a = b;
        b = resto;
        resto = a%b;
    }

    return absoluto(b);
}

Racional::Racional(int nume, int deno)
{
    if(signo(deno))
    {
        nume = -nume;
        deno = -deno;
    }

    int divisor = mcd(nume, deno);

    if(divisor != 0)
    {
        this->nume = nume/divisor;
        this->deno = deno/divisor;
    }
    else
    {
        this->nume = nume;
        this->deno = deno;
    }

}

ostream &operator <<(ostream &salida, Racional racio)
{
    cout << racio.nume << '/' << racio.deno;
    return salida;
}

int Racional::getNumerador()
{ return nume; }

int Racional::getDenominador()
{ return deno; }

int Racional::enteroMasCercano()
{ return float(nume)/deno + 0.5; }

void Racional::aEnteroYFraccion(Racional r)
{
    int enteros = r.nume/r.deno;

    if(enteros != 0)
    { cout << enteros << " " << (r.nume-r.deno*enteros) << '/' << r.deno; }
    else
    { cout << enteros << " " << r.nume << '/' << r.deno; }

}

Racional Racional::operator++()
{
    nume += deno;
    return *this;
}

