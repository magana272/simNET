#include "lossfunction.h"

float CrossEntropyLoss(int true_label[], mat * prediction , int BatchSize){ 
    // The predictions are probs... 
    double loss = 0.f; 
    int i;
    for ( i=0 ; i< BatchSize; i++){ 
        loss+=logf(prediction->matrix_t[i][true_label[i]]);
    }
    return loss;
}

float dCrossEntropyz(float z){
    return -1/z;
}