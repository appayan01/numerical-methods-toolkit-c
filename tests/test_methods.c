#include <stdio.h>
#include <math.h>

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

int passed = 0;
int failed = 0;

void check(const char *test_name, int condition)
{
    if (condition)
    {
        printf("[PASS] %s\n", test_name);
        passed++;
    }
    else
    {
        printf("[FAIL] %s\n", test_name);
        failed++;
    }
}

int main(void)
{
    Result result;

    printf("Numerical Methods Toolkit - Tests\n");
    printf("=================================\n\n");

    /* Bisection: successful convergence */
    result = bisection(function, 1.0, 2.0, 0.000001, 100);

    check("Bisection converges",
          result.status == SUCCESS &&
          fabs(result.root - 1.5213797068) < 0.00001);

    /* Bisection: invalid interval */
    result = bisection(function, 0.0, 1.0, 0.000001, 100);

    check("Bisection detects invalid interval",
          result.status == INVALID_INTERVAL);

    /* Bisection: maximum iterations */
    result = bisection(function, 1.0, 2.0, 0.000000000001, 1);

    check("Bisection detects maximum iterations",
          result.status == MAX_ITERATIONS);

    /* Newton-Raphson: successful convergence */
    result = newton_raphson(function, derivative, 1.5, 0.000001);

    check("Newton-Raphson converges",
          result.status == SUCCESS &&
          fabs(result.root - 1.5213797068) < 0.00001);

    /* Newton-Raphson: zero derivative */
    result = newton_raphson(function, derivative,
                             sqrt(1.0 / 3.0), 0.000001);

    check("Newton-Raphson detects zero derivative",
          result.status == ZERO_DERIVATIVE);

    /* Secant: successful convergence */
    result = secant(function, 1.5, 2.0, 0.000001);

    check("Secant converges",
          result.status == SUCCESS &&
          fabs(result.root - 1.5213797068) < 0.00001);

    /* Secant: zero denominator */
    result = secant(function, 1.0, 1.0, 0.000001);

    check("Secant detects zero denominator",
          result.status == ZERO_DENOMINATOR);

    /* Regula Falsi: successful convergence */
    result = regula_falsi(function, 1.0, 2.0, 0.000001);

    check("Regula Falsi converges",
          result.status == SUCCESS &&
          fabs(result.root - 1.5213797068) < 0.00001);

    /* Regula Falsi: invalid interval */
    result = regula_falsi(function, 0.0, 1.0, 0.000001);

    check("Regula Falsi detects invalid interval",
          result.status == INVALID_INTERVAL);

    printf("\n=================================\n");
    printf("Tests passed: %d\n", passed);
    printf("Tests failed: %d\n", failed);

    if (failed == 0)
    {
        printf("All tests passed.\n");
        return 0;
    }

    printf("Some tests failed.\n");
    return 1;
}
