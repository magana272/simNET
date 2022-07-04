#pragma once
#include <stdio.h>
#include <stdlib.h>	
#include "layer.h"
#include "node.h"
#include "../math/mymath.h"
#include "../opt_cost_fitness/activations.h"
typedef struct layer_t
{	int output_numbers; 
	int neuron_units;
	neuron ** neurons;
	mat * weights;
 	struct layer * next_layer;
	struct layer * prev_layer;
} layer;


layer * createLayer(int units, layer * prev);
layer * createInPutLayer(int units);
layer * createOutputLayer(int units, layer * prev);

