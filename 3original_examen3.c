// INICIA RESPUESTA
// Para que agregues tus Librerías para los ejercicios prácticos.

// TERMINA RESPUESTA
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char alumno[100] = "luis leal";

/*  

    Fecha : 29 de Noviembre 2024
    Diseno de Estructura de Datos - Grupo B
    Tercera Evaluación Síncrona

  Teoría 1:     6 preguntas de 5 puntos       /30 pts
  Teoría 2:     4 preguntas de 10 puntos      /40 pts
  Ejercicio 1:  Map                           /20 pts
  Ejercicio 2:  Priority Queue                /20 pts               
       
                                            ________
  Calificación Final:                         /110 puntos
*/

/*
******************************************************** Teoría 1: 6 preguntas de 5 puntos       /30 pts **************************************************************

1)	Explica cuál es la diferencia entre una función pública y una función privada?

  R= una funcion publica es accesible desde cualquier parte del codigo incluso fuera del archivo o modulo mientras que la privada solo es accesible dentro del modulo o archivo donde se encuentra

2)  Menciona una diferencia entre una cola (ordinaria) y una cola de prioridad, desde el punto de vista de su comportamiento, no de su implementación:

  R= en una cola ordinaria los elemntos se procesan en el orden en el que fueron anadidos mientras que en el otro se procesan en funcion de su prioridad independientemente del orden de insercion 

3)  Explica a detalle la importancia de la función "hash" al implementar un Mapa / Tabla Hash, y por qué se le aplica la operación de módulo.

  R= es importante porque convierte una entrada en un indice dentro del rango permitido de la tabla asegurando un acceso eficiente a los datos, a operacion modulo se utiliza para garantizar que el indice generado este dentro del rango de indices validos de la tabla evitando desbordamientos

4)	¿Por qué implementamos un conjunto mediante un árbol binario de búsqueda en lugar de utilizar una lista enlazada o un arreglo? Justifica bien tu respuesta.	

  R= un arbol binario de busqueda permite realizar operaciones como insercion, eliminacion y busqueda con complejidad 0 log n, mientras que una lista o arreglo tienen complejidad para buscar elemento de 0 n,ya que deben correr secuencialmente los elementos

5)	Al crear un TDA / Librería ¿Por qué utilizamos void pointers en lugar de datos de un tipo específico?

  R= permiten que el tda o la libreria sea generica y pueda trabajar con cualquier tipo de dato

6) Menciona una diferencia entre un conjunto y un mapa, desde el punto de vista de su comportamiento, no de su implementación:

  R= un conjunto solo almacena valores unicos, mientras que un mapa almacena pares de clave valor, donde cada clave es unica

******************************************************** Teoría 2: 4 preguntas de 10 puntos       /40 pts **************************************************************

7)  Dibuja cómo queda el siguiente árbol binario de búsqueda después de insertar 14, 5 y 13 (en este orden). 

             10
          /      \
        3         16
      /   \      /   \
    1      8   11     18 
   /     /              \
  0     6                20

  R=         10
          /      \
        3         16
      /   \      /   \
    1      8   11     18 
   /     /    / \      \
  0     6   14   13     20
       /
      5

8) Asume que se crea un montículo binario "máximo" a partir del siguiente arreglo.:
    4, 7, 10, 5, 12, 15, 22, 8, 17, 1
    a) ¿Cómo queda el montículo binario (MaxHeap) inicialmente?  Puedes mostrar la respuesta como montículo binario (dibujo) o como arreglo.
 
      R=       22
             /   \
            17   15
          /  \   / \
         8   12 10  7
        / \
       4   5

    b) ¿Cómo queda el montículo binario (MaxHeap) de arriba después de ejecutar offer(18)?  Puedes mostrar la respuesta como montículo binario (dibujo) o como arreglo.
 
      R=       22
             /   \
            18   15
          /  \   / \
         17   12 10  7
        / \
       8   5
      /
     4 

    b) ¿Cómo queda el montículo binario (MaxHeap) de arriba después de ejecutar poll()? Puedes mostrar la respuesta como montículo binario (dibujo) o como arreglo.

      R=       18
             /   \
            17   15
          /  \   / \
         8   12 10  7
        / \
       4   5 

9)	Asume que existe una Tabla Hash que almacena fechas, y se encuentra en el siguiente estado:

HashIndex
    0   -> |31/10/1987| -> NULL
    1   -> |02/06/2012| -> |19/01/1123| -> NULL
    2   -> |01/01/2024| -> |28/05/1546| -> NULL
    3   -> NULL
    4   -> |03/11/1990| -> NULL
    5   -> |31/12/1987| -> |15/03/2025| -> |19/07/1999| -> NULL
    6   -> |31/08/2005| -> NULL

Asume que el hashing se hace de la siguiente manera:
  
  int DateHash(int dia, int mes, int anyo){
    int hash;
    
    if(anyo >= 2000)
      hash = (dia * mes) + anyo;
    else
      hash = dia + (mes * anyo);

    return hash % 7;
  }

  Dibuja la Tabla Hash resultante después de ejecutar map_put("02/02/2000") y map_put("11/11/1111");
  
  R=
  HashIndex
  0 -> |31/10/1987| -> NULL
  1 -> |02/06/2012| -> |19/01/1123| -> NULL
  2 -> |01/01/2024| -> |28/05/1546| -> |02/02/2000| -> NULL
  3 -> |11/11/1111| -> NULL
  4 -> |03/11/1990| -> NULL
  5 -> |31/12/1987| -> |15/03/2025| -> |19/07/1999| -> NULL
  6 -> |31/08/2005| -> NULL



10)	Acabas de instalar la siguiente librería para el uso de colas simples:
//Entiéndela bien antes de continuar.

      #ifndef QUEUE_H
      #define QUEUE_H
      // Tamaño máximo de la cola
      #define MAX 5

      // Estructura de la cola
      typedef struct Queue {
          int items[MAX];
          int front, rear;
      } Queue;

      // Declaración de funciones
      void initQueue(Queue *q);
      void enqueue(Queue *q, int value);
      int dequeue(Queue *q);
      void displayQueue(Queue *q);

      #endif // QUEUE_H


  Imagina que en tu "main" tienes el siguiente código:

      Queue q, z;
      initQueue(&q);
      initQueue(&z);

      enqueue(&q, "Jesus");
      enqueue(&z, "Zyanya");
      enqueue(&q, "Jorge");
      dequeue(&z);
      enqueue(&q, "Sofia"");
      enqueue(&q, "Erick");
      enqueue(&q, "Diego");
      enqueue(&q, "Chava");
      dequeue(&q);
      dequeue(&z);
      enqueue(&q, "Nicole");

      displayQueue(&q);
      return 0;

  Escribe o dibuja el estado final de la cola "q".

  R= ["Jorge", "Sofia", "Erick", "Diego", "Nicole"]



******************************************************** Ejercicio 1: Mapa                 /20 pts **************************************************************

/* 
   
   Guarda en un mapa, la relacion de cuantas repeticiones por cada numero existen
   en siguiente arreglo:

   {1,1,1,2,3,0,1,2,5,5,1}

  numero | veces
    1    |   5
    2    |   2
    3    |   1
    5    |   2

  Puedes agregar cualquier librería que hayas hecho en clase o en tu proyecto.

*/
/* INICIA RESPUESTA */
// El mapa necesita 2 funciones y tal vez una estructura, declaralas aqui:
#define MAX_MAP_SIZE 100

