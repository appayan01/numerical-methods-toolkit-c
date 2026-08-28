#include "bisection.h"

double bisection(Function f, double a, double b, double tolerance)
{
    double c;

    while ((b - a) >= tolerance)
    {
        c = (a + b) / 2.0;

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
    }

    return (a + b) / 2.0;
}
