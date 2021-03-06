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



// float array[][3] = {{1.f,2.f,3.f},{5.f,6.f,7.f}};
double array[][1] = {{1.f}};
mat* new_arr = arrayToMatrix(train_image[0],sizeof(train_image[0])/sizeof(train_image[0]),1);
// mat* relu_arr  = ReLuAct(new_arr, new_arr->row,new_arr->col);
// printMat(new_arr);
// printf("\n");
// printMat(relu_arr);
printMat(new_arr);
printf("\n");
mat* softmax = SoftMaxMAct(new_arr,new_arr->row,new_arr->col);
printMat(softmax);

free_mat(new_arr);
free_mat(softmax);






/////////////////////////////////////////////////////////////////////////////////////////
// Initalize NN 
/////////////////////////////////////////////////////////////////////////////////////////
struct simNN validing_net[KFOLD];
double LEARNING_RATE[10] = {.0075,.01, .02, .03, .05,.075,.1 , .2, .5, .6};
double ERROR[KFOLD];
int run;
//  Should maybe use realloc and make this this more dynamic 
//// but it's fine for now ... just trying to get this to work ! :-)


simNN * mytestNN = create_nn(784, 2, 2, "test");
printf("NN init");
mytestNN->input_layer = createInPutLayer(784);
printf("Create_input_layer");
mytestNN->hidden_layers[0] = createLayer(2, mytestNN->hidden_layers[0]);
printf("first hidden init");

mytestNN->hidden_layers[1] = createLayer(2, mytestNN->hidden_layers[1]);
mytestNN->output_layer = createOutputLayer(2, mytestNN->hidden_layers[1]);
random_weights(mytestNN);
printf("random weights init");
print_weight(mytestNN);


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
