#include <stdio.h>
#include <stdbool.h>

int main() {
    int numeros[8], numero, i;
    bool encontrado = false;

    for (i = 0; i < 8; i++)
    {
        printf("Ingresa 8 números: \n");
        scanf("%d", &numeros[i]);
    }

    printf("Ingresa el número a buscar: \n");
    scanf("%d", &numero);

    for (i = 0; i < 8; i++)
    {
        if (numero == numeros[i])
        {
            encontrado = true;
            break;
        }

    }
    
    if (encontrado) {
        printf("El número %d se encuentra en la posición [%d].\n", numero, i);
    } else {
        printf("No se encontro el número.\n");
    }

    return 0;
}