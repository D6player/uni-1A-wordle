#include "partida.h"

void inicializa_partida(t_partida * partida, char palabra_correcta[NUM_LETRAS_PALABRA]) {
    int i, j;

    partida->intento = 0;

    for (i = 0; i < NUM_LETRAS_PALABRA; i++)
        partida->palabra_correcta[i] = palabra_correcta[i];

    for (i = 0; i < INTENTOS; i++)
        for (j = 0; j < NUM_LETRAS_PALABRA; j++)
            inicializa_casilla(&partida->m[i][j], ' ');

    inicializa_teclado(partida->teclado);

    return;
}

void imprimir_partida(t_partida partida) {
    int i, j;

    printf_negrita_color();
    for (i = 0; i < INTENTOS; i++) {
        printf("\t+-+-+-+-+-+\n\t");
        for (j = 0; j < NUM_LETRAS_PALABRA; j++) {
            printf("|");
            imprime_casilla(partida.m[i][j]);
        }
        printf("|\n");
    }
    printf("\t+-+-+-+-+-+\n\n\n");
    printf_reset_color();

    imprime_teclado(partida.teclado);

    return;
}

void introduce_letra(
    t_partida * partida,
    char car,
    int col,
    int i
) {
    set_car(&partida->m[partida->intento][i], car);
    set_col(&partida->m[partida->intento][i], col);
    int col_aux = get_color_tecla(partida->teclado, car);
    if (col < col_aux || col_aux == COLOR_DEFAULT)
        cambia_color_tecla(partida->teclado, col, car);

    return;
}

void introduce_palabra(
    t_partida * partida,
    char palabra[NUM_LETRAS_PALABRA]
) {
    int i, col, *slot, cuenta[LETRAS_ABECEDARIO];
    char car, *solucion;

    solucion = partida->palabra_correcta;

    for (i = 0; i < LETRAS_ABECEDARIO; i++)
        cuenta[i] = 0;

    // Se cuentan las letras no verdes en el contador `cuenta`
    for (i = 0; i < NUM_LETRAS_PALABRA; i++)
        if (palabra[i] != solucion[i])
            cuenta[solucion[i] - 'A']++;

    // Se asigna el color a cada letra
    for (i = 0; i < NUM_LETRAS_PALABRA; i++) {
        // Constantes, hacen el codigo mas legible
        car = palabra[i];
        slot = &cuenta[car - 'A'];

        // Dos tridentes encadenados:
        // Si la letra esta en la posicion correcta -> color verde
        // Si la letra NO esta en la posicion -> se decrementa el
        // contador (operador coma) y se devuelve color amarillo
        // En otro caso -> color gris
        col = (car == solucion[i]) ? COLOR_LETRA_Y_POSICION_OK :
              ((*slot) > 0) ? ((*slot)--, COLOR_LETRA_OK) :
              COLOR_LETRA_KO;

        introduce_letra(partida, car, col, i);
    }

    partida->intento++;

    return;
}

int esta_ganada(t_partida partida) {
    int i;

    for (i = 0; i < NUM_LETRAS_PALABRA; i++)
        if (get_col(partida.m[partida.intento-1][i]) != COLOR_LETRA_Y_POSICION_OK)
            return FALSE;
    
    return TRUE;
}

int no_se_haya_acabado(t_partida partida) {
    return !(esta_ganada(partida) || partida.intento >= INTENTOS);
}
