//
//  main.c
//  NeuNet
//
//  Created by Manuel Magana on 6/25/22.
//
#include <stdio.h>
#include <stdlib.h>
#include "math/mymath.h"
#include "mnist.h"
#include "NN_structure/simNN.h"
#include "NN_structure/node.h"
#include "NN_structure/layer.h"
#include "opt_cost_fitness/activations.h"


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
    // float array[][3] ={{1.f,2.f,3.f},{5.f,6.f,7.f}};
    // mat* new_arr = arrayToMatrix((float*)&array,2,3);
    // mat* add_arr  = mat_add(new_arr, new_arr);
    // printMat(add_arr);
    // // TESTING Mat Free
    free_mat(new_mat);
    // free_mat(add_arr);
    // free_mat(new_arr);

    

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
////////////////////////////////////////
// Testing Activations and dactivation//
////////////////////////////////////////
// float array[][3] ={{-1.f,2.f,3.f},{5.f,-6.f,7.f}};



double array[][2] = {{11.f,11.f,},{11.f,11.f,}};
mat* new_arr = arrayToMatrix((double*)array,2,2);
// mat* relu_arr  = ReLuAct(new_arr, new_arr->row,new_arr->col);
// printMat(new_arr);
// printf("\n");
// printMat(relu_arr);
printMat(new_arr);
printf("\n");
printf("softmax act\n");
mat* softmax = SoftMaxMAct(new_arr,new_arr->row,new_arr->col);
printMat(softmax);
printf("\nfree_new_Arr\n");

free_mat(new_arr);
printf("col %d\n",softmax->col);
printf("row %d\n",softmax->row);

printf("free softmax\n");
free_mat(softmax);
printf("softmax freed\n");
printf("here\n");
simNN * mytestNN = create_nn(784, 2, 10, "test");
printf("NN init\n");
mytestNN->input_layer = createInPutLayer(784);
printf("Create_input_layer\n");
mytestNN->hidden_layers[0] = createLayer(2, mytestNN->input_layer);
printf("first hidden init\n");
mytestNN->hidden_layers[1] = createLayer(2, mytestNN->hidden_layers[0]);
printf("second hidden init\n");
mytestNN->output_layer = createOutputLayer(10, mytestNN->hidden_layers[1]);
printf("out init\n");
random_weights(mytestNN);
printf("random weights init\n");
print_weight(mytestNN);
printf("help\n");
printf("help\n");

// for(run =0 ; run < KFOLD; run++){
//     if (KFOLD == 1 ){
//        simNN test;
//         // validation_train_SET[run];
//         // validation_test_SET[run];
//         printf("Let's train on all the data %d\n", run);
//     }
//     else{
//         // struct simNN val_nn = create_nn(); 

//         int train_fold[SIZE - (SIZE/KFOLD)];
//         int validation_fold[SIZE/KFOLD];
//         printf("run: %d\n", run);
//         printf("Need to implement splitting \n");
//     }
// }
return(0);
}
