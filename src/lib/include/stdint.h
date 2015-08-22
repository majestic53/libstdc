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

#ifndef STDINT_H_
#define STDINT_H_

#include "libdef.h"
#include "limits.h"

// signed 8-bit integer type range
#define INT8_MAX CHAR_MAX
#define INT8_MIN CHAR_MIN
#define INT_FAST8_MAX CHAR_MAX
#define INT_FAST8_MIN CHAR_MIN
#define INT_LEAST8_MAX CHAR_MAX
#define INT_LEAST8_MIN CHAR_MIN

// unsigned 8-bit integer type range
#define UINT8_MAX UCHAR_MAX
#define UINT_FAST8_MAX UCHAR_MAX
#define UINT_LEAST8_MAX UCHAR_MAX

// signed 16-bit integer type range
#define INT16_MAX SHRT_MAX
#define INT16_MIN SHRT_MIN
#define INT_FAST16_MAX SHRT_MAX
#define INT_FAST16_MIN SHRT_MIN
#define INT_LEAST16_MAX SHRT_MAX
#define INT_LEAST16_MIN SHRT_MIN

// unsigned 16-bit integer type range
#define UINT16_MAX USHRT_MAX
#define UINT_FAST16_MAX USHRT_MAX
#define UINT_LEAST16_MAX USHRT_MAX

// signed 32-bit integer type range
#define INT32_MAX LONG_MAX
#define INT32_MIN LONG_MIN
#define INT_FAST32_MAX LONG_MAX
#define INT_FAST32_MIN LONG_MIN
#define INT_LEAST32_MAX LONG_MAX
#define INT_LEAST32_MIN LONG_MIN

// unsigned 32-bit integer type range
#define UINT32_MAX ULONG_MAX
#define UINT_FAST32_MAX ULONG_MAX
#define UINT_LEAST32_MAX ULONG_MAX

// signed pointer type range
#define INTMAX_MAX LONG_MAX
#define INTMAX_MIN LONG_MIN
#define INTPTR_MAX LONG_MAX
#define INTPTR_MIN LONG_MIN

// unsigned integer type range
#define UINTMAX_MAX ULONG_MAX
#define UINTPTR_MAX ULONG_MAX

/*
 * Signed 8-bit integer conversion
 * @param value castable value
 */
#define INT8_C(value) ((int8_t) value)

/*
 * Signed 16-bit integer conversion
 * @param value castable value
 */
#define INT16_C(value) ((int16_t) value)

/*
 * Signed 32-bit integer conversion
 * @param value castable value
 */
#define INT32_C(value) ((int32_t) _valstr(value, l))

/*
 * Unsigned 8-bit integer conversion
 * @param value castable value
 */
#define UINT8_C(value) ((int8_t) _valstr(value, u))

/*
 * Unsigned 16-bit integer conversion
 * @param value castable value
 */
#define UINT16_C(value) ((int16_t) _valstr(value, u))

/*
 * Unsigned 32-bit integer conversion
 * @param value castable value
 */
#define UINT32_C(value) ((int32_t) _valstr(value, ul))

/*
 * Signed integer conversion
 * @param value castable value
 */
#define INTMAX_C(value) INT32_C(value)

/*
 * Unsigned integer conversion
 * @param value castable value
 */
#define UINTMAX_C(value) UINT32_C(value)

// signed integer type definitions
typedef signed char int8_t;
typedef signed short int16_t;
typedef signed long int32_t;
typedef int8_t int_fast8_t;
typedef int16_t int_fast16_t;
typedef int32_t int_fast32_t;
typedef int8_t int_least8_t;
typedef int16_t int_least16_t;
typedef int32_t int_least32_t;

// unsigned integer type definitions
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned long uint32_t;
typedef uint8_t uint_fast8_t;
typedef uint16_t uint_fast16_t;
typedef uint32_t uint_fast32_t;
typedef uint8_t uint_least8_t;
typedef uint16_t uint_least16_t;
typedef uint32_t uint_least32_t;

// signed integer type definition
typedef int32_t intptr_t;
typedef int32_t intmax_t;

// unsigned integer type definition
typedef uint32_t uintptr_t;
typedef uint32_t uintmax_t;

#endif // STDINT_H_