typedef struct {
  int key; 
  int value;
} MapEntry;

typedef struct {
  MapEntry entries[MAX_MAP_SIZE];
  int size;
} Map;

void initMap(Map *map) {
    map->size = 0;
}
void put(Map *map, int key) {
  for (int i = 0; i < map->size; i++) {
      if (map->entries[i].key == key) {
        map->entries[i].value++;
        return;
    }
  }
    // Si no existe la clave, se agrega una nueva entrada
    map->entries[map->size].key = key;
    map->entries[map->size].value = 1;
    map->size++;
}
void printMap(Map *map) {
  printf("numero | veces\n");
    for (int i = 0; i < map->size; i++) {
      printf("   %d   |   %d\n", map->entries[i].key, map->entries[i].value);
  }
}

/* FIN DE RESPUESTA */

void ejercicio1() {
    int arreglo[] = {1, 1, 1, 2, 3, 0, 1, 2, 5, 5, 1};
    int size = 11;

    Map map;
    initMap(&map);

    for (int i = 0; i < size; i++) {
        put(&map, arreglo[i]);
    }

    printMap(&map);
}

/*
******************************************************** Ejercicio 2: Priority Queue              /20 pts **************************************************************

   Este ejercicio tiene un TDA que guarda un color, utilizando sus valores en RGB de 0 a 255.
    *R = Red = Rojo
    *G = Green = Verde
    *B = Blue = Azul
   Referencia: https://www.rapidtables.com/web/color/RGB_Color.html

   Crea una Priority Queue (Cola de prioridad) para guardar 5 colores.
   Puedes agregar cualquier librería que hayas hecho en clase o en tu proyecto.

   Una vez guardados:
   Extrae todos los colores (uno por uno) y comprueba que salen en el orden deseado.
   Cuál es ese orden? Solo hay 2 reglas:
    * El color con más rojo (R) es el más importante.
    * En caso de empate en rojo (R), utliza Azul (B) para desempatar.
*/

typedef struct color
{
  char name[15];
  int r;
  int g;
  int b;
} color;

/* INCIA RESPUESTA */
// aqui va una función que el priority queue necesita para funcionar


/* TERMINA RESPUESTA */

void ejercicio2()
{
  //Inicialización de colores.
  color c1, c2, c3, c4, c5;
  snprintf(c1.name, sizeof(c1.name), "Negro");
  c1.r=0;c1.g=0;c1.b=0;
  snprintf(c2.name, sizeof(c2.name), "Blanco");
  c2.r=255;c2.g=255;c2.b=255;
  snprintf(c3.name, sizeof(c3.name), "Limon");
  c3.r=120;c3.g=200;c3.b=10;
  snprintf(c4.name, sizeof(c4.name), "Naranja");
  c4.r=255;c4.g=153;c4.b=51;
  snprintf(c5.name, sizeof(c5.name), "Aqua");
  c5.r=120;c5.g=180;c5.b=180;

  /* INCIA RESPUESTA */
  // Inserta los 5 colores de arriba, sin importar el orden, comprueba
  // que al extraerlos, siempre sale el de mayor prioridad.


  /* FIN DE RESPUESTA */
}

int main()
{
  printf("Examen Parcial 3 de : %s\n", alumno);
  printf("\n----- Ejercicio 1:-----\n\n");
  ejercicio1();
  printf("\n----- Ejercicio 2:-----\n\n");
  ejercicio2();
}
