#include <stdio.h>
#include <stdbool.h>

int main() {
    int edad, res;
    
    printf("Ingrese su edad: \n");
    scanf("%d", &edad);

    res = (edad >= 18);
    printf("¿El usuario puede votar? %d", res);
    return 0;
}
