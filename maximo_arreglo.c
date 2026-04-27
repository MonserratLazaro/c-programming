#include <stdio.h>

int main() {
    int numeros[10], i, maximo;

    int i = 0;
    while (i < 10)
    {
        printf("Ingresa 10 números enteros: \n");
        scanf("%d", &numeros[i]);
        i++;
    }

    maximo = numeros[0];
    
    for (i = 1; i < 10; i++)
    {
        if (numeros[i] > maximo)
        {
            maximo = numeros[i];
        }
    }

    printf("El número máximo es: %d\n", maximo);
    
    return 0;
}