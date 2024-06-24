/* 
 * Programma che legge legge un carattere da tastiera, lo stampa, e stampa il 
 * codice numerico (ASCII) corrispondente
 */
#include <stdio.h>

int main()
{
    char carattere; // dichiarazione variabile carattere
    
    printf("Inserisci un carattere:\n");
    scanf("%c",&carattere); // lettura del carattere da tastiera (notare %c)
    
    /* Nella seguente istruzione, il %c causa la stampa del carattere, mentre
       trattandolo come un numero intero, ossia usando %d, viene stamapto il
       valore numerico corrispondente ossia il codice ASCII
    */
    printf("Hai inserito %c, con codice ASCII pari a %d\n",carattere,carattere);
    
    getchar(); // per evitare la chiusura della finestra in Windows..
    getchar();
    
    return 0;
}
