#include <stdio.h>

int potencia(int, int);

int main() {
    int resultado, base, exponente;

    printf("Ingresa la base: \n");
    scanf("%d", &base);
    printf("Ingresa el exponente: \n");
    scanf("%d", &exponente);

    resultado = potencia(base, exponente);
    printf("%d", resultado);

    return 0;
}

int potencia(int base, int exponente) {
    if(exponente== 0) {
        return 1; //condición base
    }
    return base * potencia(base, exponente - 1); //llamada resursiva
}