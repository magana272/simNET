#pragma once
#include <stdio.h>
#include <stdlib.h>	
#include "layer.h"
#include "node.h"
#include "../math/mymath.h"
#include "../opt_cost_fitness/activations.h"
typedef mat *(*Act_funct)(mat * matrix, int row, int col);
typedef mat *(*dAct_funct)(mat * matrix, int row, int col);
typedef struct layer_t
{	int output_numbers; 
	int neuron_units;
	Act_funct  activation_function;
    dAct_funct dactv;
	mat* cahedDact;
	mat* input; 
	mat * weights;
 	struct layer * next_layer;
	struct layer * prev_layer;
} layer;


layer * createHiddenLayer(int units, layer * prev);
layer * createLayer(int units, layer * prev);
layer * createInPutLayer(int units);
layer * createOutputLayer(int units, layer * prev);

