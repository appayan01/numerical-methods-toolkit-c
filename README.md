# Numerical Methods Toolkit in C

A modular C implementation of classical numerical root-finding methods.

## Overview

This project implements several classical numerical methods for finding
roots of nonlinear equations. Each method is implemented as an independent
C module with a common numerical result structure.

### Implemented Methods

- Bisection Method
- Newton-Raphson Method
- Secant Method
- Regula Falsi Method

The toolkit includes:

- Modular C interfaces and implementations
- Convergence and error reporting
- Invalid-input handling
- Iteration-limit detection
- Automated numerical tests
- Makefile-based build and test system
- GitHub Actions continuous integration

## Example Problem

The toolkit is demonstrated on the nonlinear equation

f(x) = x³ - x - 2

using an initial interval [1, 2] and a tolerance of 10⁻⁶.

The methods converge to approximately:

x ≈ 1.5213797068

### Example Results

| Method | Approximate Root |
|---|---:|
| Bisection | 1.521379... |
| Newton-Raphson | 1.521379... |
| Secant | 1.521379... |
| Regula Falsi | 1.521379... |

The exact iteration count depends on the method, starting values,
tolerance and stopping criterion.

## Building

Compile the project using:

```bash
make
