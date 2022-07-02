#include <stdio.h>
#include <stdlib.h>
#include "mymath.h"
#include "mnist.h"
#include "simNN.h"


simNN *create_nn(int input_size, int hidden_layers, int output_size){
    simNN* NN = (malloc(sizeof(simNN)));
    NN->input_size = input_size;
    NN->output_size = output_size;
    NN->hidden_layers = hidden_layers;
    
    
}

