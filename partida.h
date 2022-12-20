#ifndef PARTIDA_H
#define PARTIDA_H

#include <stdio.h>
#include "palabras.h"
#include "teclado.h"
#include "casilla.h"

#define INTENTOS    6
#define LETRAS_ABECEDARIO   26

typedef struct {
    int intento;
    char palabra_correcta[NUM_LETRAS_PALABRA];
    t_casilla m[INTENTOS][NUM_LETRAS_PALABRA];
    t_casilla teclado[FILS][COLS];
} t_partida;

void inicializa_partida(t_partida * partida);
void imprimir_partida(t_partida partida);
void introduce_palabra(
    t_partida * partida,
    char palabra[NUM_LETRAS_PALABRA]);

int esta_ganada(t_partida partida);
int no_se_haya_acabado(t_partida partida);

#endif
