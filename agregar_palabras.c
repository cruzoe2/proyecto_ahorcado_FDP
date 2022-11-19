#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    // se abre el archivo que contendra el resultado
    FILE *pal = fopen("palabras.txt", "a");

    // se confirma que se abrio el archivo correctamente
    if (pal == NULL)
    {
        printf("ERROR!");
        return 1;
    }

    // se declaran variables, ademas de un string
    int count, length = 0, nonchar = 1;
    char str[1000];

    while (length < 6 || nonchar > 0)
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
    }

    // estas tres lineas mueven la palabra del array "str" al array "palabra", el cual tiene la longitud exacta de la palabra o frase utilizada
    // esto se realiza para que no hayan grandes espacios despues de la palabra o frase que el usuario escribio en el documento de texto
    char palabra[length];
    strncpy(palabra, str, length);
    palabra[length] = '\0';

    // se imprimen en el documento la palabra o frase
    fprintf(pal, "%s\n", palabra);

    // se cierra el documento
    fclose(pal);
    return 0;
}