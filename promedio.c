#include <stdio.h>

int main() {
    float estudiantes[5], promedio = 0;

    for (int i = 0; i < 5; i++)
    {
        printf("Ingresa la calificación de 5 estudiantes: \n");
        scanf("%f", &estudiantes[i]);

        promedio += estudiantes[i];
    }

    promedio /= 5; 

    printf("El promedio es: %.2f\n", promedio);
    
    return 0;
}