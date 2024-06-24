/* Scrivere un programma che legge un carattere da tastiera, lo memorizza in una
 variabile char c, la stampa, ne modifica il valore tramite l’uso di una 
 variabile puntatore  (es: lo imposta a ‘!’)  e stampa c. */
 
#include <stdio.h>

int main()
{
    char c,*pc;
    
    printf("Inserisci un carattere: ");
    scanf("%c",&c);
    printf("Hai inserito: %c\n",c);
    
    pc = &c;
    *pc = '!';
    
    printf("Il carattere inserito e' diventato: %c\n",c);
    
    getchar();
    getchar();
    return 0;
}
