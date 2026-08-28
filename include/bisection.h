#ifndef BISECTION_H
#define BISECTION_H

#include "result.h"

typedef double (*Function)(double);

Result bisection(Function f, double a, double b, double tolerance);

#endif
