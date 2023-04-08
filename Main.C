/*
 * Main.C
 *
 *  Created on: 29 mar. 2023
 *      Author: Carlos Felix & Benjamin Argandq
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//hacemos nuestras definiciones de TRUE y FALSE, que apartir de ahora podrian ser usados como en otros lenguajes de programacion #1

#define TRUE 1
#define FALSE 0

// macro de si es mayuscula, usamos el operador ternario ya que una estructura if daria error de sintaxis #4

#define isUpper(c) (c >= 65 && c <= 90) ? TRUE : FALSE

// macro que convierte una letra en minuscula #5

#define toLower(c) c + 32

//creamos el enum con los dias de la semana, sus valores se asignan automaticamente #6

enum Weekday {MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY};

//funciones que imprimen los menus

void printMenu() {
	printf("Evaluación extra-aulica 2 \n\n");
	printf("1. Mostrar los números primos en el rango [a, b] \n");
	printf("2. Convertir un carácter a minúscula \n");
	printf("3. Calcular y mostrar día de la semana al sumar N días hábiles \n");
	printf("4. Calcular la potencia B^E \n");
	printf("5. Mostrar créditos \n");
	printf("6. Salir \n\n");
	printf("Seleccione opcion: ");
}

void printCreditos() {
	printf("-- CREDITOS -- \n\n");
	printf("CREADO POR: \n");
	printf("Jesus Benjamin Arganda Rubio \n");
	printf("Ingenieria Electronica \n");
	printf("2do Semestre \n");
	printf("Carlos Eduardo Felix Santamaria \n");
	printf("Ingenieria en Sistemas Computacionales\n");
	printf("2do Semestre \n");
}

int isPrime(int n){
    int i, bandera = FALSE, primo;

    for (i = 2; i <= sqrt(n) + 1; ++i) { //recorremos los numeros impares hasta la raiz de n
        if (n % i == 0) { // si el numero impar actual es multiplo de n cambiamos nuestro marcador a verdadero y terminamos el ciclo pues ya no tiene sentido seguir revisando
            bandera = TRUE;
            break;
        }
    }

    if (n < 1){ // si el numero es menor a 1 (0 o negativo) no entra
        primo = FALSE;
    } else if (n == 1) { // 1 no es primo
        primo = FALSE;
    } else if (n == 2) { // 2 si es un numero primo
    	primo = TRUE;
    } else { // si la bandera se mantuvo falsa significa que el numero n no tuvo multiplo, por tanto es primo
        if (bandera == FALSE) {
            primo = TRUE;
        } else { // si la vandera cambio a verdadero, hubo multiplo y por tanto no es primo
            primo = FALSE;
        }
    }

    return primo;
}

void printPrime(int a, int b){
	if (a>=b){ //verificamos cual de los dos valores es el mayor
		for(int j = b; j<=a; j++){ //recorremos del menor al mayor e imprimimos los primos
			if (isPrime(j)){
				printf("%d ", j);
			}
		}
	} else { // caso contratio, simplemente se invierten a y b
		for(int k = a; k<=b; k++){
			if (isPrime(k)){
				printf("%d ", k);
			}
		}
	}
	printf("\n");
}

//creamos la funcion que recibe el dia y la cantidad de dias a sumar #7
int nextWeekday(int day, int sum){
	//ciclo que funcione mientras el numero de dias a sumar sea mayor a 0
	while(sum > 0){
		//le sumas al valor actual de dia, es decir, pasas al dia siguiente
		day = day + 1;
		// si el valor de dia llega a 4 lo reseteas a 0 para que solo tome en cuenta los dias habiles
		if (day >= 4) {
			day = 0;
		}
		//reduces al contador de la sumatoria
		sum = sum - 1;
	}
	return day;
}

//creamos la funcion para imprimir los dias #8
void printWeekday(int dia){
	//switch que recibe el dia ingresado como parametro de la funcion
	switch (dia) {
	//se imprime el dia de la semana segun los valores asignados a los elementos del enum
	case MONDAY:
		printf("Monday \n");
		break;
	case TUESDAY:
		printf("Tuesday \n");
		break;
	case WEDNESDAY:
		printf("Wednesday \n");
		break;
	case THURSDAY:
		printf("Thursday \n");
		break;
	case FRIDAY:
		printf("Friday \n");
		break;
	default:
		printf("Someday \n");
		break;
	}
}

unsigned long long power(int base, int expo){
	  if (expo == 0) { //caso exponente 0
	    return 1;
	  } else if (expo == 1){ //caso exponete 1
		  return base;
	  } else { //entra en la recursion
	    return base * power(base, expo - 1);
	  }
}

enum Weekday seleccionDia(){
	int dia;
	enum Weekday diaFinal; //declaramos nuestro enum de tipo weekday
	printf("DIAS HABILES \n");
	printf("[1] Lunes \n");
	printf("[2] Martes \n");
	printf("[3] Miercoles \n");
	printf("[4] Jueves \n");
	printf("[5] Viernes \n");
	printf("Introduce el dia de la semana: ");
	scanf("%d", &dia);
	switch (dia){ //asignamos el enum correspondiente al dia que escoge el usuario
		case 1:
			 diaFinal = MONDAY;
			break;
		case 2:
			diaFinal = TUESDAY;
			break;
		case 3:
			diaFinal = WEDNESDAY;
			break;
		case 4:
			diaFinal = THURSDAY;
			break;
		case 5:
			diaFinal = FRIDAY;
			break;
		default:
			printf("Error: elija una opcion valida");
			break;
	}
	return diaFinal; //regresamos el enum que se escogio
}

int seleccionSuma(){
	int dias;
	printf("Indica el numero de dias habiles a sumar: ");
	scanf("%d", &dias);
	return dias;
}

int opcionElegida(int opcion){
	switch (opcion) {
	case 1: //numeros primos
		int num1, num2;
		printf("Introduce el primer numero del rango: ");
		scanf("%d", &num1);
		printf("Introduce el primer numero del rango: ");
		scanf("%d", &num2);
		printPrime(num1, num2);
		return 1;
		break;
	case 2: //conversion caracter
		char letraC;
		printf("Introduce el caracter que quieres convertir: ");
		scanf("%c", &letraC);
		if (isUpper(letraC) == TRUE){ //verificamos que sea una letra mayuscula
			letraC = toLower(letraC); // si si lo es la convertimos a minuscula con nuestro macro
			printf("El caracter en minusculas es: %c\n\n", letraC);
		} else {
			printf("El caracter ya esta en mayuscula, o no es un caracter valido.\n\n");
		}
		return 1;
		break;
	case 3: //dias habiles
		int dias;
		enum Weekday diaUsar;
		diaUsar = seleccionDia();
		dias = seleccionSuma();
		printWeekday(nextWeekday(diaUsar, dias));
		return 1;
		break;
	case 4: //elevar numero
		int base, exponente;
		printf("Introduce el numero a elevar: ");
		scanf("%d", &base);
		printf("Introduce el exponente: ");
		scanf("%d", &exponente);
		printf("El resultado es: %I64u \n", power(base, exponente));
		return 1;
		break;
	case 5: //creditos
		printCreditos();
		return 1;
		break;
	case 6: //salir
		return 0;
		break;
	default: //opcion incorrecta
		printf("Error: Introduzca una opcion valida");
		return 1;
		break;
	}
}

int main() {
	setbuf(stdout, NULL);
	int opcion, menu = 1;

	do { //ciclo principal del programa
		printMenu();
		scanf("%d", &opcion);
		fflush(stdin);
		menu = opcionElegida(opcion);
	} while(menu > 0); //se termina cuando la variable menu es igual a 0, se asigna ese valor cuando el usuario escoge 6 en el menu
	return 0;
}
