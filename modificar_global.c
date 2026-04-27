#include <stdio.h>

int varGlob = 0;

int incrementarValor(int);

int main() {
    incrementarValor(varGlob);
    printf("Valor de varGlob: %d\n", varGlob);
    incrementarValor(varGlob);
    printf("Valor de varGlob: %d\n", varGlob);
    incrementarValor(varGlob);
    printf("Valor de varGlob: %d\n", varGlob);

    return 0;
}

int incrementarValor(int var) {
    varGlob++;
    return varGlob;
}