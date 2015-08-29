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
#define LCINFO_C { \
	"C", \
	{ \
	}, \
	{ \
	}, \
	{ \
		".", \
		_NULLSTR, \
		_NULLSTR, \
		_NULLSTR, \
		_NULLSTR, \
		_NULLSTR, \
		_NULLSTR, \
		_NULLSTR, \
		_NULLSTR, \
		_NULLSTR, \
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
#define LCINFO_USA_PST { \
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

#define LC_INFO_MAX LC_INFO_C

#ifndef _LCCOLL
#define _LCCOLL
struct lccoll { /* empty */ };
#endif // _LCCOLL

#ifndef _LCTIME
#define _LCTIME
struct lctime {
	char *name; // time zone name
	int offset; // time zone offset (from GMT)
};
#endif // _LCTIME

#ifndef _LCTYPE
#define _LCTYPE
struct lctype { /* empty */ };
#endif // _LCTYPE

#ifndef _LCINFO
#define _LCINFO
struct lcinfo {
	char *name; // locale name
	struct lccoll coll; // collate settings
	struct lctype type; // ctype settings
	struct lconv conv; // monetary/numeric settings
	struct lctime time; // time settings
};
#endif // _LCINFO

// supported locales
static const struct lcinfo lc_c = LCINFO_C;
static const struct lcinfo lc_def = LCINFO_USA_PST;
static struct lcinfo locale = LCINFO_USA_PST;

static const struct lcinfo *LC_INFO_ST[] = {
	&lc_c, &lc_def,
};

/*
 * Retrieve a valid pointer to a supported locale
 * @param _TYPE_ locale type
 */
#define LC_INFO_STRUCT(_TYPE_) \
	((_TYPE_) > LC_INFO_MAX ? LC_INFO_ST[LC_INFO_DEF] : \
	LC_INFO_ST[_TYPE_])

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // LOCDEF_H_
