#include <stdio.h>

int main() {
    int N, factorial = 1, i = 1;

    do {
        printf("Introduce un número entero positivo: \n");
        scanf("%d", &N);
    } while (N < 0);

    while (i <= N)
    {
        factorial *= i;
        i++;
    }

    printf("El factorial de %d es: %d\n", N, factorial);
    
    return 0;
}