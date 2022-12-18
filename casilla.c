#include "casilla.h"

void inicializa_casilla(t_casilla * casilla, char car) {
    casilla->car = car;
    casilla->col = COLOR_DEFAULT;

    return;
}

void imprime_casilla(t_casilla casilla) {
    if (casilla.col == COLOR_DEFAULT)
        printf_reset_color();

    printf_bgcolor(casilla.col);
    printf("%c", casilla.car);

    printf_negrita_color();

    return;
}

void set_car(t_casilla * casilla, char car) {
    casilla->car = car;
    return;
}

void set_col(t_casilla * casilla, int col) {
    casilla->col = col;
    return;
}

char get_car(t_casilla casilla) {
    return casilla.car;
}

int get_col(t_casilla casilla) {
    return casilla.col;
}
