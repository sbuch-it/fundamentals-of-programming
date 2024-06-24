#include <stdio.h>

int main()
{
    FILE *flusso;
    
    flusso = fopen("prova.txt", "r");
    
    if (flusso == NULL) {
         printf("Errore di apertura.\n");
         return 0;
    }
    
    // operazioni di I/O
    
    fclose(flusso);
    getchar(); getchar();    
    return 0;
}
