/*determina l'intersezione di due insiemi memorizzati in due array*/
#include <stdio.h>
#include <stdlib.h>
#define NA 100
#define NB 100
#define NC 100

main(){
  int A[NA],B[NB],C[NC], i,j,k=0, na,nb,nc;
  int found=0; //ad ogni passo vale true se un elemento di A e' presente nel vettore B 
  
/* acquisiamo n dati, n <= LEN */
  do {
    printf("\nInserisci na numero di dati per A= ");
    scanf("%d", &na);
  } while (na <= 0 || na > NA);
  
  do {
    printf("\nInserisci nb numero di dati per b= ");
    scanf("%d", &nb);
  } while (nb <= 0 || nb > NB);
  
  //nc=(na<nb) ? na:nb;
  
  for (i = 0; i < na; i++) {
    printf("A[%d] = ", i);
    scanf("%d", &A[i]);
  }
  
  for (i = 0; i < nb; i++) {
    printf("B[%d] = ", i);
    scanf("%d", &B[i]);
  }
  

  /*ricerca sequenziale di u nel n elemento di A in B*/
  for(i=0;i<na;i++){
		found=0;
		for(j=0;!found && j<nb;j++){
		   found=(B[j]==A[i]);
  		}
		if(found) {
		   C[k]=A[i];
		   k++;}
  }
  if(k){
  	for(i=0;i<k;i++){
		   printf("\n C[%d] = %d", i,C[i]);
  	}
  }
  else printf("\n I due insiemi hanno intersezione nulla\n");
  
  
  system("PAUSE");
}
