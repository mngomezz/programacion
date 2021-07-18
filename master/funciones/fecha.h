#define ANIO_BASE 1601
#define ANIO_MAX 2500

typedef struct
{
    int dia, mes, anio;
} Fecha;

int esBisiesto(int);
int fechaValida(Fecha);
void diaSiguiente(Fecha*);
void sumarDias(Fecha*, unsigned);
void restarDias(Fecha*, unsigned);
int diasEntreFechas(Fecha, Fecha);
int diaDeSemana(Fecha);
