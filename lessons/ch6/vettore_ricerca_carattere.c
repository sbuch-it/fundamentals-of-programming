/* Scrivere il programma che legge un vettore di caratteri da tastiera 
(8 caratteri) ed effettua la ricerca all’interno del vettore di un carattere
 richiesto dall’utente */
#include <stdio.h>

int main()
{
    char vettore[8];
    int dimensione=8;    
    char c;
    int i;
    int trovato;
    
    for (i=0;i<dimensione;i++) {
        printf("Inserisci il carattere in posizione %d del vettore: ",i);
        scanf("%c",&vettore[i]);
        fflush(stdin);
    }
    
    printf("Inserisci un carattere da ricercare: ",c);
    scanf("%c",&c);
    
    trovato = 0;
    for (i=0;i<dimensione && !trovato;i++) {
        if (vettore[i]==c) {
           trovato = 1;
        }
    }
    
    if (trovato)
        printf("Il carattere ricercato si trova in posizione %d\n",i-1); // perchè ho inserito "i-1" ???
    else
        printf("Il carattere ricercato non e' stato trovato\n");        
    
    getchar();
    getchar();    
    return 0;
}
