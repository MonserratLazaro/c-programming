#include <stdio.h>
#include <string.h>

int main() {
    char cadena1[20];
    char cadena2[20];

    printf("Ingresa la primer cadena: \n");
    fgets(cadena1, sizeof(cadena1), stdin);
    printf("Ingresa la segunda cadena: \n");
    fgets(cadena2, sizeof(cadena2), stdin);

    if (strcmp(cadena1, cadena2) == 0) {
        printf("Las cadenas son iguales\n");
    } else {
        printf("Las cadenas son diferentes\n");
    }

    return 0;
}