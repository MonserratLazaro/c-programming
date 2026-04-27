#include <stdio.h>

int main() {
    int M1[2][2], M2[2][2], suma[2][2], i, j;

    printf("Ingresa los elementos de la 1era matriz:\n");
    for (i = 0; i < 2; i++){
        for (j = 0; j < 2; j++){
            scanf("%d", &M1[i][j]);
        }
    }

    printf("Ingresa los elementos de la 2nd matriz:\n");
    for (i = 0; i < 2; i++){
        for (j = 0; j < 2; j++){
            scanf("%d", &M2[i][j]);
        }
    }

    for (i = 0; i < 2; i++){
        for (j = 0; j < 2; j++){
            suma[i][j] = M1[i][j] + M2[i][j];
        }
    }

    printf("La matriz resultante es:\n");

    for (i = 0; i < 2; i++){
        for (j = 0; j < 2; j++){
            printf("%d \n", suma[i][j]);
        }
        printf("\n");
    }

    return 0;
}