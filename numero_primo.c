#include <stdio.h>
#include <stdbool.h>
int main() {
    int N;
    bool esPrimo = true;

    printf("Introduce un número entero: ");
    scanf("%d", &N);

    if (N <= 1) {
        printf("%d no es un número primo.\n", N);
        } else {
            for (int i = 2; i <= N / 2; i++) {
                if (N % i == 0) {
                    esPrimo = false;
                    break;
                }
            }
            
            if (esPrimo) {
                printf("%d es un número primo.\n", N);
            } else {
                printf("%d no es un número primo.\n", N);
            }  
        }
    return 0;
}