#include <stdio.h>

int main() {
    float importacion[5], exportacion[5], mayor_exportacion, mayor_importacion, diferencia, balance_imp = 0, balance_exp = 0;
    int producto1, producto2;

    for (int i = 0; i < 5; i++) {
        printf("Ingresa los valores de importación para los 5 productos (en millones de dólares): \n");
        scanf("%f", &importacion[i]);
    }
    for (int i = 0; i < 5; i++) {
        printf("Ingresa los valores de exportación para los 5 productos (en millones de dólares): \n");
        scanf("%f", &exportacion[i]);
    }

    mayor_importacion = importacion[0];
    mayor_exportacion = exportacion[0];

    for (int i = 1; i < 5; i++) {
        if (importacion[i] > mayor_importacion)
        {
            mayor_importacion = importacion[i];
            producto1 = i + 1;
        }
        if (exportacion[i] > mayor_exportacion)
        {
            mayor_exportacion = exportacion[i];
            producto2 = i + 1;
        }
    }

    printf("Diferencias netas de importación/exportación (exportación - importación):\n");

    for (int i = 0; i < 5; i++) {
        diferencia = exportacion[i] - importacion[i];
        printf("Producto %d: %.2f millones.\n", i+1, diferencia);

        balance_imp += importacion[i];
        balance_exp += exportacion[i];
    }

    printf("Producto con mayor importación: Producto %d con %.2f millones.\n", producto1, mayor_importacion);
    printf("Producto con mayor exportación: Producto %d con %.2f millones.\n", producto2, mayor_exportacion);
    printf("Balance total de importaciones: %.2f millones.\n", balance_imp);
    printf("Balance total de exportaciones: %.2f millones.\n", balance_exp);

    return 0;
}