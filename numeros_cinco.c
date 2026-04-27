#include <stdio.h>

int main() {
    int N, i = 5;

    do {
        printf("Ingresa un número: \n");
        scanf("%d", &N);
    } while (N < 0);

    do
    {
        if (i % 10 == 5) {
            printf("%d termina en 5\n", i);
        }
        i++;
    } while (i <= N);
    
    return 0;
}