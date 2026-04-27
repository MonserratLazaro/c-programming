#include <stdio.h>
#include <stdbool.h>

int main() {
    int numero_inicial, numero_final, total = 0, j;
    bool esPrimo;

    // Solicitar los límites del rango al usuario 
    printf("Introduce el número inicial del rango: \n");
    scanf("%d", &numero_inicial);
    printf("Introduce el número final del rango: \n");
    scanf("%d", &numero_final);

    printf("Los números primos en el rango son: \n");

    // Ciclo para iterar sobre todos los números en el rango
    for (int i = numero_inicial; i <= numero_final; i++) {
        // Comprobar que el número sea mayor que 1 (los números primos son mayores que 1)
        if (i <= 1) {
            continue;
        }

        j = 2;
        esPrimo = true;
        
        // Verificar si el número es primo
        while (j <= i/2) { 
            if (i % j == 0) { 
                esPrimo = false;
                break;
            }
            j++;
        }
        
        // Imprimir los números primos y contar el total de números
        if (esPrimo) {
            printf("%d ", i);
            total++; 
        }
    }

    // Mostrar el total de números primos en el rango
    printf("\nTotal de números primos: %d\n", total);

    return 0;
}