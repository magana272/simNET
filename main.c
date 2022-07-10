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



double array[][2] = {{11.f,11.f,},{-11.f,11.f,}};
mat* new_arr = arrayToMatrix((double*)array,2,2);
mat* relu_arr  = ReLuAct(new_arr, new_arr->row,new_arr->col);
mat* softmax = SoftMaxMAct(new_arr,new_arr->row,new_arr->col);
free_mat(new_arr);
free_mat(softmax);
simNN * mytestNN = create_nn(784, 2, 10, "test");
mytestNN->input_layer = createInPutLayer(784);
mytestNN->hidden_layers[0] = createHiddenLayer(784, mytestNN->input_layer);
mytestNN->hidden_layers[1] = createHiddenLayer(784, mytestNN->hidden_layers[0]);
mytestNN->output_layer = createOutputLayer(10, mytestNN->hidden_layers[1]);
random_weights(mytestNN);

mat* test_x1 = arrayToMatrix(train_image[0], 784, 1);
// printMat(test_x1);
double test[] =  {test_label[0]};

// printMat(arrayToMatrix(test, 1,1 ));
mat * prediction_prob = forwardPass(mytestNN, test_x1, arrayToMatrix(test, 1,1 ));
mat * loss = CrossEntropyLoss(test_label[0], prediction_prob, 1);

return(0);
}
