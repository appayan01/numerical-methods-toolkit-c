#ifndef REGULA_FALSI_H
#define REGULA_FALSI_H

#include "result.h"

typedef double (*Function)(double);

Result regula_falsi(Function f, double a, double b, double tolerance);

#endif
