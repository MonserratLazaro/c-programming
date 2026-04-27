#include <stdio.h>

int main() {
    int i, N, factorial = 1;

    printf("Introduce un número entero positivo: \n");
    scanf("%d", &N);

    if (N < 0) {
        printf("El fcatorial no está definido para números negativos.\n");
    } else {
        for (i = 1; i <= N; i++) {
        factorial *= i;
        }

        printf("El factorial de %d es: %d\n", N, factorial);
    }

    return 0;
}