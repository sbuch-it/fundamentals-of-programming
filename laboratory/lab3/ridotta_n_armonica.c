/*
programma che calcola e visualizza la ridotta n-esima della serie armonica  
*/
#include<stdlib.h>
#include <stdio.h>

main() {
  int n,i;
  float HN=0.0;
  char incorrectInput = 1;
  
  /*Acquisizione dati*/
  printf("\nCalcola la ridotta n-esima della serie armonica\n");
  do {
    printf("Inserisci il numero di termini n (>0):");
    scanf("%d", &n);
    if	(n>0) {
      incorrectInput = 0;
    } else {
      printf("Digitazione errata. Ripetere la scelta...\n");
    }
  } while (incorrectInput); 
 
 /*Calcola l'n-esima ridotta*/
  for(i=1;i<=n;i++){
		HN+=1.0/i;
  }
  
  printf("\nL'%d-esima ridotta vale:%f",n,HN);
  
  system("PAUSE");

}
