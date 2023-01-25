#include <stdio.h>
#define ROW1 2
#define COMMON 4
#define COL2 4
#define MAX 101

typedef struct{
	int col;
	int row;
	int value;
}matrix;



int main(){
	
	matrix m1[MAX];
	matrix m2[MAX];
matrix m3[MAX];
matrix m4[MAX];

	int a2[ROW1][COMMON]={{7,0,0,1},{0,0,0,1}};
	int a3[COMMON][COL2]={{0,3,0,1},{0,0,0,1},{2,1,8,3},{3,1,9,0}};
	sparse(ROW1,COMMON,a2,m1);	
	sparse(COMMON,COL2,a3,m2);	
	transpose(m2,m3);
	print(m1);
	print(m3);

	multiply(m1,m3,m4);
	print(m4);

}

int multiply(matrix A[MAX],matrix B[MAX],matrix C[MAX]){

int cval;
int i=1;
int dizi[10];
int j;
int m=0;
int k;
int a=1;
int count=1;
int sum=0;
func2(B,dizi);

func(A,i,&count);
printf("%d\n%d\n",i,count);

while(i<=A[0].value){
	for(k=0; k<count; k++){
		for(j=1; j<=dizi[m]; j++){
			if(A[i+k].col==B[j].col){
				if(dizi[j]!=dizi[j+1]){
					cval++;
					sum+=A[i+k].value*B[j].value;
				C[a].row=A[i+k].row;
				C[a].col=B[j].row;
				C[a].value=sum;
					sum=0;
					a++;
				}
				else{
				sum+=A[i+k].value*B[j].value;
			
			}
			}
		
		}
		j=j+dizi[m];
		m++;
		k=0;
	}
	i=i+count;
	count=1;
	func(A,i,count);
}

	C[0].value=cval-1;	
	C[0].row=ROW1;
	C[0].col=COL2;
}

int func(matrix A[MAX],int i,int *count){
	int k=i;
	while(A[i].row==A[i+1].row){
	*count=*count+1;
	i++;
	}
	i=k;
}

int func2(matrix B[MAX], int dizi[]){
	int j=0;
	int i;
	for(i=1; i<=B[0].value; i++){
		if (B[i].row!=B[i+1].row){
			dizi[j]=i;
			j++;
		}
		
	}
}


void transpose(matrix A[MAX],matrix B[MAX]){
	

	int n,i,j,currentb;
n=A[0].value; //number of items
B[0].row=A[0].col; //number of rows
B[0].col=A[0].row; //number of columns
B[0].value=n;
if(n>0){
currentb=1;
for(i=0; i<A[0].col; i++){
for(j=1; j<=n; j++) {//find the ones with col i in a
if(A[j].col==i){
B[currentb].row=A[j].col;
B[currentb].col=A[j].row;
B[currentb].value=A[j].value;
currentb++;
}
}
}
}

}

void sparse(int x,int y,int A[x][y], matrix sparsematrix[MAX]){
		int count=0;
	int i,j;
	for (i=0; i<x; i++){
		for (j=0; j<y; j++){
			if(A[i][j]!=0){
				count++;
				sparsematrix[count].row=i;
				sparsematrix[count].col=j;
				sparsematrix[count].value=A[i][j];
			}
			
			
		}
	}
	sparsematrix[0].value=count;
    sparsematrix[0].row=x;
    sparsematrix[0].col=y;
}

void print(matrix compact_matrix[MAX])
{
	int i;
 printf("Sparse Matrix Multiplication:\nRow\tColumn\tValue\n");
 for (i = 0; i <= compact_matrix[0].value; i++)
 {

 printf("%d\t %d\t %d \n",compact_matrix[i].row, compact_matrix[i].col, compact_matrix[i].value);

 }
}
