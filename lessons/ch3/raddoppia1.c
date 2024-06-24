/* 
 * Programma che legge un intero da tastiera, lo stampa, lo raddoppia e
 * stampa il risultato (versione con due variabili dichiarate)
 */
#include <stdio.h>

int main()
{
    int num,num_doppio; // dichiarazione variabili
    
    printf("Inserisci un numero intero:\n"); // stampa
    scanf("%d",&num); // lettura del numero da tastiera (attenzione al &)
    printf("Hai inserito il numero %d\n",num); // stampa del numero inserito
    
    num_doppio = num*2; // raddoppio e salvo il risultato
    
    printf("Il doppio vale %d\n",num_doppio); // stampa del doppio    
    
    getchar(); // per evitare la chiusura della finestra in Windows...
    getchar();
    
    return 0; // fine main
}
