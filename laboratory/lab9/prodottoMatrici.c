/*calcola il prodotto tra due matrici. Versione con funzioni*/
#include<stdio.h>
#define MAX 10

void init_matrice(double [][MAX], int *,int *);
int mult_AB(double [][MAX], double [][MAX], double [][MAX],int,int,int,int);
void print_matrix(double [][MAX],int,int);

main() {  
  double a[MAX][MAX], b[MAX][MAX], c[MAX][MAX];
  int i, j, k;
  int row1,col1,row2,col2;
  int status;
  
  init_matrice(a,&row1,&col1);
  init_matrice(b,&row2,&col2);
 
  
  status=mult_AB(a, b, c,row1,col1,row2,col2);
  if (status){
		print_matrix(c,row1,col2);
  }
  else printf("\nLe due matrici non possono essere moltiplicate");
}

void init_matrice(double mat[][MAX],int *m,int *n){
	int i,j;
	printf("\nInserisci il numero di righe della matrice:\n");
	scanf("%d",m);
	printf("\nInserisci il numero di colonne della matrice:\n");
	scanf("%d",n);
	printf("\nInserisci gli elementi della matrice:\n");
	for (i = 0; i < *m; i++) {
	    for (j = 0; j < *n; j++) {
	      scanf("%lf", &mat[i][j]);
	    }
  }
}

int mult_AB(double a[][MAX], double b[][MAX], double c[][MAX],int rowa,int cola,int rowb, int colb){
	 int i,j,k;
	 
	 if(cola!=rowb) return 0;
	 
	 for (i = 0; i < rowa; i++) {
	     for (j = 0; j < colb; j++) {
		     c[i][j] = 0;
		     for (k = 0; k < cola; k++) {
	           c[i][j] += a[i][k] * b[k][j];
		    }
	     }
  }
  return 1;
}

void print_matrix(double mat[][MAX],int m,int n){
	int i,j;
	printf("\n Stampa della matrice prodotto c\n");  
  	for (i = 0; i < m; i++) {
	    for (j = 0; j < n; j++) {
	      printf("mat[%d, %d] = %f\t", i, j, mat[i][j]);
	    }
	    printf("\n");
	} 
}
