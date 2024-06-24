#include <stdio.h>

int main()
{
    double A[3][2];
    double B[3][2];
    double C[3][2];
    int i,j;
    
    printf("Inserisci la matrice A...\n");
    for (i=0; i<3; i++) {
        for (j=0; j<2; j++) {
            printf("Elemento A(%d,%d): ",i,j);
            scanf("%lf",&A[i][j]);
        }
    }
    
    printf("Inserisci la matrice B...\n");
    for (i=0; i<3; i++) {
        for (j=0; j<2; j++) {
            printf("Elemento B(%d,%d): ",i,j);
            scanf("%lf",&B[i][j]);
        }
    }    
    
    for (i=0; i<3; i++) {
        for (j=0; j<2; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    } 

    printf("Matrice somma C = A + B...\n");
    for (i=0; i<3; i++) {
        for (j=0; j<2; j++) {
            printf("%lf ",C[i][j]);
        }
        printf("\n");
    }            
    
    getchar();
    getchar();
    return 0;
}
