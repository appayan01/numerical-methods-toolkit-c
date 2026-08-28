#include <stdio.h>

#include "bisection.h"
#include "newton.h"
#include "secant.h"
#include "regula_falsi.h"

double function(double x)
{
    return x * x * x - x - 2;
}

double derivative(double x)
{
    return 3.0 * x * x - 1.0;
}

const char *status_message(Status status)
{
    switch (status)
    {
        case SUCCESS:
            return "Success";

        case MAX_ITERATIONS:
            return "Maximum iterations reached";

        case INVALID_INTERVAL:
            return "Invalid interval";

        case ZERO_DERIVATIVE:
            return "Zero derivative";

        case ZERO_DENOMINATOR:
            return "Zero denominator";

        default:
            return "Unknown status";
    }
}

int main(void)
{
    double a = 1.0;
    double b = 2.0;

    double x0 = 1.5;
    double x1 = 2.0;

    double tolerance = 0.000001;
    int max_iterations = 100;

    Result bisection_result;
    Result newton_result;
    Result secant_result;
    Result regula_result;

    bisection_result =
        bisection(function, a, b, tolerance, max_iterations);

    newton_result =
    newton_raphson(function, derivative, x0, tolerance, 100);

    secant_result =
        secant(function, x0, x1, tolerance);

    regula_result =
        regula_falsi(function, a, b, tolerance);

    printf("Numerical Methods Toolkit\n");
    printf("=========================\n");

    printf("\nBisection Method\n");
    printf("----------------\n");
    printf("Root: %.10f\n", bisection_result.root);
    printf("Iterations: %d\n", bisection_result.iterations);
    printf("Final error: %.10f\n", bisection_result.error);
    printf("Status: %s\n", status_message(bisection_result.status));

    printf("\nNewton-Raphson Method\n");
    printf("---------------------\n");
    printf("Root: %.10f\n", newton_result.root);
    printf("Iterations: %d\n", newton_result.iterations);
    printf("Final error: %.10f\n", newton_result.error);
    printf("Status: %s\n", status_message(newton_result.status));

    printf("\nSecant Method\n");
    printf("-------------\n");
    printf("Root: %.10f\n", secant_result.root);
    printf("Iterations: %d\n", secant_result.iterations);
    printf("Final error: %.10f\n", secant_result.error);
    printf("Status: %s\n", status_message(secant_result.status));

    printf("\nRegula Falsi Method\n");
    printf("-------------------\n");
    printf("Root: %.10f\n", regula_result.root);
    printf("Iterations: %d\n", regula_result.iterations);
    printf("Final error: %.10f\n", regula_result.error);
    printf("Status: %s\n", status_message(regula_result.status));

    return 0;
}
