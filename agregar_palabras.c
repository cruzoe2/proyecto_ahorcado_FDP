#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
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
    return 0;
}