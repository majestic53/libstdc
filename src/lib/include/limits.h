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

#ifndef LIMITS_H_
#define LIMITS_H_

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

// bits in char type
#define CHAR_BIT 8

// char type range
#define CHAR_MIN (-CHAR_MAX - 1)
#define CHAR_MAX 0x7f

// int type range
#define INT_MIN LONG_MIN
#define INT_MAX LONG_MAX

// long type range
#define LONG_MIN (-LONG_MAX - 1l)
#define LONG_MAX 0x7fffffffl

// maximum character length
#define MB_LEN_MAX 1

// signed char type range
#define SCHAR_MIN CHAR_MIN
#define SCHAR_MAX CHAR_MAX

// short type range
#define SHRT_MIN (-SHRT_MAX - 1)
#define SHRT_MAX 0x7fff

// unsigned char type range
#define UCHAR_MAX 0xffu

// minimum unsigned int type range
#define UINT_MAX ULONG_MAX

// minimum unsigned long type range
#define ULONG_MAX 0xfffffffful

// minimum unsigned short type range
#define USHRT_MAX 0xffffu

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // LIMITS_H_
