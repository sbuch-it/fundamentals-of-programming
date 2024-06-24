/* Scrivere il programma che implementa il Teorema di Pitagora, stampando la 
 lunghezza dell’ipotenusa dopo aver letto la lunghezza dei cateti (da tastiera).
 Strutturare il programma con una funzione. Svilupparlo in due versioni: in una
 i cateti sono variabili globali, in una sono locali. 
 
 Versione con VARIABILI GLOBALI
 */
#include <stdio.h>
#include <math.h>

float val_ipotenusa; // variabile GLOBALE! accessibile da ovunque!
float cat1,cat2; // variabili GLOBALI! accessibili da ovunque!

void ipotenusa(void); // prototipo funzione...notare che non ho bisogno di parametri adesso!

int main() 
{    
    printf("Inserisci le lunghezze dei due cateti...\n");
    scanf("%f",&cat1); // cat1 e cat2 sono già state dichiarate...GLOBALI
    scanf("%f",&cat2);
    
    ipotenusa(); // non passo parametri nè controllo valori restituiti, poichè in questo esempio lavoro solo su variabili GLOBALI
    
    printf("Ipotenusa: %f\n",val_ipotenusa); // val_ipotenusa è GLOBALE
    
    getchar();
    getchar();
    return 0;
}

void ipotenusa()
{ 
    val_ipotenusa = sqrt(pow(cat1,2) + pow(cat2,2)); // posso tranquillamente usare (senza dichiararle qui) le variabili val_ipotenusa e cat1,cat2, perchè sono GLOBALI
}
