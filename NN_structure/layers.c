#include "layer.h"
layer * createLayer(int units, layer * prev){
    layer* new_layer  = malloc(sizeof(layer));
    new_layer->neuron_units = units;
	new_layer->prev_layer = prev;
    new_layer->next_layer = NULL;
    return new_layer;

}


layer * createHiddenLayer(int units, layer * prev){
    layer* new_layer  = malloc(sizeof(layer));
    new_layer->neuron_units = units;
    new_layer->activation_function = ReLuAct;
    new_layer->dactv =  dtReLuAct;
    new_layer->prev_layer = prev;
    new_layer->next_layer = NULL;
    return new_layer;
}
layer * createOutputLayer(int units, layer * prev){
    layer* new_layer  = malloc(sizeof(layer));
    new_layer->neuron_units = units;
    new_layer->activation_function = SoftMaxMAct;
    new_layer->dactv =  dtSoftMaxMAct;
    new_layer->prev_layer = prev;
    new_layer->next_layer = NULL;
    return new_layer;
}
layer * createInPutLayer(int units){
    layer* new_layer  = malloc(sizeof(layer));
    new_layer->neuron_units = units;
    new_layer->input = mycreateEmptyMatrix(units, 1);
    new_layer->prev_layer = NULL;
    new_layer->next_layer = NULL;
    return new_layer;
}