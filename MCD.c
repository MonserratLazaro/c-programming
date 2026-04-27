#include <stdio.h>

int mcd(int, int);

int main() {
    int num1, num2;

    printf("Ingrese el primer número: \n");
    scanf("%d", &num1);
    printf("Ingrese el segundo número: \n");
    scanf("%d", &num2);

    printf("El MCD de %d y %d es: %d\n", num1, num2, mcd(num1, num2));

    return 0;
}

int mcd(int a, int b) {

    if(b == 0) {
        return a;
    }

    return mdc(b, a % b);
}