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

#ifndef FLOAT_H_
#define FLOAT_H_

// maximum number of decimal digits in double (base 10)
#define DBL_DIG 15

// least significant digits in double
#define DBL_EPSILON 2.220446e-16

// maximum number of digits in double
#define DBL_MANT_DIG 53

// maximum double value
#define DBL_MAX 1.797693e+308

// maximum exponent length in double
#define DBL_MAX_EXP 1024

// maximum exponent length in double (base 10)
#define DBL_MAX_10_EXP 308

// minimum double value
#define DBL_MIN 2.225074e-308

// minimum exponent length in double
#define DBL_MIN_EXP (-307)

// minimum exponent length in double (base 10)
#define DBL_MIN_10_EXP (-1021)

// maximum number of decimal digits in float (base 10)
#define FLT_DIG 7

// least significant digits in float
#define FLT_EPSILON 1.192093e-07f

// maximum number of digits in float
#define FLT_MANT_DIG 24

// maximum float value
#define FLT_MAX 3.402823e+38f

// maximum exponent length in float
#define FLT_MAX_EXP 128

// maximum exponent length in float (base 10)
#define FLT_MAX_10_EXP 38

// minimum float value
#define FLT_MIN 1.175494e-38f

// minimum exponent length in float
#define FLT_MIN_EXP (-125)

// minimum exponent length in float (base 10)
#define FLT_MIN_10_EXP (-37)

// maximum number of decimal digits in long double (base 10)
#define LDBL_DIG 19

// least significant digits in long double
#define LDBL_EPSILON 1.084202e-19l

// maximum number of digits in long double
#define LDBL_MANT_DIG 64

// maximum long double value
#define LDBL_MAX 1.189731e+4932l

// maximum exponent length in long double
#define LDBL_MAX_EXP 16384

// maximum exponent length in long double (base 10)
#define LDBL_MAX_10_EXP 4932

// minimum long double value
#define LDBL_MIN 3.362103e-4932l

// minimum exponent length in long double
#define LDBL_MIN_EXP (-16381)

// minimum exponent length in long double (base 10)
#define LDBL_MIN_10_EXP (-4931)

// radix representation
#define FLT_RADIX 2

// rounding mode
#define FLT_ROUNDS FLT_RNDS_TO_NEAR

enum {
	FLT_RNDS_INDET = -1, // indeterminate
	FLT_RNDS_TO_ZERO, // towards zero
	FLT_RNDS_TO_NEAR, // to nearest
	FLT_RNDS_TO_POS_INF, // towards positive infinity
	FLT_RNDS_TO_NEG_INF, // towards negative infinity
};

#endif // FLOAT_H_
