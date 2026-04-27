#include <stdio.h>
#define DESCUENTO1 0.10
#define DESCUENTO2 0.20
#define DESCUENTO3 0.30

int main() {
  float precio=0, f1=0, f2=0, f3=0;
  int tipo_descuento = 0;
  
  scanf ("%f\n",&precio);
  printf("Introduce el precio del producto: %.2f\n", precio);
  scanf ("%d\n",&tipo_descuento);
  printf("Introduce el código de descuento (1, 2, 3): %d\n", tipo_descuento);
    
    switch(tipo_descuento){
      case 1:
        f1=precio*0.90;
        printf("El precio final es: %.2f", f1);
        break;
      case 2:
        f2=precio*0.80;
        printf("El precio final es: %.2f", f2);
        break;
      case 3:
        f3=precio*0.70;
        printf("El precio final es: %.2f", f3);
        break;
      default:
        printf("No se aplicó ningún descuento\n");
        printf("El precio final es: %.2f", precio);
        break;
      }
    
  return 0;
}