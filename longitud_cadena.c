#include <stdio.h>

int longitudCadena(char *);

int main() {
    char cadena[20];
    int longitud;

    printf("Ingrese una cadena: \n");
    fgets(cadena, sizeof(cadena), stdin);

    longitud = longitudCadena(cadena);

    printf("La longitud de la cadena es: %d\n", longitud - 1);

    return 0;
}

int longitudCadena(char *string) {
    int len = 0;

    while (*string != '\0') {
        len++;
        string++;
    }
    
    return len;
}