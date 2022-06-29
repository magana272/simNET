//
//  main.c
//  NeuNet
//
//  Created by Manuel Magana on 6/25/22.
//

#include <stdio.h>
#include <stdlib.h>
#include "mymath.h"
#include "mnist.h"


// #define SIZE 784 
// #define NUM_TRAIN 60000
// #define NUM_TEST 10000

int main(int argc, const char * argv[]) {

    mat* new_mat = mycreateEmptyMatrix(2,3);
    // printf("%p\n",&*new_mat);
    printf("row %d \n",new_mat->row);
    printf("col %d \n",new_mat->col);
    // printf("%p\n",new_mat->matrix_t);
    // printMat(new_mat);
    float array[][3] ={{1.f,2.f,3.f},{5.f,6.f,7.f}};
    mat* new_arr = arrayToMatrix((float*)&array,2,3);
    mat* add_arr  = mat_add(new_arr, new_arr);
    printMat(add_arr);
    // TESTING Mat Free
    free_mat(new_mat);
    free_mat(add_arr);
    free_mat(new_arr);

//////////////////////MNIST STUFF ////////////////////////////////////

    load_mnist();
	int i;
	for (i=0; i<784; i++) {
		printf("%1.1f ", test_image[0][i]);
		if ((i+1) % 28 == 0) putchar('\n');
	}




/////////////////////////////////////////////////////////////////////////////////////////
// SHUFFLE IMAGES 
// Should have a determ Shuffle and regular shuffle 
/////////////////////////////////////////////////////////////////////////////////////////




/////////////////////////////////////////////////////////////////////////////////////////
// K-Fold Cross Validation 
// Should have a determ Shuffle and regular shuffle 
/////////////////////////////////////////////////////////////////////////////////////////



    return(0);
}
