#include <iostream>
#include <conio.h>
#include <string.h>

using  namespace std;

int main()
{
    char desc, clasif, consola;
    int num_articulo, desicion, opcion;
    float precio, imp, total;

    cout << "\n\t ~~~ TIENDA DE VIDEOJUEGOS ~~~" << endl;
    cout << "\t\n ***MENU DE OPCIONES***" << endl; // \t es tabulador
    cout << "1.-Alta" << endl;
    cout << "2.-Modificacion" << endl;
    cout << "3.-Baja" << endl;
    cout << "4.-Lista" << endl;
    cout << "5.-Limpiar Pantalla" << endl;
    cout << "6.-Salir" << endl;
    cout << "\n Seleccione una opcion:" << endl;
    cin >> opcion;
    if (opcion < 1 || opcion > 6)
    {
        cout << "\n Opcion no valida, vuelva a ingresar:" << endl;
        return main();

    }
    else
    {
        switch (opcion)
        {
        case 1: //ALTA DE ARTÍCULOS
            cout << "Ingrese el numero del articulo:" << endl;
            cin >> num_articulo;
            cout << "Ingrese la descripcion/resena del articulo:" << endl;
            cin >> desc;
            cout << "Ingrese la clasificacion del articulo:" << endl;
            cin >> clasif;
            cout << "Ingrese la consola:" << endl;
            cin >> consola;
            cout << "Ingrese el precio:" << endl;
            cin >> precio;
            imp = precio * (0.16);
            total = imp + precio;
            cout << "El total es: $" << total << endl;

            cout << "\nQuiere dar de alta otro articulo? 1.-Si , 2.- No " << endl;
            cin >> desicion;

            if (desicion == 1)
            {
                return main();
            }
            else
            {
                cout << "\n Gracias" << endl;
                return main();
            }
            break;

        case 2: // MODIFICACIÓN DE ARTICULOS
            break;

        case 3: // BAJA DE ARTICULOS
            break;

        case 4://LISTA DE ARTÍCULOS
            break;

        case 5: // LIMPIAR PANTALLA
            system("cls"); 
            return main();
            break;

        case 6: // CERRAR PANTALLA/SALIR

            exit(1); 
            break;
        }

    }
}

