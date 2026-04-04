#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <string.h>

// Definiciones Globales
#define TAM 5
#define MAX_TIROS 10

//Variables para el Ranking
char mejorJugador[50] = "";
int mejorPuntaje = 99;

//Prototipos de Funciones
void inicializarTablero(char t[TAM][TAM], int *fb, int *cb);
void mostrarTablero(char t[TAM][TAM], int mostrarBarco);

int realizarDisparo(char t[TAM][TAM], int fb, int cb);

int main() {
    char tablero[TAM][TAM];
    int barcoF, barcoC, opcion, tiros, gano;
    char nombreActual[50];

    srand(time(NULL)); //Semilla rand

    do {
        printf("\n=== TP1 INFORMATICA II - 2026 ===\n");
        printf("Record: %s con %d tiros\n", mejorJugador, mejorPuntaje);
        printf("1. Iniciar Partida\n2. Salir\nSeleccione: ");
        scanf("%d", &opcion);
		
        if (opcion == 1) {
            inicializarTablero(tablero, &barcoF, &barcoC);
            tiros = 0;
            gano = 0;
            while (tiros < MAX_TIROS && !gano) {
                mostrarTablero(tablero, 0);
                printf("Disparo %d/%d\n", tiros + 1, MAX_TIROS);
                if (realizarDisparo(tablero, barcoF, barcoC)) {
                    gano = 1;
                }
                tiros++;
            }
            // Fin del juego
            mostrarTablero(tablero, 1); // Mostrar barco
            if (gano) {
                printf("Treinta años navegando he visto ese tiro exactamente... una vez. Y era yo. Así que no te pongas muy cómodo, ¿entendiste? Le diste en %d cañonazos.\n", tiros);
                printf("Ingrese su nombre para el ranking: ");
                scanf("%s", nombreActual);
                if (tiros < mejorPuntaje) { // Record
                    mejorPuntaje = tiros;
                    strcpy(mejorJugador, nombreActual);
                }
            } else {
                printf("Está bien. Está bien. Bajá el cañón. Intentaremos insultarlos desde aquí con la voz, que parece que es lo único que podés apuntar. El barco estaba en (%d, %d)\n", barcoF, barcoC);
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
    printf("\n  0 1 2 3 4\n");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", i);
        for (int j = 0; j < TAM; j++) {
            printf("%c ", t[i][j]);
        }
        printf("\n");
    }
}

int realizarDisparo(char t[TAM][TAM], int fb, int cb) {
    int f, c;
    printf("Coordenadas (fila col): ");
    scanf("%d %d", &f, &c); // [cite: 24]

    if (f < 0 || f >= TAM || c < 0 || c >= TAM) {
        printf("Fuera del mapa. Pierdes el turno.\n");
        return 0;
    }
    if (t[f][c] == 'A') { // 
        printf("Ya disparaste aqui. Intenta de nuevo.\n");
        return 0; 
    }

    if (f == fb && c == cb) {
        t[f][c] = 'B'; // [cite: 16]
        return 1; // Acierto
    } else {
        t[f][c] = 'A'; // [cite: 16]
        printf("¡AGUA!\n");
        return 0; // Fallo
    }
}
