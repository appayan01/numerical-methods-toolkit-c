#ifndef NEWTON_H
#define NEWTON_H

#include "result.h"

typedef double (*Function)(double);

Result newton_raphson(Function f, Function df, double x0,
                     double tolerance, int max_iterations);

#endif
