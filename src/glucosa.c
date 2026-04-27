#include <stdio.h>
#include <math.h>

float calcularPromedio(float [], int);
float calcularDesviacion(float [], int, float);

int main() {
    int num_mediciones;
    float mediciones[10], promedio, desviacion_estandar;

    printf("Ingrese el número de mediciones: \n");
    scanf("%d", &num_mediciones);

    for(int i = 0; i < num_mediciones; i++) {
        printf("Medicion %d: \n", i+1);
        scanf("%f", &mediciones[i]);
    }

    promedio = calcularPromedio(mediciones, num_mediciones);
    desviacion_estandar = calcularDesviacion(mediciones, num_mediciones, promedio);

    printf("Promedio de glucosa: %.2f\n", promedio);
    printf("Desvío estándar: %.2f\n", desviacion_estandar);

    return 0;
}

float calcularPromedio(float a[], int t) {
    float suma = 0, promedio;
    
    for(int i = 0; i < t; i++) {
        suma += a[i];
    }

    promedio = suma/t;

    return promedio;
}

float calcularDesviacion(float a[], int t, float prom) {
    float varianza = 0, desvio;

    for(int i = 0; i < t; i++) {
        varianza += pow(a[i] - prom, 2);
    }

    varianza /= t;
    desvio = sqrt(varianza);

    return desvio;
}