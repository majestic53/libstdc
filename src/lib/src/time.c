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
#include "../include/math.h"
#include "../include/stdio.h"
#include "../include/string.h"
#include "../include/time.h"
#include "../include/timedef.h"

// end of file (NUL) definition
#define EOF _EOF

_tm 
_mday(
	__in _tm year,
	__in _tm yday
	)
{
	_tm len, mon = TM_MON_MIN, result = yday;
	
	// iterate over year day to find containing month day
	len = TM_MON_LENGTH(year, mon);
	while((result > len) && (mon <= TM_MON_MAX)) {
		result -= len;
		++mon;
		len = TM_MON_LENGTH(year, mon);
	}
	
	return (result + TM_MDAY_MIN);
}
	
_tm 
_mon(
	__in _tm year,
	__in _tm yday
	)
{
	_tm len, rem = yday, result = TM_MON_MIN;
	
	// iterate over year day to find containing month
	len = TM_MON_LENGTH(year, result);
	while((rem > len) && (result <= TM_MON_MAX)) {
		rem -= len;
		++result;
		len = TM_MON_LENGTH(year, result);
	}
	
	return result;
}

size_t 
_strftime_len(
	__in const char tag,
	__in _tm hint
	)
{
	size_t result = 0;

	if(!tag) {
		goto exit;
	}

	switch(tag) {
		case TM_TAG_ABBREV_MON: // 'b'
			result = TM_TAG_ABBREV_MON_LEN;
			break;
		case TM_TAG_ABBREV_WDAY: // 'a'
			result = TM_TAG_ABBREV_WDAY_LEN;
			break;
		case TM_TAG_AM_PM: // 'p'
			result = TM_TAG_AM_PM_LEN;
			break;
		case TM_TAG_DATE: // 'x'
			result = TM_TAG_DATE_LEN;
			break;
		case TM_TAG_DATE_TIME: // 'c'
			result = TM_TAG_DATE_TIME_LEN;
			break;
		case TM_TAG_HOUR_12: // 'I'
			result = TM_TAG_HOUR_12_LEN;
			break;
		case TM_TAG_HOUR_24: // 'H'
			result = TM_TAG_HOUR_24_LEN;
			break;
		case TM_TAG_MIN: // 'M'
			result = TM_TAG_MIN_LEN;
			break;
		case TM_TAG_MON: // 'm'
			result = TM_TAG_MON_LEN;
			break;
		case TM_TAG_MON_DAY_ZERO: // 'd'
			result = TM_TAG_MON_DAY_ZERO_LEN;
			break;
		case TM_TAG_MON_FULL: // 'B'

			// determine full length of month
			if((hint >= TM_MON_MIN) && (hint <= TM_MON_MAX)) {
				result = strlen(TM_MON_STRING_FULL(hint));
			} else {
				result = TM_TAG_MON_FULL_LEN;
			}
			break;
		case TM_TAG_SEC: // 'S'
			result = TM_TAG_SEC_LEN;
			break;
		case TM_TAG_TIME: // 'X'
			result = TM_TAG_TIME_LEN;
			break;
		case TM_TAG_TZONE: // 'Z'
			result = TM_TAG_TZONE_LEN;
			break;
		case TM_TAG_WDAY: // 'w'
			result = TM_TAG_WDAY_LEN;
			break;
		case TM_TAG_WDAY_FULL: // 'A'

			// determine full length of week day
			if((hint >= TM_WDAY_MIN) && (hint <= TM_WDAY_MAX)) {
				result = strlen(TM_WDAY_STRING_FULL(hint));
			} else {
				result = TM_TAG_WDAY_FULL_LEN;
			}
			break;
		case TM_TAG_WMONDAY: // 'W'
			result = TM_TAG_WMONDAY_LEN;
			break;
		case TM_TAG_WSUNDAY: // 'U'
			result = TM_TAG_WSUNDAY_LEN;
			break;
		case TM_TAG_YCENT: // 'y'
			result = TM_TAG_YCENT_LEN;
			break;
		case TM_TAG_YDAY: // 'j'
			result = TM_TAG_YDAY_LEN;
			break;
		case TM_TAG_YEAR: // 'Y'
			result = TM_TAG_YEAR_LEN;
			break;
		default:
			result = TM_TAG_LEN;
			break;
	}

exit:
	return result;
}

_tm 
_wday(
	__in _tm year,
	__in _tm yday
	)
{
	_tm cent = (((year + TM_YEAR_MIN) & TM_MILLE) / 2);
	
	year %= TM_CENT;

	/*
	 * Calculate week day: wday(year, yday) = 
	 *	(mday + mon + (year % 100) + floor(year / 4) + 100) % 7
	 */
	return ((_mday(year, yday) + _mon(year, yday) + year 
		+ (_tm) floor((double) year / 4.0) + cent) % (TM_WDAY_MAX + 1));
}

