#include <stdio.h>
#include "bisection.h"

double function(double x)
{
    return x * x * x - x - 2;
}

int main(void)
{
    double a = 1.0;
    double b = 2.0;
    double tolerance = 0.000001;

    Result result = bisection(function, a, b, tolerance);

    printf("Numerical Methods Toolkit\n");
    printf("-------------------------\n");
    printf("Method: Bisection\n");
    printf("Function: x^3 - x - 2\n");
    printf("Interval: [%.1f, %.1f]\n", a, b);
    printf("Tolerance: %.6f\n", tolerance);

    printf("\nResults\n");
    printf("Root: %.10f\n", result.root);
    printf("Iterations: %d\n", result.iterations);
    printf("Final error: %.10f\n", result.error);

    return 0;
}
