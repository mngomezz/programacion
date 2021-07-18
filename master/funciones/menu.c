#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include "menu.h"
#include "utiles.h"
#include "../TDA/DINAMICO/listasimple.h"
#include "cadenas.h"

void menu_title(char *titulo, int importancia)
{
    if (importancia == 1)
    {
        printf("\t********************* %s *********************\n", titulo);
    }
    else if (importancia == 2)
    {
        printf("\t************** %s **************\n", titulo);
    }
    else
    {
        printf("\t******* %s *******\n", titulo);
    }
}

int cmp_items(const void *item1, const void *item2)
{
    return ((t_item *)item1)->pos - ((t_item *)item2)->pos;
}

void menu_options(tda_lista *opciones)
{
    if (!(*opciones))
    {
        return;
    }

    printf("%d.%s\n", ((t_item *)(*opciones)->info)->pos,
           ((t_item *)(*opciones)->info)->desc);

    menu_options(&(*opciones)->siguiente);
    return;
}

char menu_getOption(t_menu *menu)
{
    cls();
    menu_title(menu->title, menu->importancia);
    menu_options(&(menu->opciones));
    printf("\nSeleccione una opcion, ESC para salir: ");
    fflush(stdin);

    return getc(stdin);
}

void menu_mostrar(t_menu *menu)
{
    char opt;
    t_item item;
    t_nodo **pItem;

    while (((opt = menu_getOption(menu)) != 27))
    {
        item.pos = opt - '0';
        pItem = lista_getNodo(&menu->opciones, &item, cmp_items);

        if (!pItem)
        {
            printf("\n Opcion no valida\n");
        }
        else
        {
            if (item.acc == NULL)
            {
                if (lista_contarNodos(&item.submenu.opciones) > 0)
                {
                    menu_mostrar(&item.submenu);
                }
            }
            else
            {
                item.acc(item.params);
                puts("Presione cualquier tecla para continuar");
                getchar();
            }
        }
    }
}

int menu_agregarOpcion(t_menu *menu, char *code, char *description, int(acc)(void *params), void *params)
{
    t_nodo **pItem;
    char *p;
    char *pf;
    char cc[20];
    t_item item;

    if (!(*code))
    {
        return 0;
    }

    strcpy(cc, code);

    // En caso de que sea opcion para submenu.
    p = strchr(cc, '.');
    if (!p)
    {
        p = strchr(cc, '\0');
        pf = p;
    }
    else
    {
        *p = '\0';
        pf = p + 1;
    }

    item.pos = atoi(cc);

    pItem = lista_getNodo(&(menu->opciones), &item, cmp_items);

    if (pItem)
    {
        menu_agregarOpcion(&((t_item *)(*pItem)->info)->submenu, pf,
                           description, acc, params);
    }
    else
    {
        strcpy(item.code, code);
        strcpy(item.desc, description);
        item.acc = acc;
        item.params = params;
        str_copy(item.submenu.title, "menu ");
        str_concat(item.submenu.title, description, sizeof(item.submenu.title));
        str_toUpper(item.submenu.title);

        item.submenu.importancia = menu->importancia - 1;
        lista_crear(&item.submenu.opciones);
        lista_agregarEnPosicion(&menu->opciones, item.pos - 1, &item,
                                sizeof(item));
    }

    return EXITO;
}
