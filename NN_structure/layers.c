#include "layer.h"
layer * createLayer(int units, layer * prev){
    int size  = units;
    layer* new_layer  = malloc(sizeof(layer));
    mat* outputWeights;
	new_layer->neurons =  malloc(sizeof(neuron)* units);
	new_layer->prev_layer = prev;
    new_layer->next_layer = NULL;
    return new_layer;

}


layer * createHiddenLayer(int units, layer * prev){
    int size  = units;
    layer* new_layer  = malloc(sizeof(layer));
    mat* outputWeights;
	new_layer->neurons =  malloc(sizeof(neuron)* units);
    new_layer->prev_layer = prev;
    new_layer->next_layer = NULL;
    for(int i; i <= units; i++){
        new_layer->neurons[i] = createNeuron(prev->output_numbers);
    }
    return new_layer;
}
layer * createOutputLayer(int units, layer * prev){
    int size  = units;
    layer* new_layer  = malloc(sizeof(layer));
    mat* outputWeights;
	new_layer->neurons =  malloc(sizeof(neuron)* units);
    new_layer->prev_layer = prev;
    new_layer->next_layer = NULL;
    for(int i; i <= units; i++){
        new_layer->neurons[i] = createOutPutNeuron(prev->output_numbers);
    }
    return new_layer;
}
layer * createInPutLayer(int units){
    int size  = units;
    layer* new_layer  = malloc(sizeof(layer));
    mat* outputWeights;
	new_layer->neurons =  malloc(sizeof(neuron)* units);
    new_layer->prev_layer = NULL;
    new_layer->next_layer = NULL;
    for(int i; i <= units; i++){
        new_layer->neurons[i] = createInputNeuron();
    }
    return new_layer;
}