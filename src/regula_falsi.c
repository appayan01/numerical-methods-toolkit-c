#include "regula_falsi.h"

Result regula_falsi(Function f, double a, double b, double tolerance)
{
    Result result;
    double c = a;
    double previous_c = a;
    double error = 0.0;
    int iteration = 0;

    do
    {
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));

        error = c - previous_c;
        previous_c = c;

        if (f(c) == 0.0)
        {
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

        iteration++;

    } while ((error < -tolerance || error > tolerance)
             && iteration < 100);

    result.root = c;
    result.iterations = iteration;
    result.error = error < 0 ? -error : error;

    return result;
}
