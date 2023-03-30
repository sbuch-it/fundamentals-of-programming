/*esempio sbagliato nel calcolo della media*/
#include <stdio.h>
#define LEN 20

main(){
  int data[LEN], i, N = 0;
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
  min = max  = data[0];
  average=(double)data[0]/N;
  for (i = 1; i < N; i++) {
    if (data[i] < min) {
      min = data[i];
    }
    else if (data[i] > max) {
      max = data[i];
    }
    average += (double)data[i]/N; //attenzione: il calcolo della media e' sbagliato
   // printf("%lf\n",average);
  }

  printf(" Il minimo  vale %d\n", min);
  printf(" Il massimo vale %d\n", max);
  printf(" La media vale %lf\n", average);
}
