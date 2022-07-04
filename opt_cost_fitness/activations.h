#pragma once
#include <math.h>
#include "../math/mymath.h"

mat* ReLuAct(mat* input, int row, int col);
mat* dtReLuAct(mat* input, int row, int col);

// mat* LogsiticAct(mat* input, int row, int col){
// }

mat* SoftMaxMAct(mat* input, int row, int col);
mat* dtSoftMaxMAct(mat* input, int row, int col);


mat* LogisticAct(mat* input, int row, int col);

