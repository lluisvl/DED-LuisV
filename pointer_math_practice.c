#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define CLEAR printf("\033[0;0H\033[2J");

void ex01();
void ex02();
void ex03();
void ex04();

int mylength(const char *str);  
void to_lowercase(char *str);

int main()
{
    const char *myString = "Hola mundo";
    printf("Length of the string is: %d\n", mylength(myString));

    char myString2[] = "Hoa mundo";
    to_lowercase(myString2);
    printf("String en minusculas: %s\n", myString2);

    ex01();
    ex02();
    ex03();
    ex04();

    return 0;
}

void ex01()
{
  /* Excerice 01:
  Create an array of 10 integers, set their value (whatever you want)
  Using pointer arithmetic and a for loop traverse and print all the array

  DO NOT USE BRACKETS [ ]
  
  Print both the value and the address.
  
  ie
    int array = [ 2 , 3 , 5 , 6]

    array[0] = 2 -> addr = 0x00001
    array[1] = 3 -> addr = 0x00004
    array[2] = 5 -> addr = 0x00008
    array[3] = 6 -> addr = 0x0000B
*/
{
    int array[10];

    for (int i = 0; i < 10; i++) {
        *(array + i) = i * 2; 
    }
    for (int i = 0; i < 10; i++) {
        printf("array[%d] = %d -> addr = %p\n", i, *(array + i), (array + i));
    }
}
int mylength(const char *str) {
    const char *ptr = str;
    int length = 0;

    while (*ptr != '\0') {
        length++;
        ptr++;
    }

    return length;
}

void to_lowercase(char *str) {
    while (*str != '\0') {
        if (*str >= 'A' && *str <= 'Z') {
            *str = tolower(*str);
        }
        str++;
    }
}

void ex02()
{
  /* Excercise 02:
  Implement a function mylenght() that returns the size of the passed 
  string (char array). DO NOT USE strlen(), use only pointer arithmetic.

  DO NOT USE BRACKETS [ ]

  TIP: all strings are array of chars, terminated by '\0' character.
*/
int mylength(const char *str) {
    const char *ptr = str;
    int length = 0;

    while (*ptr != '\0') {
        length++;
        ptr++;
    }

    return length;
}
}

/* More practice excerises (similar to Ex02)

  NOTA :    No utilizar arreglos o corchetes dentro de
            ninguna de las 2 funciones.

  Excercise 03
  Implementa una funcion, que reciba por referencia un arreglo,
  recorra este arreglo y cambie cualquier mayuscula a minuscula, 
  el arreglo se debe de imprimir de vuelta en el main  Tip: ASCII table

  Exercise 04
  Implementa una función isBinary que reciba una cadena de texto de consola
  y determine si está formada exclusivamente por dígitos binarios (0, 1). 
  
*/
void ex03()
{
void to_lowercase(char *str) {
    while (*str != '\0') {
        if (*str >= 'A' && *str <= 'Z') {
            *str = tolower(*str);
        }
        str++;
    }
}
}
void ex04()
{

}
