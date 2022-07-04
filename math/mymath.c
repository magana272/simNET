#include "mymath.h"
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
mat* mycreateEmptyMatrix(int row, int col){
	double **m;
    int i;
    mat* new_mat;
    new_mat = (mat *) malloc(sizeof(mat));
	m = (double**)malloc(row * sizeof(double*));
	m[0] = (double*)calloc(row * col, sizeof(double));
	for (i = 1; i < row; ++i){
		m[i] = m[i-1] + col;}
    new_mat->col = col;
    new_mat->row = row;   
    new_mat->matrix_t = m;
	return new_mat;
}
mat* arrayToMatrix(double* arr, int row, int col){
    int i;
    int j;
    mat* new_matrix = mycreateEmptyMatrix(row, col);
    for (i = 0 ; i < row; ++i){
        for(j=0 ; j < col ; j++){
            new_matrix->matrix_t[i][j] = *((arr+i*col) + j);
            }
    }
    new_matrix->row = row;
    new_matrix->col = col;
    return new_matrix;
}
mat* randomMatrix(int row, int col){
    mat * randomMat = mycreateEmptyMatrix(row, col);
    int i;
    int j;
    for (i = 0 ; i < row; ++i){
        for(j=0 ; j < col ; j++){
            randomMat->matrix_t[i][j] = rand()/RAND_MAX;
            }
    }
    randomMat->row = row;
    randomMat->col = col;
return randomMat;

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
        int k;
        mat* new_mat = mycreateEmptyMatrix(A->row, B->col);
        int col ; 
        for(i=0 ; i< A->row; i++){
            for(j = 0; j< B->col; j++){
                double entry = 0.0;
                for(k=0 ; k<B->col; k++ ){
                    entry += (A->matrix_t[i][k]) * (B->matrix_t[k][j]);
                    new_mat->matrix_t[i][j] = entry;
                }
                }
        }
        return new_mat;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
mat* mat_add(mat *A, mat *B){
    int i;
    int j;
    if(A->col != B->col && A->row != B->row){
        printf("\ncol:\n");
        printf("%d", A->col);
        printf("%d",B->col);
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
    double ** matrix =  A->matrix_t;
    for(i=0; i< A->row ; i++){
        printf("[");
        for (j= 0; j<  A->col; j++){   
            printf("%f ", A->matrix_t[i][j]);}
        printf("]\n");
    }
}
void free_mat(mat* A){
    int i;
    double** m = A->matrix_t;
    if( A->row == 1){
        free(m);
        free(A);
        return;

    }
    for(i=1;i< A->row; i++){
    free(m[i-1]);}
    free(m);
    free(A);
    }


