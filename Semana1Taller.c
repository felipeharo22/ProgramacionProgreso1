#include <stdio.h>

int main() {
 
    int id = 0;
    char nombre[50];
    int stock = 0;
    float precio = 0.0;
    float ganancias = 0.0;
    
    int opcion;
    int cantidad_venta;
    int cantidad_reabastecer;

 
    do {
        printf("\n--- MENU DE LA TIENDA ---\n");
        printf("1. Registrar producto\n");
        printf("2. Vender producto\n");
        printf("3. Reabastecer stock\n");
        printf("4. Consultar informacion\n");
        printf("5. Mostrar ganancias\n");
        printf("6. Salir\n");
        printf("Elige una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                printf("Ingresa el ID: ");
                scanf("%d", &id);
                
                printf("Ingresa el nombre (una sola palabra): ");
                scanf("%s", nombre);
                
                printf("Ingresa la cantidad en stock: ");
                scanf("%d", &stock);
                
                printf("Ingresa el precio unitario: ");
                scanf("%f", &precio);
                
                printf("Producto registrado.\n");
                break;

            case 2:
                printf("Cuantas unidades vas a vender?: ");
                scanf("%d", &cantidad_venta);

               
                if (cantidad_venta <= stock) {
                    stock = stock - cantidad_venta;
                    ganancias = ganancias + (cantidad_venta * precio);
                    printf("Venta realizada. Total a cobrar: $%.2f\n", cantidad_venta * precio);
                } else {
                    printf("No puedes vender esa cantidad. Solo hay %d en stock.\n", stock);
                }
                break;

            case 3:
                printf("Cuantas unidades vas a agregar al stock?: ");
                scanf("%d", &cantidad_reabastecer);
                
                stock = stock + cantidad_reabastecer;
                printf("Stock actualizado. Ahora tienes %d unidades.\n", stock);
                break;

            case 4:
                printf("\n--- DATOS DEL PRODUCTO ---\n");
                printf("ID: %d\n", id);
                printf("Nombre: %s\n", nombre);
                printf("Stock disponible: %d\n", stock);
                printf("Precio: $%.2f\n", precio);
                break;

            case 5:
                printf("\nGanancias totales hasta el momento: $%.2f\n", ganancias);
                break;

            case 6:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Esa opcion no existe.\n");
                break;
        }

    } while (opcion != 6);

    return 0;
}
