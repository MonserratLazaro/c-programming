#include <stdio.h>

void contarLlamadas();

int main() {
    contarLlamadas();
    contarLlamadas();
    contarLlamadas();

    return 0;
}

void contarLlamadas() {
    static int contador = 0;
    contador++;
    printf("Llamada número: %d\n", contador);
}