#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

bool validarContrasena(const char *);

int main() {
    char contrasena[20];
    bool esValida;

    printf("Ingrese la constraseña: \n");
    fgets(contrasena, sizeof(contrasena), stdin);

    esValida = validarContrasena(contrasena);

    if (esValida) {
        printf("Contraseña válida.\n");
    } else {
        printf("Contraseña inválida.\n");
    }
    
}

bool validarContrasena(const char *contrasena) {
    bool valida = false, mayuscula = false, minuscula = false, digito = false;
    int tamanio = strlen(contrasena);

    if(tamanio >= 8) {
        for(int i = 0; contrasena[i] != '\0'; i++) {
            char c = contrasena[i];
            if (isupper(c)) {
                mayuscula = true;
            } else if (islower(c)) {
                minuscula = true;
            } else if (isdigit(c)) {
                digito = true;
            } 
        }
        if(mayuscula == true && minuscula == true && digito == true) {
            valida = true;
        } 
    }

    return valida;
}
