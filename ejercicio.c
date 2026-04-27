#include <stdio.h>
#include <string.h>

int compararCadenas(char *, char *);

int main() {
    char cadena1[20], cadena2[20];
    int iguales;

    // Ingresar cadenas 
    printf("Ingresa la primera cadena: \n");
    fgets(cadena1, sizeof(cadena1), stdin);
    cadena1[strcspn(cadena1, "\n")]  = '\0'; // Eliminar salto de línea
    printf("Ingresa la segunda cadena: \n");
    fgets(cadena2, sizeof(cadena2), stdin);
    cadena1[strcspn(cadena2, "\n")]  = '\0'; // Eliminar salto de línea

    // Llamar a la función
    iguales = compararCadenas(cadena1, cadena2);

    // Imprimir mensaje correspondiente
    if(!iguales){
        printf("Resultado: Las cadenas son iguales.\n");
    } else {
        printf("Resultado: Las cadenas son diferentes.\n");
    }

    return 0;
}

int compararCadenas(char *cadena1, char *cadena2){
    int i = 0;
    char c1, c2;
    // Comparar cadenas carácter por carácter
    while (cadena1[i] != '\0' || cadena2[i] != '\0') {
        if(cadena1[i] != cadena2[i]) {
            return 1; // Cadenas diferentes
        }
        i++;
    }
    return 0; // Cadenas iguales
}