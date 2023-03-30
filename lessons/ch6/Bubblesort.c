/* Esempio di algoritmo di ordinamento
   Bubblesort */
#include <stdio.h>

#define NUM 5


main(){

  int data[NUM], temp;
  unsigned int i, j;

/* acquisizione dei dati */
  for(i = 0; i < NUM; i++){
    printf("dato %d=",i+1);
    scanf("%d",&data[i]);
  }
/*  ordinamento */  
  for (i = 1; i < NUM; i++) {
     for (j = NUM - 1; j >= i; j--) {
		if (data[j-1] > data[j]) {
            temp = data[j-1];
			data[j-1] = data[j];
	   		data[j] = temp;
	}
     }
  }
/*  stampa dei dati ordinati */    
  for (i = 0; i < NUM; i++) {
  printf("%d\t",data[i]);
  }
}
