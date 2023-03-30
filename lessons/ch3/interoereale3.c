/* 
 * Programma che legge da tastiera un numero intero e un numero reale, ne fa la
 * somma, la differenza ed il  prodotto tra le due, e stampa il risultato 
 * troncato (a intero) ed il risultato reale
 * Versione senza specificare variabili per i risultati troncati: CAST!
 */
#include <stdio.h>

int main()
{
    int a;
    float b;
    float somma_reale, differenza_reale, prodotto_reale;
    
    printf("Inserisci un numero intero:\n");
    scanf("%d",&a); // lettura da tastiera (notare %d)
    
    printf("Inserisci un numero reale:\n");
    scanf("%f",&b); // lettura da tastiera (notare %f)    

    somma_reale = a+b; // somma di due float, risultato float, assegnamento ad una variabile float -> ok!    
    
    differenza_reale = a-b;    
    
    prodotto_reale = somma_reale * differenza_reale;    

    // Nota bene: le versioni "troncate" le ottengo con un cast a intero!!!
    printf("La somma troncata e reale valgono: %d e %f\n",(int)somma_reale,somma_reale);    
    printf("La differenza troncata e reale valgono: %d e %f\n",(int)differenza_reale,differenza_reale);  
    printf("Il prodotto troncato e reale dei due precenti risultati valgono: %d e %f\n",(int)prodotto_reale,prodotto_reale);  
    
    getchar(); // per evitare la chiusura della finestra in Windows..
    getchar();
    
    return 0;
}
