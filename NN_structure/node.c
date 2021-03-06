#include "node.h"


neuron * createInputNeuron(){
    mat * input;
    neuron * new_neuron   =  malloc(sizeof(new_neuron));
    mat * activation_function = NULL;
    mat * dactv = NULL;
    return new_neuron;
}

neuron * createNeuron(int inputNumber){
    mat * input;
    neuron * new_neuron   =  malloc(sizeof(new_neuron));
    mat * activation_function = &ReLuAct;
    mat * dactv =  &dtReLuAct;
    return new_neuron;
}
neuron * createOutPutNeuron(int inputNumber){
    mat * input;
    neuron * new_neuron   =  malloc(sizeof(new_neuron));
    mat * activation_function = &SoftMaxMAct;
    mat * dactv =  &dtSoftMaxMAct;
    return new_neuron;
}
