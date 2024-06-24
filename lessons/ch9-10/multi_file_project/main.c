/* inclusione di una libreria creata dall'utente*/
#include<stdio.h>
#include "MyFunction.h"

int main() {
  double x, y;
  x = 3.14;
  y = 2.72;
  printf("prima dello scambio, x = %f, y = %f\n", x, y);

  Myswap(&x, &y);

  printf("dopo lo scambio, x = %f, y = %f\n", x, y);
  return 0;
}


