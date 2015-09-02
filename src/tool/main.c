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

#include "../lib/include/libdef.h"
#include "../lib/include/assert.h"
#include "../lib/include/ctype.h"
#include "../lib/include/errdef.h"
#include "../lib/include/errno.h"
#include "../lib/include/float.h"
#include "../lib/include/iso646.h"
#include "../lib/include/libdef.h"
#include "../lib/include/limits.h"
#include "../lib/include/locale.h"
#include "../lib/include/locdef.h"
#include "../lib/include/math.h"
#include "../lib/include/setjmp.h"
#include "../lib/include/signal.h"
#include "../lib/include/stdbool.h"
#include "../lib/include/stdarg.h"
#include "../lib/include/stddef.h"
#include "../lib/include/stdint.h"
#include "../lib/include/stdio.h"
#include "../lib/include/stdlib.h"
#include "../lib/include/string.h"
#include "../lib/include/time.h"

#include "../lib/include/libdef.h"

#include <stdio.h>

/*
 * Error bound definition
 * 	used by a variety of routines to control precision
 */
#ifndef ERR_BOUND
#define ERR_BOUND 0.000000000000001
#endif // ERR_BOUND

// math routine internal constants
#define FACT_DOM_MIN 0.0
#define LOG_10 10.0
#define LOG_DOM_MIN 1.0
#define SQRT_DOM_MIN 0.0

// floating-point class flags
#define FP_FIN 0x1
#define FP_INF 0x2
#define FP_NAN 0x4

double 
(_fmod) (
	__in double numer,
	__in double denom
	);

double 
(_pow) (
	__in double base,
	__in double exp
	);

int 
_fp_inf(
	__in double x
	)
{

	// infinite floating-point values are defined as either HUGE_VAL or -HUGE_VAL
	return ((x >= HUGE_VAL) || (x <= -HUGE_VAL));
}

int 
_fp_nan(
	__in double x
	)
{
	volatile double x0 = x;
	return (x0 != x0);
}

int 
_fp_valid(
	__in double x,
	__in int flag
	)
{
	int result = FP_FIN;

	// detect infinite floating-point values
	if((flag & FP_INF) && _fp_inf(x)) {
		result = FP_INF;
	}

	// detect NaN floating-point values
	if((flag & FP_NAN) && _fp_nan(x)) {
		result = FP_NAN;
	}

	return result;
}

double 
_fact(
	__in double x
	)
{
	int valid;
	double iter, result = x;

	/*
	 * Initial factorials (0 - 30),
	 * 	fact(31) and beyond must be calculated at runtime
	 */
	static const double fact_val[_FACT_TBL_MAX + 1] = {
		1.0, 1.0, 2.0, 6.0, 24.0, 120.0, 720.0, 5040.0, 40320.0, 
		362880.0, 3628800.0, 39916800.0, 479001600.0, 6227020800.0, 
		87178291200.0, 1307674368000.0, 20922789888000.0, 355687428096000.0, 
		6402373705728000.0, 121645100408832000.0, 2432902008176640000.0, 
		51090942171709440000.0, 1124000727777607680000.0, 25852016738884978212864.0, 
		620448401733239409999872.0, 15511210043330986055303168.0, 
		403291461126605650322784256.0, 10888869450418351940239884288.0, 
		304888344611713836734530715648.0, 8841761993739700772720181510144.0, 
		265252859812191032188804700045312.0,
		};

	valid = _fp_valid(result, FP_INF | FP_NAN);
	switch(valid) {
		case FP_INF:

			if(result < FACT_DOM_MIN) {
				errno = EDOM;
				result = NAN;
			} else {
				errno = ERANGE;
				result = INFINITY;
			}
			goto exit;
		case FP_NAN:
			errno = EDOM;
			goto exit;
	}

	if(result < FACT_DOM_MIN) {
		errno = EDOM;
		result = NAN;
	} else if(result <= _FACT_TBL_MAX) {

		// lookup fact(0 - 30)
		result = fact_val[(long) x];
	} else {
		result = fact_val[_FACT_TBL_MAX];

		// calculate fact(31) and beyond
		for(iter = (_FACT_TBL_MAX + 1); iter <= x; ++iter) {
			result *= iter;
		}

		// check for valid result
		valid = _fp_valid(result, FP_INF | FP_NAN);
		switch(valid) {
			case FP_INF:

				if(result < FACT_DOM_MIN) {
					errno = EDOM;
					result = NAN;
				} else {
					errno = ERANGE;
					result = INFINITY;
				}
				goto exit;
			case FP_NAN:
				errno = EDOM;
				goto exit;
		}
	}

exit:
	return result;
}

double 
(_ceil) (
	__in double x
	)
{

	// ceil(x) = x - frac(x), unless frac(x) == 0
	return ((x - ((long) x)) > 0.0) ? (((long) x) + 1.0) : x;
}

double 
(_floor) (
	__in double x
	)
{

	// floor(x) = int(x)
	return ((long) x);
}

