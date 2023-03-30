#include<stdio.h>
#define MAX 10

int main(){
	FILE *fpin;
	FILE *fpout;
	int i;
	double num[MAX];
	
    fpin = fopen("input.txt","r");
	fpout = fopen("output.txt","w");

	for(i=0; i<MAX; i++)
		fscanf(fpin,"%lf",&num[i]);

	for(i=0; i<MAX; i++)
		fprintf(fpout,"%f\n",num[i]);

	fclose(fpin);
	fclose(fpout);
	return 0;
}
