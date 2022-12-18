#ifndef TECLADO_H
#define TECLADO_H

#include <stdio.h>
#include "casilla.h"
#include "colores.h"

#define FILS    3
#define COLS    10
#define KEYS    "QWERTYUIOPASDFGHJKLZXCVBNM"

void inicializa_teclado(t_casilla teclado[FILS][COLS]);
void imprime_teclado(t_casilla teclado[FILS][COLS]);
void cambia_color_tecla(t_casilla teclado[FILS][COLS], int col, char car);
int get_color_tecla(t_casilla teclado[FILS][COLS], char car);

#endif
