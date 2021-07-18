#ifndef INSTRUMENTO_H_INCLUDED
#define INSTRUMENTO_H_INCLUDED

#include <string>

using namespace std;

class Instrumento
{
private:
    string nombre;
protected:
    char escala;
public:
    Instrumento(const string &nombre, char escala = 'X');
    virtual ~Instrumento() = default;

    // solo para clases hijas
    virtual string getDetalles()const = 0;
    virtual char &operator ++(int)    = 0;
    virtual char &operator ++()       = 0;
    virtual char &operator --(int)    = 0;
    virtual char &operator --()       = 0;

    string getNombre()const;
    char getEscala()const;
};
#endif // INSTRUMENTO_H_INCLUDED
