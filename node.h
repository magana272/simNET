#include <stdio.h>
struct node;
typedef struct node
{
    int *activation_function;
    double *outputweight;
    double bias;
    float z; 

    double dactv;
    double *dw;
    double dactv;
    double dz;


} neuron;
