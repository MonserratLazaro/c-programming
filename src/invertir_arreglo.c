#include <stdio.h>

int main() {
    int numeros[5];

    for (int i = 0; i < 5; i++)
    {
        printf("Ingresa 5 números: \n");
        scanf("%d", &numeros[i]);
    }

    for (int i = 4; i >= 0; i--)
    {
        printf("Los números en orden inverso son: %d\n", numeros[i]);
        //printf("Los números en orden inverso son: %d\n", numeros[6-i]);
    }
    
    return 0;
}