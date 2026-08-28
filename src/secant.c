#include "secant.h"

Result secant(Function f, double x0, double x1,
              double tolerance)
{
    Result result;

    double x2 = x1;
    double error = 0.0;
    int iteration = 0;

    while (iteration < 100)
    {
        double denominator = f(x1) - f(x0);

        if (denominator == 0.0)
        {
            result.root = x1;
            result.iterations = iteration;
            result.error = error;
            result.status = ZERO_DENOMINATOR;
            return result;
        }

        x2 = x1 - f(x1) * (x1 - x0) / denominator;

        error = x2 - x1;

        if (error < 0)
            error = -error;

        iteration++;

        if (error < tolerance)
        {
            result.root = x2;
            result.iterations = iteration;
            result.error = error;
            result.status = SUCCESS;
            return result;
        }

        x0 = x1;
        x1 = x2;
    }

    result.root = x2;
    result.iterations = iteration;
    result.error = error;
    result.status = MAX_ITERATIONS;

    return result;
}
