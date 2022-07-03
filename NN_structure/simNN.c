#include "simNN.h"
#include "node.h"
#include "layer.h"

simNN *create_nn(int input_size, int hidden_layers, int output_size){
    simNN* NN = (malloc(sizeof(simNN)));
    NN->input_size = input_size;
    NN->output_size = output_size;
    NN->hidden_layers = malloc(sizeof(layer)*hidden_layers);
    return NN;
}


// simNN * forward_pass(simNN * NN){
//     int i;
//     for( i=0 ; i< NN->hidden_layers; i++){
//         printMat()
//     }
// }

// float * predict(NN)

