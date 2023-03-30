/*determina se un numero intero positivo inserito da tastiera e' 
primo oppure no usando una funzione*/

#include<stdio.h>
#include <math.h>

/*dichiarazione delle funzioni*/
int primo(int);

main() {
  int numero;
  printf("Inserisci un numero intero positivo\n");
  scanf("%d",&numero);
  /*verifica se numero e' primo oppure non e' primo*/
  if(primo(numero)) printf("%d e' primo\n", numero);
  else printf("%d non e' primo\n", numero);
}

/*definizione della funzione che determina se un intero n e' primo oppure no. 
ritorna 1 per vero  e 0 per falso*/
int primo(int n){
	int jMax,j=2;
	jMax = (int)sqrt(n) + 1;
    while ((j < jMax) && (n % j)) { 
      j++;
    }
    if (j == jMax) {
      return 1;
    }
	else  {
      return 0;
    }
}
