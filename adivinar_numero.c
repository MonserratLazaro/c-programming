#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_generado, num_ingresado, intentos = 5;
    bool adivinado = false;
    // Generar un número aleatorio
    srand(time(NULL));
    num_generado = rand() % 100 + 1;
    
    // Ciclo do-while para limitar los intentos
    do {
        printf("Adivina un número entre 1 y 100: ");
        scanf("%d", &num_ingresado);
        
        // Asegurarse que el número ingresado este dentro del rango
        if (num_ingresado < 1 || num_ingresado > 100) {
            printf("Número no válido.\n");
            continue;
        }
        
        // Determinar si el número ingresado es igual, mayor o menor que el número generado
        if (num_ingresado == num_generado) {
            adivinado = true;
            break;
        } else if (num_ingresado < num_generado) {
            printf("El número es mayor.\n");
        } else {
            printf("El número es menor.\n");
        }
        
        intentos--;
    } while (intentos > 0);
    
    // Condicional para mostrar un mensaje si se adivina el número o se alcanzan los 5 intentos según sea el caso
    if (adivinado) {
        printf("¡Felicidades! Adivinaste el número.\n");
    } else {
        printf("No te quedan más intentos. El número era %d.\n", num_generado);
    }
    
    return 0;
}