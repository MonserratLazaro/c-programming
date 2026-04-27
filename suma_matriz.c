#include <stdio.h>

int main() {
    int matriz[3][3], suma;

    // Ingresar elementos de la matriz
    printf("Ingrese los elementos de la matriz por filas:\n");
    for (int i = 0; i < 3; i++) {
        suma = 0; // Reiniciar la suma para cada fila
        for (int j = 0; j < 3; j++) {
            scanf("%d", &matriz[i][j]);
             // Sumar números de la matriz
            suma += matriz[i][j];
        }
         printf("La suma de los elementos de la fila %d es: %d\n", i + 1, suma);
    }
   
    return 0;
}