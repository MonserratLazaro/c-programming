#include <stdio.h>

int main() {
    int i = 0, num = 2, suma = 0;

    do {
        suma += num;
        num += 2;
    } while (++i <= 50);

    printf("La suma de los primeros números es: %d", suma);

    return 0;
}