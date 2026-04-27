#include <stdio.h>

int main() {
    float ingresos, tasa_de_impuestos;
    int edo_civil;
    
    printf("Introduce tus ingresos anuales: \n");
    scanf("%f", &ingresos);
    printf("Selecciona tu estado civil (1=soltero/a, 2=casado/a): \n");
    scanf("%d", &edo_civil);

    if (edo_civil == 1) {
        if (ingresos <= 30000.0) {
            tasa_de_impuestos = 10;
        } else if (ingresos >= 30001.0 && ingresos <= 60000.0) {
            tasa_de_impuestos = 20;
        } else {
            tasa_de_impuestos = 30;
        }
    } else if (edo_civil == 2) {
        if (ingresos <= 30000.0) {
            tasa_de_impuestos = 5;
        } else if (ingresos >= 30001.0 && ingresos <= 60000.0) {
            tasa_de_impuestos = 15;
        } else {
            tasa_de_impuestos = 25;
        }
    }
    printf("Debes pagar $%.2f en impuestos", (tasa_de_impuestos/100)*ingresos);
    return 0;
}