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

#ifndef TIMEDEF_H_
#define TIMEDEF_H_

#include "libdef.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

// time string tags
#define TM_AM "AM"
#define TM_PM "PM"
#define TM_TAG '%'
#define TM_TAG_ABBREV_MON 'b'
#define TM_TAG_ABBREV_WDAY 'a'
#define TM_TAG_AM_PM 'p'
#define TM_TAG_DATE 'x'
#define TM_TAG_DATE_TIME 'c'
#define TM_TAG_HOUR_12 'I'
#define TM_TAG_HOUR_24 'H'
#define TM_TAG_MON_DAY_ZERO 'd'
#define TM_TAG_MIN 'M'
#define TM_TAG_MON 'm'
#define TM_TAG_MON_FULL 'B'
#define TM_TAG_SEC 'S'
#define TM_TAG_TIME 'X'
#define TM_TAG_TZONE 'Z'
#define TM_TAG_WDAY 'w'
#define TM_TAG_WDAY_FULL 'A'
#define TM_TAG_WMONDAY 'W'
#define TM_TAG_WSUNDAY 'U'
#define TM_TAG_YCENT 'y'
#define TM_TAG_YDAY 'j'
#define TM_TAG_YEAR 'Y'

// time string tag lengths
#define TM_TAG_LEN 1
#define TM_TAG_ABBREV_MON_LEN 3
#define TM_TAG_ABBREV_WDAY_LEN 3
#define TM_TAG_AM_PM_LEN 2
#define TM_TAG_DATE_LEN 11
#define TM_TAG_DATE_TIME_LEN 20
#define TM_TAG_HOUR_12_LEN 2
#define TM_TAG_HOUR_24_LEN 2
#define TM_TAG_MIN_LEN 2
#define TM_TAG_MON_DAY_ZERO_LEN 2
#define TM_TAG_MON_FULL_LEN 3
#define TM_TAG_MON_LEN 2
#define TM_TAG_SEC_LEN 2
#define TM_TAG_TIME_LEN 8
#define TM_TAG_TZONE_LEN 3
#define TM_TAG_WDAY_FULL_LEN 3
#define TM_TAG_WDAY_LEN 1
#define TM_TAG_WMONDAY_LEN 2
#define TM_TAG_WSUNDAY_LEN 2
#define TM_TAG_YCENT_LEN 2
#define TM_TAG_YDAY_LEN 3
#define TM_TAG_YEAR_LEN 4

// time offsets
#define TM_CENT 100 // century
#define TM_MILLE 1000 // millenium
#define TM_MON_FEB 1 // february
#define TM_EPOCH_START 70 // 1970
#define TM_SEC_PER_YEAR 31536000.0
#define TM_SEC_PER_DAY 86400.0
#define TM_SEC_PER_HOUR 3600.0
#define TM_SEC_PER_MIN 60.0

// time value ranges
#define TM_DST_ACTIVE 1
#define TM_DST_INACTIVE 0
#define TM_HOUR_MAX 23
#define TM_HOUR_MIN 0
#define TM_MDAY_MAX 31
#define TM_MDAY_MIN 1
#define TM_MIN_MAX 59
#define TM_MIN_MIN 0
#define TM_MON_MAX 11
#define TM_MON_MIN 0
#define TM_SEC_MAX 61
#define TM_SEC_MIN 0
#define TM_WDAY_MAX 6
#define TM_WDAY_MIN 0
#define TM_WEEK_MAX 52
#define TM_WEEK_MIN 1
#define TM_YDAY_MAX 365
#define TM_YDAY_MIN 0
#define TM_YEAR_MIN 1900

/*
 * Calculate month length
 * @param _YEAR_ year to check against
 * @param _MON_ month to check against
 */
#define TM_MON_LENGTH(_YEAR_, _MON_) \
	((((_MON_) < TM_MON_MIN) || ((_MON_) > TM_MON_MAX)) ? _INV(_tm) : \
	(((_MON_) == TM_MON_FEB) ? (TM_MON_LEN[_MON_] + (TM_YEAR_LEAP(_YEAR_) ? 1 : 0)) : \
	TM_MON_LEN[_MON_]))

/*
 * Month string
 * @param _MON_ valid month value
 */
#define TM_MON_STRING(_MON_) \
	((((_MON_) < TM_MON_MIN) || ((_MON_) > TM_MON_MAX)) ? _UNKNOWN _UNKNOWN _UNKNOWN : \
	TM_MON_STR[_MON_])

/*
 * Full month string
 * @param _MON_ valid full month value
 */
#define TM_MON_STRING_FULL(_MON_) \
	((((_MON_) < TM_MON_MIN) || ((_MON_) > TM_MON_MAX)) ? _UNKNOWN _UNKNOWN _UNKNOWN : \
	TM_MON_STR_FULL[_MON_])

/*
 * Week day string
 * @param _WDAY_ valid weekday value
 */
#define TM_WDAY_STRING(_WDAY_) \
	((((_WDAY_) < TM_WDAY_MIN) || ((_WDAY_) > TM_WDAY_MAX)) ? _UNKNOWN _UNKNOWN _UNKNOWN : \
	TM_WDAY_STR[_WDAY_])

/*
 * Full week day string
 * @param _WDAY_ valid weekday value
 */
#define TM_WDAY_STRING_FULL(_WDAY_) \
	((((_WDAY_) < TM_WDAY_MIN) || ((_WDAY_) > TM_WDAY_MAX)) ? _UNKNOWN _UNKNOWN _UNKNOWN : \
	TM_WDAY_STR_FULL[_WDAY_])

/*
 * Determine if a year is a leap year
 * @param _YEAR_ year to check against
 */
#define TM_YEAR_LEAP(_YEAR_) \
	((!((_YEAR_) % 4)) && (((_YEAR_) % 100) || (!((_YEAR_) + TM_YEAR_MIN))))

/*
 * Determine the number of days in a year
 * @param _YEAR_ year to check against
 */
#define TM_YEAR_DAY(_YEAR_) \
	(TM_YEAR_LEAP(_YEAR_) ? (TM_YDAY_MAX + 1) : TM_YDAY_MAX)

// month length values
static const _tm TM_MON_LEN[] = {
	31, 28 /* + leap(year) */, 31, 30, 31, 
	30, 31, 31, 30, 31, 30, 31,
	};

// month string strings
static const char *TM_MON_STR[] = {
	"Jan", "Feb", "Mar", "Apr", "May", "Jun", 
	"Jul", "Aug", "Sep", "Oct", "Nov", "Dec",
	};

// full month string strings
static const char *TM_MON_STR_FULL[] = {
	"January", "February", "March", "April", "May", "June", 
	"July", "August", "September", "October", "November", "December",
	};

// week day strings
static const char *TM_WDAY_STR[] = {
	"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat",
	};

// full week day strings
static const char *TM_WDAY_STR_FULL[] = {
	"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday",
	};

// time string container
static char tm_ascstr[_ASCSTR_LEN] = { 0 };

// time value
static time_t tm_time = 0;

// time container
static struct tm tm_timeptr = {
	TM_SEC_MIN,
	TM_MIN_MIN,
	TM_HOUR_MIN,
	TM_MDAY_MIN,
	TM_MON_MIN,
	TM_YEAR_MIN,
	TM_WDAY_MIN,
	TM_YDAY_MIN,
	TM_DST_INACTIVE,
	};

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // TIMEDEF_H_
