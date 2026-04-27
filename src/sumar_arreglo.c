#include <stdio.h>

int sumaValor(int [], int);
int sumaReferencia(int*, int); 

int main() {
    int arreglo[5] = {1, 2, 3, 4, 5}, r1, r2;

    r1 = sumaValor(arreglo, 5);
    r2 = sumaReferencia(arreglo, 5);

    printf("Suma con paso por valor: %d\n", r1);
    printf("Suma con paso por referencia: %d\n", r2);

    return 0;
}

int sumaValor(int a[], int t) {
    int suma = 0;

    for(int i = 0; i < t; i++) {
        suma += a[i];
    }

    return suma;
}

int sumaReferencia(int *a, int t) {
    int suma = 0;

    for(int i = 0; i < t; i++){
        //suma += a[i];
        suma += *(a + i);
    }

    return suma;
}