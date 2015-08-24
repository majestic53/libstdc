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
	}, \
}

// default locale
#define lc_info_usa { \
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
	}, \
}

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // LOCDEF_H_