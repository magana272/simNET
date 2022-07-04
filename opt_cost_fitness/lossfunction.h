#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "../math/mymath.h"
#include <math.h>
double CrossEntropyLoss(int true_label[], mat* prediction, int BatchSize);
double dCrossEntropyz(double z);