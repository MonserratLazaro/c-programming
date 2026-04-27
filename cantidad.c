#include <stdio.h>

int main() {
    int numero, par, impar;
    par = 0;
    impar = 0;

    printf("Introduce un número(0 para terminar): \n");
    scanf("%d", &numero);

    while (numero != 0){
        if (numero % 2 == 0) {
            par++;
        } else if (numero % 2 != 0) {
            impar++;
        }
        printf("Introduce un número(0 para terminar): \n");
        scanf("%d", &numero);
    }

    printf("Números pares: %d\n", par);
    printf("Números impares: %d\n", impar);
    
    return 0;
}