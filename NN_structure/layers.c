#include "layer.h"
layer * createLayer(int units, layer * prev){
    int size  = units;
    layer* new_layer  = malloc(sizeof(layer));
    layer* outputWeights;
	new_layer->neurons =  malloc(sizeof(neuron)* units);
	new_layer->prev_layer = prev;
    new_layer->next_layer = NULL;
}

layer * createHiddenLayer(int units, layer * prev){
    int size  = units;
    layer* new_layer  = malloc(sizeof(layer));
    layer* outputWeights;
	new_layer->neurons =  malloc(sizeof(neuron)* units);
    new_layer->prev_layer = prev;
    new_layer->next_layer = NULL;
    for(int i; i <= units; i++){
        new_layer->neurons[i] = createNeuron(prev->output_numbers);
    }
}
layer * createOutputLayer(int units, layer * prev){
    int size  = units;
    layer* new_layer  = malloc(sizeof(layer));
    layer* outputWeights;
	new_layer->neurons =  malloc(sizeof(neuron)* units);
    new_layer->prev_layer = prev;
    new_layer->next_layer = NULL;
    for(int i; i <= units; i++){
        new_layer->neurons[i] = createNeuron(prev->output_numbers);
    }
}