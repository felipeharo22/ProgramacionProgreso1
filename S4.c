#include <stdio.h>
#include <string.h>

void ProductoCaro(float precios[10], char productos[10][50], int contadorProductos);

int main (int argc, char *argv[]) {
    char productos[10][50]; 
    float precios[10];
    int menu = 0;
    int opc1 = 0;
    int contadorProductos = 0;
    float precioTotal = 0;
    int c;

    do {
        printf("\n<<<<Menu>>>>\n");
        printf("1. Ingresar producto\n");
        printf("2. Calcular precio total\n");
        printf("3. Precio promedio de todos los productos\n");
        printf("4. Encontrar el producto mas caro\n");
        printf("5. Buscar un producto por su nombre y precio\n");
        
        do {
            printf(">> "); 
            scanf("%d", &menu);
            while ((c = getchar()) != '\n' && c != EOF);
            if (menu < 1 || menu > 5) {
                printf("[ERROR] Opcion invalida. Intente de nuevo.\n");
            }
        } while (menu < 1 || menu > 5);
        
        switch (menu) {
            case 1: { 
                int cantidadNuevos;
                int maxDisponibles = 10 - contadorProductos;
                
                if (maxDisponibles == 0) {
                    printf("No hay espacio para mas productos.\n");
                    break;
                }

                do {
                    printf("\nCuantos productos desea ingresar? (Espacio disponible: %d): ", maxDisponibles);
                    scanf("%d", &cantidadNuevos);  
                    while ((c = getchar()) != '\n' && c != EOF);
                    if (cantidadNuevos <= 0 || cantidadNuevos > maxDisponibles) {
                        printf("[ERROR] Cantidad invalida.\n");
                    }
                } while (cantidadNuevos <= 0 || cantidadNuevos > maxDisponibles);
                
                int limite = contadorProductos + cantidadNuevos;
                
                for (int i = contadorProductos; i < limite; i++) {
                    printf("Ingrese el nombre del producto %d: ", i + 1);
                    fgets(productos[i], 50, stdin);
                    productos[i][strcspn(productos[i], "\n")] = 0;
                    
                    do {
                        printf("Ingrese el precio del producto %d: ", i + 1);
                        scanf("%f", &precios[i]);
                        while ((c = getchar()) != '\n' && c != EOF);
                        if (precios[i] < 0) {
                            printf("[ERROR] El precio no puede ser negativo.\n");
                        }
                    } while (precios[i] < 0);
                    
                    contadorProductos++; 
                }
                break;
            }
            case 2: {
                printf("\n<<<Precio total>>>\n");
                precioTotal = 0;
                for (int i = 0; i < contadorProductos; i++) {
                    precioTotal += precios[i];
                }
                printf("El precio total es: %.2f\n", precioTotal); 
                break;
            }
            case 3: {
                printf("\n<<<Precio Prom>>>\n");
                float precioProm = 0;
                if (contadorProductos > 0) {
                    float sumaTemp = 0;
                    for (int i = 0; i < contadorProductos; i++) {
                        sumaTemp += precios[i];
                    }
                    precioProm = sumaTemp / contadorProductos;
                }
                printf("El precio promedio es: %.2f\n", precioProm); 
                break;
            }
            case 4: {
                if (contadorProductos > 0) {
                    ProductoCaro(precios, productos, contadorProductos);
                } else {
                    printf("No hay productos ingresados.\n");
                }
                break;
            }
            case 5: {
                if (contadorProductos == 0) {
                    printf("No hay productos ingresados para buscar.\n");
                    break;
                }
                char busqueda[50];
                int encontrado = 0;
                printf("Ingrese el nombre del producto a buscar: ");
                fgets(busqueda, 50, stdin);
                busqueda[strcspn(busqueda, "\n")] = 0;

                for (int i = 0; i < contadorProductos; i++) {
                    if (strcmp(productos[i], busqueda) == 0) {
                        printf("Producto encontrado: %s - Precio: %.2f\n", productos[i], precios[i]);
                        encontrado = 1;
                        break;
                    }
                }
                if (encontrado == 0) {
                    printf("Producto no encontrado.\n");
                }
                break;
            }
        }
        
        do {
            printf("\nDesea continuar? (1. Si, 2. No): "); 
            scanf("%d", &opc1);
            while ((c = getchar()) != '\n' && c != EOF);
            if (opc1 != 1 && opc1 != 2) {
                printf("[ERROR] Opcion invalida.\n");
            }
        } while (opc1 != 1 && opc1 != 2);
        
    } while (opc1 == 1);

    return 0;
}

void ProductoCaro(float precios[10], char productos[10][50], int contadorProductos) {
    float precioMax = precios[0];
    int caro = 0;
    for (int i = 0; i < contadorProductos; i++) {
        if (precioMax < precios[i]) {
            precioMax = precios[i];
            caro = i;
        }
    }
    printf("El producto mas caro es %s con un valor de: %.2f\n", productos[caro], precioMax);
}
