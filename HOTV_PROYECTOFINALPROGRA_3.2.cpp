#include <iostream>
#include <conio.h>
#include <string.h>
#include <string>                         
#include <fstream>
#include <stdlib.h>// funcione new y delete
#include <vector>
#include <clocale> //para la letra ñ y acentuar


using namespace std;

//definir la funcion
void Alta();
void Baja();
void listas();
void archivos();
void modificar();

int alta, * numitem, baja,* fecha, contador = 0;
float* subtotal, * iva, * total;

string* nombre = new string[100];
string* clasif = new string[100];
string* genero = new string[100];
string* desc = new string[100];
string* status = new string[100];
string* consola = new string[100];
string* res = new string[100];


int main()
{
	int opc;
	printf("\n\t\t~~~ TIENDA DE VIDEOJUEGOS ~~~");
	printf("\n1.-Alta\n2.-Lista\n3.-Modificar\n4.-Limpiar pantalla\n5.-Baja\n6.-Salir\n");  //categoría=clasificación
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

	numitem = new int[alta]; //arreglos
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
	fecha = new int[alta];

	for (int i = 0; i < alta; i++)
	{
		int num;
		bool numrepetido; //variable de tipo booleano 

		do
		{
			numrepetido = false;
			printf("Ingrese el numero del articulo:\n");
			scanf_s("%d", &num);

			if (num <= 0)
			{
				printf("\nNumero invalido.\n");
			}
			else
			{
				// Verificar si el número de artículo ya existe
				for (int j = 0; j < i; j++)
				{
					if (numitem[j] == num)
					{
						printf("El numero de articulo ya existe.Ingrese otro numero.\n");
						numrepetido = true;
						break;
					}
				}
			}
		} while (num <= 0 || numrepetido);

		numitem[i] = num;

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

		printf("Ingrese su rese%ca del articulo:\n", 164);
		getline(cin, res[i]);

		printf("Ingrese el a%co de lanzamiento: \n", 164);
		scanf_s("%d", &fecha[i]);

		while (fecha[i] < 1960 || fecha[i] > 2023)
		{
			printf("La fecha esta fuera del rango.Vuevla a ingresar: \n");
			scanf_s("%d", &fecha[i]);
		}
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
	contador++;
}

void listas()
{
	int opcion;
	string busqueda;

	printf("\nIngrese una opcion para filtrar:\n");
	printf("1.- Categoria/Clasificacion\n");
	printf("2.- Genero\n");
	printf("3.- Consola\n");
	printf("4.- Ver lista completa\n");
	scanf_s("%d", &opcion);

	switch (opcion) {
	case 1:
		
		if (contador == 0) {
			printf("No hay registros para mostrar.\n");
		}
		else {
			// Filtrar por Categoría/Clasificación
			printf("Ingrese la categoria/clasificacion:\n");
			cin.ignore();
			getline(cin, busqueda);
			printf("\nLISTA FILTRADA POR CATEGORIA/CLASIFICACION:\n");
			int contadorBusqueda = 0;
			for (int i = 0; i < alta; i++)
			{
				if (status[i].compare("ELIMINADO") != 0 && clasif[i] == busqueda)
				{
					
					contadorBusqueda++;
					cout << clasif[i] << endl;

				}
			}
			if (contadorBusqueda == 0) {
				cout << "No se ha encontrado nada con esa busqueda" << endl;
			}
		}
		break;
	case 2:

		
		if (contador == 0) {
			printf("No hay registros para mostrar.\n");
		}
		else 
		{
			// Filtrar por Genero
			printf("Ingrese el genero:\n");
			cin.ignore();
			getline(cin, busqueda);

			printf("\nLISTA FILTRADA POR GENERO:\n");
			int contadorBusqueda = 0;
			for (int i = 0; i < alta; i++)
			{
				if (status[i].compare("ELIMINADO") != 0 && genero[i] == busqueda)
				{
					contadorBusqueda++;
					cout << genero[i] << endl;        

				}
			}
			if (contadorBusqueda == 0) {
				cout << "No se ha encontrado nada con esa busqueda" << endl;
			}
		}
		break;
	case 3:
		
		if (contador == 0) {
			printf("No hay registros para mostrar.\n");
		}
		else {
			// Filtrar por Consola
			printf("Ingrese la consola:\n");
			cin.ignore();
			getline(cin, busqueda);

			printf("\nLISTA FILTRADA POR CONSOLA\n");
			int contadorBusqueda = 0;
			for (int i = 0; i < alta; i++)
			{
				if (status[i].compare("ELIMINADO") != 0 && consola[i] == busqueda)
				{
					contadorBusqueda++;
					cout << consola[i] << endl;

				}
			}
			if (contadorBusqueda == 0) {
				cout << "No se ha encontrado nada con esa busqueda" << endl;
			}
		}
		break;

	case 4:
		// Ver lista completa sin filtrar
		printf("\nLISTA COMPLETA:\n\n");
		if (contador == 0) {
			printf("\nNo hay registros para mostrar.\n");
		}
		else {

			int contadorBusqueda = 0;
			for (int i = 0; i < alta; i++)
			{
				if (status[i] == "ELIMINADO")
				{
					printf("REGISTRO ELIMINADO %d\n\n ", i + 1);
				}
				else
				{
					contadorBusqueda++;

					printf("Registro: #%d\n\n", i + 1);
					printf("Articulo:#%d\n", numitem[i]);
					printf("Nombre del articulo:%s \n", nombre[i].c_str());
					printf("Genero del articulo:%s \n", genero[i].c_str());
					printf("Clasificacion del articulo:%s \n", clasif[i].c_str());
					printf("Tipo de consola:%s \n", consola[i].c_str());
					printf("Descripcion del articulo:%s \n", desc[i].c_str());
					printf("Rese%ca del articulo:%s \n", 164, res[i].c_str());
					printf("A%co de lanzamiento:%d\n", 164, fecha[i]);
					printf("Costo a pagar del articulo:$ %.2f \n", total[i]);
					printf("Cantidad de impuesto:$ %.2f \n\n", iva[i]);
				}
			}
		}
		break;

	default:
		printf("Opcion invalida.\n");
		break;
	}

	//printf("\nLISTA:\n");
	//for (int i = 0; i < alta; i++)
	//{
	//	if (status[i] == "ELIMINADO")
	//	{
	//		printf("REGISTRO ELIMINADO %d\n ", i + 1);
	//	}
	//	else
	//	{
	//		contador++;
	//		printf("Registro: #%d\n", i + 1);
	//		printf("\nArticulo:#%d\n", numitem[i]);
	//		printf("Nombre del articulo:%s \n", nombre[i].c_str());
	//		printf("Genero del articulo:%s \n", genero[i].c_str());
	//		printf("Clasificacion del articulo:%s \n", clasif[i].c_str());
	//		printf("Tipo de consola:%s \n", consola[i].c_str());
	//		printf("Descripcion del articulo:%s \n", desc[i].c_str());
	//		printf("Rese%ca del articulo:%s \n",164, res[i].c_str());
	//		printf("Costo a pagar del articulo:$ %.2f \n", total[i]);
	//		printf("Cantidad de impuesto:$ %.2f \n", iva[i]);
	//		printf("A%co de lanzamiento:%d\n", 164, fecha);
	//	}
	//}
	//if (contador == 0)
	//{
	//	printf("No hay registros para mostrar.\n");
	//}
}

void Baja()
{
	int j;
	printf("Ingrese el registro a eliminar:\n");
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
	setlocale(LC_CTYPE, "Spanish");
	ofstream archivo; //clase ifstream para leer archivos
	string nombrearchivo;

	nombrearchivo = "ProyectoFINAL.txt";

	archivo.open(nombrearchivo.c_str(), ios::out);


	if (archivo.fail())
	{
		printf("ERROR NO SE PUDO CREAR EL ARCHIVO");
		exit(1);
	}

	archivo << "| NÚMERO |" << "\t";
	archivo << "| NOMBRE |" << "\t";
	archivo << "| GÉNERO |" << "\t";
	archivo << "| CLASIFICACIÓN |" << "\t";
	archivo << "| CONSOLA |" << "\t";
	archivo << "| DESCRIPCIÓN |" << "\t";
	archivo << "| RESEÑA |" << "\t";
	archivo << "| AÑO DE PUBLICACIÓN |" << "\t";
	archivo << "| TOTAL |" << "\n";

	for (int i = 0; i < alta; i++)
	{
		if (status[i] == "ELIMINADO")
		{
			archivo << "\n" << "#" << i + 1 << "\t" << "REGISTRO ELIMINADO" << "\n";
			
		}
		else
		{
			archivo << "#" << numitem[i] << "\t" << "\t";
			archivo << nombre[i] << "\t" << "\t";
			archivo << genero[i] << "\t" << "\t";
			archivo << clasif[i] << "\t" << "\t" << "\t";
			archivo << consola[i] << "\t" << "\t";
			archivo << desc[i] << "\t" << "\t" << "\t";
			archivo << res[i] << "\t" << "\t" << "\t";
			archivo << fecha[i] << "\t" << "\t" << "\t";
			archivo << "$" << total[i] << "\t" << "\t";
		}

	}
	printf("\nEl archivo se ha creado exitosamente.\n");
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
		printf("Ingrese que desea modificar:\n");
		printf(" 1. - Numero\n 2. - Nombre\n 3. - Genero\n 4. - Clasificacion\n 5. - Consola\n 6. - Descripcion\n 7. - Resena\n 8. - Fecha\n 9. - Precio\n");
		scanf_s("%d", &opcion);

		if (opcion < 1 || opcion > 9)
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
			int num;
			bool numrepetido;

			do
			{
				numrepetido = false;
				printf("Ingrese el numero del articulo:\n");
				scanf_s("%d", &num);

				if (num <= 0)
				{
					printf("\nNumero invalido.\n");
				}
				else
				{
					for (int i = 0; i < alta; i++)
					{
						if (i != j && numitem[i] == num)
						{
							printf("El numero de articulo ya existe. Ingrese otro numero.\n");
							numrepetido = true;
							break;
						}
					}
				}
			} while (num <= 0 || numrepetido);

			numitem[j] = num;
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
			//fecha
			printf("Ingrese el a%co de lanzamiento: \n", 164);
			scanf_s("%d", &fecha[i]);
			while (fecha[i] < 1960 || fecha[i] > 2023)
			{
				printf("La fecha esta fuera del rango.Vuevla a ingresar: \n");
				scanf_s("%d", &fecha[i]);
			}
		}
		break;
	case 9:
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