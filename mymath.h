#include <stdlib.h>
typedef struct Matrix
{  int col; 
   int row;
   float** matrix_t; 
} mat;

mat* mycreateEmptyMatrix(int m, int n);
mat* arrayToMatrix(float *arr, int row, int col);
mat* mat_mul(mat *A, mat *B);
mat* mat_add(mat *A, mat *B);
void mat_add_inplace(mat *A, mat *B);
//  the contains will be in A
mat* mat_sub(mat *A, mat *B);
void mat_sub_inplace(mat *A, mat *B);
// contents will be in A 
mat* mat_inverse(mat *A); 
void printMat(mat *A);
void free_mat(mat* A);