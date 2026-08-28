#include "newton.h"

Result newton_raphson(Function f, Function df,
                      double x0, double tolerance)
{
    Result result;

    double x = x0;
    double x_new;
    double error;
    int iteration = 0;

    while (iteration < 100)
    {
        if (df(x) == 0.0)
        {
            result.root = x;
            result.iterations = iteration;
            result.error = 0.0;
            result.status = ZERO_DERIVATIVE;
            return result;
        }

        x_new = x - f(x) / df(x);
        error = x_new - x;

        if (error < 0)
            error = -error;

        iteration++;

        if (error < tolerance)
        {
            result.root = x_new;
            result.iterations = iteration;
            result.error = error;
            result.status = SUCCESS;
            return result;
        }

        x = x_new;
    }

    result.root = x;
    result.iterations = iteration;
    result.error = error;
    result.status = MAX_ITERATIONS;

    return result;
}
