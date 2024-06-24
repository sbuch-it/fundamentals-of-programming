/*Ricerca binaria*/

#include <stdio.h>
#define LEN 5

int main(){
   int data[LEN], k = 0;
   unsigned int i;
   int end = LEN - 1, start = 0, middle;
   int target, found = 0;
/* l'array data[LEN] contiene i numeri da esaminare
   la variabile target identifica il numero che cerchiamo 
   la variabile found segnala se il numero viene trovato o meno 
*/

/* acquisizione dei dati */
  for(i = 0; i < LEN; i++){
    printf("dato %d=",i+1);
    scanf("%d",&data[i]);
  } 
  printf("Bersaglio = ");
  scanf("%d",&target);
  printf("\n");  
  
  /*ricerca*/
   do {
      middle =  (end + start) / 2;
      if (data[middle] == target) {
         found = 1;
      }
      else if (data[middle] < target) {
         start = middle + 1;
      }
      else {
         end = middle - 1;
      }
   } while (!found && start <= end);
   if (found == 1) {
      printf("Trovato il numero %d nella posizione %d\n",data[middle],middle);
   }
   else {
      printf("Il numero cercato non e' stato trovato\n");
   }
   
}
