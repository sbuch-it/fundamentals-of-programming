/* Scrivere il programma che legge una stringa da tastiera la concatena a se
 stessa per 10 volte e la stampa */
#include <stdio.h>

int main() 
{
    char nome[9];
    char nomi_concatenati[8*10 + 1]; // 10 concatenazioni di una stringa di 8 caratteri e carattere di fine stringa
    int i;
    int lettere,numeri,altri;
    
    printf("Inserisci un nome di 8 caratteri max\n");
    scanf("%s",nome);
    
    nomi_concatenati[0]='\0'; // così facendo imposto la stringa "vuota"
    
    for (i=0;i<10;i++)
    {
        strcat(nomi_concatenati,nome);
    }
       
    printf("Ecco la stringa che contiene tale nome ripetuto 10 volte: %s\n",nomi_concatenati);
    
    getchar();
    getchar();
    return 0;
}
