#ifndef BISECTION_H
#define BISECTION_H

typedef double (*Function)(double);

double bisection(Function f, double a, double b, double tolerance);

#endif
