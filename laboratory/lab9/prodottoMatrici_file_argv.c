/*calcola il prodotto tra due matrici. Versione con funzioni
lettura delle matrici da file*/
#include<stdio.h>
#include<stdlib.h>

#define MAX 10
/*prototipi delle funzioni*/
/*acquisice una matrice da file*/
void init_file_matrix(FILE *, double [][MAX], int *,int *);

/*calcola il prodotto di due matrici*/
int mult_AB(double [][MAX], double [][MAX], double [][MAX],int,int,int,int);

/*stampa una matrice*/
void print_matrix(double [][MAX],int,int);

int main(int argc,char *argv[]) {  
  double a[MAX][MAX], b[MAX][MAX], c[MAX][MAX];
  int i, j, k;
  int row1,col1,row2,col2;
  int status;
  FILE *input;
  
  /*apertura file*/
  if((input=fopen(argv[1],"r"))==NULL){
  	printf("\nErrore di apertura file...");
  	exit(EXIT_FAILURE);
  }
  
  /*acquisizione matrice*/	
  init_file_matrix(input,a,&row1,&col1);
  
  /*apertura file*/
  if((input=fopen(argv[2],"r"))==NULL){
  	printf("\nErrore di apertura file...");
  	exit(EXIT_FAILURE);
  }
  
  /*acquisizione matrice*/
  init_file_matrix(input,b,&row2,&col2);
 
  
  status=mult_AB(a, b, c,row1,col1,row2,col2);
  if (status){
		print_matrix(c,row1,col2);
  }
  else printf("\nLe due matrici non possono essere moltiplicate");
}

/*legge una matrice da file e la memorizza in un array bidimensionale.
esce, se errore di formato*/
void init_file_matrix(FILE * fp, double mat[][MAX],int *row,int *col){
	int i,j;
	int status;
	
	status=fscanf(fp,"%d %d",row,col);
	if(status!=2) {
		printf("\nErrore di formato...exit");
		exit(EXIT_FAILURE);
	}
	
	for (i = 0; i < *row; i++) {
	    for (j = 0; j < *col; j++) {
	      status=fscanf(fp,"%lf", &mat[i][j]);
	      if(status!=1){
	      	printf("\nErrore di formato...exit");
			exit(EXIT_FAILURE);
		  }
	    }
  }
}

/*calcola il prodotto di due matrici. 
restituisce 0 se le dimensioni NON concordano
restituisce 1 se le dimensioni concordano*/
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
