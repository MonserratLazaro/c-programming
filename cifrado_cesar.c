#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char cadena[20], cifrada[20];
    int desplazamiento, tamanio;

    printf("Ingrese una cadena: \n");
    fgets(cadena, sizeof(cadena), stdin);

    // Eliminar el salto de línea que fgets puede agregar
    tamanio = strlen(cadena);
    if (cadena[tamanio-1] == '\n') {
        cadena[tamanio-1] = '\0';
    }

    printf("Ingrese el valor de desplazamiento: \n");
    scanf("%d", &desplazamiento);

    for (int i = 0; cadena[i] != '\0'; i++) {
        if (isupper(cadena[i])) {
            cifrada[i] = (cadena[i] + desplazamiento) % 26;
        } else if (islower(cadena[i])) {
            cifrada[i] = (cadena[i] + desplazamiento) % 26;
        } else {
            cifrada[i] = cadena[i];
        }
    }

    printf("Cadena cifrada: %s\n", cifrada);

    return 0;
}