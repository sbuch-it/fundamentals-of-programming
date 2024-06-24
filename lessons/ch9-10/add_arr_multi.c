#include<stdio.h>

#define N 10

void add_arr(const int [][N],const int [][N],int [][N],int);

main(){
	int x[N][N],y[N][N],z[N][N];
	int n;
	int i,j;
	
	printf("Inserisci n:\n");	
	scanf("%d",&n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			x[i][j]=2*i+j;
			printf("x:%d ",x[i][j]);
			y[i][j]=2*j+i;	
			printf("y:%d ",y[i][j]);		
		}
		printf("\n");
	}
	add_arr(x,y,z,n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d ",z[i][j]);			
		}
		printf("\n");
	}
}

void add_arr(const int a[][N],const int b[][N],int c[][N],int m){
	int i,j;
	
	for(i=0;i<m;i++){
		for(j=0;j<m;j++){
			c[i][j]=a[i][j]+b[i][j];			
		}
	}
}
