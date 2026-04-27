#include <stdio.h>
#include <string.h>

struct Persona {
    char nombre[50];
    int edad;
};

void actualizarPersona(struct Persona *);

int main() {
    struct Persona p1 = {"Juan", 25};

    printf("Nombre actual: %s\n", p1.nombre);
    printf("Edad actual: %d\n", p1.edad);

    actualizarPersona(&p1);

    printf("Nombre actualizado: %s\n", p1.nombre);
    printf("Edad actualizada: %d\n", p1.edad);

    return 0;
}

void actualizarPersona(struct Persona *persona) {
    printf("Ingrese el nuevo nombre: \n");
    fgets(persona->nombre, sizeof(persona->nombre), stdin);
    persona->nombre[strcspn(persona->nombre, "\n")] = '\0';
    printf("Ingrese la nueva edad: \n");
    scanf("%d", &persona->edad);
}