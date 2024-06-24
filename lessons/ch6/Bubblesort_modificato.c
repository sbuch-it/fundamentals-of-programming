/* Esempio di algoritmo di ordinamento
   Bubblesort: porta il valore piu' grande ad ogni passo in fondo al vettore */
   /*Con miglioramento: se in un passo dell'algoritmo non ci sono passi, termina*/

#include <stdio.h>

#define NUM 5

main(){

  int data[NUM], i, j, temp;

/* acquisizione dei dati */
  for(i = 0; i < NUM; i++){
    printf("dato %d=",i+1);
    scanf("%d",&data[i]);
  }
/*  ordinamento */  
  for (i = 1; i < NUM ; i++) {	
	 int scambio=0;
     for (j = 1; j <= NUM-i; j++) {
	       if (data[j-1] > data[j]) {
		   scambio=1;
           temp = data[j-1];
	       data[j-1] = data[j];
	       data[j] = temp;
	}
	if(scambio==0) break;
     }
  }
/*  stampa dei dati ordinati */    
  for (i = 0; i < NUM; i++) {
  printf("%d\t",data[i]);
  }
}
