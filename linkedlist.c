#include <stdio.h>
#include <stdlib.h>
  /* UTILIZA EL CODIGO VISTO EN LAS DIAPOSITVAS EN CLASE PARA COMPLETAR
  EL SIGUIENTE EJERCICIO */

/* El nodo */
typedef struct node {
  int value;
  struct node *next;
} node;

/* Nuestro header se llama "header" y es una variable GLOBAL 
   inicializada a NULL. Todas las funciones de este ejercicio
   van a considerar "header" como la cabecera de la unica lista
   que aqui existe.  
   
   En la realidad, deben de existir muchas listas y las funciones
   deberian  de recibir la lista a la cual aplicar, pero eso lo veremos
   mas adelante  */

node *header = NULL;  //<--- esta es nuestra primer lista ligada! :) 

//Pendiente:
//void printlist( ...

//Pendiente:
//void add... 

//Pendiente:
/*Funcion que inserta un nodo N despues de X
  Encuentra el primero nodo con valor X e inserta
  N inmediatamente despues ...

  Regresa 1 si si pudo insertar o 0 si no */

//int insert_after(..


//Pendiente:
/*Funcion que inserta un nodo N antes de X
  Encuentra el primero nodo con valor X e inserta
  N inmediatamente antes ...

  Regresa 1 si si pudo insertar o 0 si no */

//int insert_before(..


//Pendiente
/* Funcion para borrar el nodo que contiene N numero adentro */
//void delete(..

//Pendiente
/*Funcion para buscar un nodo que contiene N numero, si lo encuentra
  debera de imprimir la direccion donde vive, sino lo encuentra
  debera de imprimir textualmente "NULL" */


int main() 
{
  /* #1 :
  Crea una funcion newNode(n) que cree un nuevo node con valor n,
  y devuelva el puntero al nodo recien creado */

  /* #2:
  Utilizando esta funcion, crea un nodo nuevo para que actue como el primer
  elemento "header" de nuestra lista  */

  /* #3:
  Crea 5 nodos adicionales, para tener una lista total de 5 nodos
  perfectamente ligados entre si, codifica una funcion
  add() que reciba un nodo (existente, creado con newNode()) y
  agregue este nodo al final de la lista.

  Utiliza un ciclo FOR para llenar los 5 nodos */
  //se usaria asi:
  for (int x = 1; x <= 5; x++) {
    node *n = newNode(x + 1);
    add(n);
  }
  
  /* 4
  Crea una funcion de impresion, para imprimir toda la lista ligada,
  debera verse de esta forma:
    1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10 -> NULL
  */

  //se llamara asi:
  //printlist(header);

  /* 5
  Crea un menu (en un while infinito), con las siguientes funcionalidades:

    0) agregar (agrega un nodo siempre al final)

    1) borrar (le pide la usuario un numero de la lista, para borrarlo)
        Considerar : borrar header
        Que el numero no exista : no debe de hacer nada.
    2) insertar despues de... (le pide al usuario, a partir de que numero quiere
  insertar) OJO. Aqui ya tienen que considerar : a) que pasa si quiero insertar
  en la raiz? b) que pasa si el numero no existe?

    3) inserta antes de... (igual que el punto 2, pero inserta antes)

    4) buscar (recibe un numero y devuelve un apuntador al nodo que lo contiene)
        Despues de buscar el elemento, imprimir el valor del nodo y su
  direccion.

    5) imprimir (imprime la lista de inicio a fin, como en el punto 4)

  El usuario debera de poder manipular toda la lista a placer.
  */

  int selection;
  int todel = 0;
  int toinsert = 0, tosearch = 0;
  int putafter = 0, putbefore = 0;
  node *new_node = NULL;
  int r = 0;

  while (1) {

    // printlist(header);
    printf("Select option:\n 1) delete\n 2) insert after\n 3)insert before\n"
           " 4) search\n 5)print\n");
    printf("\topc:");
    r = scanf("%d", &selection);
    switch (selection) {
    case 1:
      printf("\tnumber to delete: ");
      r = scanf("%d", &todel);
      getchar();
      //delete(todel);
      break;
    case 2:
      printf("\tnumber to insert: ");
      r = scanf("%d", &toinsert);
      getchar();
      printf("\tinsert after which node?: ");
      r = scanf("%d", &putafter);

      //new_node = newNode(toinsert);
      if (!insertafter(new_node, putafter)) // == 0
      {
        /*fail to insert, we need to free node*/
        free(new_node);
      }
      break;
    case 3:
      printf("\tnumber to insert: ");
      r = scanf("%d", &toinsert);
      getchar();
      printf("\tinsert after which node?: ");
      r = scanf("%d", &putbefore);

      new_node = newNode(toinsert);
      if(!insertbefore(new_node, putbefore))
      {
        /*fail to insert, we need to free node*/
        free(new_node);
      }
      break;
    case 4:
      printf("\tnumber to search: ");
      r = scanf("%d", &tosearch);
      getchar();
      // search(tosearch);
      break;
    case 5:
      // printlist(header);
      break;
    }
  }
  /* #6 Cuando ya tengas todo funcionando, has una copia de este archivo y
    llamalo: doublelinkedlist.c agrega el elemento :back a la estructura y crea
    una lista doblemente ligada, toda la funcionalidad tiene que persistir.

    La funcion imprimir, debera de imprimir la lista "de ida" usando el next y
    "de vuelta" usando el back y versea asi:

     1-> 2 -> 3 -> 4 -> ... 10 -> 9 -> 8 -> 7 -> ..... 1 -> NULL
  */
}
