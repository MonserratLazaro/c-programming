#include <stdio.h>

int main() {
    int numeros[10], rotado[10], K;

    printf("Ingrese 10 números: \n");

    for (int i = 0; i < 10; i++) {
        scanf("%d", &numeros[i]);
    }

    printf("Ingrese el número de posiciones a rotar: \n");
    scanf("%d", &K);

    for (int i = 0; i < 10; i++) {
        rotado[(i + K) % 10] = numeros[i]; 
    }

    printf("Arreglo rotado: \n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", rotado[i]);
    }

    return 0;
}