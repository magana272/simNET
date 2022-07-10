#include "lossfunction.h"

double CrossEntropyLoss(int true_label[], mat * prediction , int BatchSize){ 
    // The predictions are probs... 
    //  I should probaly one-hot endcode .. but for now it's fine .... 
    double loss = 0.f; 
    int i;
    for ( i=0 ; i <  prediction ->row; i++){ 
        if(i = true_label[0]){
          loss+=logf(prediction->matrix_t[i][true_label[i]]);

        } 
    }
    return loss;
}

double dCrossEntropyz(mat* input, int true_label[]){
    
    for(int i = 0 ; i < input->row; i++)

}