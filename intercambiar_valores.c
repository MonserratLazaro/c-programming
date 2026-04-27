#include <stdio.h>

void intercambiar(int*, int*); //apuntador de tipo entero

int main() {
    int a = 10, b = 20;

    printf("Antes del intercambio: a = %d, b = %d\n", a, b);
    intercambiar(&a, &b);

    printf("Después del intercambio: a = %d, b = %d\n", a, b);

    return 0;
} 

void intercambiar(int *a, int *b) { //se pueden usar variables con nombres diferentes
    int c = *a; //variable temporal temp
    *a = *b;
    *b = c;
}