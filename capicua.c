#include <stdio.h>

int main() {
    int N, copia, digito, invertido;

    do {
        printf("Ingresa un número: \n");
        scanf("%d", &N);
    } while (N <= 0);

    copia = N;
    invertido = 0;

    while (N != 0)
    {
        digito = N % 10;
        invertido = invertido * 10 + digito;

        N /= 10;
    }

    if (copia == invertido){
        printf("El número %d es un capicúa.\n", copia);
    } else {
        printf("El número %d no es un capicúa.\n", copia);
    }
    
    return 0;
}