#include <stdio.h>

int main() {
    float calificacion, promedio;
    int i = 0;
    while (i <= 10) {
        printf("Introduce la calificación: \n");
        scanf("%f", &calificacion);
        promedio = promedio + calificacion;
        i++;
    }
    printf("El promedio del grupo es: %.2f", promedio/10);

    return 0;
}