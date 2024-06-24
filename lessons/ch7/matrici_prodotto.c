#include <stdio.h>

int main()
{
    double A[3][3];
    double B[3][3];
    double C[3][3];
    int i,j,z;
    
    printf("Inserisci la matrice A...\n");
    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            printf("Elemento A(%d,%d): ",i,j);
            scanf("%lf",&A[i][j]);
        }
    }
    
    printf("Inserisci la matrice B...\n");
    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            printf("Elemento B(%d,%d): ",i,j);
            scanf("%lf",&B[i][j]);
        }
    }
    
    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            C[i][j] = 0;
            for (z=0; z<3; z++) {
                C[i][j] = C[i][j] + A[i][z] * B[z][j];
            }
        }
    } 

    printf("Matrice prodotto C = A * B...\n");
    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            printf("%lf ",C[i][j]);
        }
        printf("\n");
    }            
    
    getchar();
    getchar();
    return 0;
}
