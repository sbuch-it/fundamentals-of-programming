/* Scrivere un programma che legge un carattere da tastiera, lo memorizza in una
 variabile char c, la stampa, ne modifica il valore tramite l’uso di una 
 variabile puntatore  (es: lo imposta a ‘!’)  e stampa c. 
 
 Modifica 1: Modificare il programma affinchè non si utilizzi mai direttamente
  (in nessuna operazione) la variabile c, ma sempre e solo tramite puntatore
*/
 
#include <stdio.h>

int main()
{
    char c,*pc;

    pc = &c;    
    
    printf("Inserisci un carattere: ");
    scanf("%c",pc);
    printf("Hai inserito: %c\n",*pc);
    
    *pc = '!';
    
    printf("Il carattere inserito e' diventato: %c\n",*pc);
    
    getchar();
    getchar();
    return 0;
}
