#include <stdio.h>

int main() {
    char cadena[20];
    char reemplazar, nuevo_caracter;

    printf("Ingresa una cadena: \n");
    fgets(cadena, sizeof(cadena), stdin);

    printf("Ingresa el carácter a reemplazar: \n");
    scanf("%c", &reemplazar);

    getchar(); //Limpiar el buffer de entrada
    
    printf("Ingresa el nuevo carácter: \n");
    scanf("%c", &nuevo_caracter);

    for (int i = 0; cadena[i] != '\0'; i++) {
        if (cadena[i] == reemplazar) {
            cadena[i] = nuevo_caracter;
        }
    }

    printf("Cadena modificada: %s\n", cadena);

    return 0;
}