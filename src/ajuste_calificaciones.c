#include <stdio.h>

int main() {
    int calificaciones[10], i;

    // Ingresar calificaciones
    for (i = 0; i < 10; i++) {
        printf("Ingrese la calificación del estudiante: \n");
        scanf("%d", &calificaciones[i]);
    }

    //Imprimir calificaciones originales
    printf("Calificaciones originales: \n");
    for (i = 0; i < 10; i++) {
        printf("%d \n", calificaciones[i]);
    }

    //Modificar calificaciones
    for (i = 0; i < 10; i++) {
        if (calificaciones[i] < 60) {
            if (calificaciones[i] == 56) {
                calificaciones[i] += 4;
            } else if (calificaciones[i] == 57) {
                calificaciones[i] += 3;
            } else if (calificaciones[i] == 58) {
                calificaciones[i] += 2;
            } else if (calificaciones[i] == 59) {
                calificaciones[i] += 1;
            } else {
                calificaciones[i] += 5;
            }
        }
    }

    //Imprimir calificaciones ajustadas
    printf("Calificaciones ajustadas: \n");
    for (i = 0; i < 10; i++) {
        printf("%d \n", calificaciones[i]);
    }

    return 0;
}