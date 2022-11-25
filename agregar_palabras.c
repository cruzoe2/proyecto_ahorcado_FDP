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

    // se declaran variables, ademas de un string
    int count, length = 0, nonchar = 1, space = 0;
    char str[1000];

    while (length < 6 || nonchar > 0 || space > 0)
    {
        length = 0;
        nonchar = 1;

        // se le pide al usuario ingresar una palabra o frase y se guarda en el array "str"
        printf("Ingrese palabras o frases para incluirlas en el juego, minimo 6 espacios: ");
        fgets(str, sizeof(str), stdin);

        // este es un bucle que permite verificar la longitud de la palabra
        while (str[length] != '\0')
        {
            length++;
        }
        // se tiene que restar uno a length ya que el string se almacena con una posicion vacia al final
        length--;

        if (length < 6)
        {
            printf("Por favor ingrese una palabra o frase con al menos 6 espacios\n\n");
        }

        for (count = 0; count < length; count++)
        {
            if (isalpha(str[count]) || isblank(str[count]))
            {
                printf("lol");
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

        if (nonchar > 0)
        {
            printf("Por favor ingrese una palabra o frase sin numeros o caracteres especiales\n\n");
        }

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

    printf("La longitud de palabra o frase es %d\n\n", strlen(palabra));

    if (strlen(palabra) > 11 && strlen(palabra) < 20)
    {
        fprintf(mid, "%s\n", palabra);
    }
    else if(strlen(palabra) > 19)
    {
        fprintf(hard, "%s\n", palabra);
    }
    else
    {
        fprintf(ez, "%s\n", palabra);
    }

    // se imprimen en el documento la palabra o frase

    // se cierra el documento
    fclose(ez);
    fclose(mid);
    fclose(hard);
    return 0;
}