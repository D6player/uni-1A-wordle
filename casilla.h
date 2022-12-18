#ifndef CASILLA_H
#define CASILLA_H

#include <stdio.h>
#include "colores.h"

typedef struct {
    char car;
    int col;
} t_casilla;

void inicializa_casilla(t_casilla * casilla, char car);
void imprime_casilla(t_casilla casilla);
void set_car(t_casilla * casilla, char car);
void set_col(t_casilla * casilla, int col);
char get_car(t_casilla casilla);
int get_col(t_casilla casilla);

#endif
