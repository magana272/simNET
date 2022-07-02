#pragma once
#include <math.h>
#include "mymath.h"

mat* ReLuAct(mat* input, int row, int col);

// mat* LogsiticAct(mat* input, int row, int col){
// }

mat* SoftMaxMAct(mat* input, int row, int col);
