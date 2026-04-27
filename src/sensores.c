#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); //reloj de la computadora, s de seed/semilla, nuevos valores aleatorios a cada ejecución
    float temperaturas[8], maxima, minima, promedio = 0, num_alea; 
    const float valor_critico = 55;
    int contador = 0, i = 0;
    bool estable = true;

    while (i < 8)
    {
        num_alea = 40 + (float)rand() / (RAND_MAX) * (60 - 40);
        temperaturas[i] = num_alea;

        i++;
    }
    minima = temperaturas[0];
    maxima = temperaturas[0];

    for (i = 0; i < 8; i++)
    {
        if (temperaturas[i] > maxima)
            maxima = temperaturas[i];
        if (temperaturas[i] < minima)
            minima = temperaturas[i];

        promedio += temperaturas[i];

        if (temperaturas[i] > valor_critico)
            contador++;

        printf("La temperatura %d es: %.2f\n", i+1, temperaturas[i]);
    }

    for (i = 0; i < 7; i++)
    {
        if (temperaturas[i] - temperaturas[i+1] > 5) {
            estable = false;
            break;
        }
    }
    
    promedio /= 8;
    
    printf("La temperatura máxima es: %.2f\n", maxima);
    printf("La temperatura mínima es: %.2f\n", minima);  
    printf("La temperatura promedio es: %.2f\n", promedio);   
    printf("La temperatura ha excedido el umbral %d veces\n", contador);

    if (estable)
        printf("La temperatura ha sido estable.\n");
        else
        printf("La temperatura NO ha sido estable.\n");
    
    return 0;
}