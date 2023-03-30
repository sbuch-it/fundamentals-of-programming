/* Scrivere il programma che calcola la lunghezza di una circonferenza e area 
del cerchio, in modo che inizi con un comodo menu testuale in cui l’utente può
 scegliere se inserire la lunghezza del raggio (premendo ‘0’), calcolare la 
 circonferenza usando il raggio attualmente memorizzato (premendo ‘1’),
  calcolare l’area del cerchio usando il raggio memorizzato (premendo ‘2’), o 
  se uscire dal programma (premendo ‘u’). Strutturare il programma usando 
  funzioni.
*/
#include <stdio.h>
#include <math.h> // la includo per usare la costante M_PI, che contiene il valore pi greco

// prototipi
void stampa_menu(void);
char leggi_un_carattere(void);
int esegui_operazione(char);

// main
int main() 
{
    int uscita=0;
    char scelta;
    float risultato;
    
    while(!uscita) // finchè l'utente non vuole uscire...
    {
       stampa_menu();
       scelta = leggi_un_carattere();
       uscita = esegui_operazione(scelta);
    }
    
    return 0;
}

/* Questa funzione stampa il menu delle scelta */
void stampa_menu()
{
     printf("\nScelte possibili:\n");
     printf("0 - Inserimento raggio\n");
     printf("1 - Calcolo circonferenza\n");
     printf("2 - Calcolo area cerchio\n");     
     printf("u - Uscita\n");
}

/* Questa funzione legge un carattere da tastiera e lo restituisce */
char leggi_un_carattere()
{
     char scelta;
     scelta = getchar();
     fflush(stdin); 
     return scelta;  
}

/* Questa funzione esegue l'operazione corrispondente al carattere che legge
come parametro (ossia la variabile "scelta"). Restituisce 0 (false) se l'utente 
non ha scelto di uscite, altrimenti restituisce 1 (true). */
int esegui_operazione(char scelta)
{
     static float raggio=0; // ATTENZIONE! E' static, quindi vivrà durante tutta l'esecuzione del programma e non verrà distrutta a fine funzione!!!
     float risultato; // questa invece a fine funzione viene distrutta...
     int uscita=0; // ed anche questa...
     
     switch(scelta)
     {
          // lettura del raggio e memorizzazione
          case '0':
               printf("Inserisci il raggio...\n");
               scanf("%f",&raggio);
               fflush(stdin);
               printf("Raggio impostato al valore di %f\n",raggio);
               break;
          
          // calcolo circonferenza usando il raggio memorizzato
          case '1':               
               // controllo se l'utente ha inserito un raggio o meno
               if (raggio == 0)
                  printf("Per prima cosa devi inserire il raggio!\n");
               else
               {
                  risultato = 2*M_PI*raggio;
                  printf("Circonferenza: %f\n",risultato);               
               }
               break;     
               
          // calcolo area cerchio usando il raggio memorizzato
          case '2':               
               // controllo se l'utente ha inserito un raggio o meno
               if (raggio == 0)
                  printf("Per prima cosa devi inserire il raggio!\n");
               else
               {               
                  risultato = M_PI*raggio*raggio;
                  printf("Area cerchio: %f\n",risultato);               
               }
               break;  
               
          // l'utente ha scelto di uscire      
          case 'u':
               uscita = 1;
               break;
          default:
               printf("Hai effettuato una scelta non valida...riprova!\n");                     
     }
       
     return uscita;   
}
