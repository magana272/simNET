#include "activations.h"
mat* ReLuAct(mat* input, int row, int col){
    int row_index;
    int col_index;
    mat* relu = mycreateEmptyMatrix(row, col);
    for (row_index=0; row_index < row; row_index++)
        for(col_index = 0; col_index < col; col_index++){
            float relu_ij = (((input->matrix_t[row_index][col_index])>(0.f))?(input->matrix_t[row_index][col_index]):(0.f));
            relu->matrix_t[row_index][col_index] = relu_ij;
        }
    return relu;
    
}

// mat* LogsiticAct(mat* input, int row, int col){

// }
mat* SoftMaxMAct(mat* input, int row, int col){
    //N number of rows and for labels the  col 10;
    mat* softmaxed =  mycreateEmptyMatrix(row, col);
    int i;
    int j;
    float** matrix = input->matrix_t;
    float** out_putMatrix =  softmaxed->matrix_t;
    float* summed = (float*)calloc(sizeof(float), row);
    for(i=0 ; i<row; i++){
        for(j=0 ;j<col; j++){
            out_putMatrix[i][j] = powf(EulerNumber,matrix[i][j]);
            summed[i]+=out_putMatrix[i][j];
        }
    }
    for(i=0 ; i<row; i++){
        for(j=0 ;j<col; j++){
            out_putMatrix[i][j] = powf(EulerNumber,matrix[i][j]);
            out_putMatrix[i][j] = out_putMatrix[i][j]/summed[i];
        }
    }
    free(summed);
    return softmaxed;

}
