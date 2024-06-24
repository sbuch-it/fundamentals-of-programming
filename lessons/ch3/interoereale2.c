/* 
 * Programma che legge da tastiera un numero intero e un numero reale, ne fa la
 * somma, la differenza ed il  prodotto tra le due, e stampa il risultato 
 * troncato (a intero) ed il risultato reale
  * Versione con assegnamento dei risultati float alle variabili intere
 */
#include <stdio.h>

int main()
{
    int a;
    float b;
    int somma_troncata, differenza_troncata, prodotto_troncato;
    float somma_reale, differenza_reale, prodotto_reale;
    
    printf("Inserisci un numero intero:\n");
    scanf("%d",&a); // lettura da tastiera (notare %d)
    
    printf("Inserisci un numero reale:\n");
    scanf("%f",&b); // lettura da tastiera (notare %f)    

    somma_reale = a+b; // somma di due float, risultato float, assegnamento ad una variabile float -> ok!    
    somma_troncata = somma_reale; // assegno una variabile float ad una variabile intera -> troncamento
    
    differenza_reale = a-b;    
    differenza_troncata = differenza_reale;    
    
    prodotto_reale = somma_reale * differenza_reale;    
    prodotto_troncato = prodotto_reale;    

    printf("La somma troncata e reale valgono: %d e %f\n",somma_troncata,somma_reale);    
    printf("La differenza troncata e reale valgono: %d e %f\n",differenza_troncata,differenza_reale);  
    printf("Il prodotto troncato e reale dei due precenti risultati valgono: %d e %f\n",prodotto_troncato,prodotto_reale);  
    
    getchar(); // per evitare la chiusura della finestra in Windows..
    getchar();
    
    return 0;
}
