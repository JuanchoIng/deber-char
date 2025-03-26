#include <stdio.h>
 
int main()
{
    int id, stock, cantidad, opcion, aggcant, menu = 1;
    float precio, total_ganancias = 0, venta = 0, descuento = 0;
    char nombre[30], respuesta_descuento;
    do
    {
        printf("\nMenu de Opciones:\n");
        printf("1. Registrar Producto\n");
        printf("2. Vender producto\n");
        printf("3. Reabastecer producto\n");
        printf("4. Mostrar informacion del producto\n");
        printf("5. Mostrar total de ganancias\n");
        printf("6. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
 
        switch (opcion)
        {
        case 1:
 
            menu = 2;
            printf("Ingrese el ID del producto: ");
            scanf("%d", &id);
            printf("Ingrese el nombre del producto: ");
            fflush(stdin);
            fgets(nombre, 30, stdin);
            do {
                printf("Ingrese la cantidad inicial en stock: ");
                while (scanf("%d", &stock) != 1) {
                   
                    printf("Error: por favor ingrese un numero valido para la cantidad en stock.\n");
                    while (( stock = getchar()) != '\n' && stock != EOF);  
                    printf("Ingrese la cantidad inicial en stock: ");
                }
                if (stock < 1) {
                    printf("La cantidad debe ser mayor a cero, vuelva a ingresar la cantidad;\n");
                }
            } while (stock < 1);
       
            do {
                printf("Ingrese el precio unitario del producto: ");
                while (scanf("%f", &precio) != 1) {
                    printf("Error: por favor ingrese un numero valido para el precio.\n");
                    while ((precio = getchar()) != '\n' && precio != EOF);  
                }
                if (precio < 1) {
                    printf("El precio debe ser mayor a cero, vuelva a ingresar el precio;\n");
                }
            } while (precio < 1);
 
            break;
        case 2:
        if (menu == 1)
        {
            do
            {
                printf("Ingrese la cantidad inicial en stock: ");
                scanf("%d", &stock);
                if (stock < 1)
                {
                    printf("La cantidad debe ser mayor a cero, vuelva a ingresar la cantidad;\n");
                }
            } while (stock < 1);
            do
            {
                printf("Ingrese el precio unitario del producto: ");
                scanf("%f", &precio);
                if (precio < 1)
                {
                    printf("La cantidad debe ser mayor a cero, vuelva a ingresar la cantidad;\n");
                }
 
            } while (precio < 1);
        }
        do
        {
            printf("Ingrese la cantidad a vender: ");
            scanf("%d", &cantidad);
            if (cantidad < 1)
            {
                printf("La cantidad debe ser mayor a cero, vuelva a ingresar la cantidad;\n");
            }
            if (cantidad > stock)
            {
                printf("No existe el stock suficiente para esta venta\n");
            }
        } while (cantidad < 1 || cantidad > stock);
 
        venta = cantidad * precio;
        printf("El total de la venta es: %.2f\n", venta);
 
   
        printf("Desea aplicar un descuento: S o N: ");
        fflush(stdin);
        scanf("%c", &respuesta_descuento);
 
        if (respuesta_descuento == 'S' || respuesta_descuento == 's')
        {
            do
            {
                printf("Ingrese el porcentaje de descuento (0-100): ");
                scanf("%f", &descuento);
                if (descuento < 0 || descuento > 100)
                {
                    printf("El descuento debe estar entre 0 y 100 porciento.\n");
                }
            } while (descuento < 0 || descuento > 100);
 
           
            float descuento_monto = venta * (descuento / 100);
            venta -= descuento_monto;
           
            printf("Descuento aplicado: %.2f\n", descuento_monto);
            printf("Total de la venta con descuento: %.2f\n", venta);
        }
 
        total_ganancias += venta;
        stock -= cantidad;
 
        break;
 
        case 3:
            if (menu == 1)
            {
                do
                {
                    printf("Ingrese la cantidad inicial en stock: ");
                    scanf("%d", &stock);
                    if (stock < 1)
                    {
                        printf("La cantidad debe ser mayor a cero, vuelva a ingresar la cantidad;\n");
                    }
                } while (stock < 1);
            }
 
            printf("Ingrese la cantidad a agregar al stock: ");
            scanf("%d", &aggcant);
            stock += aggcant;
            break;
 
        case 4:
            if (menu == 1)
            {
                printf("Ingrese el ID del producto: ");
                scanf("%d", &id);
                printf("Ingrese el nombre del producto: ");
                fflush(stdin);
                fgets(nombre, 30, stdin);
               
            }
 
            printf("\nInformación del producto:\n");
            printf("ID: %d\n", id);
            printf("Nombre: %s", nombre);
            printf("Stock disponible: %d\n", stock);
            printf("Precio unitario: %.2f\n", precio);
            break;
 
        case 5:
            printf("Total de ganancias: $%.2f\n", total_ganancias);
            break;
 
        case 6:
            printf("Saliendo del programa...\n");
            break;
 
        default:
            printf("Opción inválida. Intente nuevamente.\n");
        }
    } while (opcion != 6);
 
    return 0;
}