/* Scrivere il programma che legge tre numeri reali da tastiera e stampa il
  maggiore dei tre */
#include <stdio.h>

int main()
{
    float a,b,c,maggiore;
    
    printf("Inserisci un numero reale:\n");
    scanf("%f",&a); 
    printf("Inserisci un altro numero reale:\n");
    scanf("%f",&b);   
    printf("Inserisci un ulteriore numero reale:\n");
    scanf("%f",&c);                     

    if (a>b)
    {
        if (a>c)
        {
           maggiore=a;
        }
        else
        {
            if (c>b)
            {
                maggiore=c;
            }            
        }
    }
    else
    {
        if (b>c)
        {
           maggiore=b;
        }
        else
        {
            if (c>b)
            {
                maggiore=c;
            }
        }
    }
    
    printf("Il numero piu' grande vale %f\n",maggiore);
           
    getchar();
    getchar();
    return 0;
}
