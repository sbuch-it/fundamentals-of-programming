#include <stdio.h>

int main()
{
    FILE *flusso;
    char c;
    
    flusso = fopen("caratteri.txt", "r");
    
    if (flusso == NULL) {
         printf("Errore di apertura.\n");
         return 0;
    }
    
    do {
        c = fgetc(flusso);
        printf("%c", c);
    } while (feof(flusso) == 0);
    
    fclose(flusso);
    getchar(); getchar();    
    return 0;
}
