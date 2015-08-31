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

#define EXP_ERR 0.00000001
#define FACT_DOM_MIN 0.0
#define FP_FIN 0x1
#define FP_INF 0x2
#define FP_NAN 0x4
#define LOG_10 10.0
#define LOG_DOM_MIN 1.0
#define LOG_ERR 0.00000001
#define SQRT_DOM_MIN 0.0
#define SQRT_ERR 0.0001

int 
_fp_inf(
	__in double x
	)
{
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

	if((flag & FP_INF) && _fp_inf(x)) {
		result = FP_INF;
	}

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
			break;
		case FP_NAN:
			errno = EDOM;
			break;
		default:

			if(result < FACT_DOM_MIN) {
				errno = EDOM;
				result = NAN;
			} else if(result <= _FACT_TBL_MAX) {
				result = fact_val[(long) x];
			} else {
				result = fact_val[_FACT_TBL_MAX];

				for(iter = (_FACT_TBL_MAX + 1); iter <= x; ++iter) {
					result *= iter;
				}
			}
			break;
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
	return ((x - ((long) x)) > 0.0) ? (((long) x) + 1.0) : x;
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
	int valid;
	double denom, iter = 2.0, next, numer, prev, result = x;

	valid = _fp_valid(result, FP_INF | FP_NAN);
	switch(valid) {
		case FP_INF:
			errno = ERANGE;
			result = ((result < 0.0) ? -INFINITY : INFINITY);
			break;
		case FP_NAN:
			errno = EDOM;
			break;
		default:

			if(result == 0.0) {
				result = 1.0;
			} else {
				result += 1.0;
				next = result;

				for(;; ++iter) {
					prev = next;
					errno = 0;
					numer = pow(x, iter);

					switch(errno) {
						case EDOM:
						case ERANGE:
							goto exit;
					}

					errno = 0;
					denom = _fact(iter);

					switch(errno) {
						case EDOM:
						case ERANGE:
							goto exit;
					}

					next = (numer / denom);
					result += next;

					if(next < EXP_ERR) {
						break;
					}
				}
			}
			break;
	}

exit:
	return result;
}

double 
fabs(
	__in double x
	)
{
	double result = x;
	int valid = _fp_valid(result, FP_INF | FP_NAN);

	switch(valid) {
		case FP_INF:
			errno = ERANGE;
			result = INFINITY;
			break;
		case FP_NAN:
			errno = EDOM;
			break;
		default:
			result = ((result < 0.0) ? (-result) : result);
			break;
	}

	return result;
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
	int valid;
	double iter = 2.0, next, prev, result = x;

	valid = _fp_valid(result, FP_INF | FP_NAN);
	switch(valid) {
		case FP_INF:

			if(result < LOG_DOM_MIN) {
				errno = EDOM;
				result = NAN;
			} else {
				errno = ERANGE;
				result = INFINITY;
			}
			break;
		case FP_NAN:
			errno = EDOM;
			break;
		default:

			if(result == LOG_DOM_MIN) {
				result = 0.0;
			} else if(result < LOG_DOM_MIN) {
				errno = EDOM;
				result = NAN;
			} else {
				result = ((x - LOG_DOM_MIN) / x);
				next = result;

				for(;; ++iter) {
					prev = next;
					errno = 0;
					next = (pow(((x - LOG_DOM_MIN) / x), iter) / iter);

					switch(errno) {
						case EDOM:
						case ERANGE:
							goto exit;
					}

					result += next;

					errno = 0;
					if(fabs(prev - next) < LOG_ERR) {
						break;
					}

					switch(errno) {
						case EDOM:
						case ERANGE:
							goto exit;
					}
				}
			}
			break;
	}

exit:
	return result;
}

double 
log10(
	__in double x
	)
{
	int valid;
	double denom, numer, result = x;

	valid = _fp_valid(result, FP_INF | FP_NAN);
	switch(valid) {
		case FP_INF:

			if(result < LOG_DOM_MIN) {
				errno = EDOM;
				result = NAN;
			} else {
				errno = ERANGE;
				result = INFINITY;
			}
			break;
		case FP_NAN:
			errno = EDOM;
			break;
		default:

			if(result == LOG_DOM_MIN) {
				result = 0.0;
			} else if(result < LOG_DOM_MIN) {
				errno = EDOM;
				result = NAN;
			} else {
				errno = 0;
				numer = log(x);

				switch(errno) {
					case EDOM:
					case ERANGE:
						goto exit;
				}

				errno = 0;
				denom = log(LOG_10);

				switch(errno) {
					case EDOM:
					case ERANGE:
						goto exit;
				}

				result = (numer / denom);
			}
			break;
	}

exit:
	return result;
}

double 
modf(
	__in double x,
	__inout double *ipart
	)
{
	int valid;
	double result = x;

	if(!ipart) {
		errno = EINVAL;
		goto exit;
	}

	*ipart = ((long) result);

	valid = _fp_valid(result, FP_INF | FP_NAN);
	switch(valid) {
		case FP_INF:
			errno = ERANGE;
			result = 0.0;
			break;
		case FP_NAN:
			errno = EDOM;
			break;
		default:
			result -= *ipart;
			break;
	}

exit:
	return result;
}

double 
pow(
	__in double base,
	__in double exp
	)
{
	int valid;
	double result = 1.0;

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
	int valid;
	double prev, result = x;

	valid = _fp_valid(result, FP_INF | FP_NAN);
	switch(valid) {
		case FP_INF:

			if(result < SQRT_DOM_MIN) {
				errno = EDOM;
				result = NAN;
			} else {
				errno = ERANGE;
				result = INFINITY;
			}
			break;
		case FP_NAN:
			errno = EDOM;
			break;
		default:

			if(result == SQRT_DOM_MIN) {
				goto exit;
			} else if(result < SQRT_DOM_MIN) {
				errno = EDOM;
				result = NAN;
			} else {
				result = 1.0;

				for(;;) {
					prev = result;
					errno = 0;
					result = (result - ((pow(result, 2.0) - x) / (2.0 * result)));

					switch(errno) {
						case EDOM:
						case ERANGE:
							goto exit;
					}

					errno = 0;
					if(fabs(prev - result) < SQRT_ERR) {
						break;
					}

					switch(errno) {
						case EDOM:
						case ERANGE:
							goto exit;
					}
				}
			}
			break;
	}

exit:
	return result;	
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
