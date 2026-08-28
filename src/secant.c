#include "secant.h"

Result secant(Function f, double x0, double x1, double tolerance)
{
    Result result;
    double x2;
    double error;
    int iteration = 0;

    do
    {
        x2 = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0));

        error = x2 - x1;

        x0 = x1;
        x1 = x2;

        iteration++;

    } while ((error < -tolerance || error > tolerance)
             && iteration < 100);

    result.root = x1;
    result.iterations = iteration;
    result.error = error < 0 ? -error : error;

    return result;
}
