// QUITAR LA PALABRA QUE HAY QUE ADIVINAR CUANDO SE FINALICE TODO

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <math.h>
#include <ctype.h>

// Prototipo de funciones
void menu();
void seleccionDif(char nombrejugador[]);
void nivelFacil(char nombrejugador[], int diff, int puntos);
void nivelIntermedio(char nombrejugador[], int diff, int puntos);
void nivelDificil(char nombrejugador[], int diff, int puntos);
int juego();
void dificultad(char nombrejugador[], int diff, int puntos);
void intento(int e);
void tablaPosiciones(char nombrejugador[], int diff, int puntos, int select);
int ingresarPalabras();

// FUNCION PRINCIPAL MAIN
int main()
{
	// llamando a menu
	menu();
	system("pause");
	return 0;
}

// funcion menu
void menu()
{
	char player[100]; // guardando nombre del usuario
	int length = 0, puntos = 0, select = 0, diff = 0;

	// inicio del juego y obteniedo nombre del usuario
	printf("\n\t\t\t\tJUEGO DEL AHORCADO\n");
	printf("\nIngrese su nombre: ");
	fflush(stdin);
	gets(player);
	system("cls");

	// este es un bucle que permite verificar la longitud del nombre
	while (player[length] != '\0')
	{
		length++;
	}

	// estas tres lineas mueven la palabra del array "player" al array "nombrejugador", el cual tiene la longitud exacta de la palabra o frase utilizada
	// esto se realiza para que no hayan grandes espacios despues del nombre que el usuario escribio en el documento de texto
	char nombrejugador[length];
	strncpy(nombrejugador, player, length);
	nombrejugador[length] = '\0';

	// depuracion para saber si es correcta la longitud del string final
	// printf("La longitud del nombre es %d\n\n", strlen(nombrejugador));
	// system("pause");

	char opcion;
	do
	{ // imprime el menu principal varias veces hasta que sea necesario
		system("cls");
		printf("%s, bienvenido a nuestro juego!\n\n", nombrejugador);
		printf("\n\t\t\t\tJUEGO DEL AHORCADO\n");
		printf("\nSeleccione una categoria:\n");
		printf("1.Jugar \n");
		printf("2.Ingresar Palabras\n");
		printf("3.Tabla de posiciones \n");
		printf("4.Salir \n");
		printf("Ingrese opcion: ");
		scanf("%c", &opcion);
	} while (opcion < '1' || opcion > '4'); // evalua los datos ingresados por el usuario

	switch (opcion)
	{ // selecciona el caso ingresado por el usuario
	case '1':
		seleccionDif(nombrejugador);
		break; // llamado a la funcion de seleccion de dificultad
	case '2':
		ingresarPalabras();
		break; // llamado a la funcion ingresar palabras
	case '3':
		tablaPosiciones(nombrejugador, diff, puntos, select);
		break; // llamado a la funcion tabla de posiciones
	case '4':
		printf("\n\nGracias por jugar!\n\n");
		break;
	}
}

// Selector de dificultad
void seleccionDif(char nombrejugador[])
{
	system("cls");
	// variables
	int op, length = 0, puntos = 0;

	do
	{
		system("cls");
		printf("\n\t\t\t\tJUEGO DEL AHORCADO\n");
		printf("\nSELECCIONE EL NIVEL DE DIFICULTAD CON EL DESEA JUGAR:\n");
		printf("1. Nivel Facil \n");
		printf("2. Nivel Intermedio \n");
		printf("3. Nivel Dificil \n");
		printf("4. Regresar al menu principal \n");
		printf("Ingrese opcion: ");
		scanf("%d", &op);
	} while (op < 1 || op > 4);

	switch (op)
	{
	case 1:
		nivelFacil(nombrejugador, op, puntos);
		break;
	case 2:
		nivelIntermedio(nombrejugador, op, puntos);
		break;
	case 3:
		nivelDificil(nombrejugador, op, puntos);
		break;
	case 4:
		menu(); // regresando al menu
		break;
	}
}

