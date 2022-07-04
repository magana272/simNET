#include "simNN.h"
#include "node.h"
#include "layer.h"

simNN *create_nn(int input_size, int hidden_layers, int output_size , char* typeNN){
    simNN* NN = (malloc(sizeof(simNN)));
    NN->input_size = input_size;
    NN->output_size = output_size;
    NN->hidden_layers_count  = hidden_layers;
    NN->input_layer =  malloc(sizeof(layer));
    NN->hidden_layers = malloc(sizeof(layer)*hidden_layers);
    NN->output_layer = malloc(sizeof(layer));
    return NN;
}

void connect(simNN* network){
}


void random_weights(simNN* network){
    int out;
    layer * curr_layer = network->output_layer;
    while(curr_layer != NULL){
        out = curr_layer->neuron_units;
        curr_layer->prev_layer;
        curr_layer->weights = randomMatrix(curr_layer->neuron_units,out);
    }
}

void print_weight(simNN* network){
    int out;
    layer * curr_layer = network->output_layer;
    while(curr_layer != NULL){
        out = curr_layer->neuron_units;
        curr_layer->prev_layer;
        printMat(curr_layer->weights);
    }
}