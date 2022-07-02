// class Linear(Activation):
// def __init__(self):
// super().__init__()
// def forward(self, Z: np.ndarray) -> np.ndarray:
// """Forward pass for f(z) = z."""
// return Z
// def backward(self, Z: np.ndarray, dY: np.ndarray) -> np.ndarray:
// """Backward pfor f(z) = z."""
// return dY
#include <math.h>

float ReLuAct(float input){
   return (((input)>(0))?(input):(0));
}

float dReLuAct(float input){
    /// not really worring about undefined
   return (((input)>=(0))?(1):(0));
}

