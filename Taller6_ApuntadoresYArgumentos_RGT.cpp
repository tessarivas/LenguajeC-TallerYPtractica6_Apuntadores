/*
NOMBRE: Teresa Rivas Gomez
MATRICULA: 372565
FECHA: Octubre - 12 - 2023
MATERIA: Lenguaje C
ACTIVIDAD: Taller 6: Apuntadores y Argumentos de Funciones
NOMBRE DEL ARCHIVO: Taller5_ApuntadoresYArreglos_RGT.cpp
INSTRUCCIONES: Durante este taller, vamos a resolver ejercicios relacionados con la unidad 3. Para cada
ejercicio, declaren las variables, constantes y funciones necesarias para llevar a cabo la tarea requerida.
Realicen el código a mano de los siguientes ejercicios*.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int msges();
void menu();

int Validar(const char mensj[], int ri, int rf);
int ValidarEntero(const char cadena[]);

void ApuBasicos();

void ApuFuncion();
void MultiPorDos(int* i);

void Arreglos();
int Random(int ri, int rf);
int EstaRepetido(int num, int i, int vector[]);

int ModiArreglo(int *Apuntador, int Numero);
void SumarElementos(int *Apuntador, int Numero);

int main()
{
    srand(time(NULL));
    menu();
    return 0;
}

int Validar(const char mensj[], int ri, int rf) 
{
    int num;
    char cadena[50]; 
    do
    {
        printf("%s", mensj);
        fflush(stdin); 
        gets(cadena);
        num = atoi(cadena);
    } while (num < ri || num > rf);
    return num;
}

int ValidarEntero(const char mensj[])
{
    char cadena[50];
    int i = 0;
    int num;
    int Valido = 1;
    do
    {
        printf("%s", mensj);
        fflush(stdin);
        gets(cadena);
        i = 0;
        Valido = 1;
        while(cadena[i] != '\0')
        {
            if (cadena[i] < '0' || cadena[i] > '9')
            {
                printf("Tiene que ser numero entero, intenta de nuevo.\n");
                Valido = 0;
            }
            i++;
        }
    } while (!Valido);

    num = atoi(cadena); 
    return num;
}

int msges()
{
    int op;
    system ("CLS");
    printf("\n MENU: Taller 6 \n");
    printf("1. Apuntadores Basicos\n");
    printf("2. Pasar Apuntadores a una Funcion\n");
    printf("3. Arreglos\n");
    printf("4. Modificar Elementos de un Arreglo\n");
    printf("0. Salir del programa\n");
    op = Validar("Selecciona una opcion(Entre 1 y 5)\n", 0, 4);
    return op;
}

void menu()
{
    int op;
    int arreglo[7];
    do {
        system("CLS");
        op = msges();
        switch(op)
        {
            case 1:
                ApuBasicos();
                system("PAUSE");
                break;
            case 2:
                ApuFuncion();
                system("PAUSE");
                break;
            case 3:
                Arreglos();
                system("PAUSE");
                break;
            case 4:
                ModiArreglo(arreglo, 5);
                system("PAUSE");
                break;
            case 0:
                printf("Saliste del programa.\n");
                break;
        }
    } while(op != 0);
}

/* Apuntadores Básicos: Dado un entero x, crea un apuntador ptr que apunte a
x. Luego, imprime el valor de x y el valor al que apunta ptr. */
void ApuBasicos()
{
    int x;
    int* puntero;

    system("CLS");
    x = ValidarEntero("Ingresa el valor de x: \n");

    puntero = &x;

    printf("El valor de X es: %d\n", x);
    printf("El valor al que apunta puntero es: %d\n", *puntero);
}

/* Pasar Apuntadores a una Función: Escribe una función llamada
multiplicarPorDos que tome un apuntador a un entero como argumento. Dentro
de la función, multiplica el valor al que apunta el apuntador por 2. Luego, llama
a esta función desde main() y muestra el valor modificado. */
void ApuFuncion()
{
    int x;
    int* puntero;
    system("CLS");

    x = ValidarEntero("Ingresa el valor de x: \n");

    puntero = &x;

    printf("El valor de X es: %d\n", x);

    MultiPorDos(puntero);

    printf("El valor de X por 2 es: %d\n", x);
}

void MultiPorDos(int* i)
{
    *i = (*i) * 2;
}

/* Arreglos: Crea un arreglo de enteros de tamaño 7 (Los valores que genere
sean random entre 1-50, y que los valores no sean repetidos). Luego, crea un
apuntador que apunte al primer elemento del arreglo. Utiliza un bucle para
imprimir todos los elementos del arreglo utilizando el apuntador. */
void Arreglos()
{
    int i;
    int Arreglo[7];
    int Numero;

    system("CLS");

    int* Apuntador = Arreglo;

    for (i = 0; i < 7; i++)
    {
        do {
            Numero = Random(1, 50);
        } while (EstaRepetido(Numero, i, Arreglo) != 0);

        Arreglo[i] = Numero;
    }
    printf("Elementos del arreglo:\n");

    for (i = 0; i < 7; i++)
    {
        printf("Arreglo[%d]: %d\n", i, *Apuntador);
        Apuntador++; 
    }
}

int Random(int ri, int rf)
{
    int rango = (rf - ri + 1);
    return rand() % rango + ri;
}

int EstaRepetido(int num, int i, int vector[])
{
    for (int j = 0; j < i; j++)
    {
        if (num == vector[j])
        {
            return 1;
        }
    }
    return 0;
}

/* Modificar Elementos de un Arreglo: Escribe una función llamada
sumarAElementos que tome un apuntador a un arreglo de enteros y un valor
entero como argumentos. Dentro de la función, suma el valor entero a cada
elemento del arreglo utilizando aritmética de direcciones. Llama a esta función
desde main() y muestra el arreglo modificado. */
int ModiArreglo(int *Apuntador, int Numero)
{
    int i;

    printf("ARREGLO:\n");
    for (i = 0; i < 7; i++)
    {
        printf("Arreglo[%d]: %d\n", i, Apuntador[i]);
    }

    printf("Sumando %d a cada elemento del arreglo:\n", Numero);
    SumarElementos(Apuntador, Numero);

    printf("NUEVO ARREGLO:\n");
    for (i = 0; i < 7; i++)
    {
        printf("Arreglo[%d]: %d\n", i, Apuntador[i]);
    }

    return 0;
}

void SumarElementos(int *Apuntador, int Numero)
{
    int i;
    for (i = 0; i < 7; i++)
    {
        *Apuntador = (*Apuntador) + Numero;
        Apuntador++;
    }
}