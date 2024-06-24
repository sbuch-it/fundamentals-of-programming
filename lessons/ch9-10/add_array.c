#include<stdio.h>

#define N 10

void add_arr(const int a[],const int b[],int c[],int n);

main(){
	int x[N],y[N],z[N];
	int n;
	int i;
		
	scanf("%d",&n);
		for(i=0;i<n;i++){
			x[i]=2*i;
			printf("x:%d ",x[i]);
			y[i]=2+i;	
			printf("y:%d ",y[i]);		
		}

	
	add_arr(x,y,z,n);
	
	for(i=0;i<n;i++){
			printf("%d ",z[i]);			
		}
		printf("\n");
	
}

void add_arr(const int a[],const int b[],int c[],int m){
	int i;
	
	for(i=0;i<m;i++){
		c[i]=a[i]+b[i];			
	}
}
