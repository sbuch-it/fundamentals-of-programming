/* 
 * Programma che effettua la somma di due numeri reali
 */
#include <stdio.h>

int main()
{
    float a,b,somma; // dichiarazione variabili float
    
    printf("Inserisci il primo numero reale (float):\n");
    scanf("%f",&a); // lettura da tastiera (notare %f)
    
    printf("Inserisci il secondo numero reale (float):\n");
    scanf("%f",&b); // lettura da tastiera (notare %f)    
    
    somma = a+b;

    printf("La somma vale: %f\n",somma);
    
    /* avrei potuto evitare l'uso della variabile "somma", semplicemente 
       scrivendo:
       printf("La somma vale: %f\n",a+b);
    */
    
    getchar(); // per evitare la chiusura della finestra in Windows..
    getchar();
    
    return 0;
}