_tm 
_week_num(
	__in _tm yday,
	__in _tm wday
	)
{
	_tm result = ((yday - wday) + 10) / 7;

	/*
	 * Calculate week number: wnum(yday, wday) = ((yday - wday) + 10) / 7,
	 *	if wnum < 1, wnum = 52; if wnum > 52, wnum = 1
	 */
	if(result < TM_WEEK_MIN) {
		result = TM_WEEK_MAX;
	} else if(result > TM_WEEK_MAX) {
		result = TM_WEEK_MIN;
	}

	return result;
}

char *
asctime(
	__in const struct tm *timeptr
	)
{
	/*sprintf(tm_ascstr, "%.3s %.3s %02u %02u:%02u:%02u %04u\n", 
		TM_WDAY_STRING(timeptr->tm_wday),
		TM_MON_STRING(timeptr->tm_mon),
		timeptr->tm_mday,
		timeptr->tm_hour,
		timeptr->tm_min,
		timeptr->tm_sec,
		timeptr->tm_year + TM_YEAR_MIN
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
	__in time_t next,
	__in time_t prev
	)
{
	return (double) (next > prev) ? (next - prev) : (-1 * (prev - next));
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

	memset(&tm_timeptr, 0, sizeof(struct tm));

	/*
	 * Calculate years: year(t) = sum(ydays_in(n + 1900) * sec_per_day),
		where 0 <= n <= M
	 */
	while(rem > TM_SEC_PER_YEAR) {
		rem -= (TM_YEAR_DAY(tm_timeptr.tm_year + TM_YEAR_MIN) 
			* TM_SEC_PER_DAY);
		tm_timeptr.tm_year++;
	}

	// offset year by unix epoch (01/01/1970)
	tm_timeptr.tm_year += TM_EPOCH_START;

	/*
	 * Calculate year days (< 1 year): yday(t) = sum(n * sec_per_day),
		where 0 <= n <= M
	 */
	while(rem > TM_SEC_PER_DAY) {
		rem -= TM_SEC_PER_DAY;
		tm_timeptr.tm_yday++;
	}

	/*
	 * Calculate hours (< 1 day): hour(t) = sum(n * sec_per_hour),
		where 0 <= n <= M
	 */
	while(rem > TM_SEC_PER_HOUR) {
		rem -= TM_SEC_PER_HOUR;
		tm_timeptr.tm_hour++;
	}

	/*
	 * Calculate minutes (< 1 hour): min(t) = sum(n * sec_per_min),
		where 0 <= n <= M
	 */
	while(rem > TM_SEC_PER_MIN) {
		rem -= TM_SEC_PER_MIN;
		tm_timeptr.tm_min++;
	}

	// set seconds to remainder of t
	tm_timeptr.tm_sec = rem;

	// calculate the remaining members using previously collected year and year day
	tm_timeptr.tm_mon = _mon(tm_timeptr.tm_year, tm_timeptr.tm_yday);
	tm_timeptr.tm_mday = _mday(tm_timeptr.tm_year, tm_timeptr.tm_yday);
	tm_timeptr.tm_wday = _wday(tm_timeptr.tm_year, tm_timeptr.tm_yday);

exit:
	return (*timer < 0) ? NULL : &tm_timeptr;
}

struct tm *
localtime(
	__in const time_t *timer
	)
{

	/*
	 * Calculate localtime(t) = gmtime(t) - time zone offset
	 */
	time_t loc = *timer - (locale.time.offset * TM_SEC_PER_HOUR);
	return gmtime(&loc);
}

time_t 
mktime(
	__inout struct tm *timeptr
	)
{
	time_t iter = TM_EPOCH_START, leap = 0, result = 0;

	// determine the number of leap days that must be added between 1900 and t
	for(; iter <= timeptr->tm_year; ++iter) {

		if(TM_YEAR_LEAP(TM_YEAR_MIN + iter)) {
			++leap;
		}
	}

	/*
	 * Calculate time(t) = ((year - 1970) * sec_per_year)
	 * 	+ ((year days + leap days + 1) * sec_per_day)
		+ ((hours * sec_per_hour)
		+ ((minutes * sec_per_minute)
		+ seconds
	 */
	result = (((timeptr->tm_year - TM_EPOCH_START) * TM_SEC_PER_YEAR)
		+ ((timeptr->tm_yday + leap + 1) * TM_SEC_PER_DAY)
		+ (timeptr->tm_hour * TM_SEC_PER_HOUR)
		+ (timeptr->tm_min * TM_SEC_PER_MIN)
		+ timeptr->tm_sec);

	// remove an hour if DST is active
	if(timeptr->tm_isdst) {
		result -= TM_SEC_PER_HOUR;
	}

	// offset for local time zone
	result -= (locale.time.offset * TM_SEC_PER_HOUR);

	return (result < 0) ? _INV(time_t) : result;
}