double 
(_fmod) (
	__in double numer,
	__in double denom
	)
{
	int valid;
	double result;

	// check for valid numerator
	valid = _fp_valid(numer, FP_INF | FP_NAN);
	switch(valid) {
		case FP_INF:
			errno = ERANGE;
			result = ((numer < 0.0) ? -INFINITY : INFINITY);
			goto exit;
		case FP_NAN:
			errno = EDOM;
			result = NAN;
			goto exit;
	}

	// check for valid denominator
	valid = _fp_valid(denom, FP_INF | FP_NAN);
	switch(valid) {
		case FP_INF:
			errno = ERANGE;
			result = 0.0;
			goto exit;
		case FP_NAN:
			errno = EDOM;
			result = NAN;
			goto exit;
	}

	result = (numer / denom);

	// perform round towards zero
	if(result < 0.0) {
		result = _ceil(result);
	} else {
		result = _floor(result);
	}

	/*
	 * Calculate fmod(x, y) = x - (round(x / y) * y)
	 * 	where round is towards zero
	 */
	result = (numer - (result * denom));

	// check for valid result
	valid = _fp_valid(result, FP_INF | FP_NAN);
	switch(valid) {
		case FP_INF:
			errno = ERANGE;
			result = ((result < 0.0) ? -INFINITY : INFINITY);
			goto exit;
		case FP_NAN:
			errno = EDOM;
			result = NAN;
			goto exit;
	}

exit:
	return result;
}

double 
(_pow) (
	__in double base,
	__in double exp
	)
{
	int valid;
	double result = 1.0;

	// check if base is valid
	valid = _fp_valid(base, FP_INF | FP_NAN);
	switch(valid) {
		case FP_INF:
			errno = ERANGE;
			result = ((base < 0.0) ? -INFINITY : INFINITY);
			goto exit;
		case FP_NAN:
			errno = EDOM;
			result = NAN;
			goto exit;
	}

	// check if exp is valid
	valid = _fp_valid(exp, FP_INF | FP_NAN);
	switch(valid) {
		case FP_INF:
			errno = ERANGE;
			result = ((exp < 0.0) ? -INFINITY : INFINITY);
			goto exit;
		case FP_NAN:
			errno = EDOM;
			result = NAN;
			goto exit;
	}

	while(exp) {

		/*
		 * Calculate pow(b, e) = prod(b),
		 * 	where i = e
		 */
		result *= base;

		valid = _fp_valid(result, FP_INF | FP_NAN);
		switch(valid) {
			case FP_INF:
				errno = ERANGE;
				result = ((result < 0.0) ? -INFINITY : INFINITY);
				goto exit;
			case FP_NAN:
				errno = EDOM;
				result = NAN;
				goto exit;
		}

		--exp;
	}

exit:
	return result;
}

double 
(_atan) (
	__in double x
	)
{
	int valid;
	double denom, iter = 0.0, next, numer, result = 0.0;

	valid = _fp_valid(x, FP_INF | FP_NAN);
	switch(valid) {
		case FP_INF:
			errno = ERANGE;
			result = ((x < 0.0) ? -INFINITY : INFINITY);
			goto exit;
		case FP_NAN:
			errno = EDOM;
			result = NAN;
			goto exit;
	}

	// no work if x == 0.0
	if((x < 0.0) || (x > 0.0)) {

		/*
		 * Calculating arctan(x) = sum((((-1) ^ n) * (x ^ (2n + 1))) / (2n + 1)),
		 * 	where -INF < x < INF && x != NaN && 0.0 <= n <= M
		 */
		for(;; ++iter) {
			errno = 0;
			numer = _pow(-1.0, iter);

			switch(errno) {
				case EDOM:
				case ERANGE:
					goto exit;
			}

			errno = 0;
			denom = ((2.0 * iter) + 1.0);
			numer *= _pow(x, denom);

			switch(errno) {
				case EDOM:
				case ERANGE:
					goto exit;
			}

			next = (numer / denom);
			result += next;

			// check if error bound has been reached
			if((next < ERR_BOUND) && (next > -ERR_BOUND)) {
				break;
			}
		}

		// check for valid result
		valid = _fp_valid(result, FP_INF | FP_NAN);
		switch(valid) {
			case FP_INF:
				errno = ERANGE;
				result = ((result < 0.0) ? -INFINITY : INFINITY);
				goto exit;
			case FP_NAN:
				errno = EDOM;
				result = NAN;
				goto exit;
		}
	}

exit:
	return result;
}

#define VAL 1.23

int 
main(void)
{
	int result = 0;
	double val0, val1;

	errno = 0;	
	val0 = _atan(VAL);

	switch(errno) {
		case EDOM:
			printf("NaN(val0)\n");
			break;
		case ERANGE:
			printf("INF(val0)\n");
			break;
	}

	errno = 0;
	val1 = atan(VAL);
	
	switch(errno) {
		case EDOM:
			printf("NaN(val1)\n");
			break;
		case ERANGE:
			printf("INF(val1)\n");
			break;
	}

	printf("%f, %f\n", val0, val1);

	return result;
}
