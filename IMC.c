#include <stdio.h>
#include <math.h>

float calcularIMC(float, float);
void clasificarIMC(float, char*);

char clasificacion[10];

int main() {
    float peso, altura, IMC;

    printf("Peso (kg): \n");
    scanf("%f", &peso);
    printf("Altura (m): \n");
    scanf("%f", &altura);

   IMC = calcularIMC(peso, altura);
   clasificarIMC(IMC, clasificacion);

   printf("IMC: %.2f\n", IMC);
   printf("Clasificación: %s", clasificacion);

   return 0;
}

float calcularIMC(float p, float a) {
    float calculo;
    calculo = p/pow(a,2);
    return calculo;
}

void clasificarIMC(float imc, char *clasificación) {
    if(imc < 18.5) {
        sprintf(clasificacion, "Bajo peso");
    } else if (imc >= 18.6 && imc <= 24.9) {
        sprintf(clasificacion, "Normal");
    } else if (imc >= 25 && imc <= 29.9) {
        sprintf(clasificacion, "Sobrepeso"); 
    } else {
        sprintf(clasificacion, "Obesidad");
    }
}