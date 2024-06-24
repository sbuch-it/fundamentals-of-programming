/*Scrivere il programma che calcola l�area del trapezio di cui si inseriscono 
base maggiore, base minore, e altezza (interi) da tastiera. Si deve verificare 
che l�utente non abbia inserito valori negativi. Strutturare il codice in modo 
che il calcolo dell�area sia effettuato in una apposita funzione. 
Anche l�inserimento dell�input da tastiera deve essere gestito da apposite 
funzioni. 

- Modifica: Modificare il programma in modo che le funzioni siano definite dopo
 il main (ossia usando i prototipi)
 
- Modifica: Modificare il programma in modo che, dopo aver stampato il 
risultato, chieda all�utente se vuol terminare il programma (digitando �s�) 
oppure se vuol calcolare l�area di un nuovo trapezio (digitando �n�)
*/

#include <stdio.h>

// prototipi delle funzioni definite in questo file
int leggi_intero_e_controlla_segno(void);
short controlla_negativo(int);
float calcola_area_trapezio(int, int, int);

// funzione principale
int main() 
{
    int b,B,h;
    float area;
    char c;
    
    // messaggi per l'utente
    printf("Questo programma calcola l'area del trapezio.\n");
    printf("Basi e altezza devono essere valori interi positivi.\n");
    printf("Inserendo valori negativi, l'operazione di inserimento dovra' essere ripetuta!\n\n");
    
    // ciclo di esecuzione (finch� l'utente non digita 'n')
    do {
        
       // inserimento basi e altezza...realizzati con la medesima funzione!
       printf("Inserisci la base minore...\n");
       b = leggi_intero_e_controlla_segno();
    
       printf("Inserisci la base maggiore...\n");
       B = leggi_intero_e_controlla_segno();
    
       printf("Inserisci l'altezza...\n");
       h = leggi_intero_e_controlla_segno();        
    
       // calcolo area trapezio e stampa del risultato
       area = calcola_area_trapezio(b,B,h);    
       printf("L'area del trapezio vale: %f\n",area);
    
       // richiesta ripetizione
       fflush(stdin);
       printf("Vuoi calcolare un'altra area (s/n)?\n");
       
       // ciclo che legge un carattere da tastiera, ignorandoli tutti finch� l'utente inserisce 's' o 'n'
       do {
          c = getchar();
       } while (c != 'n' && c != 's');
           
    } while (c == 's');      
    

    return 0;
}

/* Questa funzione restituisce 1 (true) se il parametro in ingresso � negativo, 
altrimenti ritorna 0 (false) */
short controlla_negativo(int n)
{
    if (n<0)
       return 1;
    else
       return 0;
}

/* Questa funzione legge un intero da tastiera, e pretende che venga inserito
di nuovo nel caso in cui sia negativo */
int leggi_intero_e_controlla_segno()
{
    int numero;
    do {
       scanf("%d",&numero);    
    } while(controlla_negativo(numero));
    return numero;
}

/* Questa funzione calcola l'area del trapezio e restituisce il risultato */
float calcola_area_trapezio(int basemin, int basemag, int altezza)
{
    float risultato;
    risultato = (basemin+basemag)*altezza/2;
    return risultato;
}
