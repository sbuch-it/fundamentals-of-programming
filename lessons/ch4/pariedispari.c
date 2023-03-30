/* Scrivere il programma che legge un numero intero da tastiera e stampa
 se si tratta di un numero pari o dispari */
#include <stdio.h>

int main()
{
    int numero;
    float resto;
    
    printf("Inserisci un numero intero:\n");
    scanf("%d",&numero);           
    
    resto=numero%2;
    
    if (resto==0)
    {
        printf("Numero pari!\n");
    }
    else
    {
        printf("Numero dispari!\n");
    }
           
    getchar();
    getchar();
    return 0;
}
