#include <stdio.h>
#include "bisection.h"
#include "newton.h"

double function(double x)
{
    return x * x * x - x - 2;
}

double derivative(double x)
{
    return 3.0 * x * x - 1.0;
}

int main(void)
{
    double a = 1.0;
    double b = 2.0;
    double x0 = 1.5;
    double tolerance = 0.000001;

    Result bisection_result;
    Result newton_result;

    bisection_result = bisection(function, a, b, tolerance);

    newton_result = newton_raphson(function, derivative, x0, tolerance);

    printf("Numerical Methods Toolkit\n");
    printf("=========================\n");

    printf("\nBisection Method\n");
    printf("----------------\n");
    printf("Root: %.10f\n", bisection_result.root);
    printf("Iterations: %d\n", bisection_result.iterations);
    printf("Final error: %.10f\n", bisection_result.error);

    printf("\nNewton-Raphson Method\n");
    printf("---------------------\n");
    printf("Root: %.10f\n", newton_result.root);
    printf("Iterations: %d\n", newton_result.iterations);
    printf("Final error: %.10f\n", newton_result.error);

    return 0;
}
