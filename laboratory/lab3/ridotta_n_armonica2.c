/*
programma che calcola e visualizza la ridotta n-esima della serie armonica  
*/
#include<stdlib.h>
#include <stdio.h>

main() {
  int n,i;
  float HN=0.0;
  char incorrectInput = 1;
  char stop=0;
  
  /*Acquisizione dati*/
  printf("\nCalcola la ridotta n-esima della serie armonica\n");
  do{
	 do{
    	printf("\nInserisci il numero di termini n (>0):"
		"\n0 per terminare");
    	scanf("%d", &n);
    	if	(n>0) {
    	  incorrectInput = 0;
    	} 
    	else if(n==0){
			printf("\nTermina...");
			stop=1;
    	}
		else{
     	 printf("Digitazione errata. Ripetere la scelta...\n");
   	    }
  	}while (incorrectInput); 
  	/*Calcola l'n-esima ridotta*/
     for(i=1;i<=n;i++){
		HN+=1.0/i;
  	}
  printf("\nL'%d-esima ridotta vale:%f",n,HN);
  }while(!stop);
 
 
  
  system("PAUSE");

}
