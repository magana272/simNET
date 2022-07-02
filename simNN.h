struct simNN; 
typedef struct simNN{
int input_size, hidden_layers, output_size;
} simNN;
simNN *create_nn(int input_size, int hidden_layers, int output_size);

void forward_pass(simNN net);

void backward_pass(simNN net);