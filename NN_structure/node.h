#pragma once 
#include <stdio.h>
typedef struct node_t
{   int *activation_function;
    double *outputweight;
    double bias;
    float z;
    double *dw;
    double dactv;
    double dz;
}neuron;

//  update  w <-  w - dW; 