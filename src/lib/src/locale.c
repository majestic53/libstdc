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

enum {
	LC_INFO_DEF = 0,
	LC_INFO_C,
};

#define lc_info_max LC_INFO_C

typedef struct __attribute__((__packed__)) {
	// TODO: add collate changes
} lccoll;

typedef struct __attribute__((__packed__)) {
	// TODO: add time changes
} lctime;

typedef struct __attribute__((__packed__)) {
	// TODO: add ctype changes
} lctype;

typedef struct __attribute__((__packed__)) {
	char *name; // locale name
	lccoll coll; // collate settings
	lctype type; // ctype settings
	lconv conv; // monetary/numeric settings
	lctime time; // time settings
} lcinfo;

static const lcinfo lc_c = lc_info_c;
static const lcinfo lc_def = lc_info_usa;

static const lcinfo *lc_info_st[] = {
	&lc_c, &lc_def,
};

#define lc_info_struct(type) \
	((type) > lc_info_max ? lc_info_st[0] : \
	lc_info_st[type])

static lcinfo _locale = lc_info_usa;

struct lconv *
localeconv(void)
{
	return (struct lconv *) &_locale.conv;
}

int 
setlocale_collate(
	__in const lcinfo *info
	)
{
	int result = 1;

	if(!info) {
		result = 0;
		goto exit;
	}

	// TODO: add collate changes

exit:
	return result;
}

int 
setlocale_ctype(
	__in const lcinfo *info
	)
{
	int result = 1;

	if(!info) {
		result = 0;
		goto exit;
	}

	// TODO: add ctype changes

exit:
	return result;
}

int 
setlocale_monetary(
	__in const lcinfo *info
	)
{
	int result = 1;

	if(!info) {
		result = 0;
		goto exit;
	}

	_locale.conv.int_curr_symbol = info->conv.int_curr_symbol;
	_locale.conv.currency_symbol = info->conv.currency_symbol;
	_locale.conv.mon_decimal_point = info->conv.mon_decimal_point;
	_locale.conv.mon_thousands_sep = info->conv.mon_thousands_sep;
	_locale.conv.mon_grouping = info->conv.mon_grouping;
	_locale.conv.positive_sign = info->conv.positive_sign;
	_locale.conv.negative_sign = info->conv.negative_sign;
	_locale.conv.int_frac_digits = info->conv.int_frac_digits;
	_locale.conv.frac_digits = info->conv.frac_digits;
	_locale.conv.p_cs_precedes = info->conv.p_cs_precedes;
	_locale.conv.p_sep_by_space = info->conv.p_sep_by_space;
	_locale.conv.n_cs_precedes = info->conv.n_cs_precedes;
	_locale.conv.n_sep_by_space = info->conv.n_sep_by_space;
	_locale.conv.p_sign_posn = info->conv.p_sign_posn;
	_locale.conv.n_sign_posn = info->conv.n_sign_posn;

exit:
	return result;
}

int 
setlocale_numeric(
	__in const lcinfo *info
	)
{
	int result = 1;

	if(!info) {
		result = 0;
		goto exit;
	}

	_locale.conv.decimal_point = info->conv.decimal_point;
	_locale.conv.thousands_sep = info->conv.thousands_sep;
	_locale.conv.grouping = info->conv.grouping;

exit:
	return result;
}

int 
setlocale_time(
	__in const lcinfo *info
	)
{
	int result = 1;

	if(!info) {
		result = 0;
		goto exit;
	}

	// TODO: add time changes

exit:
	return result;
}

int 
setlocale_all(
	__in const lcinfo *info
	)
{
	int result = 1;

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
	lcinfo *info = NULL;
	int lc = LC_INFO_DEF, set = 0;

	if(!locale) {
		result = lc_info_struct(LC_INFO_DEF)->name;
		goto exit;
	}

	for(; lc <= lc_info_max; ++lc) {

		info = (lcinfo *) lc_info_struct(lc);
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
