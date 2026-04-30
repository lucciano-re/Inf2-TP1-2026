#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void generar_nombre_aleatorio(char *nombre_generado, int tamano) {
    const char *nombres[] = {
        "Juan", "Mario", "Luigi", "Ana", "Lucas", 
        "Coti", "Pedro", "Sofia", "Diego", "Lucio"
    };
    
    const char *apellidos[] = {
        "Garcia", "Lopez", "Martinez", "Rodriguez", "Fernandez", 
        "Perez", "Gomez", "Sanchez", "Diaz", "Romero"
    };

    int cantidad_nombres = sizeof(nombres) / sizeof(nombres[0]);
    int cantidad_apellidos = sizeof(apellidos) / sizeof(apellidos[0]);

    int indice_nombre = rand() % cantidad_nombres;
    int indice_apellido = rand() % cantidad_apellidos;

    snprintf(nombre_generado, tamano, "%s %s", nombres[indice_nombre], apellidos[indice_apellido]);
}

int main() {
    srand(time(NULL));

    char nombre[50];
 
    int cantidad_a_generar = 5;

    printf("Generando %d nombres aleatorios:\n", cantidad_a_generar);
    printf("--------------------------------\n");

    for (int i = 0; i < cantidad_a_generar; i++) {
        generar_nombre_aleatorio(nombre, sizeof(nombre));
        printf("%d. %s\n", i + 1, nombre);
    }

    return 0;
}
