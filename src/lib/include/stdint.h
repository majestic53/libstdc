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

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

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
#ifndef _INT8_T
#define _INT8_T
typedef _int8_t int8_t;
#endif // _INT8_T

#ifndef _INT16T
#define _INT16_T
typedef _int16_t int16_t;
#endif // _INT16_T

#ifndef _INT32T
#define _INT32_T
typedef _int32_t int32_t;
#endif // _INT32_T

#ifndef _INT_FAST8_T
#define _INT_FAST8_T
typedef int8_t int_fast8_t;
#endif // _INT_FAST8_T

#ifndef _INT_FAST16_T
#define _INT_FAST16_T
typedef int16_t int_fast16_t;
#endif // _INT_FAST16_T

#ifndef _INT_FAST32_T
#define _INT_FAST32_T
typedef int32_t int_fast32_t;
#endif // _INT_FAST32_T

#ifndef _INT_LEAST8_T
#define _INT_LEAST8_T
typedef int8_t int_least8_t;
#endif // _INT_LEAST8_T

#ifndef _INT_LEAST16_T
#define _INT_LEAST16_T
typedef int16_t int_least16_t;
#endif // _INT_LEAST16_T

#ifndef _INT_LEAST32_T
#define _INT_LEAST32_T
typedef int32_t int_least32_t;
#endif // _INT_LEAST32_T

// signed integer type definition
#ifndef _INTMAX_T
#define _INTMAX_T
typedef int32_t intmax_t;
#endif // _INTMAX_T

#ifndef _INTPTR_T
#define _INTPTR_T
typedef int32_t intptr_t;
#endif // _INTPTR_T

// unsigned integer type definitions
#ifndef _UINT8_T
#define _UINT8_T
typedef _uint8_t uint8_t;
#endif // _UINT8_T

#ifndef _UINT16_T
#define _UINT16_T
typedef _uint16_t uint16_t;
#endif // _UINT16_T

#ifndef _UINT32_T
#define _UINT32_T
typedef _uint32_t uint32_t;
#endif // _UINT32_T

#ifndef _UINT_FAST8_T
#define _UINT_FAST8_T
typedef uint8_t uint_fast8_t;
#endif // _UINT_FAST8_T

#ifndef _UINT_FAST16_T
#define _UINT_FAST16_T
typedef uint16_t uint_fast16_t;
#endif // _UINT_FAST16_T

#ifndef _UINT_FAST32_T
#define _UINT_FAST32_T
typedef uint32_t uint_fast32_t;
#endif // _UINT_FAST32_T

#ifndef _UINT_LEAST8_T
#define _UINT_LEAST8_T
typedef uint8_t uint_least8_t;
#endif // _UINT_LEAST8_T

#ifndef _UINT_LEAST16_T
#define _UINT_LEAST16_T
typedef uint16_t uint_least16_t;
#endif // _UINT_LEAST16_T

#ifndef _UINT_LEAST32_T
#define _UINT_LEAST32_T
typedef uint32_t uint_least32_t;
#endif // _UINT_LEAST32_T

// unsigned integer type definition
#ifndef _UINTMAX_T
#define _UINTMAX_T
typedef uint32_t uintmax_t;
#endif // _UINTMAX_T

#ifndef _UINTPTR_T
#define _UINTPTR_T
typedef uint32_t uintptr_t;
#endif // _UINTPTR_T

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // STDINT_H_
