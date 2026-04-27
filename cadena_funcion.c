#include <stdio.h>
#include <ctype.h>

int contarVocales(char[]);

int main() {
    char palabra[20];
    int resultado;

    printf("Ingrese una palabra: \n");
    fgets(palabra, sizeof(palabra), stdin);

    resultado = contarVocales(palabra);

    printf("La cantidad de vocales es: %d", resultado);

    return 0;
}

int contarVocales(char c[]) {
    int contador = 0, caracter;

    for (int i = 0; c[i] != '\0'; i++) {
        caracter = c[i];
        if (isalpha(caracter)) {
            caracter = tolower(caracter);
            if (caracter == 'a' || caracter == 'e' || caracter == 'i' || caracter == 'o' || caracter == 'u') {
                contador++;
            }
        }
    }

    return contador;
}