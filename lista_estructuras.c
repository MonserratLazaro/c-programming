#include <stdio.h>

struct Producto
{
    char nombre[20];
    float precio;
};

void actualizarProducto(struct Producto *, int);

int main()
{
    int i;
    struct Producto productos[3];
    struct Producto p0 = {"Manzana", 8.50};
    struct Producto p1 = {"Platano", 7.00};
    struct Producto p2 = {"Naranja", 15.50};

    productos[0] = p0;
    productos[1] = p1;
    productos[2] = p2;

    for (i = 0; i < 3; i++)
    {
        printf("Producto %d: %s - $%.2f\n", i, productos[i].nombre, productos[i].precio);
    }

    printf("Ingrese el índice del producto a actualizar: \n");
    scanf("%d", &i);

    actualizarProducto(productos, i);

    for (i = 0; i < 3; i++)
    {
        printf("Producto %d: %s - $%.2f\n", i, productos[i].nombre, productos[i].precio);
    }

    return 0;
}

void actualizarProducto(struct Producto *arreglo, int indice)
{
    printf("Ingrese el nuevo nombre: \n");
    fgets(arreglo[indice].nombre, sizeof(arreglo[indice].nombre), stdin);
    arreglo[indice].nombre[strlen(arreglo[indice].nombre) - 1] = '\0'; // Remove newline character
    printf("Ingrese el nuevo precio: \n");
    scanf("%f", &arreglo[indice].precio);
}