#include "utiles.h"
#include "cadenas.h"

#define SON_IGUALES 0

void swapVal(void *dato1, void *dato2, size_t datasize)
{
    char aux;

    while (datasize--)
    {
        aux = *(char *)dato1;
        *(char *)dato1 = *(char *)dato2;
        *(char *)dato2 = aux;
        dato1++;
        dato2++;
    }
}

void cls()
{
    //system("cls");
    system("clear");
}

/** FUNCIONES PARA IMPRIMIR GENERICAS **/
void print_int(unsigned formato, const void *entero)
{
    printf("%*d\t", formato, *(int *)entero);
}

void print_char(unsigned formato, const void *caracter)
{
    printf("%*c", formato, *(char *)caracter);
}

void print_float(unsigned formato, const void *flotante)
{
    printf("%*.2f", formato, *(float *)flotante);
}

void print_empleado(const void *emp)
{
    printf("%-3u\t%-20s\t%-3u\t$%-10.2f\n",
           ((t_empleado *)emp)->id, ((t_empleado *)emp)->nombre,
           ((t_empleado *)emp)->edad, ((t_empleado *)emp)->salario);
}

void print_alumno(const void *alu)
{
    printf("%-3u\t%-20s\tEDAD:%-3d\t%-5.2f\t%c\n",
           ((t_alumno *)alu)->dni, ((t_alumno *)alu)->nombre,
           ((t_alumno *)alu)->edad, ((t_alumno *)alu)->promedio,
           ((t_alumno *)alu)->sexo);
}

void print_producto(const void *prod)
{
    fprintf(stdout, "#%-3d\t%3du\t$%.2f\n", ((t_producto *)prod)->id,
            ((t_producto *)prod)->cantidad, ((t_producto *)prod)->precio);
}

/** FUNCIONES PARA COMPARAR GENERICAS **/
int cmp_int(const void *entero1, const void *entero2)
{
    return *(int *)entero1 - *(int *)entero2;
}

int cmp_float(const void *flotante1, const void *flotante2)
{
    return *(float *)flotante1 - *(float *)flotante2;
}

int cmp_char(const void *caracter1, const void *caracter2)
{
    return *(char *)caracter1 - *(char *)caracter2;
}

int cmp_string(const void *cadena1, const void *cadena2)
{
    return str_compare((char *)cadena1, (char *)cadena2);
}

int cmp_alumno(const void *alumno1, const void *alumno2)
{
    t_alumno al1 = *(t_alumno *)alumno1,
             al2 = *(t_alumno *)alumno2;

    return (al1.dni - al2.dni) ? al1.dni - al2.dni : (strcmp(al1.nombre, al2.nombre)) ? strcmp(al1.nombre, al2.nombre)
                                                 : (al1.edad - al2.edad)              ? al1.edad - al2.edad
                                                 : (al1.promedio - al2.promedio)      ? al1.promedio - al2.promedio
                                                                                      : SON_IGUALES;
}

int cmp_empleado(const void *empleado1, const void *empleado2)
{
    t_empleado em1 = *(t_empleado *)empleado1,
               em2 = *(t_empleado *)empleado2;

    return (em1.id - em2.id) ? em1.id - em2.id : (strcmp(em1.nombre, em2.nombre)) ? strcmp(em1.nombre, em2.nombre)
                                             : (em1.edad - em2.edad)              ? em1.edad - em2.edad
                                             : (em1.salario - em2.salario)        ? em1.salario - em2.salario
                                                                                  : SON_IGUALES;
}

int cmp_cliente(const void *cliente1, const void *cliente2)
{
    t_cliente cl1 = *(t_cliente *)cliente1,
              cl2 = *(t_cliente *)cliente2;

    return (cl1.dni - cl2.dni) ? cl1.dni - cl2.dni : (strcmp(cl1.nombre, cl2.nombre)) ? strcmp(cl1.nombre, cl2.nombre)
                                                 : (cl1.saldo - cl2.saldo)            ? cl1.saldo - cl2.saldo
                                                                                      : SON_IGUALES;
}

int cmp_producto(const void *producto1, const void *producto2)
{
    t_producto pr1 = *(t_producto *)producto1,
               pr2 = *(t_producto *)producto2;

    return (pr1.id - pr2.id) ? pr1.id - pr2.id : (pr1.precio - pr2.precio)   ? pr1.precio - pr2.precio
                                             : (pr1.cantidad - pr2.cantidad) ? pr1.cantidad - pr2.cantidad
                                                                             : SON_IGUALES;
}

/** FUNCIONES ESPECIFICAS **/

char *parse_data_alumno(char *cad)
{
    char *pc = strrchr(cad, '|');

    if (!pc)
    {
        return NULL;
    }

    *pc = 0;
    return ++pc;
}

int cargarAlumno(char *cadena, t_alumno *alu1)
{
    char *pChar = (char *)cadena;
    pChar = parse_data_alumno(pChar);
    alu1->sexo = *(pChar);
    pChar = parse_data_alumno(cadena);
    sscanf(pChar, "%f", &alu1->promedio);
    pChar = parse_data_alumno(cadena);
    sscanf(pChar, "%d", &alu1->edad);
    pChar = parse_data_alumno(cadena);
    strcpy(alu1->nombre, pChar);
    sscanf(cadena, "%d", &alu1->dni);
    return 1;
}

int cargarAlumno2(char *cadena, t_alumno *alu1)
{
    char *pc = cadena + (strlen(cadena) - 2);
    alu1->sexo = *pc;
    *pc = 0;
    pc -= 5;
    sscanf(pc, "%f", &(alu1->promedio));
    *pc = 0;
    pc -= 3;
    sscanf(pc, "%u", &(alu1->edad));
    *pc = 0;
    pc -= 30;
    strcpy(alu1->nombre, pc);
    *pc = 0;
    pc -= 3;
    sscanf(pc, "%u", &(alu1->dni));
    return 1;
}

int filtro_producto(const void *info)
{
    return ((t_producto *)info)->cantidad > 50;
}

void acumulo_producto(const void *prod, void *acum)
{
    *(float *)acum += ((t_producto *)prod)->precio * ((t_producto *)prod)->cantidad;
}
