/*
calcola le occorrenze di una sottomatrice B in una matrice A.
Gli elementi di B possono essere non contigui in A*/
#include<stdio.h>
#include<stdlib.h>

#define N 100

main(){
	int A[N][N], B[2][2],C[N][N];
	int i,j;//indici 
	int n;//dimensione reale della matrice A
	int count=0,icount,jcount; //contatore delle occorrenze di B in A 
	
	/*acquisizione dati*/
	printf("Inserisci la dimensione della matrice A:\n");
	scanf("%d",&n);
	printf("n=%d\n",n);
	
	printf("Inserisci la matrice A per righe:\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&A[i][j]);
			printf("%d \t", A[i][j]);
		}
		printf("\n");
	}
	
	printf("Inserisci la matrice B di dim 2x2 per righe:\n");
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			scanf("%d",&B[i][j]);
			printf("%d \t", B[i][j]);
		}
		printf("\n");
	}
	/*inizializzo C a 0*/
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			C[i][j]=0;
		}
	}
	
	/*calcolo delle occorrenze di B in A*/
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1;j++){
			if(A[i][j]==B[0][0]){
				//state++;
				jcount=j;
				/*scorri le colonne di A alla ricerca dell'occorrenza di B[0][1]*/
				while(jcount<n && A[i][jcount+1]!=B[0][1]) jcount++;
				if(jcount<n){ //quindi A[i][jcount+1]==B[0][1]
					icount=i;
					/*scorri le righe di A alla ricerca dell'occorrenza di B[1][0]*/
					while(A[icount+1][j]!=B[1][0] && icount<n) icount++;
					if(icount<n){
						if(A[icount+1][jcount+1]==B[1][1]){
							count++;
							printf("occorrenza %d trovata\n",count);
							C[i][j]=1;
						}
					}
				}
			}
		}
	}
	
	if(count){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				printf("%d\t",C[i][j]);
			}
			printf("\n");
		}
	}
	else
		printf("B non e' una sottomatrice di A\n");
	
	system("PAUSE");
}
