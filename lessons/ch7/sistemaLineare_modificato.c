#include <stdio.h>
#include <math.h>

#define N 100

main() {
/* soluzione dei sistemi di equazioni con il metodo di eliminazione
     delle incognite di Gauss con controllo sugli elementi diagonali */
  double A[N][N], b[N], x[N];
  double temp; //variabile d'appoggio per lo scambio di righe 
  double C, S;
  int n, i, j, k;
/* inserisce i dati iniziali */
  printf(" Inserisci il numero di equazioni (<100): ");
  scanf("%d", &n);
  printf("\n Inserisci ora i coefficienti del sistema e i termini noti\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("A[%d, %d] = ", i, j);
      scanf("%lf", &A[i][j]);
    }
    printf("b[%d] = ", i);
    scanf("%lf", &b[i]);
  }
/* triangolarizza la matrice */
  for (i = 0; i < n; i++) {
    /* divide l'i-esima equazione per l'elemento diagonale C */
    if(A[i][i]==0){
		int h=i+1;
		while(A[h][i]==0 && h<n) h++;
		if(h==n) {
			printf("il rango della matrice e'<n\n");
			exit(1);
		}else{
			/*scambia la riga i-esima con la riga h-esima*/
			int l;
			for(l=0;l<n;l++){
				temp=A[i][l];
				A[i][l]=A[h][l];
				A[h][l]=temp;
			}
			temp=b[i];
			b[i]=b[h];
			b[h]=temp;
		}
    }
	C = A[i][i];
    for (j = i; j < n; j++) {
      A[i][j] /= C;
    }
    b[i] /= C;
/* sottrae l'equazione normalizzata dalle altre */
    for (k = i + 1; k < n; k++) {
      C = A[k][i];
      for (j = i; j < n; j++) {
	    A[k][j] -= A[i][j] * C;
      }
      b[k] -= C * b[i];
    }
  }  
/* risolve */ 
  for (k = n - 1; k >= 0; k--) {
    S = 0.;
    for (i = k + 1; i < n; i++) {  
      S += A[k][i] * x[i];
    }
    x[k] = b[k] - S;
  } 
/* stampa il risultato */
  for (i = 0; i < n; i++) {
    printf("x[%d] = %lf\n", i, x[i]);
  } 
  system("PAUSE");
}
