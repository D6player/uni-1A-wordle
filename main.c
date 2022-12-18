#include <stdio.h>
#include "palabras.h"
#include "partida.h"

char hacer_mayuscula(char car);

int main() {
	t_partida partida;
	int i, idioma;
	char palabra_correcta[NUM_LETRAS_PALABRA],
		 palabra[NUM_LETRAS_PALABRA],
		 car;
	
	printf("WORDLE:\n\n");

	// Guardar idioma usuario
	do {
		printf("Seleccione el idioma de las palabras:\n");
		for (i = 0; i < NUM_IDIOMAS; i++) {
			printf("%d) ", i);
			imprimir_nombre_idioma(i);
			printf(" (%d palabras)\n", contar_palabras(i));
		}
		printf("\nIntro opción: ");

		scanf("%d%*c", &idioma);
	} while (!(0 <= idioma && idioma < NUM_IDIOMAS));

	// Inicializar partida
	inicializar_azar();
	palabra_al_azar(idioma, contar_palabras(idioma), palabra_correcta);

	inicializa_partida(&partida, palabra_correcta);

	// While principal del juego,  se acaba cuando se acaben los intentos 
	// o se gane la partida.
	do {
		imprimir_partida(partida);

		// Guardar palabra usuario, loop hasta que sea valida
		while (TRUE) {
			printf("Intruoduce palabra: ");

			i = 0;
			do {
				scanf("%c", &car);
				if (i < NUM_LETRAS_PALABRA)
					palabra[i] = hacer_mayuscula(car);

				i++;
			} while (car != '\n');

			if (es_palabra_correcta(idioma, palabra) && i == (NUM_LETRAS_PALABRA + 1))
				break;
			else
				printf("Palabra incorrecta. ");
		}

		// Guardar palabra en la partida
		introduce_palabra(&partida, palabra);

	} while(no_se_haya_acabado(partida));

	// Prints finales
	if (esta_ganada(partida))
		printf("Bien hechoooo!!!\n");
	else {
		printf("La palabra era: ");
		for (i = 0; i < NUM_LETRAS_PALABRA; i++)
			printf("%c", palabra_correcta[i]);
		printf("\n");
	}
	
	imprimir_partida(partida);

	return 0;
}

char hacer_mayuscula(char car) {
	if ('a' <= car && car <= 'z')
		return car + ( 'A' - 'a' );
	return car;
}
