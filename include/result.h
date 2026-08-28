#ifndef RESULT_H
#define RESULT_H

typedef enum
{
    SUCCESS,
    MAX_ITERATIONS,
    INVALID_INTERVAL,
    ZERO_DERIVATIVE,
    ZERO_DENOMINATOR
} Status;

typedef struct
{
    double root;
    int iterations;
    double error;
    Status status;
} Result;

#endif
