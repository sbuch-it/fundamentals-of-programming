/* Scrivere il programma che legge due vettori numerici (di 5 numeri ciascuno) 
da tastiera e ne effettua la somma, stampando il risultato */
#include <stdio.h>

int main() 
{
    double v1[5];
    double v2[5];
    double vsomma[5];
    int i;
    
    // lettura primo vettore
    for(i=0;i<5;i++) {
       printf("Inserisci l'elemento %d del primo vettore: ",i);
       scanf("%lf",&v1[i]);
    }
    
    // lettura secondo vettore
    for(i=0;i<5;i++) {
       printf("Inserisci l'elemento %d del secondo vettore: ",i);
       scanf("%lf",&v2[i]);
    }
    
    // somma    
    for(i=0;i<5;i++) {
       vsomma[i]=v1[i]+v2[i];
    }   
    
    // stampa risultato 
    for(i=0;i<5;i++) {
       printf("L'elemento %d del vettore somma vale: %f\n",i,vsomma[i]);
    } 
    
    // DOMANDA: posso rimuovere alcuni cicli effettuando più operazioni in ognuno di essi? (si...provare a farlo!)         
        
    getchar();
    getchar();
    return 0;
}
