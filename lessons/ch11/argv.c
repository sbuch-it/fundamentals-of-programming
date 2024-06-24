#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[]){
	FILE *fpin;
	FILE *fpout;
	
	if((fpin=fopen(argv[1],"r"))==NULL)
		exit(EXIT_FAILURE);
	else{
		if((fpout=fopen(argv[2],"w"))==NULL)
			exit(EXIT_FAILURE);
		else{
			int c;
			
			while((c=fgetc(fpin))!=EOF){
				fputc(c,fpout);
			}
		}
	}
    
	fclose(fpin);
	fclose(fpout);
	return 0;
}
