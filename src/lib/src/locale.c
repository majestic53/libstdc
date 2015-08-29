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

#include "../include/limits.h"
#include "../include/locale.h"
#include "../include/locdef.h"
#include "../include/string.h"

struct lconv *
localeconv(void)
{
	return (struct lconv *) &locale.conv;
}

int 
setlocale_collate(
	__in const struct lcinfo *info
	)
{
	int result = 1;

	if(!info) {
		result = 0;
		goto exit;
	}

	result = (memcpy(&locale.coll, &info->coll, sizeof(struct lccoll)) != NULL);

exit:
	return result;
}

int 
setlocale_ctype(
	__in const struct lcinfo *info
	)
{
	int result = 1;

	if(!info) {
		result = 0;
		goto exit;
	}

	result = (memcpy(&locale.type, &info->type, sizeof(struct lctype)) != NULL);

exit:
	return result;
}

int 
setlocale_monetary(
	__in const struct lcinfo *info
	)
{
	int result = 1;

	if(!info) {
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
setlocale_numeric(
	__in const struct lcinfo *info
	)
{
	int result = 1;

	if(!info) {
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
setlocale_time(
	__in const struct lcinfo *info
	)
{
	int result;

	if(!info) {
		result = 0;
		goto exit;
	}

	result = (memcpy(&locale.time, &info->time, sizeof(struct lctime)) != NULL);

exit:
	return result;
}

int 
setlocale_all(
	__in const struct lcinfo *info
	)
{
	int result;

	result = setlocale_collate(info);
	if(!result) {
		goto exit;
	}

	result = setlocale_ctype(info);
	if(!result) {
		goto exit;
	}

	result = setlocale_monetary(info);
	if(!result) {
		goto exit;
	}

	result = setlocale_numeric(info);
	if(!result) {
		goto exit;
	}

	result = setlocale_time(info);
	if(!result) {
		goto exit;
	}

exit:
	return result;
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
		result = lc_info_struct(LC_INFO_DEF)->name;
		goto exit;
	}

	for(; lc <= lc_info_max; ++lc) {

		info = (struct lcinfo *) lc_info_struct(lc);
		if(!strcmp(locale, info->name)) {
			break;
		}
	}

	if(lc > lc_info_max) {
		goto exit;
	}

	switch(category) {
		case LC_ALL:
			set = setlocale_all(info);
			break;
		case LC_COLLATE:
			set = setlocale_collate(info);
			break;
		case LC_CTYPE:
			set = setlocale_ctype(info);
			break;
		case LC_MONETARY:
			set = setlocale_monetary(info);
			break;
		case LC_NUMERIC:
			set = setlocale_numeric(info);
			break;
		case LC_TIME:
			set = setlocale_time(info);
			break;
		default:
			goto exit;
	}

	if(set) {
		result = (char *) info->name;
	}

exit:
	return result;
}
