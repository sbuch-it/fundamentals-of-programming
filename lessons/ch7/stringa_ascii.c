/* Scrivere il programma che legge una stringa da tastiera, stampa la lunghezza
 della stringa inserita ed i codici ASCII di tutti i caratteri presenti nella 
 stringa */
#include <stdio.h>

int main() 
{
    char mystring[11];
    int i;
    int len;
    
    printf("Inserisci una stringa di 10 caratteri max\n");
    scanf("%s",mystring);
    
    len = strlen(mystring);
    
    printf("Stampa di carattere -> codice ASCII:\n");
    for (i=0;i<len;i++)
    {
        printf("%c -> %d\n",mystring[i],mystring[i]);
    }
       
    printf("La stringa inserita e' lunga %d\n",len);
    
    getchar();
    getchar();
    return 0;
}
