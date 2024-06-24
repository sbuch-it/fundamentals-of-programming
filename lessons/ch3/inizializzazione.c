/* 
 * Programma che stampa il valore di un intero prima e dopo averlo inizializzato
 */
#include <stdio.h>

int main()
{
    /* Con la seguente istruzione si riserva spazio in memoria per una variabile
       intera ma non si assegna nessun valore ad essa, ossia NON E' 
       INIZIALIZZATA. Il valore che gli viene assegnato dipende dal contenuto
       della porzione di memoria che gli viene riservata. Non è necessariamente
       zero. Se eseguo il programma più volte (o se riavvio la macchina e lo
       rieseguo), posso vedere come questo valore cambierà ad ogni esecuzione, 
       visto che ogni volta viene riservata una diversa area di memoria. */
       
    int a; // dichiarazione...ma NON inizializzazione!
    
    printf("Valore della variabile non inzializzata: %d\n",a);
    
    a=5; // assegno un valore ad "a"
    
    printf("Valore della variabile dopo avergli assegnato un valore: %d\n",a);    
    
    getchar(); // per evitare la chiusura della finestra in Windows...
    
    return 0; 
}
