#include <stdio.h>
#include <stdlib.h>

int** create_matrix(int row, int col)
{
    int **matrix = (int **)malloc(row*sizeof(int));
    for (int r=0; r<row; r++) {
        matrix[r] = (int *)malloc(col*sizeof(int));
    }
    return matrix;
}

int free_matrix(int **matrix, int row, int col)
{
    for (int r=0; r<row; r++) {
        free(matrix[r]);
    }
    free(matrix);
    return 1;
}

int fill_data(int **matrix, int row, int col)
{
    int idx = 1;
    for(int r=0; r<row; r++) {
        for(int c=0; c<col; c++) {
            matrix[r][c] = idx;
            idx++;
        }
    }
}

void print_matrix(int **matrix, int row, int col)
{
    for(int r=0; r<row; r++) {
        for(int c=0; c<col; c++) {
            printf("%d ", matrix[r][c]);
        }
        printf("\n");
    }
}

int main()
{
    int row, col;
    scanf("%d %d", &row, &col);

    int **matrix = create_matrix(row, col);
    fill_data(matrix,row,col);
    print_matrix(matrix, row, col);
    free_matrix(matrix, row, col);

    return 0;

}

/*
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int row,col;
	scanf("%d %d", &row, &col);
	
	int** matrix = (int **)malloc(sizeof(int)*row);			//**
	for(int r=0; r<row; r++) {					//**
		matrix[r] = (int *)malloc(sizeof(int)*col);		//**
	}
	
	int idx=1;
	for(int r=0; r<row; r++) {
		for(int c=0; c<col; c++) {
			matrix[r][c] = idx;
			printf("%d ",matrix[r][c]);
			idx++;
		}
		printf("\n");
	}
	
	for(int r=0; r<row; r++) {
		free(matrix[r]);
	}
	free(matrix);
}
*/
