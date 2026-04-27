#include <stdio.h>
#include <string.h>

int main() {
    char cadena[20], inverso[20];
    int longitud;

    printf("Ingresa una cadena: \n");
    fgets(cadena, sizeof(cadena), stdin); 
    
    longitud = strlen(cadena);

    for (int i = 0; cadena[i] != '\0'; i++) {
        inverso[i] = cadena[longitud-i-1];
    }

    printf("Cadena invertida: %s", inverso);

    return 0;
}
