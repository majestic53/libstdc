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

#include "../include/errno.h"
#include "../include/math.h"

enum {
	FP_FINITE = 0,
	FP_INFINITE,
	FP_NAN,
};

int detect_fp_inf(
	__in double x
	)
{
	return ((x >= HUGE_VAL) || (x <= -HUGE_VAL));
}

int detect_fp_nan(
	__in double x
	)
{
	volatile double x0 = x;
	return (x0 != x0);
}

int validate_fp(
	__in double x,
	__in int inf,
	__in int nan
	)
{
	int result = FP_FINITE;

	if(inf && detect_fp_inf(x)) {
		result = FP_INFINITE;
	}

	if(nan && detect_fp_nan(x)) {
		result = FP_NAN;
	}

	return result;
}

double 
acos(
	__in double x
	)
{
	// TODO
	return 0.0;
}

double 
asin(
	__in double x
	)
{
	// TODO
	return 0.0;
}

double 
atan(
	__in double x
	)
{
	// TODO
	return 0.0;
}

double 
atan2(
	__in double y,
	__in double x
	)
{
	// TODO
	return 0.0;
}

double 
ceil(
	__in double x
	)
{
	double inter = floor(x);
	return ((x - inter) > 0.0) ? (inter + 1.0) : x;
}

double 
cos(
	__in double x
	)
{
	// TODO
	return 0.0;
}

double 
cosh(
	__in double x
	)
{
	// TODO
	return 0.0;
}

double 
exp(
	__in double x
	)
{
	// TODO
	return 0.0;
}

double 
fabs(
	__in double x
	)
{
	// TODO
	return 0.0;
}

double 
floor(
	__in double x
	)
{
	return ((long) x);
}

double 
fmod(
	__in double numer,
	__in double denom
	)
{
	// TODO
	return 0.0;
}

double 
frexp(
	__in double x, 
	__inout int *exp
	)
{
	// TODO
	return 0.0;
}

double 
ldexp(
	__in double sig,
	__in int exp
	)
{
	// TODO
	return 0.0;
}

double 
log(
	__in double x
	)
{
	// TODO
	return 0.0;
}

double 
log10(
	__in double x
	)
{
	// TODO
	return 0.0;
}

double 
modf(
	__in double x,
	__inout double *ipart
	)
{
	double result = x;

	if(ipart) {
		*ipart = ((long) x);
		result -= *ipart;
	} else {
		errno = EINVAL;
	}

	return result;
}

double 
pow(
	__in double base,
	__in double exp
	)
{
	double result = 1.0;

	while(exp) {
		result *= base;
		--exp;
	}

	return result;
}

double 
sin(
	__in double x
	)
{
	// TODO
	return 0.0;
}

double 
sinh(
	__in double x
	)
{
	// TODO
	return 0.0;
}

double 
sqrt(
	__in double x
	)
{
	// TODO
	return 0.0;
}

double 
tan(
	__in double x
	)
{
	// TODO
	return 0.0;
}

double 
tanh(
	__in double x
	)
{
	// TODO
	return 0.0;
}
