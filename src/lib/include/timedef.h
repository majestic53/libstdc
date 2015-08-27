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
#define tm_am "AM"
#define tm_pm "PM"
#define tm_tag '%'
#define tm_tag_len 1
#define tm_tag_abbrev_mon 'b'
#define tm_tag_abbrev_mon_len 3
#define tm_tag_abbrev_wday 'a'
#define tm_tag_abbrev_wday_len 3
#define tm_tag_am_pm 'p'
#define tm_tag_am_pm_len 2
#define tm_tag_date 'x'
#define tm_tag_date_len 11
#define tm_tag_date_time 'c'
#define tm_tag_date_time_len 20
#define tm_tag_full_mon 'B'
#define tm_tag_full_mon_len 3
#define tm_tag_full_wday 'A'
#define tm_tag_full_wday_len 3
#define tm_tag_hour_12 'I'
#define tm_tag_hour_12_len 2
#define tm_tag_hour_24 'H'
#define tm_tag_hour_24_len 2
#define tm_tag_mon_day_zero 'd'
#define tm_tag_mon_day_zero_len 2
#define tm_tag_min 'M'
#define tm_tag_min_len 2
#define tm_tag_mon 'm'
#define tm_tag_mon_len 2
#define tm_tag_sec 'S'
#define tm_tag_sec_len 2
#define tm_tag_time 'X'
#define tm_tag_time_len 8
#define tm_tag_tzone 'Z'
#define tm_tag_tzone_len 3
#define tm_tag_wday 'w'
#define tm_tag_wday_len 1
#define tm_tag_wmonday 'W'
#define tm_tag_wmonday_len 2
#define tm_tag_wsunday 'U'
#define tm_tag_wsunday_len 2
#define tm_tag_ycent 'y'
#define tm_tag_ycent_len 2
#define tm_tag_yday 'j'
#define tm_tag_yday_len 3
#define tm_tag_year 'Y'
#define tm_tag_year_len 4


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
#define tm_yday_max 365
#define tm_yday_min 0
#define tm_year_min 1900

/*
 * Offset from 01/01/1990 - 01/01/1970 in seconds
 * 	(((70 * 365) + 17) * 86400)
 */
#define epoch_offset 0x83aa7e80

// full month string strings
static const char *mon_full_str[] = {
	"January", "February", "March", "April", "May", "June", 
	"July", "August", "September", "October", "November", "December",
	};

/*
 * Full month string
 * @param mon valid full month value
 */
#define mon_full_string(mon) \
	(((mon < tm_mon_min) || (mon > tm_mon_max)) ? _unknown _unknown _unknown : \
	mon_full_str[mon])

// full week day strings
static const char *wday_full_str[] = {
	"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday",
	};

/*
 * Full week day string
 * @param wday valid weekday value
 */
#define wday_full_string(wday) \
	(((wday < tm_wday_min) || (wday > tm_wday_max)) ? _unknown _unknown _unknown : \
	wday_full_str[wday])

// month string strings
static const char mon_str[][4] = {
	"Jan", "Feb", "Mar", "Apr", "May", "Jun", 
	"Jul", "Aug", "Sep", "Oct", "Nov", "Dec",
	};

/*
 * Month string
 * @param mon valid month value
 */
#define mon_string(mon) \
	(((mon < tm_mon_min) || (mon > tm_mon_max)) ? _unknown _unknown _unknown : \
	mon_str[mon])

// week day strings
static const char wday_str[][4] = {
	"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat",
	};

/*
 * Week day string
 * @param wday valid weekday value
 */
#define wday_string(wday) \
	(((wday < tm_wday_min) || (wday > tm_wday_max)) ? _unknown _unknown _unknown : \
	wday_str[wday])

// time string container
static char asc_str[_asc_str_len] = { 0 };

// time value
static time_t cur_time = 0;

// time container
static tm tm_time = {
	tm_sec_min,
	tm_min_min,
	tm_hour_min,
	tm_mday_min,
	tm_mon_min,
	tm_year_min,
	tm_wday_min,
	tm_yday_min,
	tm_dsm_inactive,
	};

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // TIMEDEF_H_
