#include <stdio.h>
#include <string.h>

void generarNombreCompleto(char *, char *, char *);
void crearSaludo(char *, char *);

int main() {
    char nombre[50];
    char apellido[50];
    char nombreCompleto[100];
    char saludo[150];

    printf("Ingrese su nombre: \n");
    fgets(nombre, sizeof(nombre), stdin);
    nombre[strcspn(nombre, "\n")] = '\0';

    printf("Ingrese su apellido: \n");
    fgets(apellido, sizeof(apellido), stdin);
    apellido[strcspn(apellido, "\n")] = '\0';

    generarNombreCompleto(nombre, apellido, nombreCompleto);
    crearSaludo(nombreCompleto, saludo);

    printf("%s\n", saludo);

    return 0;
}

void generarNombreCompleto(char *nombre, char *apellido, char *nombreCompleto) {
    strcpy(nombreCompleto, nombre);
    strcat(nombreCompleto, " ");
    strcat(nombreCompleto, apellido);
}

void crearSaludo(char *nombreCompleto, char *saludo) {
    sprintf(saludo, "Hola, %s! Bienvenido/a.", nombreCompleto);
}