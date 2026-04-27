#include <stdio.h>

int sumaDigitos(int);

int main() {
    int N;
    printf("Ingrese un número: \n");
    scanf("%d", &N);
    printf("La suma de los dígitos es: %d\n", sumaDigitos(N));

    return 0;
}

int sumaDigitos(int numero) {

    if(numero == 0) {
        return 0;
    }

    return numero % 10 + sumaDigitos(numero / 10);
}