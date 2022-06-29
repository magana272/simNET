#include "mymath.h"
#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
mat* mycreateEmptyMatrix(int row, int col){
	float **m;
    int i;
    mat* new_mat;
    new_mat = (mat *) malloc(sizeof(mat));
	m = (float**)malloc(row * sizeof(float*));
	m[0] = (float*)calloc(row * col, sizeof(float));
	for (i = 1; i < row; ++i){
		m[i] = m[i-1] + col;}
    new_mat->col = col;
    new_mat->row = row;   
    new_mat->matrix_t = m;
	return new_mat;
}
mat* arrayToMatrix(float* arr, int row, int col){
    int i;
    int j;
    mat* new_matrix = mycreateEmptyMatrix(row, col);
    for (i = 0 ; i < row; ++i){
        for(j=0 ; j < col ; j++){
            new_matrix->matrix_t[i][j] = *((arr+i*col) + j);
            }
    }
    return new_matrix;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
mat* mat_mul(mat *A, mat *B){
    if(A->col != B->row){
        printf("Mismatching dim");
        exit(1);
    } 
    else{
        int i;
        int j;
        mat* new_mat = mycreateEmptyMatrix(A->row, B->col);
        int col ; 
        for(i=0 ; i< A->row; i++){
            int entry = 0;
            for(j = 0; j< A->col; j++){
                entry += (A->matrix_t[i][j]) * (B->matrix_t[j][i]);
                }
            new_mat->matrix_t[i][col] = entry;
            col++;
        }
        return new_mat;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
mat* mat_add(mat *A, mat *B){
    int i;
    int j;
    if(A->col != B->col && A->row != B->row){
        printf("Mismatching dim");
        exit(1);
    }
    else{
        mat* new_mat = mycreateEmptyMatrix(A->col, A->row);
        for(i=0; i< A->row ; i++){
            for (j= 0; j<  A->col; j++){   
                new_mat->matrix_t[i][j] =  A->matrix_t[i][j]+ B->matrix_t[i][j];
            }
        }
        new_mat->row  = A->row;
        new_mat->col  = B->col;
        return new_mat;
    }
}
mat* mat_sub(mat *A, mat *B){
    int i;
    int j;
    if(A->col != B->col && A->row != B->row){
        printf("Mismatching dim");
        exit(1);}
    else{
        mat* new_mat = mycreateEmptyMatrix(A->col, A->row);
        for(i=0; i< A->row ; i++){
            for (j= 0; j<  A->col; j++){   
                new_mat->matrix_t[i][j] =  A->matrix_t[i][j] - B->matrix_t[i][j];
            }
        }
        new_mat->row  = A->row;
        new_mat->col  = B->col;
        return new_mat;
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void printMat(mat *A){
    int i;
    int j;
    float ** matrix =  A->matrix_t;
    for(i=0; i< A->row ; i++){
        printf("[");
        for (j= 0; j<  A->col; j++){   
            printf("%f ", A->matrix_t[i][j]);}
        printf("]\n");
    }
}
void free_mat(mat* A){
    int i;
    float** m = A->matrix_t;
    for(i=1;i< A->row; i++){
    free(m[i-1]);}
    free(m);
    free(A);
    }
// mat mat_inverse(mat A){
//     // TO-DO

// }