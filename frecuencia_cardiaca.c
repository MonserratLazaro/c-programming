#include <stdio.h>

float calcularPromedio(int [], int);
int obtenerMaximo(int [], int);
int obtenerMinimo(int[], int);

int main() {
    int mediciones[10], num_mediciones, f_max, f_min;
    float promedio;

    printf("Ingrese el número de mediciones: \n");
    scanf("%d", &num_mediciones);

    for(int i = 0; i < num_mediciones; i++) {
        printf("Medición %d: ", i+1);
        scanf("%d", &mediciones[i]);
    }

    promedio = calcularPromedio(mediciones, num_mediciones);
    f_max = obtenerMaximo(mediciones, num_mediciones);
    f_min =obtenerMinimo(mediciones, num_mediciones);

    printf("Frecuencia cardíaca promdedio: %.2f\n", promedio);
    printf("Frecuencia máxima: %d\n", f_max);
    printf("Frecuencia mínima: %d\n", f_min);

    return 0;
}

float calcularPromedio(int a[], int t) {
    int suma = 0;
    float promedio;

    for(int i = 0; i < t; i++){
        suma += a[i];
    }

    promedio = (float)suma/t;
    return promedio;
}

int obtenerMaximo(int a[], int t) {
    int max = a[0];

    for(int i = 1; i < t; i++) {
        if(a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

int obtenerMinimo(int a[], int t) {
    int min = a[0];

    for(int i = 1; i < t; i++) {
        if(a[i] < min) {
            min = a[i];
        }
    }
    return min;
}