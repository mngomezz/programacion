#include "main.h"

int main()
{
    /*
        int nro, i, nros[] = {100, 50, 75, 25, 150, 175, 125};
        tda_arbol arbol;

        arbol_crear(&arbol);

        for(i=0; i < sizeof(nros)/sizeof(int); i++)
        { arbol_ingresar(&arbol, &nros[i], sizeof(int), cmp_int); }


        char* opciones[] =
        {
            "Recorrer arbol en preorden",
            "Recorrer arbol en inorden",
            "Recorrer arbol en postorden",
            "Mostrar arbol",
            "Chequear cantidad de nodos",
            "Chequear altura del arbol",
            "Chequear si el arbol esta completo",
            "Chequear si el arbol es AVL",
            "Chequear si el arbol esta balanceado",
            "Buscar elemento en arbol",
            "Vaciar el arbol"
        };

        switch(menu(opciones, 10))
        {
            case 'a':
            {
                printf("Recorrido preorden:\n");
                arbol_preorden(&arbol, print_int);
                break;
            }
            case 'b':
            {
                printf("Recorrido inorden:\n");
                arbol_inorden(&arbol, print_int);
                break;
            }
            case 'c':
            {
                printf("Recorrido postorden:\n");
                arbol_postorden(&arbol, print_int);
                break;
            }
            case 'd':
            {
                arbol_mostrar(&arbol, 1, print_int);
                break;
            }
            case 'e':
            {
                printf("\nEl arbol tiene %u nodos", arbol_cantNodos(&arbol));
                break;
            }
            case 'f':
            {
                printf("\nLa altura del arbol es %u", arbol_altura(&arbol));
                break;
            }
            case 'g':
            {
                printf("\nEl arbol %s completo",
                       arbol_esCompleto(&arbol) ? "esta" : "no esta");
                break;
            }
            case 'h':
            {
                printf("\nEl arbol %s AVL", arbol_esAVL(&arbol) ? "es":"no es");
                break;
            }
            case 'i':
            {
                printf("\nEl arbol %s balanceado",
                       arbol_esBalanceado(&arbol) ? "esta" : "no esta");
                break;
            }
            case 'j':
            {
                printf("\nEl arbol se vacio. Cantidad de nodos eliminados: %d",
                       arbol_vaciar(&arbol));
                break;
            }
            case 'k':
            {
                printf("\nElemento%s encontrado",
                       arbol_buscar(&arbol, &nro, sizeof(nro), cmp_int) ? " " : " no");
                break;
            }
            default:
            {
                printf("\nSaliendo del programa...\n");
            }
        }

        printf("\n\nFin del programa.\n");
    */

    t_menu menu;

    lista_crear(&menu.opciones);
    menu.importancia = 1;
    strcpy(menu.title, "MENU PRINCIPAL");

    menu_agregarOpcion(&menu, "1", "Ejercicios", NULL, NULL);
    menu_agregarOpcion(&menu, "1.1", "Factorial", NULL, NULL);
    menu_agregarOpcion(&menu, "1.2", "Fibonacci", NULL, NULL);
    menu_agregarOpcion(&menu, "1.3", "Palindromo", NULL, NULL);

    menu_agregarOpcion(&menu, "2", "Cadenas", NULL, NULL);
    menu_agregarOpcion(&menu, "2.1", "Ocurrencias", NULL, NULL);
    menu_agregarOpcion(&menu, "2.2", "Normalizar", NULL, NULL);
    menu_agregarOpcion(&menu, "2.3", "Desplazar N veces", NULL, NULL);

    menu_agregarOpcion(&menu, "3", "Vectores", NULL, NULL);
    menu_agregarOpcion(&menu, "3.1", "Eliminar primero", NULL, NULL);
    menu_agregarOpcion(&menu, "3.2", "Eliminar ultimo", NULL, NULL);
    menu_agregarOpcion(&menu, "3.3", "Ordenar", NULL, NULL);

    menu_agregarOpcion(&menu, "4", "Matrices", NULL, NULL);
    menu_agregarOpcion(&menu, "4.1", "Calcular simetria", NULL, NULL);
    menu_agregarOpcion(&menu, "4.2", "Recorrer en espiral", NULL, NULL);
    menu_agregarOpcion(&menu, "4.3", "Rotar 180 grados", NULL, NULL);

    menu_agregarOpcion(&menu, "5", "Archivos", NULL, NULL);
    menu_agregarOpcion(&menu, "5.1", "Crear archivo", NULL, NULL);
    menu_agregarOpcion(&menu, "5.2", "Cerrar archivo", NULL, NULL);
    menu_agregarOpcion(&menu, "5.3", "Calcular tamanio", NULL, NULL);

    menu_agregarOpcion(&menu, "6", "Arboles", NULL, NULL);
    menu_agregarOpcion(&menu, "6.1", "Mostrar", NULL, NULL);
    menu_agregarOpcion(&menu, "6.2", "Recorrer inorden", NULL, NULL);
    menu_agregarOpcion(&menu, "6.3", "Recorrer preorden", NULL, NULL);
    menu_agregarOpcion(&menu, "6.4", "Recorrer postorden", NULL, NULL);

    menu_mostrar(&menu);

    return 0;
}
//    t_producto prods[10] =
//    {
//        {1, 50, 5.50},
//        {5, 10, 100},
//        {23, 45, 1000},
//        {11, 75, 25.50},
//        {53, 20, 1100},
//        {6, 105, 5.50},
//        {9, 101, 100},
//        {43, 45, 1000},
//        {12, 225, 25.50},
//        {77, 110, 1100}
//    }, productoNuevo = {9, 101, 100};
