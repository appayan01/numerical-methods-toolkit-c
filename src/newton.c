#include "newton.h"
#include <math.h>

Result newton_raphson(Function f, Function df,
                      double x0, double tolerance)
{
    Result result;

    double x = x0;
    double x_new;
    double error = 0.0;

    int iteration = 0;

    const double derivative_tolerance = 1e-12;

    while (iteration < 100)
    {
        double derivative_value = df(x);

        if (fabs(derivative_value) < derivative_tolerance)
        {
            result.root = x;
            result.iterations = iteration;
            result.error = 0.0;
            result.status = ZERO_DERIVATIVE;

            return result;
        }

        x_new = x - f(x) / derivative_value;

        error = fabs(x_new - x);

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
