/* Scrivere il programma che calcola il fattoriale di un numero, usando un 
 ciclo for */
#include <stdio.h>

int main()
{
    int n;
    int i;
    int fattoriale;
    
    printf("Inserisci un numero intero:\n");
    scanf("%d",&n);
    
    fattoriale=n;    
    for (i=1;i<n;i++)
    {
        fattoriale=fattoriale*(n-i);
    }
    
    printf("Il fattoriale di %d vale %d\n",n,fattoriale);
    getchar();
    getchar();
    return 0;
}
