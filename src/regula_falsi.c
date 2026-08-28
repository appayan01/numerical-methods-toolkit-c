#include "regula_falsi.h"

Result regula_falsi(Function f, double a, double b,
                    double tolerance)
{
    Result result;

    double c = a;
    double previous_c = a;
    double error = 0.0;
    int iteration = 0;

    if (f(a) * f(b) > 0.0)
    {
        result.root = 0.0;
        result.iterations = 0;
        result.error = 0.0;
        result.status = INVALID_INTERVAL;
        return result;
    }

    while (iteration < 100)
    {
        double denominator = f(b) - f(a);

        if (denominator == 0.0)
        {
            result.root = c;
            result.iterations = iteration;
            result.error = error;
            result.status = ZERO_DENOMINATOR;
            return result;
        }

        c = (a * f(b) - b * f(a)) / denominator;

        error = c - previous_c;

        if (error < 0.0)
            error = -error;

        iteration++;

        if (f(c) == 0.0 || error < tolerance)
        {
            result.root = c;
            result.iterations = iteration;
            result.error = error;
            result.status = SUCCESS;
            return result;
        }

        if (f(a) * f(c) < 0.0)
            b = c;
        else
            a = c;

        previous_c = c;
    }

    result.root = c;
    result.iterations = iteration;
    result.error = error;
    result.status = MAX_ITERATIONS;

    return result;
}
