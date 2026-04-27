#include <stdio.h>
#define CONTRASENA_FIJA 1234

int main() {
    int intento = 1, contrasena_usuario;

    do {
        printf("Introduce la contraseña: \n");
        scanf("%d", contrasena_usuario);
        
        if (contrasena_usuario == CONTRASENA_FIJA)
        {
            printf("Contraseña correcta");
        } else {
            printf("Contraseña incorrecta. Intento %d de 3.\n", intento);
        }
        intento++;
    } while (intento < 4 && contrasena_usuario != CONTRASENA_FIJA);
    printf("Ha superado el número máximo de intentos.");

}