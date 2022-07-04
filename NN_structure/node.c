#include "node.h"

neuron * createNeuron(int inputNumber){
    mat * input;
    neuron * new_neuron   =  malloc(sizeof(new_neuron));
    mat * activation_function = &ReLuAct;
    mat * dactv =  &dtReLuAct;
}
neuron * createOutPutNeuron(int inputNumber){
    mat * input;
    neuron * new_neuron   =  malloc(sizeof(new_neuron));
    mat * activation_function = &SoftMaxMAct;
    mat * dactv =  &dtSoftMaxMAct;
}
