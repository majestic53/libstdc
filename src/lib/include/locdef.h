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

#ifndef LOCDEF_H_
#define LOCDEF_H_

#include "ctype.h"
#include "limits.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

// minimal locale
#define lc_info_c { \
	"C", \
	{ \
	}, \
	{ \
	}, \
	{ \
		".", \
		_nullstr, \
		_nullstr, \
		_nullstr, \
		_nullstr, \
		_nullstr, \
		_nullstr, \
		_nullstr, \
		_nullstr, \
		_nullstr, \
		CHAR_MAX, \
		CHAR_MAX, \
		CHAR_MAX, \
		CHAR_MAX, \
		CHAR_MAX, \
		CHAR_MAX, \
		CHAR_MAX, \
		CHAR_MAX, \
	}, \
	{ \
		"GMT", \
		0, \
	}, \
}

// default locale
#define lc_info_usa_pst { \
	"", \
	{ \
	}, \
	{ \
	}, \
	{ \
		".", \
		",", \
		"\3", \
		"USD", \
		"$", \
		".", \
		",", \
		"\3", \
		"+", \
		"-", \
		2, \
		2, \
		1, \
		0, \
		1, \
		0, \
		SIGN_POSN_IMMED_PREC, \
		SIGN_POSN_IMMED_PREC, \
	}, \
	{ \
		"PST", \
		-8, \
	}, \
}

enum {
	LC_INFO_DEF = 0, // default locale
	LC_INFO_C, // c locale
};

#define lc_info_max LC_INFO_C

typedef struct {
	// TODO: add collate members
} lccoll;

typedef struct {
	char tzone[_tzone_len]; // time zone
	int tzone_off; // time zone offset (from GMT)
	// TODO: add time members
} lctime;

typedef struct {
	// TODO: add ctype members
} lctype;

typedef struct {
	char *name; // locale name
	lccoll coll; // collate settings
	lctype type; // ctype settings
	lconv conv; // monetary/numeric settings
	lctime time; // time settings
} lcinfo;

// supported locales
static const lcinfo lc_c = lc_info_c;
static const lcinfo lc_def = lc_info_usa_pst;
static lcinfo locale = lc_info_usa_pst;

static const lcinfo *lc_info_st[] = {
	&lc_c, &lc_def,
};

/*
 * Retrieve a valid pointer to a supported locale
 * @param type locale type
 */
#define lc_info_struct(type) \
	((type) > lc_info_max ? lc_info_st[0] : \
	lc_info_st[type])

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // LOCDEF_H_
