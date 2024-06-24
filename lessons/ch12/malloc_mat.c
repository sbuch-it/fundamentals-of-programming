#include<stdlib>

main(){
	..
	int riga, col;
	int **mat;
	mat=alloc_matr(riga,col);
	....
	free(*mat);
	free(mat);
}

int **alloc_matr(int rig,int col){
	int *data,**mat;
	int i;
	data=malloc(rig *col*sizeof(*data));
	if (data==NULL)return NULL;
	
	mat=malloc(rig*sizeof(*mat));
	if(mat==NULL) return NULL;
	
	for(i=0;i<rig;i++){
		mat[i]=data;
		data+=col;
	}
	return mat;
}
