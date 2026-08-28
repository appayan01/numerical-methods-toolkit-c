#include "newton.h"

Result newton_raphson(Function f, Function df, double x0, double tolerance)
{
    Result result;
    double x = x0;
    double x_new;
    double error = 0.0;
    int iteration = 0;

    do
    {
        x_new = x - f(x) / df(x);
        error = x_new - x;
        x = x_new;
        iteration++;

    } while ((error < -tolerance || error > tolerance) && iteration < 100);

    result.root = x;
    result.iterations = iteration;
    result.error = error < 0 ? -error : error;

    return result;
}
