# include <stdio.h>

int main() {
    int num1, num2, suma = 0;

    do
    {
        printf("Ingresa el valor inicial: \n");
        scanf("%d", &num1);
        printf("Ingresa el valor final: \n");
        scanf("%d", &num2);
    } while (num1 >= num2);

    for (int i = num1; i <= num2; i++)
    {
        if (i % 2 == 0) {
            suma += i;
        }
    }
    
    printf("La suma de los números pares entre %d y %d es: %d\n", num1, num2, suma);
    
    return 0; 
}