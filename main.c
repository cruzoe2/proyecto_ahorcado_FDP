#include <stdio.h>



//PROTOTIPOS DE LAS FUNCIONES
void menu();
void jugar();
void puntajes();
void dificultad();
void ingresarPalabras();

//FUNCION PRINCIPAL MAIN
int main(){
	
	menu();

	return 0;
}

//funcion  de menu seleccion
void menu(){
	int opcion;
	do{
		
		printf("\n\t\t\t\tJUEGO EL AHORCADO\n\n");
		printf(" Seleccione una de las siguientes opciones: \n\n");
		printf(" 1. Jugar\n");
		printf(" 2. Tabla de posiciones\n");
		printf(" 3. Ingresar palabras\n");
		printf(" Ingresa una opcion: ");
		scanf("%d",&opcion);		
	}while(opcion<1 || opcion>3);

	if (opcion==1){ 
	    dificultad(opcion);} //manda a la funcion dificultad para seleccionar el modo que desea jugar

	if (opcion==2){ 
	    puntajes(opcion); }//revisar el puntaje de cada jugador por nivel de difcultad

	if (opcion==3){ 
	    ingresarPalabras(opcion);} // para que el usuario pueda ingresar las palabras deseadas
}


//se escoge el nivel de difcultad para continuar con el juego
void dificultad(){
    int nivel;
    do{
		
		printf("\n\t\t\t\tJUEGO EL AHORCADO\n\n");
		printf(" Seleccione el nivel de dificultad en el que desea jugar \n\n");
		printf(" 1. Facil\n");
		printf(" 2. Intermedio\n");
		printf(" 3. Dificil\n");
		printf(" Ingresa una opcion: ");
		scanf("%d",&nivel);		
    }while(nivel<1 || nivel>3);
}

// mostrar los puntajes de cada jugador
void puntajes(){
    
}

//ingresar palabras
void ingresarPalabras(){
    
}


