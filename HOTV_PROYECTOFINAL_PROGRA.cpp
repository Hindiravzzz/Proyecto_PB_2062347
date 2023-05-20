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
void listas();
void archivos();
void eliminar();
void modificar();

int alta, * numarticulo;
float * subtotal, * iva, * total, contador;
string* nombre, * clasif, * genero, * desc, * consola, * status, * res;

int main()
{
	int opc;
	printf("1.-Alta\n2.-Mostrar\n3.-Limpiar pantalla\n4.-Modificar\n5.-Eliminar\n6.-Archivo\n7.-Salir\n");
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
		system("cls"); //system("clear");
		return main();
		break;

	case 4:
		modificar();
		return main();
		break;

	case 5:
		eliminar();
		return main();
		break;

	case 6:
		archivos();
		break;

	case 7:
		exit(1); // cierra la pantalla
		break;

	default:
		printf("\nopcion invalida\n");
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
			printf("Opcion no valida.\n");
		}
	} 
	while (alta <= 0);
	
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

		}
		while (numarticulo[i] <= 0);

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

		iva[i]= subtotal[i] * (0.16f);
		total[i] = iva[i] + subtotal[i];

		printf("El total es: $ %f\n", total[i]);
		printf("El iva es de: $ %f\n\n", iva[i]);

		status[i] = "ACTIVO";
	}
	
}

void listas()
{
	int contador = 0;

	for (int i = 0; i < alta; i++)
	{
		//if (matricula[i] == 0)
		if (status[i] == "ELIMINADO")
		{
			printf("REGISTRO ELIMINADO %d\n ", i + 1);
		}
		else
		{
			contador++;

			printf("registro %d\n", i + 1);
			printf("\n%d\n", numarticulo[i]);
			printf("%s \n", nombre[i].c_str());
			printf("%s \n", genero[i].c_str());
			printf("%s \n", clasif[i].c_str());
			printf("%s \n", consola[i].c_str());
			printf("%s \n", desc[i].c_str());
			printf("%s \n", res[i].c_str());
			printf("$ %f \n", total[i]);
			printf("$ %f \n\n", iva[i]);
		}
	}
	if (contador == 0)
	{
		printf("No hay registros para mostrar.\n");
	}
}

void archivos()
{

	ofstream archivo; //clase ifstream para leer archivos
	string nombrearchivo;
	int texto;
	string texto2;
	                                                                                    
	nombrearchivo = "altasmatricula.txt";

	//printf("Ingrese el nombre de su archivo:\n"); getline(cin, nombrearchivo);

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
		
	}
	printf("El archivo se ha creado exitosamente.\n");
	archivo.close();
}

void eliminar()
{
	int j;
	printf("ingrese el  registro a eliminar \n");
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
		/*
		matricula[i] = 0;
		nombre[i] = " ";
		calf[i] = 0;
		calflab[i] = 0;
		*/
}

void modificar()
{
	int j, opcion, op2;
	do
	{
		printf("ingrese el numero registro a modificar \n");
		scanf_s("%d", &j);

		if (j < 1 || j > alta)
		{
			printf("Registro invalido.\n", alta);
			op2 = 1;
		}
		else
		{
			j = j - 1; // esto debido a que i inicia en 0

			for (int i = j; i == j; i++)
			{
				if (status[i] == "ELIMINADO")
				{
					printf("REGISTRO ELIMINADO %d\n", i + 1);
					printf("Ingrese un registro válido.\n");
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
		printf("Ingrese que desea modificar:\n");
		printf("1. - Numero\n 2. - Nombre\n 3. - Genero\n 4. - Clasificacion\n 5. - Consola\n 6. - Descripcion\n 7. - Resena\n");
		scanf_s("%d", &opcion);

		if (opcion < 1 || opcion > 7)
		{
			printf("Opcion invalida.\n");
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
		}
		break;

	case 2:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n'); //se vacia el buffer o el espacio
			printf("Ingrese el nombre del articulo:\n");
			getline(cin, nombre[i]);
		}
		break;

	case 3:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n'); //se vacia el buffer o el espacio
			printf("Ingrese el genero:\n");
			getline(cin, genero[i]);
		}
		break;


	case 4:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n'); //se vacia el buffer o el espacio
			printf("Ingrese clasificacion:\n");
			getline(cin, clasif[i]);
		}
		break;

	case 5:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n'); //se vacia el buffer o el espacio
			printf("Ingrese la consola:\n");
			getline(cin, consola[i]);
		}
		break;

	case 6:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n'); //se vacia el buffer o el espacio
			printf("Ingrese descripcion:\n");
			getline(cin, desc[i]);
		}
		break;

	case 7:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n'); //se vacia el buffer o el espacio
			printf("Ingrese su resena:\n");
			getline(cin, res[i]);
		}
		break;

	}

}
