#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/* I/O Lectura de archivos:


*/
int main()
{

  /* Abre el archivo ventas.txt */
  /* Lee linea por linea los consumos por dia:
  

    dia 5 ventas $100.50 articulos 15
    dia 6 ventas $210.99 articulos 21
    ..

  */

  /* Calcula el costo promedio por articulo por dia y escribelo
    en OTRO ARCHIVO (ventas_promedio.txt), 
    cada linea debera quedar asi:

    PROMEDIOS DEL MES
    dia 5 promedio $6.7
    dia 6 promedio $10.04
    ..
  */

  
  /* Al terminar de escribir en ventas_promedio.txt, vuelve
    a ventas.txt y escribe en una linea nueva la leyenda:
    PROMEDIOS ESCRITOS EN ventas_promedio.txt
    el archivo debera de quedar asi...

    ...
    dia 9 ventas $1200 articulos 150
    dia 19 ventas $200 articulos 50
    PROMEDIOS ESCRITOS EN ventas_promedio.txt
  */

  
  
  return 0;
}
