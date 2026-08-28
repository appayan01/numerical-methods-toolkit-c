#include "bisection.h"

Result bisection(Function f, double a, double b, double tolerance)
{
    Result result;
    double c;
    int iteration = 0;

    while ((b - a) >= tolerance)
    {
        c = (a + b) / 2.0;
        iteration++;

        if (f(c) == 0.0)
        {
            a = c;
            b = c;
            break;
        }
        else if (f(a) * f(c) < 0)
        {
            b = c;
        }
        else
        {
            a = c;
        }
    }

    result.root = (a + b) / 2.0;
    result.iterations = iteration;
    result.error = (b - a) / 2.0;

    return result;
}
