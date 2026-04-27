#include <stdio.h>

int main() {
    int opcion;
    float saldo = 1000, cantidad;

    // Ciclo para mostrar el menú hasta que el usuario elija salir (opción 4)
    do {
        printf("\nMenú de opciones:\n");
        printf("1. Consultar saldo\n");
        printf("2. Depositar dinero\n");
        printf("3. Retirar dinero\n");
        printf("4. Salir\n");
        printf("Selecciona una opción: \n");
        scanf("%d", &opcion); // Leer la opción seleccionada por el usuario

        // Estructura para manejar la opción seleccionada
        switch (opcion)
        {
            case 1: // Consultar saldo
                printf("Tu saldo es de: %.2f\n", saldo);
                break;
            case 2: // Depositar
                printf("¿Cuánto deseas depositar?\n");
                scanf("%f", &cantidad);
                saldo += cantidad;
                printf("Tu nuevo saldo es: %.2f\n", saldo);
                break;
            case 3: // Retirar
                printf("¿Cuánto deseas retirar?\n");
                scanf("%f", &cantidad);
                // Verificar que el monto de retiro no exceda el saldo
                if (cantidad <= saldo) {
                    saldo -= cantidad;
                    printf("Has retirado %.2f, tu nuevo saldo es: %.2f\n", cantidad, saldo);
                } else {
                    printf("No cuentas con suficientes fondos.\n");
                }
                break;
            case 4: // Salir
                printf("Has salido del menú.\n");
                break;
            default: // Cualquier otra opción ingresada por el usuario
                printf("Opción no válida.\n");
                break;
        }
    } while (opcion != 4);

    return 0;
}