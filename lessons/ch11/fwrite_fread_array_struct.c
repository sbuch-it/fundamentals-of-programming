#include <stdio.h>

typedef struct {
    int n;
    char c;
} TEST;
    
int main()
{  
    TEST v[3], v_nuovo[3];
    FILE *f;
    int i;
    
    printf("Inserisci tre coppie intero/carattere...\n");    
    for (i=0; i<3; i++) {
        scanf("%d %c", &v[i].n, &v[i].c);
        getchar();    
    }
    
    f = fopen("test.dat", "wb");
    if (f==NULL) {
        printf("Errore di accesso al file!\n");
        return 0;       
    }    
    if (fwrite(v, sizeof(TEST), 3, f) != 3) {
        printf("Errore di scrittura!\n");
        return 0;
    }
    fclose(f);    
    
    f = fopen("test.dat", "rb");
    if (f==NULL) {
        printf("Errore di accesso al file!\n");
        return 0;       
    }
    if (fread(v_nuovo, sizeof(TEST), 3, f) != 3) {
        printf("Errore di lettura!\n");
        return 0;
    }
    fclose(f); 
    
    printf("Ho letto dal file test.dat le seguenti informazioni:\n");
    for (i=0; i<3; i++) {
        printf("%d %c\n", v_nuovo[i].n, v_nuovo[i].c);
    }           
    
    getchar(); getchar();
    return 0;
}