void nivelFacil(char nombrejugador[], int diff, int puntos)
{
	system("cls");
	char palabras[100][100];
	FILE *facil;
	int i = 0, conta = 0;
	facil = fopen("facil.txt", "r"); // abre el archivo en solo lectura

	while (fgets(palabras[i], 100, facil))
	{
		palabras[i][strlen(palabras[i]) - 1] = '\0';
		i++;
	}

	fclose(facil);

	// se da una semilla para el generador y se genera un numero aleatorio
	srand(time(NULL));
	int n = rand() % i;

	// debug, se imprimen cada una de las posiciones del arreglo ademas de valores utiles
	// for (conta = 0; conta < i; conta++)
	//{
	//	printf("%s|", palabras[conta]);
	//}
	// printf("\nNumero aleatorio es %d\n", n);
	printf("La palabra aleatoria es %s\n", palabras[n]);
	// printf("El nombre es %s\n", nombrejugador);

	juego(palabras[n], nombrejugador, diff, puntos); // mandando el valor a la funcion juego
}

void nivelIntermedio(char nombrejugador[], int diff, int puntos)
{
	system("cls");
	char palabras[100][100];
	FILE *facil;
	int i = 0, conta = 0;
	facil = fopen("medio.txt", "r"); // abre el archivo en solo lectura

	while (fgets(palabras[i], 100, facil))
	{
		palabras[i][strlen(palabras[i]) - 1] = '\0';
		i++;
	}

	fclose(facil);

	// se da una semilla para el generador y se genera un numero aleatorio
	srand(time(NULL));
	int n = rand() % i;

	// debug, se imprimen cada una de las posiciones del arreglo ademas de valores utiles
	// for (conta = 0; conta < i; conta++)
	//{
	//	printf("%s|", palabras[conta]);
	//}
	// printf("\nNumero aleatorio es %d\n", n);
	printf("La palabra aleatoria es %s\n", palabras[n]);
	// printf("El nombre es %s\n", nombrejugador);

	juego(palabras[n], nombrejugador, diff, puntos); // mandando el valor a la funcion juego
}

void nivelDificil(char nombrejugador[], int diff, int puntos)
{
	system("cls");
	char palabras[100][100];
	FILE *facil;
	int i = 0, conta = 0;
	facil = fopen("dificil.txt", "r"); // abre el archivo en solo lectura

	while (fgets(palabras[i], 100, facil))
	{
		palabras[i][strlen(palabras[i]) - 1] = '\0';
		i++;
	}

	fclose(facil);

	// se da una semilla para el generador y se genera un numero aleatorio
	srand(time(NULL));
	int n = rand() % i;

	// debug, se imprimen cada una de las posiciones del arreglo ademas de valores utiles
	// for (conta = 0; conta < i; conta++)
	//{
	//	printf("%s|", palabras[conta]);
	//}
	// printf("\nNumero aleatorio es %d\n", n);
	printf("La palabra aleatoria es %s\n", palabras[n]);
	// printf("El nombre es %s\n", nombrejugador);

	juego(palabras[n], nombrejugador, diff, puntos); // mandando el valor a la funcion juego
}

