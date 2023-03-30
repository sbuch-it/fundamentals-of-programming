/*Dato un vettore A di n interi positivi determinare se esiste un indice k 
tale che la somma degli elementi che precedono la posizione k meno la somma 
degli elementi che seguono la posizione k in valore assoluto è minore 
o uguale a A[k].*/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define SIZE 100
#define MAX 9


main()
{
	int A[SIZE],K[SIZE];//K e' il vettore degli indici k cercati
	
	int i,j=0,k,seed;
	int sprec=0,ssucc=0; //somma dei precedenti e somma dei successivi
	
	seed=time(0);
	srand(seed);
	
	for(i=0;i<SIZE;i++){
		//genera in maniera casuale un intero tra 0 e MAX :
	    A[i]=(double) rand()/RAND_MAX*MAX;
	    printf("A[%d]=%d,\t",i,A[i]);
	}
	
	for(i=1;i<SIZE;i++){
		ssucc+=A[i];
	}
	
	/*calcolo degli indici k che verificano la proprieta'*/
	
	for(k=1;k<SIZE;k++){
		sprec+=A[k-1];
		ssucc-=A[k];
		if(A[k]>=abs(sprec-ssucc)){
			K[j]=k;
			j++;
		}
	}
	
		
	for(i=0;i<SIZE;i++){
		printf("A[%d]=%d,\t",i,A[i]);
	}
	printf("\n");
	for(i=0;i<j;i++){
		printf("K[%d]=%d,\t",i,K[i]);
	}
	system("PAUSE");
}
