/* Scrivere il programma che calcola la media degli elementi (numerici) di un
 vettore di 10 numeri, letto da tastiera.
 
- Modifica: Modificare il programma in modo che l’operazione di inserimento e
 quella di media siano definite in apposite funzioni
 */
#include <stdio.h>

int main() 
{
    float vettore[10];
    float med=0;
    int dimensione=10;    
    int i;
    
    for (i=0;i<dimensione;i++) {
        printf("Inserisci l'elemento %d del vettore: ",i);
        scanf("%f",&vettore[i]);
    }
    
    for (i=0;i<dimensione;i++) {
        med += vettore[i];
    }   
    med /= dimensione;

    printf("La media degli elementi vale: %f\n",med);
    
    getchar();
    getchar();
    return 0;
}
