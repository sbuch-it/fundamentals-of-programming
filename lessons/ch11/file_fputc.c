#include <stdio.h>

int main()
{
    FILE *flusso;
    char c;
    
    flusso = fopen("caratteri.txt", "w");
    
    if (flusso == NULL) {
         printf("Errore di apertura.\n");
         return 0;
    }
    
    do {
        scanf("%c", &c);
        getchar();
        fputc(c, flusso);
    } while (c != 's');
    
    fclose(flusso);
    getchar(); getchar();    
    return 0;
}