int juego(char palabras[], char nombrejugador[], int diff, int puntos)
{
	// se declaran variables de uso interno y el array de la palabra a utilizar, ademas de las letras que el usuario ingrese
	int longitud = 0, error = 0, intentos = 0, i = 0, contador = 0, select = 1;
	char respuesta[100], letra, res, res1;
	do
	{
		// se calcula la longitud de la respuesta
		longitud = strlen(palabras);
		intentos = 0; // contabilizador de intentos fallidos inicia en 0
		contador = 0; // contador interno

		// este bucle es para mostrar las letras como "_" y los espacios de la frase (si es que tiene)
		for (i = 0; i < longitud; i++)
		{
			fflush(stdin);
			if (isblank(palabras[i]))
			{
				respuesta[i] = ' ';
			}
			else
			{
				respuesta[i] = '_';
			}
			printf(" %c ", respuesta[i]);
		}

		// se omite que el usuario ingrese espacios cuando sea el momento de ingresar caracteres
		for (i = 0; i < longitud; i++)
		{
			if (isblank(respuesta[i]))
			{
				contador++;
			}
		}

		// el propio juego en si
		do
		{
			// se pide que se ingrese una letra para ver si se puede adivinar
			fflush(stdin);
			printf("\n\nIngrese una letra: ");
			scanf("%c", &letra);
			system("cls");
			error = 0;

			for (i = 0; i < longitud; i++)
			{
				// la letra ingresada se compara a las letras de la palabra o frase a adivinar, sin importar mayusculas o minusculas
				if (letra == toupper(palabras[i]) || letra == tolower(palabras[i]))
				{
					if (letra != respuesta[i])
					{
						respuesta[i] = letra; // sustituye el "_" por la letra correspondiente
						contador++;			  // aumenta contador en uno
						puntos = puntos + 10; // se suman puntos por adivinar letras correctamente
					}
				}
				else
				{
					error++; // aumenta el error en uno
				}
				printf(" %c ", respuesta[i]); // se imprime el caracter final, sea la letra correcta o se queda como "_" si la letra es incorrecta
			}

			// entra si la letra advinada no es igual a ninguna opcion
			if (error == longitud)
			{
				// aumenta el intento si la letra ingresada no es igual a ninguna de las letras de la palabra a adivinar, ademas se restan puntos
				intentos++;
				puntos = puntos - 5;
			}
			// se entra a la funcion intentos
			intento(intentos);
		} while (contador < longitud && intentos < 6);
		// todo se repite mientras el numero de intentos fallidos no supere 6 y el contador de letras adivinadas sea menos al total de letras adivinadas

		// cuando se comete el numero maximo de intentos, se imprime que el juego ha terminado
		if (intentos == 6)
		{
			printf("\nGAME OVER :(\n");
			tablaPosiciones(nombrejugador, diff, puntos, select);
			if (puntos < 0)
			{
				// si los valores quedan negativos, no hay puntos y se imprime 0
				printf("Su puntaje es: 0\n");
				// se reinician los puntos
				puntos = 0;
			}
			else
			{
				// Si a pesar de perder hay puntos, se muestran aqui
				printf("Su puntaje es: %d\n", puntos);
				// se reinician los puntos
				puntos = 0;
			}

			// se muestra la palabra correcta
			printf("La palabra correcta era: ");
			for (i = 0; i < longitud; i++)
			{
				printf("%c", palabras[i]);
			}
		}

		// entra si todas las letras ingresadas corresponden a la palabra y se cometieron menos de 6 errores
		if (contador == longitud)
		{
			if (intentos == 0)
			{ // si no se cometio ningun error
				printf("\nFelicidades, Usted ha ganado sin cometer ningun error \n");
				printf("Su puntaje es: %d", puntos);
			}
			else
			{ // si los intentos fallidos fueron menores a 6 pero mayores a 0
				printf("\nFelicidades, usted ha ganado, con %d intentos fallidos \n", intentos);
				printf("Su puntaje es: %d", puntos);
			}
		}

		// despues de ganar o perder, se pregunta si se quiere volver a jugar
		fflush(stdin);
		printf("\n\nPresione ''S'' si desea volver a jugar o cualquier otra tecla si no es asi: ");
		scanf("%s", &res);
		fflush(stdin);

		if (res == 'S' || res == 's')
		{
			// system("cls");
			dificultad(nombrejugador, diff, puntos);
		}
	} while (res == 'S' || res == 's');
	// si el caracter ingresado es S repite el juego

	tablaPosiciones(nombrejugador, diff, puntos, select);

	// se pregunta si se quiere volver al menu o salir
	printf("\nPresione ''N'' para volver al menu, cualquier otra tecla para salir: ");
	scanf("%s", &res1);
	if (res1 == 'N' || res1 == 'n')
	{ // si el caracter ingresado es N regresara al menu
		menu();
	}
	else
	{
		printf("\nGracias por jugar!\n");
		system("pause");
		exit(0);
	}
}

void dificultad(char nombrejugador[], int diff, int puntos)
{
	fflush(stdin);
	switch (diff)
	{
	case 1:
		nivelFacil(nombrejugador, diff, puntos);
		break;
	case 2:
		nivelIntermedio(nombrejugador, diff, puntos);
		break;
	case 3:
		nivelDificil(nombrejugador, diff, puntos);
		break;
	}
}

// mostrar y guardar el puntaje
void intento(int intentos)
{
	int f = 0;
	f = 6 - intentos;
	printf("\nUsted tiene %d oportunidades restantes.\n", f);
}

