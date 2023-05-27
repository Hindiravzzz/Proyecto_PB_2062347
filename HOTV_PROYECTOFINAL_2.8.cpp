#include <iostream>
#include <conio.h>
#include <string.h>
#include <string>
#include <fstream>
#include <stdlib.h>// funcione new y delete
#include <vector>

using namespace std;

//definir la funcion
void Alta();
void Baja();
void listas();
void archivos();
void modificar();

int alta, * numarticulo, baja;
float* subtotal, * iva, * total, contador;
string* nombre, * clasif, * genero, * desc, * status, * consola, * res;

int main()
{
	int opc;
	printf("\n\t\t~~~ TIENDA DE VIDEOJUEGOS ~~~");
	printf("\n1.-Alta\n2.-Lista\n3.-Modificar\n4.-Limpiar pantalla\n5.-Baja\n6.-Salir\n");
	printf("\nSeleccione una opcion:\n");
	scanf_s("%d", &opc);

	switch (opc)
	{
	case 1:
		Alta();
		return main();
		break;

	case 2:
		listas();
		return main();
		break;

	case 3:
		modificar();
		return main();
		break;

	case 4:
		system("cls"); //system("clear");
		return main();
		break;

	case 5:
		Baja();
		return main();
		break;

	case 6:
		archivos();
		break;

	default:
		printf("Opcion no valida\n");
		return main();
		break;
	}
}

void Alta()
{
	do
	{
		printf("Digite el numero de registros que desea dar de alta: \n");
		scanf_s("%d", &alta);

		if (alta <= 0)
		{
			printf("Opcion no valida.\nVuelva a ingresar.\n");
		}
	} while (alta <= 0);

	numarticulo = new int[alta]; //arreglos
	subtotal = new float[alta];
	total = new float[alta];
	iva = new float[alta];
	genero = new string[alta];
	consola = new string[alta];
	desc = new string[alta];
	nombre = new string[alta];
	clasif = new string[alta];
	res = new string[alta];
	status = new string[alta];

	for (int i = 0; i < alta; i++)
	{
		do
		{
			printf("Ingrese el numero del articulo:\n");
			scanf_s("%d", &numarticulo[i]);

			if (numarticulo[i] <= 0)
			{
				printf("Numero invalido.\n");
			}

		} while (numarticulo[i] <= 0);

		while (getchar() != '\n'); //se vacia el buffer o el espacio o cin.ignore
		printf("Ingrese nombre del articulo: \n");
		getline(cin, nombre[i]); //permite los espacios en el nombre

		printf("Ingrese el genero del articulo:\n");
		getline(cin, genero[i]);

		printf("Ingrese clasificacion del articulo:\n");
		getline(cin, clasif[i]);

		printf("Ingrese la consola: \n");
		getline(cin, consola[i]);

		printf("Ingrese descripcion del articulo:\n");
		getline(cin, desc[i]);

		printf("Ingrese su resena del articulo:\n");
		getline(cin, res[i]);


		//* subtotal, * iva, * total
		printf("Ingrese el precio del articulo: \n");//printf
		scanf_s("%f", &subtotal[i]); //scanf 

		while (subtotal[i] <= 0)
		{
			printf("Cantidad no valida\n");
			printf("Ingrese el precio:\n");
			scanf_s("%f", &subtotal[i]);
		}

		iva[i] = subtotal[i] * (0.16f);
		total[i] = iva[i] + subtotal[i];

		printf("-El total es: $ %.2f\n", total[i]);
		printf("-El iva es de: $ %.2f\n\n", iva[i]);


	}
}

void listas()
{
	printf("\nLISTA:\n");
	for (int i = 0; i < alta; i++)
	{
		if (status[i] == "ELIMINADO")
		{
			printf("REGISTRO ELIMINADO %d\n ", i + 1);
		}
		else
		{
			contador++;
			printf("Registro: #%d\n", i + 1);
			printf("\nArticulo:#%d\n", numarticulo[i]);
			printf("Nombre del articulo:%s \n", nombre[i].c_str());
			printf("Genero del articulo:%s \n", genero[i].c_str());
			printf("Clasificacion del articulo:%s \n", clasif[i].c_str());
			printf("Tipo de consola:%s \n", consola[i].c_str());
			printf("Descripcion del articulo:%s \n", desc[i].c_str());
			printf("Resena del articulo:%s \n", res[i].c_str());
			printf("Costo a pagar del articulo:$ %.2f \n", total[i]);
			printf("Cantidad de impuesto:$ %.2f \n\n", iva[i]);
		}
	}
	if (contador == 0)
	{
		printf("No hay registros para mostrar.\n");
	}
}
void Baja()
{
	int j;
	printf("Ingrese el  registro a eliminar \n");
	scanf_s("%d", &j);
	j = j - 1;

	if (j >= 0 && j < alta)
	{
		printf("Eliminando registro %d\n", j + 1);
		status[j] = "ELIMINADO";
	}
	else
	{
		printf("Registro invalido\n");
	}

}

