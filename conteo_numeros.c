#include <stdio.h>

int main() {
    int N, i = 0;

    do {
        printf("Ingresa un número: \n");
        scanf("%d", &N);
    } while (N <= 0);

    do
    {
        N /= 10;
        i++;
    } while (N != 0);

    printf("El número tiene %d dígitos\n", i);
    
    return 0;
}