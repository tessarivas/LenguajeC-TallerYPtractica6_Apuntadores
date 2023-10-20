/*
NOMBRE DEL ARCHIVO: Practica6_ApuntadoresYArgumentos_RivasGomezTeresa
AUTOR: Teresa Rivas Gomez
FECHA DE CREACION: Oct - 19 - 2023
DESCRIPCION: Crear un programa en C que realice operaciones básicas en arreglos utilizando 
apuntadores y funciones. Deberás crear un menú interactivo que permita al usuario elegir 
entre varias operaciones en un arreglo. Las operaciones incluirán la suma de elementos de un 
arreglo, la copia de arreglos, la concatenación de arreglos y la comparación de arreglos.
*/

#include <stdio.h>
#include <stdlib.h>

int msges();
void menu();
int suma(int *arreglo, int longitud);
void copia(int *a_origen, int *a_destino, int longitud);
void concatenacion(int *A_Entrada1, int *A_Entrada2, int *resultado, int longitud1, int longitud2);
int comparacion(int *arreglo1, int *arreglo2, int longitud);
int encontrar(int *arreglo, int longitud);
int ValidarCadena(char mensj[], int ri, int rf);

int main()
{
    menu();
    return 0;
}

int msges()
{
    int op;
    printf("\n M E N U : Practica 6 \n");
    printf("1.- Suma de elementos en un arreglo.\n");
    printf("2.- Copia de arreglos.\n");
    printf("3.- Concatenacion de arreglos.\n");
    printf("4.- Comparacion de arreglos.\n");
    printf("5.- Encontrar el elemento maximo.\n");
    printf("0.- Salir del menu.\n");
    op = ValidarCadena("Seleccione una opcion del 0 al 5", 0, 5);
    return op;
}

void menu()
{
    int op;
    int arreglo1[] = {1, 2, 3, 4, 5};
    int arreglo2[] = {6, 7, 8, 9, 0};
    int longitud1 = sizeof(arreglo1) / sizeof(int);
    int longitud2 = sizeof(arreglo2) / sizeof(int);
    int longitud;
    int resultado;
    int resultado1[20];
    int maximo;

    do{
        system("CLS");
        op = msges();
        switch(op)
        {
            case 1:
                printf("1.- Suma de elementos en un arreglo.\n");
                printf("Arreglo 1: 1, 2, 3, 4, 5.\n");

                resultado = suma(arreglo1, longitud1);

                printf("La suma de los elemntos en el arreglo es: %d\n", resultado);

                system("PAUSE");
                break;
            case 2:
                printf("2.- Copia de arreglos.\n");
                printf("Arreglo 1: 1, 2, 3, 4, 5.\n");
                printf("Arreglo 2: 6, 7, 8, 9, 0.\n");

                copia(arreglo1, arreglo2, longitud1);

                printf("Arreglo de origen: \n");
                for (int i = 0; i < longitud1; i++) 
                {
                    printf("%d, ", arreglo1[i]);
                }

                printf("\n");

                printf("Arreglo de destino (copia): \n");
                for (int i = 0; i < longitud1; i++) 
                {
                    printf("%d, ", arreglo2[i]);
                }

                system("PAUSE");
                break;
            case 3:
                printf("3.- Concatenacion de arreglos.\n");
                printf("Arreglo 1: 1, 2, 3, 4, 5.\n");
                printf("Arreglo 2: 6, 7, 8, 9, 0.\n");

                longitud = longitud1 + longitud2;
                concatenacion(arreglo1, arreglo2, resultado1, longitud1, longitud2); 

                printf("Arreglo 1: ");
                for (int i = 0; i < longitud1; i++) 
                {
                    printf("%d ", arreglo1[i]);
                }

                printf("\n");

                printf("\nArreglo 2: ");
                for (int i = 0; i < longitud2; i++) 
                {
                    printf("%d ", arreglo2[i]);
                }

                printf("\n");

                printf("\nArreglo de destino: ");
                for (int i = 0; i < longitud; i++) 
                {
                    printf("%d ", resultado1[i]);
                }

                system("PAUSE");
                break;
            case 4:
                printf("4.- Comparacion de arreglos.\n");
                printf("Arreglo 1: 1, 2, 3, 4, 5.\n");
                printf("Arreglo 2: 6, 7, 8, 9, 0.\n");

                if (longitud1 != longitud2) 
                {
                    printf("Los arreglos no tienen la misma longitud, entonces no son iguales.\n");
                }
                else 
                {
                    int resultado = comparacion(arreglo1, arreglo2, longitud1);
                    if (resultado) 
                    {
                        printf("Los arreglos son iguales.\n");
                    } 
                    else 
                    {
                        printf("Los arreglos no son iguales.\n");
                    }
                }

                system("PAUSE");
                break;
            case 5:
                printf("5.- Encontrar el elemento maximo.\n");
                printf("Arreglo 1: 1, 2, 3, 4, 5.\n");

                maximo = encontrar(arreglo1, longitud1);

                printf("El elemento maximo en el arreglo es: %d\n", maximo);

                system("PAUSE");
                break;
            case 0:
                printf("Saliste del programa.\n");
                break;
        }
    } while(op != 0);
}

