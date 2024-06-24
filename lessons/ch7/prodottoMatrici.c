/*Programma che calcola il prodotto di due matrice a e b*/
#include<stdio.h>

#define ROW1 2
#define COL1 3
#define ROW2 COL1
#define COL2 2

main() {  
  double a[ROW1][COL1], b[ROW2][COL2], c[ROW1][COL2];
  int i, j, k;
  
  printf("\n Inserisci i coefficienti della matrice a\n");
  for (i = 0; i < ROW1; i++) {
    for (j = 0; j < COL1; j++) {
      printf("a[%d, %d] = ", i, j);
      scanf("%lf", &a[i][j]);
    }
  }
  printf("\n Inserisci i coefficienti della matrice b\n");
  for (i = 0; i < ROW2; i++) {
    for (j = 0; j < COL2; j++) {
      printf("b[%d, %d] = ", i, j);
      scanf("%lf", &b[i][j]);
    }
  }  
  /*moltiplicazione di a per b*/
  for (i = 0; i < ROW1; i++) {
     for (j = 0; j < COL2; j++) {
	     c[i][j] = 0;
	     for (k = 0; k < COL1; k++) {
           c[i][j] += a[i][k] * b[k][j];
	    }
     }
  }
  printf("\n Stampa della matrice prodotto c\n");  
  for (i = 0; i < ROW1; i++) {
    for (j = 0; j < COL2; j++) {
      printf("c[%d, %d] = %f\t", i, j, c[i][j]);
    }
    printf("\n");
  } 

}
