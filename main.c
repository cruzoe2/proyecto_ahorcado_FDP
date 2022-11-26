#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <math.h>
#include <ctype.h>
#define LONGITUD_MAXIMA_CADENA 1000

// Prototipo de funciones
void menu();
void carga();
void nivelFacil();
void nivelintermedio();
void niveldificil();
int ingresarPalabras();
void tabla();
int juego();
void rotulo(int e);
void gotoxy(short x, short y);

// FUNCION PRINCIPAL MAIN
int main()
{

	// llamando a menu
	menu();

	return 0;
}

// FUNCION DEL MENU seleccionada

void menu()
{
	char opcion;
	do
	{ // imprime el menu principal varias veces hasta que sea necesario
		system("cls");
		printf("\n\t\t\tJUEGO DEL AHORCADO \n\t\t\t");
		printf("Seleccione una categoria \n");
		printf("1.Jugar \n");
		printf("2.Ingresar Palabras\n");
		printf("3.Tabla de posiciones \n");
		printf("4.Salir \n");
		printf("Ingrese opcion: ");
		scanf("%c", &opcion);
	} while (opcion < '1' || opcion > '4'); // evalua los datos ingresados por el usuario
	switch (opcion)
	{ // seleeciona el caso ingresado por el usuario
	case '1':
		juego();
		break; // llamado a la funcion juego
	case '2':
		ingresarPalabras();
		break; // ingresar palabras
	case '3':
		// void tabla()
		break; // llamado a la funcion tabla de posiciones
	case '4':
		printf("\n\nGracias por utilizar nuestro programa.....\n\n");
		break;
	}
}

// FUNCION PRINCIPAL DEL JUEGO
int juego()
{

	// variables
	int op;
	char player[25]; // guardando nombre del usuario

	// inicio del juego y obteniedo nombre del usuario
	printf("\n\t\t\t\tJUEGO DEL AHORCADO\n\t\t\t\t");
	printf("\nIngrese su nombre: ");
	fflush(stdin);
	gets(player);
	system("cls");
	printf("Bienvenido %s a nuestro juego", player);

	do
	{
		system("cls");
		printf("\n\t\t\t\tJUEGO DEL AHORCADO\n\t\t\t\t");
		printf("SELECCIONE EL NIVEL DE DIFICULTAD CON EL DESEA JUGAR \n");
		printf("1. Nivel Facil \n");
		printf("2. Nivel intermedio \n");
		printf("3. Nivel Dificil \n");
		printf("4. Regresar al menu principal \n");
		scanf("%d", &op);
	} while (op < 1 || op > 4);

	switch (op)
	{
	case 1:
		nivelFacil();
		break;
	case 2:

		break;
	case 3:

		break;
	case 4:
		menu(); // regresando al menu
		break;
	}
}

void nivelFacil()
{
	char const s[] = "\n\t";
	char *token;
	char arreglo[LONGITUD_MAXIMA_CADENA];
	int longitud;
	FILE *archivo = fopen("facil.txt", "r");
	char bufer[LONGITUD_MAXIMA_CADENA]; // Aquí vamos a ir almacenando cada línea

	while (fgets(bufer, LONGITUD_MAXIMA_CADENA, archivo))
	{
		longitud = strlen(bufer);

		token = strtok(bufer, s);
		// La imprimimos, pero realmente podríamos hacer cualquier otra cosa
		while (token != NULL)
		{
			printf("\n%s\n", token);
			token = strtok(NULL, s);
			for (int i = 0; i <= longitud; i++)
			{

				arreglo[i] = bufer[i];
				putchar(arreglo[i]);
			}
		}
	}

	printf("\n %d", longitud);
}

// mostrar los puntajes de cada jugador
void puntajes()
{
}

