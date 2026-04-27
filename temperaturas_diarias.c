#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int temperaturas[30], contador = 0, suma = 0, max = 10, min = 40, dia_max, dia_min;
    srand(time(NULL));

    printf("Ingrese las temperaturas diarias: \n");

    for (int i = 0; i < 30; i++) {
        temperaturas[i] = 10 + rand()/(RAND_MAX)*(40-10); //enteros
        suma += temperaturas[i];

        if (temperaturas[i] > max) {
            max = temperaturas[i];
            dia_max = i + 1;
        }
        if (temperaturas[i] < min) {
            min = temperaturas[i];
            dia_min = i + 1;
        }
        printf("%d\n", temperaturas[i]);
    }

    float promedio = (float)suma/30;

    for (int i = 0; i < 30; i++) {
        if (temperaturas[i] > promedio) {
            contador++;
        }
    }

    printf("Temperatura promedio: %.2f°C\n", promedio);
    printf("Temperatura más alta: %d°C en el día %d\n", max, dia_max);
    printf("Temperatura más baja: %d°C en le día %d\n", min, dia_min);
    printf("Días por encima del promedio: %d\n", contador);

    return 0;
}