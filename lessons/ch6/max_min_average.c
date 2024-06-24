/*CALCOLA IL MINIMO, IL MASSIMO E LA MEDIA DEGLI ELEMENTI IN UN VETTORE DI N INTERI*/

#include <stdio.h>
#define LEN 20

main(){
  int data[LEN], N = 0;
  unsigned int i;
  int min, max;
  double average;
/* acquisiamo N dati, N <= LEN */
  do {
    printf("numero di dati = ");
    scanf("%d", &N);
  } while (N <= 0 || N > LEN);
  
  
  for (i = 0; i < N; i++) {
    printf("dato %d = ", i + 1);
    scanf("%d", &data[i]);
  }
/* analizziamo l'array data */
  min = max = average = data[0];
  
  for (i = 1; i < N; i++) {
    if (data[i] < min) {
      min = data[i];
    }
    else if (data[i] > max) {
      max = data[i];
    }
    average += data[i];
    //printf("%lf\n",average);
  }
  average /= N;
  printf(" Il minimo  vale %d\n", min);
  printf(" Il massimo vale %d\n", max);
  printf(" La media vale %lf\n", average);
}
