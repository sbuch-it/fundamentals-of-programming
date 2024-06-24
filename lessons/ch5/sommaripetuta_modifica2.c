/* Scrivere il programma che legge un intero da tastiera, effettua la somma di
 5 numeri uguali a tale numero e restituisce il risultato
 Modifica 1: Modificare il programma, in modo che venga richiesto all’utente di 
 specificare quante volte effettuare la somma
 Modifica 2: Modificare il programma, in modo che non venga accettata la
 richiesta di un numero di somme negativo 
 */
#include <stdio.h>

int main()
{
    int n;
    int r; 
    int i; // contatore
    int volte; // numero di ripetizioni della somma
    
    printf("Inserisci un numero intero:\n");
    scanf("%d",&n);
    
    do
    {
       printf("Inserisci il numero di elementi della somma:\n");
       scanf("%d",&volte); 
         
       if (volte<0)      
       {
          printf("Attento! Devi inserire un numero di ripetizioni positivo!\n");       
       }
    }
    while (volte<0);    
    
    
    i=0; // inizializzo il contatore
    r=0; // inizializzo la variabile che conterrà le somme parziali ad ogni iterazione (e la somma finale)
    
    while(i<volte)
    {
       r=r+n;
       i++; // incremento il contatore (attenzione!)
    }
    
    printf("La somma di %d numeri che valgono %d e' %d\n",n,volte,r);
    getchar();
    getchar();
    return 0;
}