void archivos()
{
	ofstream archivo; //clase ifstream para leer archivos
	float texto;
	string texto2, nombrearchivo;
	int contador = 0;

	printf("Digite el nombre del archivo\n");
	cin.ignore();
	getline(cin, nombrearchivo);
	nombrearchivo += ".txt";    // Agregar la extensión .txt al nombre del archivo

	archivo.open(nombrearchivo.c_str(), ios::out);


	if (archivo.fail())
	{
		printf("ERROR NO SE PUDO CREAR EL ARCHIVO");
		exit(1);
	}

	archivo << "NUMERO" << "\t";
	archivo << "NOMBRE" << "\t";
	archivo << "GENERO" << "\t";
	archivo << "CLASIFICACION" << "\t";
	archivo << "CONSOLA" << "\t";
	archivo << "DESCRIPCION" << "\t";
	archivo << "RESEÑA" << "\t";
	archivo << "TOTAL" << "\n";

	for (int i = 0; i < alta; i++)
	{
		if (status[i] == "ELIMINADO")
		{
			texto2 = "REGISTRO ELIMINADO ";
			texto = i;
			archivo << texto2 << texto << "\n";
		}
		else
		{
			
			archivo << numarticulo[i] << "\t" << "\t";
			//archivo << texto << "\t" << "\t";
			archivo << nombre[i] << "\t" << "\t";
			//archivo << texto2 << "\t" << "\t";
			archivo << genero[i] << "\t" << "\t";
			//archivo << texto2 << "\t" << "\t";
			archivo << clasif[i] << "\t" << "\t";
			//archivo << texto2 << "\t" << "\t";
			archivo << consola[i] << "\t" << "\t";
			//archivo << texto2 << "\t" << "\t";
			archivo << desc[i] << "\t" << "\t";
			//archivo << texto2 << "\t" << "\t";
			archivo << res[i] << "\t" << "\t";
			//archivo << texto2 << "\t" << "\t";
			archivo << total[i] << "\t" << "\t";
			//archivo << texto << "\t" << "\t";
		}
		/*
		 texto = numarticulo[i];
            archivo << texto << "\t" << "\t";
            texto2 = nombre[i];
            archivo << texto2 << "\t" << "\t";
            texto2 = genero[i];
            archivo << texto2 << "\t" << "\t";
            texto2 = clasif[i];
            archivo << texto2 << "\t" << "\t";
            texto2 = consola[i];
            archivo << texto2 << "\t" << "\t";
            texto2 = desc[i];
            archivo << texto2 << "\t" << "\t";
            texto2 = res[i];
            archivo << texto2 << "\t" << "\t";
            texto = total[i];
            archivo << texto << "\t" << "\t";
		
		*/
		
	}
	printf("El archivo se ha creado exitosamente.\n");
	archivo.close();
}


void modificar()
{
	int j, opcion, op2;
	do
	{
		printf("Ingrese el numero registro a modificar \n");
		scanf_s("%d", &j);

		if (j < 1 || j > alta)
		{
			printf("Registro invalido, ingrese una opcion valida\n", alta);
			return;
		}
		else
		{
			j = j - 1; // esto debido a que i inicia en 0

			for (int i = j; i == j; i++)
			{
				if (status[i] == "ELIMINADO")
				{
					printf("REGISTRO ELIMINADO\n", i + 1);
					printf("Ingrese un registro valido.\n");
					op2 = 1;
				}
				else
				{
					op2 = 2;
				}
			}
		}
	}

	while (op2 == 1);
	do
	{
		printf("Ingrese que desea modificar:");
		printf("\n1. - Numero\n 2. - Nombre\n 3. - Genero\n 4. - Clasificacion\n 5. - Consola\n 6. - Descripcion\n 7. - Resena\n 8. - Precio\n");
		scanf_s("%d", &opcion);

		if (opcion < 1 || opcion > 8)
		{
			printf("Opcion invalida, vuelva a ingresar.\n");
			op2 = 1;
		}
		else
		{
			op2 = 2;

		}
	}

	while (op2 == 1);

	switch (opcion)
	{
	case 1:
		for (int i = j; i == j; i++)
		{
			printf("Ingrese numero de articulo:\n");
			scanf_s("%d", &numarticulo[i]);
			system("pause");
		}
		break;

	case 2:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n'); //se vacia el buffer o el espacio
			printf("Ingrese el nombre del articulo:\n");
			getline(cin, nombre[i]);
			system("pause");
		}
		break;

	case 3:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n'); //se vacia el buffer o el espacio
			printf("Ingrese el genero:\n");
			getline(cin, genero[i]);
			system("pause");
		}
		break;


	case 4:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n'); //se vacia el buffer o el espacio
			printf("Ingrese clasificacion:\n");
			getline(cin, clasif[i]);
			system("pause");
		}
		break;

	case 5:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n'); //se vacia el buffer o el espacio
			printf("Ingrese la consola:\n");
			getline(cin, consola[i]);
			system("pause");
		}
		break;

	case 6:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n'); //se vacia el buffer o el espacio
			printf("Ingrese descripcion:\n");
			getline(cin, desc[i]);
			system("pause");
		}
		break;

	case 7:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n'); //se vacia el buffer o el espacio
			printf("Ingrese su resena:\n");
			getline(cin, res[i]);
			system("pause");
		}
		break;

	case 8:
		for (int i = j; i == j; i++)
		{
			printf("Ingrese el costo:\n");
			scanf_s("%f", &subtotal[i]);

			while (subtotal[i] <= 0)
			{
				printf("Cantidad no valida\n");
				printf("Ingrese un precio valido:\n");
				scanf_s("%f", &subtotal[i]);
			}

			iva[i] = subtotal[i] * (0.16f);
			total[i] = iva[i] + subtotal[i];

			printf("-El total es: $ %f\n", total[i]);
			printf("-El iva es de: $ %f\n\n", iva[i]);
			system("pause");

		}
		break;
	}

}
