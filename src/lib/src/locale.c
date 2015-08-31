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

#include "../include/errno.h"
#include "../include/limits.h"
#include "../include/locale.h"
#include "../include/locdef.h"
#include "../include/string.h"

int 
_set_coll(
	__in const struct lcinfo *info
	)
{
	int result = 1;

	if(!info) {
		errno = EINVAL;
		result = 0;
		goto exit;
	}

	result = (memcpy(&locale.coll, &info->coll, sizeof(struct lccoll)) != NULL);

exit:
	return result;
}

int 
_set_ctype(
	__in const struct lcinfo *info
	)
{
	int result = 1;

	if(!info) {
		errno = EINVAL;
		result = 0;
		goto exit;
	}

	result = (memcpy(&locale.type, &info->type, sizeof(struct lctype)) != NULL);

exit:
	return result;
}

int 
_set_mon(
	__in const struct lcinfo *info
	)
{
	int result = 1;

	if(!info) {
		errno = EINVAL;
		result = 0;
		goto exit;
	}

	locale.conv.int_curr_symbol = info->conv.int_curr_symbol;
	locale.conv.currency_symbol = info->conv.currency_symbol;
	locale.conv.mon_decimal_point = info->conv.mon_decimal_point;
	locale.conv.mon_thousands_sep = info->conv.mon_thousands_sep;
	locale.conv.mon_grouping = info->conv.mon_grouping;
	locale.conv.positive_sign = info->conv.positive_sign;
	locale.conv.negative_sign = info->conv.negative_sign;
	locale.conv.int_frac_digits = info->conv.int_frac_digits;
	locale.conv.frac_digits = info->conv.frac_digits;
	locale.conv.p_cs_precedes = info->conv.p_cs_precedes;
	locale.conv.p_sep_by_space = info->conv.p_sep_by_space;
	locale.conv.n_cs_precedes = info->conv.n_cs_precedes;
	locale.conv.n_sep_by_space = info->conv.n_sep_by_space;
	locale.conv.p_sign_posn = info->conv.p_sign_posn;
	locale.conv.n_sign_posn = info->conv.n_sign_posn;

exit:
	return result;
}

int 
_set_num(
	__in const struct lcinfo *info
	)
{
	int result = 1;

	if(!info) {
		errno = EINVAL;
		result = 0;
		goto exit;
	}

	locale.conv.decimal_point = info->conv.decimal_point;
	locale.conv.thousands_sep = info->conv.thousands_sep;
	locale.conv.grouping = info->conv.grouping;

exit:
	return result;
}

int 
_set_time(
	__in const struct lcinfo *info
	)
{
	int result;

	if(!info) {
		errno = EINVAL;
		result = 0;
		goto exit;
	}

	result = (memcpy(&locale.time, &info->time, sizeof(struct lctime)) != NULL);

exit:
	return result;
}

int 
_set_all(
	__in const struct lcinfo *info
	)
{
	int result;

	result = _set_coll(info);
	if(!result) {
		goto exit;
	}

	result = _set_ctype(info);
	if(!result) {
		goto exit;
	}

	result = _set_mon(info);
	if(!result) {
		goto exit;
	}

	result = _set_num(info);
	if(!result) {
		goto exit;
	}

	result = _set_time(info);
	if(!result) {
		goto exit;
	}

exit:
	return result;
}

struct lconv *
localeconv(void)
{
	return (struct lconv *) &locale.conv;
}

char *
setlocale(
	__in int category,
	__in const char *locale
	)
{	
	char *result = NULL;
	struct lcinfo *info = NULL;
	int lc = LC_INFO_DEF, set = 0;

	if(!locale) {
		errno = EINVAL;
		result = LC_INFO_STRUCT(LC_INFO_DEF)->name;
		goto exit;
	}

	for(; lc <= LC_INFO_MAX; ++lc) {

		info = (struct lcinfo *) LC_INFO_STRUCT(lc);
		if(!strcmp(locale, info->name)) {
			break;
		}
	}

	if(lc > LC_INFO_MAX) {
		errno = EINVAL;
		goto exit;
	}

	switch(category) {
		case LC_ALL:
			set = _set_time(info);
			break;
		case LC_COLLATE:
			set = _set_coll(info);
			break;
		case LC_CTYPE:
			set = _set_ctype(info);
			break;
		case LC_MONETARY:
			set = _set_mon(info);
			break;
		case LC_NUMERIC:
			set = _set_num(info);
			break;
		case LC_TIME:
			set = _set_time(info);
			break;
		default:
			errno = EINVAL;
			goto exit;
	}

	if(set) {
		result = (char *) info->name;
	}

exit:
	return result;
}