size_t 
strftime(
	__inout char *buf,
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

		// supported tag
		if(*ch == TM_TAG) {
			++ch;

			if(*ch == EOF) {
				goto exit;
			} else if(*ch == TM_TAG_MON_FULL) {
				hint = timeptr->tm_mon;
			} else if(*ch == TM_TAG_WDAY_FULL) {
				hint = timeptr->tm_wday;
			} else {
				hint = 0;
			}

			// determine required space for tag
			fill = _strftime_len(*ch, hint);
			if((result + fill) > (maxsize - 1)) {
				goto exit;
			}

			result += fill;

			switch(*ch) {
				case TM_TAG: // %
					*buf = *ch;
					break;
				case TM_TAG_ABBREV_MON: // 'b'
					strcpy(buf, TM_MON_STRING(timeptr->tm_mon));
					break;
				case TM_TAG_ABBREV_WDAY: // 'a'
					strcpy(buf, TM_WDAY_STRING(timeptr->tm_wday));
					break;
				case TM_TAG_AM_PM: // 'p'
					strcpy(buf, (timeptr->tm_hour >= 12) ? TM_PM : TM_AM);
					break;
				case TM_TAG_DATE: // 'x'
					/*sprintf(buf, "%.3s %02u %04u", 
						TM_MON_STRING(timeptr->tm_mon),
						timeptr->tm_mday,
						timeptr->tm_year + TM_YEAR_MIN
						);*/
					break;
				case TM_TAG_DATE_TIME: // 'c'
					/*sprintf(buf, "%.3s %02u %02u:%02u:%02u %04u", 
						TM_MON_STRING(timeptr->tm_mon),
						timeptr->tm_mday,
						timeptr->tm_hour,
						timeptr->tm_min,
						timeptr->tm_sec,
						timeptr->tm_year + TM_YEAR_MIN
						);*/
					break;
				case TM_TAG_HOUR_12: // 'I'
					//sprintf(buf, "%02u", timeptr->tm_hour % 12);
					break;
				case TM_TAG_HOUR_24: // 'H'
					//sprintf(buf, "%02u", timeptr->tm_hour);
					break;
				case TM_TAG_MIN: // 'M'
					//sprintf(buf, "%02u", timeptr->tm_min);
					break;
				case TM_TAG_MON: // 'm'
					//sprintf(buf, "%02u", timeptr->tm_mon + 1);
					break;
				case TM_TAG_MON_DAY_ZERO: // 'd'
					//sprintf(buf, "%02u", timeptr->tm_mday);
					break;
				case TM_TAG_MON_FULL: // 'B'
					strcpy(buf, TM_MON_STRING_FULL(timeptr->tm_mon));
					break;
				case TM_TAG_SEC: // 'S'
					//sprintf(buf, "%02u", timeptr->tm_sec);
					break;
				case TM_TAG_TIME: // 'X'
					/*sprintf(buf, "%02u:%02u:%02u", 
						timeptr->tm_hour, 
						timeptr->tm_min, 
						timeptr->tm_sec
						);*/
					break;
				case TM_TAG_TZONE: // 'Z'
					strcpy(buf, locale.time.name);
					break;
				case TM_TAG_WDAY: // 'w'
					//sprintf(buf, "%02u", timeptr->tm_wday);
					break;
				case TM_TAG_WDAY_FULL: // 'A'
					strcpy(buf, TM_WDAY_STRING_FULL(timeptr->tm_wday));
					break;
				case TM_TAG_WMONDAY: // 'W'
					/*sprintf(buf, "%02u", _week_num(timeptr->tm_yday, 
						timeptr->tm_wday));*/
					break;
				case TM_TAG_WSUNDAY: // 'U'
					/*sprintf(buf, "%02u", _week_num(timeptr->tm_yday, 
						timeptr->tm_wday));*/
					break;
				case TM_TAG_YCENT: // 'y'
					//sprintf(buf, "%02u", (timeptr->tm_year + TM_YEAR_MIN) % 100);
					break;
				case TM_TAG_YDAY: // 'j'
					//sprintf(buf, "%03u", timeptr->tm_yday + 1);
					break;
				case TM_TAG_YEAR: // 'Y'
					//sprintf(buf, "%04u", timeptr->tm_year + TM_YEAR_MIN);
					break;
				default:
					*buf = *_UNKNOWN;
					break;
			}

			buf += fill;

		// unsupported tag added as character
		} else {
			*buf = *ch;
			++buf;
			++result;
		}

		++ch;
	}

	// fill remainder of input with EOF characters
	while((result + fill++) <= maxsize) {
		*buf = EOF;
		++buf;
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
	// TODO: sys call: set tm_time to current unix time

	if(timer) {
		*timer = tm_time;
	}

	return tm_time;
}
