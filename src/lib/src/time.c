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

#include "../include/locale.h"
#include "../include/locdef.h"
//#include "../include/math.h"
//#include "../include/stdio.h"
#include "../include/string.h"
#include "../include/time.h"
#include "../include/timedef.h"

#define EOF _eof

_tm 
find_mday(
	__in _tm year,
	__in _tm yday
	)
{
	_tm len, mon = tm_mon_min, result = yday;
	
	len = tm_mon_length(year, mon);
	while((result > len) && (mon <= tm_mon_max)) {
		result -= len;
		++mon;
		len = tm_mon_length(year, mon);
	}
	
	return (result + tm_mday_min);
}
	
_tm 
find_mon(
	__in _tm year,
	__in _tm yday
	)
{
	_tm len, rem = yday, result = tm_mon_min;
	
	len = tm_mon_length(year, result);
	while((rem > len) && (result <= tm_mon_max)) {
		rem -= len;
		++result;
		len = tm_mon_length(year, result);
	}
	
	return result;
}

size_t 
find_strftime_len(
	__in const char tag,
	__in _tm hint
	)
{
	size_t result = 0;

	if(!tag) {
		goto exit;
	}

	switch(tag) {
		case tm_tag_abbrev_mon: // 'b'
			result = tm_tag_abbrev_mon_len;
			break;
		case tm_tag_abbrev_wday: // 'a'
			result = tm_tag_abbrev_wday_len;
			break;
		case tm_tag_am_pm: // 'p'
			result = tm_tag_am_pm_len;
			break;
		case tm_tag_date: // 'x'
			result = tm_tag_date_len;
			break;
		case tm_tag_date_time: // 'c'
			result = tm_tag_date_time_len;
			break;
		case tm_tag_full_mon: // 'B'

			if((hint >= tm_mon_min) && (hint <= tm_mon_max)) {
				result = strlen(tm_mon_full_string(hint));
			} else {
				result = tm_tag_full_mon_len;
			}
			break;
		case tm_tag_full_wday: // 'A'

			if((hint >= tm_wday_min) && (hint <= tm_wday_max)) {
				result = strlen(tm_wday_full_string(hint));
			} else {
				result = tm_tag_full_wday_len;
			}
			break;
		case tm_tag_hour_12: // 'I'
			result = tm_tag_hour_12_len;
			break;
		case tm_tag_hour_24: // 'H'
			result = tm_tag_hour_24_len;
			break;
		case tm_tag_mon_day_zero: // 'd'
			result = tm_tag_mon_day_zero_len;
			break;
		case tm_tag_min: // 'M'
			result = tm_tag_min_len;
			break;
		case tm_tag_mon: // 'm'
			result = tm_tag_mon_len;
			break;
		case tm_tag_sec: // 'S'
			result = tm_tag_sec_len;
			break;
		case tm_tag_time: // 'X'
			result = tm_tag_time_len;
			break;
		case tm_tag_tzone: // 'Z'
			result = tm_tag_tzone_len;
			break;
		case tm_tag_wday: // 'w'
			result = tm_tag_wday_len;
			break;
		case tm_tag_wmonday: // 'W'
			result = tm_tag_wmonday_len;
			break;
		case tm_tag_wsunday: // 'U'
			result = tm_tag_wsunday_len;
			break;
		case tm_tag_ycent: // 'y'
			result = tm_tag_ycent_len;
			break;
		case tm_tag_yday: // 'j'
			result = tm_tag_yday_len;
			break;
		case tm_tag_year: // 'Y'
			result = tm_tag_year_len;
			break;
		default:
			result = tm_tag_len;
			break;
	}

exit:
	return result;
}

_tm 
find_wday(
	__in _tm year,
	__in _tm yday
	)
{
	/*_tm cent = (((year + tm_year_min) & tm_mille) / 2);
	
	year %= tm_cent;

	return ((find_mday(year, yday) + find_mon(year, yday) + year 
		+ (_tm) floor((double) year / 4.0) + cent) % (tm_wday_max + 1));*/

	return 0;
}

_tm 
find_week_num(
	__in _tm yday,
	__in _tm wday
	)
{
	_tm result = ((yday - wday) + 10) / 7;

	if(result < tm_week_min) {
		result = tm_week_max;
	} else if(result > tm_week_max) {
		result = tm_week_min;
	}

	return result;
}

char *
asctime(
	__in const struct tm *timeptr
	)
{
	/*sprintf(tm_ascstr, "%.3s %.3s %02u %02u:%02u:%02u %04u\n", 
		tm_wday_string(timeptr->tm_wday),
		tm_mon_string(timeptr->tm_mon),
		timeptr->tm_mday,
		timeptr->tm_hour,
		timeptr->tm_min,
		timeptr->tm_sec,
		timeptr->tm_year + tm_year_min
		);*/
		
	return tm_ascstr;
}

clock_t 
clock(void)
{
	return (clock_t) time(NULL);
}

char *
ctime(
	__in const time_t *timer
	)
{
	return asctime(localtime(timer));
}

double 
difftime(
	__in time_t time1,
	__in time_t time0
	)
{
	return (double) (time1 > time0) ? (time1 - time0) : (-1 * (time0 - time1));
}

struct tm *
gmtime(
	__in const time_t *timer
	)
{
	time_t rem = *timer;

	if(rem < 0) {
		goto exit;
	}

	memset(&tm_time, 0, sizeof(struct tm));

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
	tm_time.tm_mon = find_mon(tm_time.tm_year, tm_time.tm_yday);
	tm_time.tm_mday = find_mday(tm_time.tm_year, tm_time.tm_yday);
	tm_time.tm_wday = find_wday(tm_time.tm_year, tm_time.tm_yday);

exit:
	return (*timer < 0) ? NULL : &tm_time;
}

