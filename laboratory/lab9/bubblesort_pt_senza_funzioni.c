#include <stdio.h>
#include <stdlib.h>
#define NUM 5
/* Esempio di algoritmo di ordinamento
   Bubblesort */

main(){

  int data[NUM], n, i, temp, *pd, *max;

/* acquisizione dei dati */
	
	do{
		printf("Inserisci la dimensione n<%d del vettore\n",NUM+1);
		scanf("%d",&n);
	}while(n<=0 || n>NUM);

  for(i = 0; i < n; i++){
    printf("dato %d=",i+1);
    scanf("%d",&data[i]);
  }
/*  ordinamento */  

  for (i = 0; i < n - 1; i++) {
	int *min;
	min=data + i;
    for (pd = data + n - 1; pd > min; pd--) {
      if (*(pd - 1) > *pd) {
        temp = *(pd - 1);
	    *(pd - 1) = *pd;
	    *pd = temp;
      }
    }
  }
  
  max=data+n;
  for (pd=data; pd < max; pd++) {
  printf("%d\t",*pd);
  }
  system("PAUSE");
}
