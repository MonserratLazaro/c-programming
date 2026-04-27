#include <stdio.h>

int main() {
    int elementos[3][3], suma = 0, i, j;

    printf("Ingresa los números de la matriz 3x3:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &elementos[i][j]);
        }
    }
    
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            suma += elementos[i][j];
        }
    }

    printf("La suma de los elementos es: %d\n", suma);

    return 0;
}