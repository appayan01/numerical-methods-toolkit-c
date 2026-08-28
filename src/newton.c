#include <math.h>
#include "newton.h"

Result newton_raphson(Function f, Function df, double x0,
                      double tolerance, int max_iterations)
{
    Result result;
    double x = x0;

    result.root = x;
    result.iterations = 0;
    result.error = fabs(f(x));
    result.status = MAX_ITERATIONS;

    for (int i = 0; i < max_iterations; i++)
    {
        double derivative = df(x);

        if (fabs(derivative) < 1e-14)
        {
            result.root = x;
            result.iterations = i;
            result.error = fabs(f(x));
            result.status = ZERO_DERIVATIVE;
            return result;
        }

        double x_new = x - f(x) / derivative;
        double error = fabs(x_new - x);

        result.root = x_new;
        result.iterations = i + 1;
        result.error = error;

        if (error < tolerance)
        {
            result.status = SUCCESS;
            return result;
        }

        x = x_new;
    }

    result.root = x;
    result.error = fabs(f(x));
    result.status = MAX_ITERATIONS;

    return result;
}
