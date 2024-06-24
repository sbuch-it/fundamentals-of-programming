/* Scrivere il programma che legge un intero da tastiera, effettua la somma di
 5 numeri uguali a tale numero e restituisce il risultato */
#include <stdio.h>

int main()
{
    int n;
    int r; 
    int i; // contatore
    printf("Inserisci un numero intero:\n");
    scanf("%d",&n);
    
    i=0; // inizializzo il contatore
    r=0; // inizializzo la variabile che conterrà le somme parziali ad ogni iterazione (e la somma finale)
    
    while(i<5)
    {
       r=r+n;
       i++; // incremento il contatore (attenzione!)
    }
    
    printf("La somma di 5 numeri che valgono %d e' %d\n",n,r);
    getchar();
    getchar();
    return 0;
}