// Funcion ingresar palabras
int ingresarPalabras()
{
	// se abren los archivos que contendran las palabras
	FILE *ez = fopen("facil.txt", "a");
	FILE *mid = fopen("medio.txt", "a");
	FILE *hard = fopen("dificil.txt", "a");

	// se confirma que se abrieron los archivos correctamente
	if (ez == NULL)
	{
		printf("ERROR!");
		return 1;
	}
	if (mid == NULL)
	{
		printf("ERROR!");
		return 1;
	}
	if (hard == NULL)
	{
		printf("ERROR!");
		return 1;
	}

	// se declaran variables, ademas de un string lo suficientemente largo
	int count, length = 0, nonchar = 1, space = 0;
	char str[1000];

	// se hace un loop que mantiene al usuario en la ventana de ingresar frase mientras se cumplan los requisitos
	// en este caso son, una longitud igual o mayor a 6 caracteres, que solo tenga letras y espacios, y que no hayan espacios al inicio o al final de la palabra o frase
	while (length < 6 || nonchar > 0 || space > 0)
	{
		// se reinician ciertos valores si acaso
		length = 0;
		nonchar = 1;

		// se le pide al usuario ingresar una palabra o frase y se guarda en el array "str"
		printf("Ingrese palabras o frases para incluirlas en el juego, minimo 6 espacios: ");
		fgets(str, sizeof(str), stdin);

		// este es un bucle que permite verificar la longitud de la palabra o frase
		while (str[length] != '\0')
		{
			length++;
		}
		// se tiene que restar uno a length ya que el string se almacena con una posicion vacia al final
		length--;

		// si hay menos de 6 letras, se pide que se ingrese una palabra o frase con al menos 6 espacios
		if (length < 6)
		{
			printf("Por favor ingrese una palabra o frase con al menos 6 espacios\n\n");
		}

		// luego, para cada caracter de lo ingresado, se verifica que sean solo letras o espacios, sino se suma uno a nonchar cada vez que se detecta un caracter extraño
		for (count = 0; count < length; count++)
		{
			if (isalpha(str[count]) || isblank(str[count]))
			{
			}
			else
			{
				nonchar++;
			}
		}
		// se tiene que restar uno a nonchar ya que el valor inicial de la variable es 1, y el programa pide que se repita mientras sea superior a 0
		nonchar--;

		// lineas de sepuracion para saber el valor de nonchar y length
		// printf("\nnonchar es %d\n", nonchar);
		// printf("length es %d\n\n", length);

		// si se encuentra algo que no sea una letra o espacio, se imprime un mensaje de informacion
		if (nonchar > 0)
		{
			printf("Por favor ingrese una palabra o frase sin numeros o caracteres especiales\n\n");
		}

		// si se encuentran espacios al inicio o al final de la frase o palabra, se imprime un mensaje de informacion y se reinicia el loop
		// si no se encuentran espacios al inicio o final, el valor de space es igual a 0 y se guarda la palabra o frase ingresada
		if (isblank(str[0]) || isblank(str[(length - 1)]))
		{
			space = 1;
			printf("Por favor ingrese una palabra o frase sin espacios al inicio o al final\n\n");
		}
		else
		{
			space = 0;
		}
	}

	// estas tres lineas mueven la palabra del array "str" al array "palabra", el cual tiene la longitud exacta de la palabra o frase utilizada
	// esto se realiza para que no hayan grandes espacios despues de la palabra o frase que el usuario escribio en el documento de texto
	char palabra[length];
	strncpy(palabra, str, length);
	palabra[length] = '\0';

	// otra linea de depuracion para saber la longitud de la nueva string, "palabra"
	// printf("La longitud de palabra o frase es %d\n\n", strlen(palabra));

	// aqui se determina en que documento se guardaran las palabras o frases, dependiendo de su longitud
	// si la longitud es superior a 11 e inferior a 20, sera guardado en el documento de dificultad media
	if (strlen(palabra) > 11 && strlen(palabra) < 20)
	{
		fprintf(mid, "%s\n", palabra);
	}
	// si la longitud es superior a 19, sera guardado en el documento de dificultad dificil
	else if (strlen(palabra) > 19)
	{
		fprintf(hard, "%s\n", palabra);
	}
	// si la longitud es inferior a 12, sera guardado en el documento de dificultad facil
	else
	{
		fprintf(ez, "%s\n", palabra);
	}

	// se cierran los documentos
	fclose(ez);
	fclose(mid);
	fclose(hard);
}