void tablaPosiciones(char nombrejugador[], int diff, int puntos, int select)
{
	if (select == 0)
	{
		system("cls");
		char leaderboard[100][100];
		FILE *tabla;
		int i = 0, conta = 0, op, n = 0;
		char f[] = "Nivel facil", m[] = "Nivel intermedio", d[] = "Nivel dificil";
		char ef[] = "Fin facil", em[] = "Fin intermedio";
		tabla = fopen("tabla.txt", "r"); // abre el archivo

		while (fgets(leaderboard[i], sizeof(leaderboard), tabla))
		{
			leaderboard[i][strlen(leaderboard[i]) - 1] = '\0';
			i++;
		}

		// se cierra el archivo
		fclose(tabla);

		do
		{
			// system("cls");
			printf("\n\t\t\t\tJUEGO DEL AHORCADO\n");
			printf("\nSeleccione la dificultad de las puntuaciones que desea ver :\n");
			printf("1. Nivel Facil \n");
			printf("2. Nivel Intermedio \n");
			printf("3. Nivel Dificil \n");
			printf("4. Regresar al menu principal \n");
			printf("Ingrese opcion: ");
			scanf("%d", &op);
		} while (op < 1 || op > 4);

		printf("HIGHSCORES\n\n");

		switch (op)
		{
		// tabla nivel facil
		case 1:
			op = 0;
			do
			{
				for (conta = 0; conta < i; conta++)
				{
					if (strcmp(ef, leaderboard[conta]) == 0)
					{
						printf("");
						break;
					}
					else
					{
						printf("%s\n", leaderboard[conta]);
					}
				}

				printf("\nIngrese la opcion que desee: \n");
				printf("1. Volver al menu de puntuaciones\n");
				printf("2. Volver al menu principal\n");
				printf("\nIngrese su opcion: ");
				scanf("%d", &op);
			} while (op < 1 || op > 2);

			switch (op)
			{
			case 1:
				tablaPosiciones(nombrejugador, diff, puntos, select);
				break;
			case 2:
				menu();
				break;
			}
			break;

		// tabla nivel medio
		case 2:
			op = 0;
			do
			{
				for (conta = 0; conta < i; conta++)
				{
					if (strcmp(m, leaderboard[conta]) == 0)
					{
						printf("");
						n = conta;
						break;
					}
				}

				for (conta = n; conta < i; conta++)
				{
					if (strcmp(em, leaderboard[conta]) == 0)
					{
						printf("");
						break;
					}
					else
					{
						printf("%s\n", leaderboard[conta]);
					}
				}

				printf("\nIngrese la opcion que desee: \n");
				printf("1. Volver al menu de puntuaciones\n");
				printf("2. Volver al menu principal\n");
				printf("\nIngrese su opcion: ");
				scanf("%d", &op);
			} while (op < 1 || op > 2);

			system("cls");

			switch (op)
			{
			case 1:
				tablaPosiciones(nombrejugador, diff, puntos, select);
				break;
			case 2:
				menu();
				break;
			}
			break;

		// tabla nivel dificil
		case 3:
			op = 0;
			do
			{
				for (conta = 0; conta < i; conta++)
				{
					if (strcmp(d, leaderboard[conta]) == 0)
					{
						printf("");
						n = conta;
						break;
					}
				}

				for (conta = n; conta < i; conta++)
				{
					printf("%s\n", leaderboard[conta]);
				}

				printf("\nIngrese la opcion que desee: \n");
				printf("1. Volver al menu de puntuaciones\n");
				printf("2. Volver al menu principal\n");
				printf("\nIngrese su opcion: ");
				scanf("%d", &op);
			} while (op < 1 || op > 2);

			switch (op)
			{
			case 1:
				tablaPosiciones(nombrejugador, diff, puntos, select);
				break;
			case 2:
				menu();
				break;
			}
			break;

			// regresando al menu
		case 4:
			menu();
			break;
		}
	}
	else
	{
		// funcion para agregar mas valores a la tabla
		char leaderboard[100][100], niveles[100][100];
		FILE *tabla2 = fopen("tabla.txt", "r+");
		int a = 0, i = 0, i2 = 0, conta = 0, op, n = 0, tamano = 0, swap, puntaje[20];
		char f[] = "Nivel facil", m[] = "Nivel intermedio", d[] = "Nivel dificil";
		char ef[] = "Fin facil", em[] = "Fin intermedio";

		while (fgets(leaderboard[i], sizeof(leaderboard), tabla2))
		{
			leaderboard[i][strlen(leaderboard[i]) - 1] = '\0';
			i++;
		}

		fclose(tabla2);
		FILE *tabla = fopen("tabla.txt", "w+");

		switch (diff)
		{
		// tabla nivel facil
		case 1:

			for (conta = 0; conta < i; conta++)
			{
				if (strcmp(ef, leaderboard[conta]) == 0)
				{
					fprintf(tabla, "%s\n%d\n", nombrejugador, puntos);
					fprintf(tabla, "%s\n", leaderboard[conta]);
				}
				else
				{
					fprintf(tabla, "%s\n", leaderboard[conta]);
				}
			}
			fclose(tabla);
			break;

		// tabla nivel medio
		case 2:

			for (conta = 0; conta < i; conta++)
			{
				if (strcmp(em, leaderboard[conta]) == 0)
				{
					fprintf(tabla, "%s\n%d\n", nombrejugador, puntos);
					fprintf(tabla, "%s\n", leaderboard[conta]);
				}
				else
				{
					fprintf(tabla, "%s\n", leaderboard[conta]);
				}
			}
			fclose(tabla);
			break;

		// tabla nivel dificil
		case 3:
			for (conta = 0; conta < i; conta++)
			{
				fprintf(tabla, "%s\n", leaderboard[conta]);
			}
			fprintf(tabla, "%s\n%d\n", nombrejugador, puntos);
			fclose(tabla);
			break;
		}
	}
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

	int nueva = 1;

	while (nueva == 1)
	{

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
			system("cls");
			printf("\nIngrese palabras o frases para incluirlas en el juego, minimo 6 espacios, o ingrese 1 para regresar al menu principal:\n");
			fgets(str, sizeof(str), stdin);

			// si se selecciona 1, se regresa al menu principal
			if (str[0] == '1')
			{
				// se cierran los documentos
				fclose(ez);
				fclose(mid);
				fclose(hard);
				menu();
			}

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
				printf("\nPor favor ingrese una palabra o frase con al menos 6 espacios\n");
				system("pause");
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

			// lineas de depuracion para saber el valor de nonchar y length
			// printf("\nnonchar es %d\n", nonchar);
			// printf("length es %d\n\n", length);

			// si se encuentra algo que no sea una letra o espacio, se imprime un mensaje de informacion
			if (nonchar > 0)
			{
				printf("\nPor favor ingrese una palabra o frase sin numeros o caracteres especiales\n");
				system("pause");
			}

			// si se encuentran espacios al inicio o al final de la frase o palabra, se imprime un mensaje de informacion y se reinicia el loop
			// si no se encuentran espacios al inicio o final, el valor de space es igual a 0 y se guarda la palabra o frase ingresada
			if (isblank(str[0]) || isblank(str[(length - 1)]))
			{
				space = 1;
				printf("\nPor favor ingrese una palabra o frase sin espacios al inicio o al final\n");
				system("pause");
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

		// se declara que nueva sea igual a 0 de nuevo para ingresar en el siguiente loop
		nueva = 0;

		// este loop sirve para que el usuario seleccione entre agregar una nueva palabra y regresar al menu principal
		while (nueva != 1)
		{
			nueva = 0;
			printf("\nEscriba 1 para ingresar una nueva palabra y 2 para regresar al menu principal: ");
			scanf("%d", &nueva);

			// si se selecciona 2, se guardan las palabras que se ingresaron y se regresa al menu principal
			if (nueva == 2)
			{
				// se cierran los documentos
				fclose(ez);
				fclose(mid);
				fclose(hard);
				menu();
				return 1;
			}
			// si se selecciona cualquier otro numero, se pide al usuario ingresar o 1 o 2
			else if (nueva != 2 && nueva != 1)
			{
				printf("Por favor ingrese 1 o 2\n");
				nueva = 0;
			}
			// si se ingresa 1, el valor de la variable "nueva" sigue siendo 1
			else
			{
				nueva = 1;
			}
		}
	}
}