int ValidarCadena(char mensj[], int ri, int rf) 
{
    int num;
    char cadena[200]; 
    do
    {
        printf("%s", mensj);
        fflush(stdin); 
        gets(cadena);
        num = atoi(cadena);
    } while (num < ri || num > rf);
    return num;
}

/* Suma de elementos en un arreglo: Crea una función que calcule la suma de los
elementos en un arreglo utilizando apuntadores y aritmética de direcciones. La función
debe tomar un apuntador al arreglo y devolver la suma. */
int suma(int *arreglo, int longitud)
{ 
    int suma = 0;
    int i;

    for(i = 0; i < longitud; i++)
    {
        suma += *arreglo;
        arreglo++;
    }

    return suma;
}

/* Copia de arreglos: Crea una función que copie un arreglo de origen en un arreglo de
destino. Utiliza apuntadores para realizar esta operación. La función debe tomar dos
apuntadores como argumentos, uno para el arreglo de origen y otro para el arreglo de
destino. */
void copia(int *a_origen, int *a_destino, int longitud)
{
    for (int i = 0; i < longitud; i++) 
    {
        *a_destino = *a_origen; 
        a_origen++;           
        a_destino++;          
    }
}

/* Concatenación de arreglos: Crea una función que tome dos arreglos de entrada y
los concatene en un tercer arreglo. Utiliza apuntadores y aritmética de direcciones para
realizar la concatenación. La función debe tomar tres apuntadores como argumentos:
dos para los arreglos de entrada y uno para el arreglo de destino. */
void concatenacion(int *A_Entrada1, int *A_Entrada2, int *resultado, int longitud1, int longitud2)
{
    for (int i = 0; i < longitud1; i++) 
    {
        *resultado = *A_Entrada1;  
        A_Entrada1++;           
        resultado++;          
    }
    
    for (int i = 0; i < longitud2; i++) 
    {
        *resultado = *A_Entrada2;  
        A_Entrada2++;            
        resultado++;           
    }
}

/* Comparación de arreglos: Crea una función que compare dos arreglos y determine
si son iguales. Utiliza apuntadores y aritmética de direcciones para realizar la
comparación. La función debe tomar dos apuntadores como argumentos y devolver
un valor que indique si los arreglos son iguales. */
int comparacion(int *arreglo1, int *arreglo2, int longitud)
{
    for (int i = 0; i < longitud; i++) 
    {
        if (*arreglo1 != *arreglo2) 
        {
            return 0; 
        }
        arreglo1++; 
        arreglo2++;
    }
    return 1;
}

/* Encontrar el elemento máximo: Crea una función que encuentre y devuelva el
elemento máximo en el arreglo. */
int encontrar(int *arreglo, int longitud)
{
    int Elemento_Maximo = arreglo[0];

    for (int i = 1; i < longitud; i++) 
    {
        if (arreglo[i] > Elemento_Maximo) 
        {
            Elemento_Maximo = arreglo[i];
        }
    }

    return Elemento_Maximo;
}
