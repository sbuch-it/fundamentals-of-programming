/* Scrivere il programma che legge dal file 'matrice.txt' una 
matrice di numeri
floating point, formata da R righe e C colonne 
(definiti con #define).
Il programma deve stampare a video la matrice letta e 
memorizzare sul file
'matrice_trasposta.txt' la sua trasposta. */

#include <stdio.h>
 
#define R 2
#define C 3
 
int main()
{
     FILE *f1, *f2;
     float M[R][C];
     int i,j;
     
     f1 = fopen("matrice.txt", "r");
     if (f1 == NULL) {
        printf("Errore durante l'apertura del file.\n");
        exit(0);
     }
     
     f2 = fopen("matrice_trasposta.txt", "w");
     if (f2 == NULL) {
        printf("Errore durante la creazione del file.\n");
        exit(0);
     }     
     
     for (i = 0; i<R; i++) {
        for (j = 0; j<C; j++) {       
           fscanf(f1, "%f", &M[i][j]);
        }
     }
     
     printf("La matrice caricata da file e' la seguente:\n");
     for (i = 0; i<R; i++) {
        for (j = 0; j<C; j++) {  
            printf("%f\t", M[i][j]);
        }
        printf("\n");
     } 
     
     for (i = 0; i<C; i++) {
        for (j = 0; j<R; j++) {       
           fprintf(f2, "%f", M[j][i]);
           if (j<R-1) fprintf(f2, "\t");
        }
        fprintf(f2, "\n");
     }              
     
     fclose(f1);
     fclose(f2);
     getchar(); getchar();
     return 0;
}
