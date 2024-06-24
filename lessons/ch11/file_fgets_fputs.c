#include <stdio.h>

int main()
{
    FILE *flusso;
    char nome[20];
    int i;
    
    flusso = fopen("nomi.txt", "w");
    
    if (flusso == NULL) {
         printf("Errore di apertura.\n");
         return 0;
    }
    
    for (i=1; i<=3; i++) {
        scanf("%s", nome);
        fputs(nome, flusso);
        fputc('\n', flusso);
    }    
    fclose(flusso);
    
    flusso = fopen("nomi.txt", "r");
    
    if (flusso == NULL) {
         printf("Errore di apertura.\n");
         return 0;
    }
    
    for (i=1; i<=3; i++) {  
        fgets(nome, 20, flusso);
        printf("%s", nome);
    }
    
    fclose(flusso);    
    getchar(); getchar();    
    return 0;
}
