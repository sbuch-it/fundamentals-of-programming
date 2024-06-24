/* Scrivere il programma che implementa il Teorema di Pitagora, stampando la 
 lunghezza dell’ipotenusa dopo aver letto la lunghezza dei cateti (da tastiera).
 Strutturare il programma con una funzione. Svilupparlo in due versioni: in una
 i cateti sono variabili globali, in una sono locali. 
 
 Versione con VARIABILI LOCALI
 */
#include <stdio.h>
#include <math.h>

float ipotenusa(float, float);

int main() 
{
    float cat1,cat2,ipot;
    
    printf("Inserisci le lunghezze dei due cateti...\n");
    scanf("%f",&cat1);
    scanf("%f",&cat2);
    
    ipot = ipotenusa(cat1,cat2);
    
    printf("Ipotenusa: %f\n",ipot);
    
    getchar();
    getchar();
    return 0;
}

float ipotenusa(float cateto1, float cateto2)
{ 
    float val_ipotenusa;
    val_ipotenusa = sqrt(pow(cateto1,2) + pow(cateto2,2));
    return val_ipotenusa;
}
