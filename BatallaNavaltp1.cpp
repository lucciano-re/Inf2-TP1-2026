#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <string.h>

//definiciones
#define TAM 2
#define MAX_TIROS 100

//variables del ranking
char mejorJugador[50] = "Lucho";
int mejorPuntaje = 99;

//definicion
void inicializarTablero(char t[TAM][TAM], int *fb, int *cb);
void mostrarTablero(char t[TAM][TAM], int mostrarBarco);
 
int realizarDisparo(char t[TAM][TAM], int fb, int cb);
int validarDisparo(char t[TAM][TAM]);

int main() {
    char tablero[TAM][TAM];
    int barcoF, barcoC, opcion, tiros, gano;
    char nombreActual[50];
	int resultado;

    srand(time(NULL)); //Semilla rand

    do {  
        printf("\n=== TP1 INFORMATICA II - 2026 ===\n");
		
		if (mejorPuntaje < 20)printf("Record: %s con %d tiros\n", mejorJugador, mejorPuntaje);
		
        printf("1. Iniciar Partida\n2. Salir\nSeleccione: ");
        scanf("%d", &opcion);
		
        if (opcion == 1) {
            inicializarTablero(tablero, &barcoF, &barcoC);
            tiros = 0;
            gano = 0;
			while (tiros < MAX_TIROS && !gano) {
				mostrarTablero(tablero, 0);
				printf("Disparo actual: %d/%d\n", tiros + 1, MAX_TIROS);
				resultado = realizarDisparo(tablero, barcoF, barcoC);
				if (resultado != -1) {
					// Checkeo validez
					if (resultado == 1) gano = 1;
					tiros++; 
				}
				// Aprovechar el -1
			}
            // Fin del juego
            mostrarTablero(tablero, 1); // Mostrar barco
            if (gano) {
                printf("Treinta anos navegando he visto ese tiro exactamente... una vez. Y era yo. Asi que no te pongas muy comodo, entendiste? Le diste en %d canonazos.\n", tiros);
                printf("Dime tu nombre muchacho, esto debe ser recordado: ");
                scanf("%s", nombreActual);
                if (tiros < mejorPuntaje) { // Record
                    mejorPuntaje = tiros;
                    strcpy(mejorJugador, nombreActual);
                }
            } else {
                printf("Esta bien. Esta bien. Baja el canon. Intentaremos insultarlos desde aqui con la voz, que parece que es lo unico que puedes apuntar. El barco estaba en (%d, %d)\n", barcoF, barcoC);
            }
        }
    } while (opcion != 2);

    return 0;
}

//Funciones
void inicializarTablero(char t[TAM][TAM], int *fb, int *cb) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) t[i][j] = '.'; //Llenar
    }
    *fb = rand() % TAM;
    *cb = rand() % TAM;
}

void mostrarTablero(char t[TAM][TAM], int mostrarBarco) {
    printf("   ");
    for (int i = 0; i < TAM; i++) {
        printf("%2d ", i);
    }
    printf("\n");
    for (int i = 0; i < TAM; i++) {
        printf("%2d ", i);
        for (int j = 0; j < TAM; j++) {
            printf(" %c ", t[i][j]);
        }
        printf("\n");
    }
}


int realizarDisparo(char t[TAM][TAM], int fb, int cb) {
    int f, c;
    printf("Coordenadas: ");
    printf("\nFila: ");
    scanf("%d", &f);
    printf("Columna: ");
    scanf("%d", &c);

    // Validar tablero
    if (f < 0 || f >= TAM || c < 0 || c >= TAM) {
        printf("\nTecnicamente... no fallaste. Para fallar, la bala tiene que haber tenido alguna posibilidad de dar. Lo tuyo fue otra cosa. Lo tuyo fue... arte.\n");
        return -1; // -1 para decir invalido
    }

    // Validar repetido
    if (t[f][c] == 'A' || t[f][c] == 'B') { 
        printf("Ya has disparado ahi, y ya has fallado ahi! Te perdonare la bala por esta vez recluta.\n");
        return -1; // same
    }

    // 3. Procesar el disparo
    if (f == fb && c == cb) {
        t[f][c] = 'B'; 
        return 1; // Barco
    } else {
        t[f][c] = 'A'; 
        printf("\nAGUA!\n");
        return 0; // Agua
    }
}
