#include <stdio.h>
#include <ctype.h>

void convertirMayusculas(char *);

int main() {
    char cadena[20];

    printf("Ingresa una cadena: \n");
    fgets(cadena, sizeof(cadena), stdin);

    convertirMayusculas(cadena);

    printf("Cadena en mayúsculas: %s", cadena);
    
    return 0;
}

void convertirMayusculas(char *string) {
    for(; *string != '\0'; string++) {
        *string = toupper(*string);
    }
}