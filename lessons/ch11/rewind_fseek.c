#include <stdio.h>

int main()
{
    FILE *f;
    f = fopen("prova.txt", "w+");
    
    fputc('A', f);
    
    //rewind(f);
    fseek(f, 0, SEEK_SET);
    
    printf("Il carattere memorizzato e' %c\n", fgetc(f));
    
    fclose(f);
    
    getchar(); getchar();
    return 0;
}
