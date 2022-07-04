#pragma once 
#include <stdio.h>
#include <stdlib.h>
#include "../math/mymath.h"
#include "../opt_cost_fitness/activations.h"

typedef struct node_t
{   mat *activation_function;
    mat *outputweight;
    double bias;
    double z;
    double h;
    mat * input; //some input vector

    double *dw;
    mat * dactv;

} neuron;

neuron * createNeuron(int inputNumber);
neuron * createOutPutNeuron(int inputNumber);
neuron * createInputNeuron();


