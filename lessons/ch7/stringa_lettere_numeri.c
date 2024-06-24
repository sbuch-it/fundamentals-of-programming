/* Scrivere il programma che legge una stringa da tastiera e stampa il numero di
 lettere e di caratteri numerici contenuti in tale stringa */
#include <stdio.h>

int main() 
{
    char stringa[21];
    int i;
    int lettere = 0,numeri = 0,altri = 0;
    
    printf("Inserisci una stringa di 20 caratteri max\n");
    scanf("%s",stringa);
    
    for (i=0;i<strlen(stringa);i++)
    {
        if (isalpha(stringa[i])) // isalpha restituisce 1 (true) se il carattere stringa[i] è una lettera
           lettere++;
        else {
             if (isdigit(stringa[i])) // isdigit restituisce 1 (true) se il carattere stringa[i] è un numero
                numeri++;
        }
    }
    
    altri = strlen(stringa)-lettere-numeri; // strlen restituisce la lunghezza della stringa
    
    printf("Stringa formata da %d lettere, %d numeri, %d altri caratteri.\n",lettere,numeri,altri);
    
    getchar();
    getchar();
    return 0;
}
