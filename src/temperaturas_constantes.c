#include <stdio.h>

void calcularEstadisticas (const int *, int, int *, int *, float *);

int main() {
    int num_temperaturas, min, max;
    float promedio = 0;

    printf("Ingrese el número de temperaturas: \n");
    scanf("%d", &num_temperaturas);

    int temperaturas[num_temperaturas];

    printf("Ingrese las temperaturas: \n");
    for(int i = 0; i < num_temperaturas; i++) {
        scanf("%d", &temperaturas[i]);
    }

    calcularEstadisticas(temperaturas, num_temperaturas, &max, &min, &promedio);

    printf("Temperatura máxima: %d\n", max);
    printf("Temperatura miníma: %d\n", min);
    printf("Temperatura promedio: %.2f\n", promedio);

    return 0;
}

void calcularEstadisticas (const int *temperaturas, int t, int *max, int *min, float *promedio) {
    *max = *min =  temperaturas[0];
    for(int i = 0; i < t; i++) {
        if(*max > temperaturas[i]) {
            *max = temperaturas[i];
        }
        if(*min < temperaturas[i]) {
            *min = temperaturas[i];
        }
        *promedio += (float)temperaturas[i];
    }
    *promedio /= t;
}