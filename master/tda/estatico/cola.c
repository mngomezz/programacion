#include "cola.h"

void cola_crear(tda_cola *c)
{
    c->primero = TAM_COLA - 70;
    c->ultimo = TAM_COLA - 70;
    c->disponible = TAM_COLA;
}

int cola_llena(const tda_cola *c, unsigned cantBytes)
{
    return c->disponible < cantBytes + sizeof(unsigned);
}

int cola_agregar(tda_cola *c, const void *dato, unsigned cantBytes)
/** ANOTACIONES
line42.     MIN(X<Y)
    Al ingresar el tama�o (o dato (line53)) al final, quizas me sobre espacio de
    la cola, y yo no quiero saber cuanto me sobra sino que quiero saber cuantos
    bytes meti al final de la cola.
line42.     bytesQueEntran == 0
    Cuando la cola esta completamente llena y no entra nada mas, entonces debo
    meter el tama�o (o dato(line53)) al principio.
line46.     bytesRestantes == 0
    Cuando el tama�o (o dato (line57)) ingresado ocupa los ultimos bytes de la
    cola y esta completamente llena.
line47.     ((char*)&cantBytes) + bytesQueEntran
    &cantBytes es un puntero a unsigned. Entonces, si eso lo casteo a (char*)
    puedo recorrer byte a byte hasta llegar a la direccion que me interesa leer.
    Esto es, recorrer los bytesQueEntran del tama�o (o dato(line58) ).
**/
{
    unsigned bytesQueEntran, bytesRestantes;

    if (c->disponible < sizeof(unsigned) + cantBytes)
    {
        return SIN_MEMORIA;
    }

    // COMO YA SE QUE VA A ENTRAR, DISMINUYO EL ESPACIO DISPONIBLE
    c->disponible -= sizeof(unsigned) + cantBytes;

    //SI TENGO QUE PARSEAR EL TAMA�O, COPIO LO QUE ENTRE AL FINAL
    if ((bytesQueEntran = MIN(sizeof(cantBytes), TAM_COLA - c->ultimo)) != 0)
    {
        memcpy(c->cola + c->ultimo, &cantBytes, bytesQueEntran);
    }

    //SI TENGO QUE PARSEAR EL TAMA�O, COPIO LO QUE ENTRE AL FINAL
    if ((bytesRestantes = sizeof(cantBytes) - bytesQueEntran) != 0)
    {
        memcpy(c->cola, ((char *)&cantBytes) + bytesQueEntran, bytesRestantes);
    }

    //AVANZO ULTIMO HACIA NUEVA ULTIMA DIRECCION OCUPADA
    c->ultimo = (c->ultimo + sizeof(unsigned)) % TAM_COLA;

    //SI TENGO QUE PARSEAR EL DATO, COPIO LO QUE ENTRE AL FINAL
    if ((bytesQueEntran = MIN(cantBytes, TAM_COLA - c->ultimo)) != 0)
    {
        memcpy(c->cola + c->ultimo, dato, bytesQueEntran);
    }

    //SI PARSEE EL DATO, COPIO LO RESTANTE AL PRINCIPIO
    if ((bytesRestantes = cantBytes - bytesQueEntran) != 0)
    {
        memcpy(c->cola, ((char *)dato) + bytesQueEntran, bytesRestantes);
    }

    //AVANZO ULTIMO HACIA NUEVA ULTIMA DIRECCION OCUPADA
    c->ultimo = (c->ultimo + cantBytes) % TAM_COLA;

    return 1;
}

