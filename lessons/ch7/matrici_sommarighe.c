/* legge una matrice di dimensioni m righe ed n colonne, 
   ricerca la riga con somma massima e stampa l'indice di riga
   corrispondente */

#include <stdio.h>

#define N 3
#define M 4

int main(){

    // dichiarazione variabili
    int m[N][M];
    int num_r,num_c;
    int max_somma,max_riga;
    int somma_riga=0;
    int i,j;
    
    // inserimento dati        
    printf("Inserire i %d elementi della matrice %dX%d...\n", N*M, N, M);
    for (i=0;i<N;i++)
        for (j=0;j<M;j++)
            scanf("%d", &m[i][j]);
    
    // stampa matrice
    printf("Hai inserito la matrice:\n");
    for (i=0;i<N;i++) {
        for (j=0;j<M;j++) {
            printf("%d\t", m[i][j]); 
        }
        printf("\n");
    }
                 
    // inizializzazione variabili
    max_somma=0;
    max_riga=0;
       
    // calcolo della somma di ciascuna riga
    for (i=0;i<N;i++){
        somma_riga=0;
        for (j=0;j<M;j++)
            somma_riga += m[i][j]; 
        // ricerca della riga con somma massima    
        if (somma_riga>max_somma) {
           max_riga = i;
           max_somma = somma_riga;
        }
    }
    printf("La riga %d ha somma massima!\n", max_riga);
    
    fflush(stdin);
    getchar();
    return 0;
}
