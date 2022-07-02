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
#include "simNN.h"


#define KFOLD 1

// #define SIZE 784 
// #define NUM_TRAIN 60000
// #define NUM_TEST 10000

int main(int argc, const char * argv[]) {


////////// Math stuff 
    mat* new_mat = mycreateEmptyMatrix(2,3);
    // printf("%p\n",&*new_mat);
    printf("row %d \n",new_mat->row);
    printf("col %d \n",new_mat->col);
    // printf("%p\n",new_mat->matrix_t);
    // printMat(new_mat);
    float array[][3] ={{1.f,2.f,3.f},{5.f,6.f,7.f}};
    mat* new_arr = arrayToMatrix((float*)&array,2,3);
    mat* add_arr  = mat_add(new_arr, new_arr);
    // printMat(add_arr);
    // TESTING Mat Free
    free_mat(new_mat);
    free_mat(add_arr);
    free_mat(new_arr);

    

//////////////////////MNIST STUFF ////////////////////////////////////

    load_mnist();
	int i;
	// for (i=0; i<784; i++) {
	// 	printf("%1.1f ", train_image[0][i]);
	// 	if ((i+1) % 28 == 0) putchar('\n');
       
	// }
    // printf("\n%d\n", train_label[0]);
/////////////////////////////////////////////////////////////////////////////////////////
// SHUFFLE IMAGES 
// Should have a determ Shuffle and regular shuffle
// let's just shuffle the index
/////////////////////////////////////////////////////////////////////////////////////////
// Making sure shuffle works .... 

// for(i=0 ; i <10 ; i++){
//     printf("%d\n", shuffled_image_index[i]);
// }






/////////////////////////////////////////////////////////////////////////////////////////
// K-Fold Cross Validation 
// Should have a determ Shuffle and regular shuffle cd
/////////////////////////////////////////////////////////////////////////////////////////

k_fold(KFOLD);


/////////////////////////////////////////////////////////////////////////////////////////
// Initalize NN 
/////////////////////////////////////////////////////////////////////////////////////////
struct simNN validing_net[KFOLD];
float LEARNING_RATE[10] = {.0075,.01, .02, .03, .05,.075,.1 , .2, .5, .6};
double ERROR[KFOLD];
int run;
for(run =0 ; run < KFOLD; run++){
    if (KFOLD == 1 ){
        struct simNN test;
        // validation_train_SET[run];
        // validation_test_SET[run];
        printf("Let's train on all the data %d\n", run);
    }
    else{
        // struct simNN val_nn = create_nn(); 

        int train_fold[SIZE - (SIZE/KFOLD)];
        int validation_fold[SIZE/KFOLD];
        printf("run: %d\n", run);
        printf("Need to implement splitting \n");
    }
}
return(0);
}
