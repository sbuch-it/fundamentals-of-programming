#include <stdio.h>

int main()
{
    double A[3][2];
    double AT[2][3];
    int i,j;
    
    printf("Inserisci la matrice A...\n");
    for (i=0; i<3; i++) {
        for (j=0; j<2; j++) {
            printf("Elemento A(%d,%d): ",i,j);
            scanf("%lf",&A[i][j]);
        }
    }
    
    for (i=0; i<3; i++) {
        for (j=0; j<2; j++) {
            AT[j][i] = A[i][j];
        }
    } 

    printf("Matrice trasposta A'...\n");
    for (i=0; i<2; i++) {
        for (j=0; j<3; j++) {
            printf("%lf ",AT[i][j]);
        }
        printf("\n");
    }            
    
    getchar();
    getchar();
    return 0;
}
