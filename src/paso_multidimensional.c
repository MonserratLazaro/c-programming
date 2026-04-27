#include <stdio.h>

int calcularTotalVentas(int [2][4]);

int main() {
    int ventas_diarias[2][4], total_ventas;
    
    printf("Ingrese las ventas de cada día por departamento: \n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &ventas_diarias[i][j]);
        }
    }

    total_ventas = calcularTotalVentas(ventas_diarias);

    printf("El total de ventas del fin de semana es: %d", total_ventas);

    return 0;
}

int calcularTotalVentas(int matriz[2][4]) {
    int suma = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            suma += matriz[i][j];
        }
    }
    return suma;
}