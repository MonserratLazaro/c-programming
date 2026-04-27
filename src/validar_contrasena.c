#include <stdio.h>

int main()
{
    int intento = 1, contrasena_usuario;

    do
    {
        printf("Introduce la contraseña: \n");
        scanf("%d", &contrasena_usuario);

        if (contrasena_usuario == 1234)
        {
            printf("Contraseña correcta\n");
        }
        else
        {
            printf("Contraseña incorrecta. Intento %d de 3.\n", intento);
            if (intento == 3)
            {
                printf("Ha superado el número máximo de intentos.");
            }
        }
        intento++;
    } while (intento < 4 && contrasena_usuario != 1234);
    return 0;
}