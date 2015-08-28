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

/*#include "../lib/include/assert.h"
#include "../lib/include/ctype.h"
#include "../lib/include/errdef.h"
#include "../lib/include/errno.h"
#include "../lib/include/float.h"
#include "../lib/include/iso646.h"
#include "../lib/include/libdef.h"
#include "../lib/include/limits.h"
#include "../lib/include/locale.h"
#include "../lib/include/locdef.h"
#include "../lib/include/setjmp.h"
#include "../lib/include/stdbool.h"
#include "../lib/include/stdarg.h"
#include "../lib/include/stddef.h"
#include "../lib/include/stdint.h"
#include "../lib/include/string.h"
#include "../lib/include/time.h"*/

#include <stdio.h>
#include <string.h>
#include <time.h>

// time offsets
#define tm_epoch_leap 26 // seconds
#define tm_epoch_start 70 // 1970
#define tm_sec_per_year 31536000.0
#define tm_sec_per_day 86400.0
#define tm_sec_per_hour 3600.0
#define tm_sec_per_min 60.0

// time value ranges
#define tm_dst_active 1
#define tm_dsm_inactive 0
#define tm_hour_max 23
#define tm_hour_min 0
#define tm_mday_max 31
#define tm_mday_min 1
#define tm_min_max 59
#define tm_min_min 0
#define tm_mon_max 11
#define tm_mon_min 0
#define tm_sec_max 61
#define tm_sec_min 0
#define tm_wday_max 6
#define tm_wday_min 0
#define tm_week_max 52
#define tm_week_min 1
#define tm_yday_max 365
#define tm_yday_min 0
#define tm_year_min 1900

/*
 * Offset from 01/01/1900 to 01/01/1970 in seconds
 * 	(((70 * 365) + 17) * 86400)
 */
#define tm_epoch_offset \
	(((tm_epoch_start * tm_yday_max) + tm_epoch_leap) * tm_sec_per_day)

/*
 * Determine if a year is a leap year
 * @param year year to check against
 */
#define tm_year_leap(year) \
	((!((year) % 4)) && (((year) % 100) || (!((year) + tm_year_min))))

/*
 * Determine the number of days in a year
 * @param year year to check against
 */
#define tm_year_day(year) \
	(tm_year_leap(year) ? (tm_yday_max + 1) : tm_yday_max)

static struct tm tm_time = { 0 };

struct tm *
gmtimes(
	const time_t *timer
	)
{
	time_t rem = *timer;

	if(rem < 0) {
		goto exit;
	}

	memset(&tm_time, 0, sizeof(struct tm));

/*
	// TODO: set these values
	_tm tm_mday; // month day (1 - 31)
	_tm tm_mon; // month (0 - 11)
	_tm tm_wday; // week day (0 - 6)
 */

	while(rem > tm_sec_per_year) {
		rem -= (tm_year_day(tm_year_min + tm_time.tm_year) 
			* tm_sec_per_day);
		tm_time.tm_year++;
	}

	tm_time.tm_year += tm_epoch_start;

	while(rem > tm_sec_per_day) {
		rem -= tm_sec_per_day;
		tm_time.tm_yday++;
	}

	while(rem > tm_sec_per_hour) {
		rem -= tm_sec_per_hour;
		tm_time.tm_hour++;
	}

	while(rem > tm_sec_per_min) {
		rem -= tm_sec_per_min;
		tm_time.tm_min++;
	}

	tm_time.tm_sec = rem;

exit:
	return (*timer < 0) ? NULL : &tm_time;
}

int 
main(void)
{
	time_t t1, t2;	
	int result = 0;
	struct tm *tt = NULL;

	t1 = time(NULL);
	t2 = t1;

	tt = gmtime(&t1);
	printf("[%lu] %s\n", t1, asctime(tt));

	tt = gmtimes(&t2);
	printf("[%lu] %s\n", t2, asctime(tt));

	// TODO

	return result;
}
