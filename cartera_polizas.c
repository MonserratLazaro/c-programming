#include <stdio.h>
#include <stdbool.h>

int main() {
    int polizas[5][4], primas = 0, riesgos = 0, region, umbral, i, j;
    bool seEncontro = false;
    
    // Leer los datos de las pólizas
    printf("Ingresa los datos de las pólizas (ID, región, prima, riesgo):\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 4; j++) {
            scanf("%d", &polizas[i][j]);
            // Sumar los valores de las primas y los riesgos de todas las pólizas
            if (j == 2) {
                primas += polizas[i][j];
            }
            if (j == 3){
                riesgos += polizas[i][j];
            }
        }
    }

    // Pedir la región y el umbral de riesgo
    printf("Ingrese la región a buscar: \n");
    scanf("%d", &region);
    printf("Ingrese el umbral de riesgo: \n");
    scanf("%d", &umbral);

    // Imprimir los totales de primas y riesgos
    printf("Total de primas: %d\n", primas);
    printf("Total de riesgos: %d\n", riesgos);

    // Determinar si hay alguna póliza con riesgo superior al umbral en la región solicitada
    for (i = 0; i < 5; i++) {
        if (polizas[i][1] == region && polizas[i][3] > umbral) {
            printf("Póliza con riesgo superior a %d encontrada en la región %d: ID %d\n", umbral, region, polizas[i][0]);
            seEncontro = true;
        }
    }

    if (!seEncontro) {
        printf("No se encontraron pólizas con riesgo superior a %d en la región %d\n", umbral, region);
    }

    return 0;
}