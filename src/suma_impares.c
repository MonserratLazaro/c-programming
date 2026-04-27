#include <stdio.h>

int main() {
    int i, num, suma = 0;

    printf("Introduce un número: \n");
    scanf("%d", &num);

    for (i = 1; i <= num; i += 2) {
        suma += i;
    }

    printf("La suma de los números impares es: %d\n", suma);

    return 0;
}