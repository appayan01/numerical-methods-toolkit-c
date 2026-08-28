#include "bisection.h"

Result bisection(Function f, double a, double b,
                  double tolerance, int max_iterations)
{
    Result result;
    double c;
    double error;
    int iteration = 0;

    if (f(a) * f(b) > 0)
    {
        result.root = 0.0;
        result.iterations = 0;
        result.error = 0.0;
        result.status = INVALID_INTERVAL;
        return result;
    }

    while (iteration < max_iterations)
    {
        c = (a + b) / 2.0;
        error = (b - a) / 2.0;
        iteration++;

        if (f(c) == 0.0 || error < tolerance)
        {
            result.root = c;
            result.iterations = iteration;
            result.error = error;
            result.status = SUCCESS;
            return result;
        }

        if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;
    }

    result.root = (a + b) / 2.0;
    result.iterations = iteration;
    result.error = (b - a) / 2.0;
    result.status = MAX_ITERATIONS;

    return result;
}
