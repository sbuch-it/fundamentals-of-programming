/* legge due matrice di dimensioni n*n, 
   effettua somma, sottrazione */

#include <stdio.h>

#define N 3

int main(){

    // dichiarazione variabili
    int a[N][N],b[N][N],result[N][N];
    int i,j;
    
    // inserimento dati        
    printf("Inserire i %d elementi della prima matrice...\n", N*N);
    for (i=0;i<N;i++)
        for (j=0;j<N;j++)
            scanf("%d", &a[i][j]);
    
    // stampa matrice
    printf("Hai inserito la matrice:\n");
    for (i=0;i<N;i++) {
        for (j=0;j<N;j++) {
            printf("%d\t", a[i][j]); 
        }
        printf("\n");
    }
                 
    // inserimento dati        
    printf("Inserire i %d elementi della seconda matrice...\n", N*N);
    for (i=0;i<N;i++)
        for (j=0;j<N;j++)
            scanf("%d", &b[i][j]);
    
    // stampa matrice
    printf("Hai inserito la matrice:\n");
    for (i=0;i<N;i++) {
        for (j=0;j<N;j++) {
            printf("%d\t", b[i][j]); 
        }
        printf("\n");
    }
       
    //somma
    for (i=0;i<N;i++) {
        for (j=0;j<N;j++) {
            result[i][j]=a[i][j]+b[i][j]; 
        }
    }
    
    // stampa matrice
    printf("Somma delle matrici:\n");
    for (i=0;i<N;i++) {
        for (j=0;j<N;j++) {
            printf("%d\t", result[i][j]); 
        }
        printf("\n");
    }

    //sottrazione
    for (i=0;i<N;i++) {
        for (j=0;j<N;j++) {
            result[i][j]=a[i][j]-b[i][j]; 
        }
    }
    
    // stampa matrice
    printf("Sottrazione delle matrici:\n");
    for (i=0;i<N;i++) {
        for (j=0;j<N;j++) {
            printf("%d\t", result[i][j]); 
        }
        printf("\n");
    }
    
    fflush(stdin);
    getchar();

    return 0;
}
