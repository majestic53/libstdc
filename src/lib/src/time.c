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

#include "../include/time.h"

char *
asctime(
	__in const tm *timeptr
	)
{
	// TODO
}

clock_t 
clock(void)
{
	// TODO
}

char *
ctime(
	__in const time_t *timer
	)
{
	// TODO
}

double 
difftime(
	__in time_t time1,
	__in time_t time0
	)
{
	// TODO
}

tm *
gmtime(
	__in const time_t *timer
	)
{
	// TODO
}

tm *
localtime(
	__in const time_t *timer
	)
{
	// TODO
}

time_t 
mktime(
	__inout tm *timeptr
	)
{
	// TODO
}

size_t 
strftime(
	__inout char *s,
	__in size_t maxsize,
	__in const char *format,
	__in const tm *timeptr
	)
{
	// TODO
}

time_t 
time(
	__inout time_t *timer
	)
{
	// TODO
}
