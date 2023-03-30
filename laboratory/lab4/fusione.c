#include <stdio.h>
#include <stdlib.h>
#define NUM 20
/* Esempio di fusione di due vettori ordinati in sensonon crescente 
in un vettore totalmente ordinato*/

main()
{
	int A[NUM], B[NUM], C[2*NUM];
	int i=0, j=0,k=0,nA,nB,nC;
	
	/* acquisizione dei dati */
	printf("Inserisci la dimensione di A\n");
	scanf("%d",&nA);
    printf("Inserisci la dimensione di B\n");
	scanf("%d",&nB);
	nC=nA+nB;
	
	printf("Inserisci %d numeri positivi in ordine non decrescente\n",nA);
  for(i = 0; i < nA; i++){
    printf("dato %d=",i);
    scanf("%d",&A[i]);
  }
  /* acquisizione dei dati */
  printf("Inserisci %d numeri positivi  in ordine non decrescente\n",nB);
  for(i = 0; i < nB; i++){
    printf("dato %d=",i);
    scanf("%d",&B[i]);
  }
	i=0;
	/*ordina: scandisci sia A sia B e confronta 
	i due elementi considerati ad ogni passo*/
	while(i<nA && j<nB)
	{
		if(A[i]<=B[j]){
			C[k]=A[i];
			i++;
		}
		else{
			C[k]=B[j];
			j++;
		}
	k++;
	}
	if(i>=nA){
		int h;
		for(h=j;h<nB;h++){
			C[k]=B[h];
			k++;
		}
   }	
	else if(j>=nB){
		int h;
	    for(h=i;h<nA;h++){
			C[k]=A[h];
			k++;
		}	
	}
	printf("Elementi di C:\n");
	for(k=0;k<nC;k++){
		printf("%d,\t",C[k]);
	}
	system("PAUSE");
}
