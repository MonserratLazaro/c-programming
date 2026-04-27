#include <stdio.h>
#include <math.h>

int main() {
    double monto_total, interes_anual, interes_mensual, cuota_mensual, balance;
    int tiempo, numero_pagos;

    // Solicitar al usuario el monto del préstamo, la tasa de interés anual y el número de años para pagar el préstamo
    printf("Introduce el monto total del préstamo: \n");
    scanf("%lf", &monto_total);
    printf("Introduce la tasa de interés anual (en porcentaje): \n");
    scanf("%lf", &interes_anual);
    printf("Introduce el número de años para pagar el préstamo: \n");
    scanf("%d", &tiempo);

    // Verificar que el monto del préstamo sea positivo y la tasa de interés anual sea mayor que cero
    if (monto_total <= 0 || interes_anual <= 0) {
        printf("El monto del préstamo debe ser un valor positivo y la tasa de interés anual debe ser mayor que cero.\n");
    } else {
        // Calcular la tasa de interés mensual y el número total de pagos
        interes_mensual = (interes_anual / 100) / 12;
        numero_pagos = tiempo * 12;

        // Calcular la cuota mensual
        cuota_mensual = (monto_total * interes_mensual * pow(1 + interes_mensual, numero_pagos)) / (pow(1 + interes_mensual, numero_pagos) - 1);

        printf("\nLa cuota mensual a pagar es: %.2f\n", cuota_mensual);

        balance = monto_total;

        // Calcular el balance restante después de cada año
        for (int i = 1; i <= tiempo; i++) {
            for (int j = 1; j <= 12; j++) {
                balance -= (cuota_mensual - (balance * interes_mensual));
            }

            printf("Año %d: Balance restante: %.2f\n", i, balance);
        }
    }

    return 0;
}