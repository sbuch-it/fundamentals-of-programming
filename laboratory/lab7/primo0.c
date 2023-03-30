/*determina se un numero intero positivo inserito da tastiera e' primo oppure no*/

#include<stdio.h>
#include <math.h>

main() {
  int n,jMax,j=2;
  /*Acquisizione dati*/
  printf("Inserisci un numero intero positivo\n");
  scanf("%d",&n);
  
  /*primalita'*/
  jMax = (int)sqrt(n) + 1;
    while ((j < jMax) && (n % j)) { 
      j++;
    }
    /*visualizzazione*/
    if (j == jMax) {
      printf("%d e' primo\n", n);
    }
	else  {
      printf("%d non e' primo\n", n);
    }
}
