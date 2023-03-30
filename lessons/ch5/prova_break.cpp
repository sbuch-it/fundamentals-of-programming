/*
  esempio di utilizzo di break nel caso di piu' cicli annidati
*/

#include <stdio.h>

main() {
  int i,j;
  
  for(i=0;i<3;i++) {
    printf("ciclo esterno %d\n",i);
    for(j=0;j<2;j++){
	    if (j==1)  break;
	    printf("ciclo interno %d\n",j);
    }
  } 
}
