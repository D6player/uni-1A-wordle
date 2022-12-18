#include "teclado.h"

const int cols[FILS] = {10, 9, 7};

void inicializa_teclado(t_casilla teclado[FILS][COLS]) {
	int i, j, n;

	for (i = 0, n = 0; i < FILS; i++) {
		for (j = 0; j < cols[i]; j++, n++) {
			inicializa_casilla(&teclado[i][j], KEYS[n]);
		}
	}

}

void imprime_teclado(t_casilla teclado[FILS][COLS]) {
	int i, j;

	printf_negrita_color();

	for (i = 0; i < FILS; i++) {
		for (j = 0; j < i; j++)
			printf(" ");

		for (j = 0; j < cols[i]; j++) {
			printf("[");
			imprime_casilla(teclado[i][j]);
			printf("]");
		}
		printf("\n");
	}
	printf("\n");

	printf_reset_color();

	return;
}

void cambia_color_tecla(t_casilla teclado[FILS][COLS], int col, char car) {
	int i, j;

	for (i = 0; i < FILS; i++) {
		for (j = 0; j < cols[i]; j++) {
			if (get_car(teclado[i][j]) == car) {
				set_col(&teclado[i][j], col);
				return;
			}
		}
	}

	return;
}

int get_color_tecla(t_casilla teclado[FILS][COLS], char car) {
	int i, j;

	for (i = 0; i < FILS; i++)
		for (j = 0; j < cols[i]; j++)
			if (get_car(teclado[i][j]) == car)
				return get_col(teclado[i][j]);
	
	return -1;
}
