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

#ifndef LOCALE_H_
#define LOCALE_H_

#include "libdef.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

// null definition
#define NULL _null

enum {
	LC_ALL = 0, // set everything
	LC_COLLATE, // affects scrcoll/strxfrm routines
	LC_CTYPE, // affects all char routines
	LC_MONETARY, // affects monetary formatting
	LC_NUMERIC, // affects decimal-point formatting
	LC_TIME, // affects strftime routine
};

enum {
	SIGN_POSN_ENCAP = 0, // encapsulates value and curreny_symbol
	SIGN_POSN_PREC, // sign precedes value and curreny_symbol
	SIGN_POSN_SUCC, // sign succeeds value and curreny_symbol
	SIGN_POSN_IMMED_PREC, // sign immediatly precedes value and curreny_symbol
	SIGN_POSN_IMMED_SUCC, // sign immediatly succeeds value and curreny_symbol
};

#ifndef _LCONV
#define _LCONV
struct lconv {
	char *decimal_point; // decimal point character
	char *thousands_sep; // thousands place seperator character
	char *grouping;	// amount of digits that format a thousands seperated group
	char *int_curr_symbol; // international currency symbol
	char *currency_symbol; // local currency symbol
	char *mon_decimal_point; // monetary decimal point character
	char *mon_thousands_sep; // monetary thousands place seperator character
	char *mon_grouping; // amount of digits that format a monetary thousands seperated group
	char *positive_sign; // sign used for non-negative monetary values
	char *negative_sign; // sign used for negative monetary values
	char int_frac_digits; // amount of digits to show after decimal point in international monetary values
	char frac_digits; // amount of digits to show after decimal point in monetary values
	char p_cs_precedes; // currency symbol preceeding non-negative monetary values
	char p_sep_by_space; // space between the currency symbol and non-negative monetary values
	char n_cs_precedes; // currency symbol preceeding negative monetary values
	char n_sep_by_space; // space between the currency symbol and negative monetary values
	char p_sign_posn; // position of sign for non-negative monetary values
	char n_sign_posn; // position of sign for negative monetary values
};

typedef struct lconv lconv;
#endif // _LCONV

/*
 * Retrieve locale information
 * @return a valid pointer to locale information
 */
struct lconv *localeconv(void);

/*
 * Set locale information
 * @param category locale category
 * @param locale locale designation string
 * @return current locale designation string on success, else returns NULL
 */
char *setlocale(
	__in int category,
	__in const char *locale
	);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // LOCALE_H_
