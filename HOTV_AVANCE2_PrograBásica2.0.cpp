#include <iostream>
#include <math.h> 
#include <conio.h> 
#include <stdio.h>
#include <string.h>
#include <string>
#include <wchar.h>

using  namespace std;

struct proyecto
{
    string desc;
    int numarticulo;
    char clasif[100], consola[100], nombre[100];
    float precio = 0, imp, total = 0;
};

int main()
{
    proyecto videojuegos[3];
    int opcion;

    do
    {
        printf("\n\t\t~~~ TIENDA DE VIDEOJUEGOS ~~~");
        printf("\t\n ***MENU DE OPCIONES***");
        printf("\n1.-Alta");
        printf("\n2.-Modificacion");
        printf("\n3.-Baja");
        printf("\n4.-Lista de articulos");
        printf("\n5.-Limpiar Pantalla");
        printf("\n6.-Salir\n");

        printf("\nSeleccione una opcion:\n");
        cin >> opcion;

        switch (opcion)
        {
        case 1: //ALTA
            for (int i = 0; i < 3; i++)
            {
                
                printf("Ingrese el numero del articulo:\n");
                scanf_s("%d", &videojuegos[i].numarticulo);

                cin.ignore();
                printf("Ingrese el nombre del articulo:\n");
                gets_s(videojuegos[i].nombre);

                printf("Ingrese la descripcion/resena del articulo:\n");
                getline(cin, videojuegos[i].desc);

                printf("Ingrese la clasificacion del articulo:\n");
                gets_s(videojuegos[i].clasif);

                printf("Ingrese la consola:\n");
                gets_s(videojuegos[i].consola);

                printf("Ingrese el precio:\n");
                scanf_s("%f", &videojuegos[i].precio);

                while (videojuegos[i].precio <= 0)
                {
                    printf("Cantidad no valida\n");
                    printf("Ingrese el precio:\n");
                    scanf_s("%f", &videojuegos[i].precio);
                }
                videojuegos[i].imp = videojuegos[i].precio * (0.16f);
                videojuegos[i].total = videojuegos[i].imp + videojuegos[i].precio;
                printf("El total es: $ %f\n", videojuegos[i].total);
                printf("Impuesto de: %f\n\n", videojuegos[i].imp);
            }
            break;

        case 2://MODIFICACION 
            break;

        case 3://BAJA DE ARTICULOS
            break;

        case 4: //LISTA DE ARTICULOs
            for (int i = 0; i < 3; i++)
            {
                printf("\nNOMBRE DEL ARTICULO:%s\n", videojuegos[i].nombre);
                printf("# ARTICULO:%d\n", videojuegos[i].numarticulo);
                printf("DESCRIPCION:%s\n", videojuegos[i].desc.c_str());
                printf("CLASIFICACION:%s\n", videojuegos[i].clasif);
                printf("CONSOLA:%s\n", videojuegos[i].consola);
                printf("PRECIO A PAGAR: $%f\n", videojuegos[i].total);
            }

            break;

        case 5:
            system("cls"); // limpiar pantalla
            break;

        case 6:
            exit(1); // cierra la pantalla
            break;

        }
    } while (opcion != 6);
}


