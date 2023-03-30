/* Scrivere il programma che legge una stringa. Se l’utente inserisce “gatto” o
 “cane” o “topo”, il programma mi avverte che ho inserito un animale. 
 Se l’utente inserisce “auto” o “bici” o “bus” mi avverte che ho inserito un 
 mezzo di trasporto. Altrimenti mi comunica che non ha riconosciuto la parola 
 inserita.
 */
#include <stdio.h>

int main() 
{
    char mystring[11];
    int i;
    int len;
    
    printf("Inserisci una stringa di 10 caratteri max\n");
    scanf("%s",mystring);
    
    if (!strcmp(mystring,"cane") || !strcmp(mystring,"gatto") || !strcmp(mystring,"topo"))
       printf("Animale.\n");
    else {
       if (!strcmp(mystring,"auto") || !strcmp(mystring,"bici") || !strcmp(mystring,"bus"))
          printf("Mezzo di trasporto.\n");         
       else
          printf("Non riconosciuta.\n");
    }

    getchar();
    getchar();
    return 0;
}