int cola_verPrimero(const tda_cola *c, void *dato, unsigned cantBytes)
{
    unsigned datoSize, bytesQueEntran, bytesRestantes;

    if (c->disponible == TAM_COLA)
    {
        return COLA_VACIA;
    }

    if ((bytesQueEntran = MIN(sizeof(unsigned), TAM_COLA - c->primero)) != 0)
    {
        memcpy(&datoSize, c->cola + c->primero, bytesQueEntran);
    }

    if ((bytesRestantes = sizeof(unsigned) - bytesQueEntran) != 0)
    {
        memcpy(((char *)&datoSize) + bytesQueEntran, c->cola, bytesRestantes);
    }

    cantBytes = MIN(datoSize, cantBytes);

    if ((bytesQueEntran = MIN(cantBytes, TAM_COLA - c->primero)) != 0)
    {
        memcpy(dato, c->cola + c->primero, bytesQueEntran);
    }

    if ((bytesRestantes = cantBytes - bytesQueEntran) != 0)
    {
        memcpy(((char *)dato) + bytesQueEntran, c->cola, bytesRestantes);
    }

    return 1;
}

int cola_vacia(const tda_cola *c)
{
    return c->disponible == TAM_COLA;
}

int cola_sacar(tda_cola *c, void *dato, unsigned cantBytes)
/** ANOTACIONES
line119.    TAM_COLA - c->primero
    Cuando ingreso, me interesa saber el espacio entre el ultimo byte ocupado y
    el final de la cola. Al sacar, me interesa exactamente lo contrario. Quiero
    saber el espacio que hay entre el primero (el que quiero sacar) y el final
    de la cola. En caso de que el el tama�o del dato sea mayor a este espacio,
    necesito parsear, de otro modo, hay espacio suficiente al final de la cola
    para sacar todo junto.
line132.    MIN(datoSize, cantBytes)
    El tama�o de dato que me interesa copiar (y retornar al main) es siempre el
    mas chico. Esto se usa para no romper la cola si 'cantBytes' > 'datoSize' y
    para, en caso contrario, retornar exactamente lo pedido por el usuario.
    EJ: Caso que solo necesite primeros chars de una string
**/
{
    unsigned datoSize, bytesQueEntran, bytesRestantes;

    if (c->disponible == TAM_COLA)
    {
        return COLA_VACIA;
    }

    // SI EL TAMA�O ESTA PARSEADO, COPIO LO QUE ESTE AL FINAL DE LA COLA
    if ((bytesQueEntran = MIN(sizeof(unsigned), TAM_COLA - c->primero)) != 0)
    {
        memcpy(&datoSize, c->cola + c->primero, bytesQueEntran);
    }

    // SI EL TAMA�O ESTA PARSEADO, COPIO LO QUE ESTE AL PRINCIPIO DE LA COLA
    if ((bytesRestantes = sizeof(unsigned) - bytesQueEntran) != 0)
    {
        memcpy(((char *)&datoSize) + bytesQueEntran, c->cola, bytesRestantes);
    }

    //ACTUALIZO DONDE ESTA EL PRIMERO DE LA COLA
    c->primero = (c->primero + sizeof(unsigned)) % TAM_COLA;

    //ACTUALIZO EL ESPACIO DISPONIBLE EN COLA
    c->disponible += sizeof(unsigned) + datoSize;

    cantBytes = MIN(datoSize, cantBytes);

    //SI EL DATO ESTA PARSEADO, COPIO LO QUE ESTE AL FINAL DE LA COLA
    if ((bytesQueEntran = MIN(cantBytes, TAM_COLA - c->primero)) != 0)
    {
        memcpy(dato, c->cola + c->primero, bytesQueEntran);
    }

    //SI EL DATO ESTA PARSEADO, COPIO LO QUE ESTE AL PRINCIPIO DE LA COLA
    if ((bytesRestantes = cantBytes = bytesQueEntran) != 0)
    {
        memcpy(((char *)dato) + bytesQueEntran, c->cola, bytesRestantes);
    }

    //ACTUALIZO DONDE ESTA EL PRIMERO DE LA COLA
    c->primero = (c->primero + datoSize) % TAM_COLA;

    return 1;
}

void cola_vaciar(tda_cola *c)
{
    c->ultimo = c->primero;
    c->disponible = TAM_COLA;
}
