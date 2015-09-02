/**
 * libstdc
 * Copyright (C) 2015 David Jolly
 * ----------------------
 *
 * libstdc is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * libstdc is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef MATH_H_
#define MATH_H_

#include "libdef.h"
#include "float.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

// huge value definition
#define HUGE_VAL DBL_MAX

// infinity definition
#define INFINITY HUGE_VAL

// e constant definition
#define M_E 2.7182818284590452354

// pi constant definition
#define M_PI 3.14159265358979323846
#define M_2_PI (2.0 * M_PI)
#define M_PI_2 (M_PI / 2.0)

// not-a-number definition
#define NAN (0.0 / 0.0)

/*
 * Compute arc-cosine of input
 * @param x input value
 * @return computed value
 */
double acos(
	__in double x
	);

/*
 * Compute arc-sine of input
 * @param x input value
 * @return computed value
 */
double asin(
	__in double x
	);

/*
 * Compute arc-tangent of input
 * @param x input value
 * @return computed value
 */
double atan(
	__in double x
	);

/*
 * Compute arc-tangent of two inputs (y/x)
 * @param y input value
 * @param x input value
 * @return computed value
 */
double atan2(
	__in double y,
	__in double x
	);

/*
 * Compute ceiling of input
 * @param x input value
 * @return computed value
 */
double ceil(
	__in double x
	);

/*
 * Compute cosine of input
 * @param x input value
 * @return computed value
 */
double cos(
	__in double x
	);

/*
 * Compute hyperbolic cosine of input
 * @param x input value
 * @return computed value
 */
double cosh(
	__in double x
	);

/*
 * Compute the base-e exponential function of input
 * @param x input value
 * @return computed value
 */
double exp(
	__in double x
	);

/*
 * Compute absolute value of input
 * @param x input value
 * @return computed value
 */
double fabs(
	__in double x
	);

/* 
 * Compute floor of input
 * @param x input value
 * @return computed value
 */
double floor(
	__in double x
	);

/*
 * Compute remainder of input (numer/denom)
 * 	[fmod(numer, denom)] = numer - quot * denom
 * @param numer numerator value
 * @param denom denominator value
 * @return computed value
 */
double fmod(
	__in double numer,
	__in double denom
	);

/*
 * Compute base-2 significand and exponent of value
 * 	x = [sig] * 2 ^ exp
 * @param x input value
 * @param exp computed exponent value
 * @return computed significand
 */
double frexp(
	__in double x, 
	__inout int *exp
	);

/*
 * Compute result of base-2 significand and exponent
 * 	[ldexp(sig, exp)] = sig * 2 ^ exp
 * @param sig significand value
 * @param exp exponent value
 * @return computed value
 */
double ldexp(
	__in double sig,
	__in int exp
	);

/*
 * Compute the base-e (natural) logarithm of value
 * @param x input value
 * @return computed value
 */
double log(
	__in double x
	);

/*
 * Compute the base-10 logarithm of value
 * @param x input value
 * @return computed value
 */
double log10(
	__in double x
	);

/*
 * Decompose input into integer and fractional parts
 * @param x input value
 * @param ipart output integer part
 * @return output fractional part
 */
double modf(
	__in double x,
	__inout double *ipart
	);

/*
 * Raise base to power exponent
 * @param base base value
 * @param exp exponent value
 * @return computed value
 */
double pow(
	__in double base,
	__in double exp
	);

/*
 * Compute sine of input
 * @param x input value
 * @return computed value
 */
double sin(
	__in double x
	);

/*
 * Compute hyperbolic sine of input
 * @param x input value
 * @return computed value
 */
double sinh(
	__in double x
	);

/*
 * Compute square root input
 * @param x input value
 * @return computed value
 */
double sqrt(
	__in double x
	);

/*
 * Compute tangent of input
 * @param x input value
 * @return computed value
 */
double tan(
	__in double x
	);

/*
 * Compute hyperbolic tangent of input
 * @param x input value
 * @return computed value
 */
double tanh(
	__in double x
	);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // MATH_H_
