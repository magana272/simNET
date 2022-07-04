#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "../math/mymath.h"
#include "layer.h"
struct simNN; 
typedef struct simNN{
int input_size, hidden_layers_count, output_size;
layer ** hidden_layers;
layer * output_layer;
layer * input_layer;
int * opti;
int * lossfunction; 
} simNN;

simNN *create_nn(int input_size, int hidden_layers, int output_size, char * typeNN);
void random_weights(simNN *network);

void forward_pass(simNN net);

void backward_pass(simNN net);
void print_weight(simNN* network);
