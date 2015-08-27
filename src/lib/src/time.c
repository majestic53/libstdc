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

//#include "../include/stdio.h"
#include "../include/string.h"
#include "../include/time.h"
#include "../include/timedef.h"

#define EOF _eof

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
				result = strlen(mon_full_string(hint));
			} else {
				result = tm_tag_full_mon_len;
			}
			break;
		case tm_tag_full_wday: // 'A'

			if((hint >= tm_wday_min) && (hint <= tm_wday_max)) {
				result = strlen(wday_full_string(hint));
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

char *
asctime(
	__in const tm *timeptr
	)
{
	/*sprintf(asc_str, "%s %s %02u %02u:%02u:%02u %04u\n", 
		wday_string(timeptr->tm_wday),
		mon_string(timeptr->tm_mon),
		timeptr->tm_mday,
		timeptr->tm_hour,
		timeptr->tm_min,
		timeptr->tm_sec,
		timeptr->tm_year + tm_year_min
		);*/
		
	return asc_str;
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
	time0 -= epoch_offset;
	time1 -= epoch_offset;

	return (double) (time1 > time0) ? (time1 - time0) : (-1 * (time0 - time1));
}

tm *
gmtime(
	__in const time_t *timer
	)
{
	// TODO

	return &tm_time;
}

tm *
localtime(
	__in const time_t *timer
	)
{
	// TODO

	return &tm_time;
}

time_t 
mktime(
	__inout tm *timeptr
	)
{
	time_t result;

	// TODO
	result = 0;
	// ---

	return result;
}

size_t 
strftime(
	__inout char *s,
	__in size_t maxsize,
	__in const char *format,
	__in const tm *timeptr
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

			fill = _strftime_len(*ch, hint);
			if((result + fill) > (maxsize - 1)) {
				goto exit;
			}

			result += fill;

			switch(*ch) {
				case tm_tag: // %
					*s = *ch;
					break;
				case tm_tag_abbrev_mon: // 'b'
					strcpy(s, mon_string(timeptr->tm_mon));
					break;
				case tm_tag_abbrev_wday: // 'a'
					strcpy(s, wday_string(timeptr->tm_wday));
					break;
				case tm_tag_am_pm: // 'p'

					// TODO
					break;
				case tm_tag_date: // 'x'

					// TODO
					break;
				case tm_tag_date_time: // 'c'

					// TODO
					break;
				case tm_tag_full_mon: // 'B'
					strcpy(s, mon_full_string(timeptr->tm_mon));
					break;
				case tm_tag_full_wday: // 'A'
					strcpy(s, wday_full_string(timeptr->tm_wday));
					break;
				case tm_tag_hour_12: // 'I'

					// TODO
					break;
				case tm_tag_hour_24: // 'H'

					// TODO
					break;
				case tm_tag_mon_day_zero: // 'd'

					// TODO
					break;
				case tm_tag_min: // 'M'

					// TODO
					break;
				case tm_tag_mon: // 'm'

					// TODO
					break;
				case tm_tag_sec: // 'S'

					// TODO
					break;
				case tm_tag_time: // 'X'

					// TODO
					break;
				case tm_tag_tzone: // 'Z'

					// TODO
					break;
				case tm_tag_wday: // 'w'

					// TODO
					break;
				case tm_tag_wmonday: // 'W'

					// TODO
					break;
				case tm_tag_wsunday: // 'U'

					// TODO
					break;
				case tm_tag_ycent: // 'y'

					// TODO
					break;
				case tm_tag_yday: // 'j'

					// TODO
					break;
				case tm_tag_year: // 'Y'

					// TODO
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
	// TODO: set cur_time

	if(timer) {
		*timer = cur_time;
	}

	return cur_time;
}
