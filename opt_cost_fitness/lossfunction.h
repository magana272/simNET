#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "../math/mymath.h"
#include <math.h>
float CrossEntropyLoss(int true_label[], mat* prediction, int BatchSize);
float dCrossEntropyz(float z);