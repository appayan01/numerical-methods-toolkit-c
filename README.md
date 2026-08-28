# Numerical Methods Toolkit in C

A modular C implementation of classical numerical root-finding methods.

## Overview

This project implements several classical numerical methods for finding
roots of nonlinear equations. The methods are implemented as independent
C modules with a common numerical result structure.

Currently implemented:

- Bisection Method
- Newton-Raphson Method
- Secant Method
- Regula Falsi Method

The project also includes a Makefile for compilation and a GitHub Actions
workflow for automated build verification.

## Example Problem

The toolkit is demonstrated on the nonlinear equation:

f(x) = x^3 - x - 2

using an initial interval of [1, 2] and a tolerance of 10^-6.

All four methods converge to approximately:

x ≈ 1.5213797068

## Results

| Method | Approximate Root | Iterations |
|---|---:|---:|
| Bisection | 1.5213799477 | 20 |
| Newton-Raphson | 1.5213797068 | 3 |
| Secant | 1.5213797068 | 5 |
| Regula Falsi | 1.5213794618 | 12 |

The iteration counts depend on the starting values and stopping criterion.

## Project Structure

```text
numerical-methods-toolkit-c/
│
├── .github/
│   └── workflows/
│       └── build.yml
│
├── include/
│   ├── bisection.h
│   ├── newton.h
│   ├── regula_falsi.h
│   ├── result.h
│   └── secant.h
│
├── src/
│   ├── bisection.c
│   ├── main.c
│   ├── newton.c
│   ├── regula_falsi.c
│   └── secant.c
│
├── .gitignore
├── Makefile
└── README.md
