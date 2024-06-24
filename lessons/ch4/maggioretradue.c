/* Scrivere il programma che legge due numeri reali da tastiera e stampa il
 maggiore dei due */
#include <stdio.h>

int main()
{
    float n1, n2;
    
    printf("Inserisci un numero reale:\n");
    scanf("%f",&n1);
    
    printf("Inserisci un numero reale diverso dal precedente:\n");
    scanf("%f",&n2);              
    
    if (n1>n2)
    {
        printf("Il numero maggiore e' il primo inserito, ossia %f\n",n1);
    }
    else
    {
        printf("Il numero maggiore e' il secondo inserito, ossia %f\n",n2);
    }
           
    getchar();
    getchar();
    return 0;
}
