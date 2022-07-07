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

void random_weights(simNN* network){
    int out;
    printf("help");
    int i;
    layer * curr_layer = network->output_layer;
    layer * hold = network->output_layer;
    printf("help %d\n", curr_layer->neuron_units);
    for(i = 0 ; i < (network->hidden_layers_count)+1; i++){
        out = curr_layer->neuron_units;
        curr_layer = curr_layer->prev_layer;
        printf("%d\n",curr_layer->neuron_units);
        printf("%d\n",out);
        curr_layer->weights = randomMatrix(curr_layer->neuron_units,out);
        // printMat(curr_layer->weights);
    }
}

void print_weight(simNN* network){
    int out;
    layer * curr_layer = network->output_layer;
    int i;
    for(i = 0 ; i < (network->hidden_layers_count)+1; i++){
        curr_layer = curr_layer->prev_layer;
        printMat(curr_layer->weights);
        printf("here\n");
    }
}