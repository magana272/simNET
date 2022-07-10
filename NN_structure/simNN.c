#include "simNN.h"
#include "node.h"
#include "layer.h"

simNN *create_nn(int input_size, int hidden_layers, int output_size , char* typeNN){
    simNN* NN = (malloc(sizeof(simNN)));
    NN->input_size = input_size;
    NN->output_size = output_size;
    NN->hidden_layers_count  = hidden_layers;
    NN->input_layer =  malloc(sizeof(layer));
    NN->hidden_layers = malloc(sizeof(layer)*hidden_layers);
    NN->output_layer = malloc(sizeof(layer));
    return NN;
}

void random_weights(simNN* network){
    int out;
    int i;
    layer * curr_layer = network->output_layer;
    layer * hold = network->output_layer;
    for(i = 0 ; i < (network->hidden_layers_count)+1; i++){
        out = curr_layer->neuron_units;
        curr_layer = curr_layer->prev_layer;
        curr_layer->weights = randomMatrix(curr_layer->neuron_units,out);
        // printMat(curr_layer->weights);
    }
}

void print_weight(simNN* network){
    int out;
    layer * curr_layer = network->output_layer;
    int i;
    for(i = 0 ; i < (network->hidden_layers_count)+1; i++){
        curr_layer = curr_layer->prev_layer;
        printMat(curr_layer->weights);
        printf("here\n");
    }
}
mat* forwardPass(simNN* net, mat* input){
    int layerPos;
    int layerCount  = net->hidden_layers_count;
    mat* input_ = mat_mul(matTranspose(net->input_layer->weights), input);
    printMat(input_);
    printf("the worked\n");
    mat* compute ;
    for(layerPos=0 ; layerPos < layerCount ; layerPos++){
        layer * curr = net->hidden_layers[layerPos];
        compute = (curr->activation_function(input_ ,(int)input_->row, (int)input_->col));
        net->hidden_layers[layerPos]->cahedDact =  net->hidden_layers[layerPos]->dactv(input_ ,(int)input_->row, (int)input_->col);
        input_ = mat_mul(matTranspose(net->hidden_layers[layerPos]->weights),compute);
        printf("the worked\n");
        printMat(input_);
        printf("the worked\n");
    }
    compute  = input_ ;
    input_ = matTranspose(input_);
    input_ = net->output_layer->activation_function(input_, (int)input_->row, (int)input_->col);
    net->output_layer->dactv =  net->output_layer->dactv(compute, (int)compute->row, (int)compute->col);
    return input_;

}
mat* backwardPass(simNN* net, mat* input, mat* label){


}
