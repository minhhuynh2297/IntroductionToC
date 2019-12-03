#include <stdio.h>
#include <stdlib.h>

void print(int** matrix, int row, int column){
    int i, j;
	for(i=0; i<row; i++){
		for(j=0; j<column; j++){
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}

int main(int argc, char** argv){
	
	FILE* file;
	int row;
	int column; 
	int i;
	int j;

	if(argc!=2){
		printf("error\n");
		exit(0);
	}

	file=fopen(argv[1], "r"); 

	
	if(file==NULL){
		printf("error\n");
		exit(0);
	} 

	fscanf(file, "%d	%d", &row, &column); 
	
	//printf("rows: %d\n", row);
	//printf("columns: %d\n", column);

	int** matrix1=malloc(row*sizeof(int*)); 

	for(i=0; i<row; i++){
		matrix1[i]=malloc(column*sizeof(int*)); 
	}

	int** matrix2=malloc(row*sizeof(int*));
	for(i=0; i<row; i++){
		matrix2[i]=malloc(column*sizeof(int*));
	}

	while(!feof(file)){
		for(i=0; i<row; i++){
			for(j=0; j<column; j++){
				fscanf(file, "%d", &matrix1[i][j]); 
			}
		}
	//	printf("\n");
		for(i=0; i<row; i++){
			for(j=0; j<column; j++){
				fscanf(file, "%d", &matrix2[i][j]); 
			}
		}
	}

	

	print(matrix1, row, column); 
	printf("\n");
	print(matrix2, row, column); 
	printf("\n"); 

	int** matrix3=malloc(row*sizeof(int*));
	for(i=0; i<row; i++){
		matrix3[i]=malloc(column*sizeof(int*));
	}

	for(i=0; i<row; i++){
		for(j=0; j<column; j++){
			matrix3[i][j]=(matrix1[i][j] + matrix2[i][j]); 
		}
	}

	print(matrix3, row, column); 
	
return 0;
}
