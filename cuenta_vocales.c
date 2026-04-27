#include <stdio.h>
#include <ctype.h>

int main() {
    char cadena[20];
    int contador = 0;

    printf("Ingresa una cadena:\n");
    fgets(cadena, sizeof(cadena), stdin);

    for (int i = 0; cadena[i] != '\0'; i++) {
        char c = tolower(cadena[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            contador++;
        }
    }

    printf("La cadena contiene %d vocales", contador);

    return 0;
}