#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "../tda/dinamico/listasimple.h"

typedef struct s_menu
{
    char title[30];
    int importancia; // INDICA SI ES SUBMENU DE OTRO MENU
    tda_lista opciones;
} t_menu;

typedef struct s_item
{
    unsigned pos;
    char code[10];
    char desc[24];
    int (*acc)(void *params);
    void *params;
    t_menu submenu;
} t_item;

void menu_mostrar(t_menu *menu);
int menu_agregarOpcion(t_menu *menu, char *code, char *description,
                       int(acc)(void *params), void *params);

//char menu_getOption(t_menu* menu);
//void menu_options(tda_lista* opciones);
//void menu_title(char* titulo, int importancia);
//int cmp_items(const void* item1, const void* item2);

#endif // MENU_H_INCLUDED
