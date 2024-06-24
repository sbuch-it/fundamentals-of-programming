/*ricerca sequenziale di un elemento target in un vettore (non ordinato)*/
#include <stdio.h>
#include <stdlib.h>
#define LEN 15
#define NOT_FOUND -1

main(){
  int data[LEN], i, n;
  int target;
  int found=0; //vale true se target e' presente nel vettore
  int where; //indice dell'elemento uguale a target, se presente o NOT_FOUND 
  
/* acquisiamo n dati, n <= LEN */
  do {
    printf("\nInserisci n numero di dati = ");
    scanf("%d", &n);
  } while (n <= 0 || n > LEN);
  
  
  for (i = 0; i < n; i++) {
    printf("dato %d = ", i);
    scanf("%d", &data[i]);
  }
  
  printf("\nInserisci il target:");
  scanf("%d", &target);
    
  /*ricerca sequenziale di target nel vettore data. 
  appena target e' trovato esci dal ciclo*/
  for(i=0; !found && i<n;i++){
		found=(data[i]==target);
  }
  
  /*restituisci l'indice dell'elemento uguale a target oppure NOT_FOUND*/
  if(found) where=i-1;
  else where=NOT_FOUND;
  
  printf("\nL'indice dell'elemento e':%d",where);
  
  system("PAUSE");
}
