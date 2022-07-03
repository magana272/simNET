#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "../math/mymath.h"
#include "layer.h"
struct simNN; 
typedef struct simNN{
int input_size, hidden_layers_count, output_size;
layer * hidden_layers;
layer * input;
layer * output;
int * opti;
int * lossfunction; 
} simNN;

simNN *create_nn(int input_size, int hidden_layers, int output_size);



void forward_pass(simNN net);

void backward_pass(simNN net);
