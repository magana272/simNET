//
//  main.c
//  NeuNet
//
//  Created by Manuel Magana on 6/25/22.
//

#include <stdio.h>
#include <stdlib.h>
#include "mymath.h"

int main(int argc, const char * argv[]) {

    mat* new_mat = mycreateEmptyMatrix(2,3);
    // printf("%p\n",&*new_mat);
    printf("row %d \n",new_mat->row);
    printf("col %d \n",new_mat->col);
    // printf("%p\n",new_mat->matrix_t);
    printMat(new_mat);

    return(0);
}
