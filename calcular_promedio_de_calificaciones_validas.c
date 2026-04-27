#include <stdio.h>

int main() {
    float calificacion, suma, promedio;
    int contador;

    calificacion = 0;
    contador = 0;
    suma = 0;

    while (calificacion >= 0 && calificacion <= 100) {
        printf("Introduce la calificación: \n");
        scanf("%f", &calificacion);
        suma = suma + calificacion;
        contador++;
    }
    promedio = suma/10;
    printf("Se ingresaron %d calificaciones válidas\n", contador);
    printf("El promedio de las calificaciones válidas es: %.2f", promedio);

    return 0;
}