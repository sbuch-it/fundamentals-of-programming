#include <stdio.h>
#include <stdlib.h>
/*calcola l'istogramma relativo ai dati contenuti in un vettore e lo visualizza*/

#include <time.h>
#define MAX_NUM 10000
#define MAX_BINS 100
#define MAX_CHAR 100


main() {
  int i,j,k, bins, content[MAX_BINS]={0};
  int seed, N;
  double const xmin=0, xmax=1;
  double  inv_width; //inverso dell'ampiezza di una classe
  double data[MAX_NUM];
  char hist[MAX_BINS+2][MAX_CHAR+1];// #righe= numero di intervalli + 2,#colonne=altezza max +1
  seed = time(0);
  srand(seed);

/*acquisisci i dati*/
  do {
    printf("Numero di eventi nell'istogramma = ");
    scanf("%d", &N);
  } while (N < 0 || N > MAX_NUM);
  /*popola i dati con numeri razionali casuali nell'intervallo [0,1)*/
  for(k=0; k < N; k++) {
    data[k] = (double) rand() / (RAND_MAX + 1.);
  }


  do {
    printf("Dare numero di intervalli bins = ");
    scanf("%d",&bins);
  } while (bins < 0 || bins > MAX_BINS);
  printf("Limiti xmin=%f, xmax=%f, %d intervalli\n", xmin, xmax, bins);
  
  /*per ogni dato calcola a quale intervallo appartiene*/
  inv_width = (double) bins / (xmax - xmin);
  for (i = 0; i < N; i++) {    
    j =  (data[i] - xmin) * inv_width;
    if(j < bins && j >= 0) {
      content[j]++;
    }   
  }

   for(k=0; k < bins; k++) {
    printf("contenuto del bin %d = %d\n", k, content[k]);
  } 
  /*inizializza l'istogramma*/
  char c = '*', empty = ' ';
  
  for (i = 0; i < bins + 2; i++) {
    for (j = 0; j < MAX_CHAR+1; j++) {
      hist[i][j] = empty;
    }
  } 
  
  /*calcola l'altezza massima dei rettangoli dell'istogramma*/
  int  max;
  max = content[0];
  for (i = 1; i < bins; i++) {
    if (content[i] > max) {
      max = content[i];
    }
  }
  if (max > MAX_CHAR) {//massima altezza rappresentabile
    max = MAX_CHAR;
  }   
  
  /*riempi l'istogramma*/
  for (j = 1; j <= max; j++) {
    hist[0][j] = '|';
  }
  hist[0][0] = hist[1][0] = '_';
  
  for (i = 2; i < bins + 2; i++) {
    hist[i][0] = '_';
    for (j = 0; j < content[i-2]&& j<=max; j++) {
      hist[i][j + 1] = c;
    }
  }
  /*visualizza l'istogramma per colonne*/
  for (j = max; j >= 0 ; j--) {
    for (i = 0; i < bins + 2; i++) {
      printf("%c", hist[i][j]);
    }
    printf("\n");
  } 
}


