#include <stdio.h>
#include <math.h>

int cuadrado(int);

int main (){
    int num;

    printf ("Ingresa un número: ");
    scanf("%d\n", &num);

    cuadrado(num);

    printf("El cuadrado de %d es: %d\n", num, cuadrado(num)); //oguardando el resultado en una variable

    return 0;
}

int cuadrado(int num) {
    return pow(num, 2);
}