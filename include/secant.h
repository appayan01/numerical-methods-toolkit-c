#ifndef SECANT_H
#define SECANT_H

#include "result.h"

typedef double (*Function)(double);

Result secant(Function f, double x0, double x1, double tolerance);

#endif
