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

#ifndef TIME_H_
#define TIME_H_

#include "libdef.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

// clock ticks per second
#define CLOCKS_PER_SEC _clocks_per_sec

// null definition
#define NULL _null

// clock_t definition
#ifndef _CLOCK_T
#define _CLOCK_T
typedef _clock_t clock_t;
#endif // _CLOCK_T

// size_t definition
#ifndef _SIZE_T
#define _SIZE_T
typedef _size_t size_t;
#endif // _SIZE_T

// time_t definition
#ifndef _TIME_T
#define _TIME_T
typedef _time_t time_t;
#endif // _TIME_T

#ifndef _TM
#define _TM
typedef struct {
	_tm tm_sec; // second (0 - 61)
	_tm tm_min; // minute (0 - 59)
	_tm tm_hour; // hour (0 - 23)
	_tm tm_mday; // month day (1 - 31)
	_tm tm_mon; // month (0 - 11)
	_tm tm_year; // year (since 1900)
	_tm tm_wday; // week day (0 - 6)
	_tm tm_yday; // day (0 - 365)
	_tm tm_isdst; // daylight saving time (0: not active, 1: active)
} tm;
#endif // _TM

// TODO
char *asctime(
	__in const tm *timeptr
	);

// TODO
clock_t clock(void);

// TODO
char *ctime(
	__in const time_t *timer
	);

// TODO
double difftime(
	__in time_t time1,
	__in time_t time0
	);

// TODO
tm *gmtime(
	__in const time_t *timer
	);

// TODO
tm *localtime(
	__in const time_t *timer
	);

// TODO
time_t mktime(
	__inout tm *timeptr
	);

// TODO
size_t strftime(
	__inout char *s,
	__in size_t maxsize,
	__in const char *format,
	__in const tm *timeptr
	);

// TODO
time_t time(
	__inout time_t *timer
	);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // TIME_H_