struct tm *
localtime(
	__in const time_t *timer
	)
{
	time_t loc = *timer - (locale.time.tzone_off * tm_sec_per_hour);
	return gmtime(&loc);
}

time_t 
mktime(
	__inout struct tm *timeptr
	)
{
	time_t iter = tm_epoch_start, leap = 0, result = 0;

	for(; iter <= timeptr->tm_year; ++iter) {

		if(tm_year_leap(tm_year_min + iter)) {
			++leap;
		}
	}

	result = (((timeptr->tm_year - tm_epoch_start) * tm_sec_per_year)
		+ ((timeptr->tm_yday + leap + 1) * tm_sec_per_day)
		+ (timeptr->tm_hour * tm_sec_per_hour)
		+ (timeptr->tm_min * tm_sec_per_min)
		+ timeptr->tm_sec);

	if(timeptr->tm_isdst) {
		result -= tm_sec_per_hour;
	}

	result -= (locale.time.tzone_off * tm_sec_per_hour);

	return (result < 0) ? _inv(time_t) : result;
}

size_t 
strftime(
	__inout char *s,
	__in size_t maxsize,
	__in const char *format,
	__in const struct tm *timeptr
	)
{	
	_tm hint;
	char *ch = (char *) format;	
	size_t fill = 0, result = 0;

	if(!maxsize) {
		goto exit;
	}

	while((*ch != EOF) && (result < maxsize)) {

		if(*ch == tm_tag) {
			++ch;

			if(*ch == EOF) {
				goto exit;
			} else if(*ch == tm_tag_full_mon) {
				hint = timeptr->tm_mon;
			} else if(*ch == tm_tag_full_wday) {
				hint = timeptr->tm_wday;
			} else {
				hint = 0;
			}

			fill = find_strftime_len(*ch, hint);
			if((result + fill) > (maxsize - 1)) {
				goto exit;
			}

			result += fill;

			switch(*ch) {
				case tm_tag: // %
					*s = *ch;
					break;
				case tm_tag_abbrev_mon: // 'b'
					strcpy(s, tm_mon_string(timeptr->tm_mon));
					break;
				case tm_tag_abbrev_wday: // 'a'
					strcpy(s, tm_wday_string(timeptr->tm_wday));
					break;
				case tm_tag_am_pm: // 'p'
					strcpy(s, (timeptr->tm_hour >= 12) ? tm_pm : tm_am);
					break;
				case tm_tag_date: // 'x'
					/*sprintf(s, "%.3s %02u %04u", 
						tm_mon_string(timeptr->tm_mon),
						timeptr->tm_mday,
						timeptr->tm_year + tm_year_min
						);*/
					break;
				case tm_tag_date_time: // 'c'
					/*sprintf(s, "%.3s %02u %02u:%02u:%02u %04u", 
						tm_mon_string(timeptr->tm_mon),
						timeptr->tm_mday,
						timeptr->tm_hour,
						timeptr->tm_min,
						timeptr->tm_sec,
						timeptr->tm_year + tm_year_min
						);*/
					break;
				case tm_tag_full_mon: // 'B'
					strcpy(s, tm_mon_full_string(timeptr->tm_mon));
					break;
				case tm_tag_full_wday: // 'A'
					strcpy(s, tm_wday_full_string(timeptr->tm_wday));
					break;
				case tm_tag_hour_12: // 'I'
					//sprintf(s, "%02u", timeptr->tm_hour % 12);
					break;
				case tm_tag_hour_24: // 'H'
					//sprintf(s, "%02u", timeptr->tm_hour);
					break;
				case tm_tag_mon_day_zero: // 'd'
					//sprintf(s, "%02u", timeptr->tm_mday);
					break;
				case tm_tag_min: // 'M'
					//sprintf(s, "%02u", timeptr->tm_min);
					break;
				case tm_tag_mon: // 'm'
					//sprintf(s, "%02u", timeptr->tm_mon + 1);
					break;
				case tm_tag_sec: // 'S'
					//sprintf(s, "%02u", timeptr->tm_sec);
					break;
				case tm_tag_time: // 'X'
					/*sprintf(s, "%02u:%02u:%02u", 
						timeptr->tm_hour, 
						timeptr->tm_min, 
						timeptr->tm_sec
						);*/
					break;
				case tm_tag_tzone: // 'Z'
					strcpy(s, locale.time.tzone);
					break;
				case tm_tag_wday: // 'w'
					//sprintf(s, "%02u", timeptr->tm_wday);
					break;
				case tm_tag_wmonday: // 'W'
					/*sprintf(s, "%02u", find_week_num(timeptr->tm_yday, 
						timeptr->tm_wday));*/
					break;
				case tm_tag_wsunday: // 'U'
					/*sprintf(s, "%02u", find_week_num(timeptr->tm_yday, 
						timeptr->tm_wday));*/
					break;
				case tm_tag_ycent: // 'y'
					//sprintf(s, "%02u", (timeptr->tm_year + tm_year_min) % 100);
					break;
				case tm_tag_yday: // 'j'
					//sprintf(s, "%03u", timeptr->tm_yday + 1);
					break;
				case tm_tag_year: // 'Y'
					//sprintf(s, "%04u", timeptr->tm_year + tm_year_min);
					break;
				default:
					*s = *_unknown;
					break;
			}

			s += fill;
		} else {
			*s = *ch;
			++s;
			++result;
		}

		++ch;
	}

	while((result + fill++) <= maxsize) {
		*s = EOF;
		++s;
	}

	++result;

exit:
	return result;
}

time_t 
time(
	__inout time_t *timer
	)
{
	// TODO: set tm_cur

	if(timer) {
		*timer = tm_cur;
	}

	return tm_cur;
}
