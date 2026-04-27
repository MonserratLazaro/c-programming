#include <stdio.h>

int calcularSuma(int [], int);

int main() {
    int enteros[5], resultado;

    printf("Ingresa 5 números: \n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &enteros[i]);
    }

    resultado = calcularSuma(enteros, 5);

    printf("La suma de los números es: %d\n", resultado);

    return 0;
}

int calcularSuma(int arreglo[], int t) {
    int suma = 0;
    for (int i = 0; i < t; i++) {
        suma += arreglo[i];
    }

    return suma;
}
