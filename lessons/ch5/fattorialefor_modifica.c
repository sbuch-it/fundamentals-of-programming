/* Scrivere il programma che calcola il fattoriale di un numero, usando un 
 ciclo for
 Modifica: Modificare il programma in modo che non produca risultati maggiori 
 di 150, usando l’istruzione break…e senza usarla!
 */
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
        if (fattoriale*(n-i)>150)
        {        
           break;
        }        
        fattoriale=fattoriale*(n-i);
    }
    
    printf("Attenzione: restituisco risultati validi solo se inferiori a 150!\n");
    printf("Il fattoriale di %d vale %d\n",n,fattoriale);
    getchar();
    getchar();
    return 0;
}
