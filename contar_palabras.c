#include <stdio.h>

int main() {
    char cadena[20];
    int contador = 1;

    printf("Ingresa una cadena: \n");
    fgets(cadena, sizeof(cadena), stdin); 

    for (int i = 0; cadena[i] != '\0'; i++) {
        if (cadena[i] == ' ') { //&& cadena !=' '
        contador++;
        }

    }
    
    printf("La cadena tiene %d palabras", contador);

    return 0;
}