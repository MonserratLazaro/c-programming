#include <stdio.h>

int main() {
    int arreglo[10] = {0}, matriz[3][3], i, j;

    printf("Ingresa 9 números para llenar la matriz(0,9):\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }
    
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            arreglo[matriz[i][j]]++;
        }
    }

    printf("Frecuencia de los número en la matriz:\n");
    for (i = 0; i < 10; i++) {
        printf("Número %d: %d\n", i, arreglo[i]);
    }

    return 0;
}