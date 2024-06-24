/* Scrivere un programma che legge due numeri reali ed un carattere da tastiera.
 Il carattere può essere uno tra +,-,*,/. In base al carattere inserito, il 
 programma deve stampare rispettivamente la somma, la differenza, il prodotto o
 la divisione tra i due numeri reali. Se viene inserito un carattere non 
 ammesso, deve stampare un messaggio di avvertimento. Utilizzare 
 l’istruzione switch
*/
#include <stdio.h>
 
int main()
{
    float n1,n2,risultato;
    char c;
    
    printf("Inserisci un numero reale:\n");
    scanf("%f",&n1); 
    printf("Inserisci un altro numero reale:\n");
    scanf("%f",&n2);
    fflush(stdin);
    
    printf("Inserisci un operatore tra +, -, * e /:\n");
    scanf("%c",&c);                  
    
    switch(c)
    {
       case '+':
            risultato=n1+n2;
            printf("La somma vale: %f\n",risultato);            
            break;
       case '-':
            risultato=n1-n2;
            printf("La differenza vale: %f\n",risultato);
            break;
       case '*':
            risultato=n1*n2;
            printf("Il prodotto vale: %f\n",risultato);
            break;
       case '/':
            risultato=n1/n2;
            printf("La divisione vale: %f\n",risultato);   
            break;
       default:
            printf("Hai inserito un operatore non valido!\n");            
    }
    
    getchar();
    getchar();
    return 0;
}
