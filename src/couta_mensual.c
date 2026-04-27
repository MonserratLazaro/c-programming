#include <stdio.h>
#include <math.h>

int main() {
    double interes_anual, M, P, r, balance;
    int tiempo, n;

    // Solicitar al usuario el monto del préstamo
    printf("Introduce el monto total del préstamo: \n");
    scanf("%lf", &P);

    // Verificar que el monto del préstamo sea positivo
    if (P <= 0) {
        printf("El monto del préstamo debe ser un valor positivo.\n");
        return 1;
    }

    // Solicitar la tasa de interés anual
    printf("Introduce la tasa de interés anual (en porcentaje): \n");
    scanf("%lf", &interes_anual);

    // Verificar que la tasa de interés anual sea mayor que cero
    if (interes_anual <= 0) {
        printf("La tasa de interés anual debe ser mayor que cero.\n");
        return 1;
    }

    // Solicitar el número de años para pagar el préstamo
    printf("Introduce el número de años para pagar el préstamo: \n");
    scanf("%d", &tiempo);

    // Calcular la tasa de interés mensual y el número total de pagos
    r = (interes_anual / 100) / 12;
    n = tiempo * 12;

    // Calcular la cuota mensual
    M = (P * r * pow(1 + r, n)) / (pow(1 + r, n) - 1);

    printf("\nLa cuota mensual a pagar es: %.2f\n", M);

    balance = P;

    // Ciclo para el balance después de cada año
    for (int i = 1; i <= tiempo; i++) {
        // Calcular el pago total en un año
        for (int i = 0; i < 12; i++) {
            balance = balance * (1 + r) - M; 
        }
        
        printf("Año %d: Balance restante: %.2f\n", i, balance);
    }
}