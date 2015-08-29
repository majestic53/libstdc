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

#ifndef CTYPE_H_
#define CTYPE_H_

#include "libdef.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/*
 * Check if character is alphanumeric
 * @param ch character to be checked
 * @return non-zero if character is alphanumeric, else returns 0
 */
int isalnum(
	__in int ch
	);

/*
 * Check if character is alphabetical
 * @param ch character to be checked
 * @return non-zero if character is alphabetical, else returns 0
 */
int isalpha(
	__in int ch
	);

/*
 * Check if character is a control character
 * @param ch character to be checked
 * @return non-zero if character is a control character, else returns 0
 */
int iscntrl(
	__in int ch
	);

/*
 * Check if character is a digit
 * @param ch character to be checked
 * @return non-zero if character is a digit, else returns 0
 */
int isdigit(
	__in int ch
	);

/*
 * Check if character is graphical
 * @param ch character to be checked
 * @return non-zero if character is graphical, else returns 0
 */
int isgraph(
	__in int ch
	);

/*
 * Check if character is lower case
 * @param ch character to be checked
 * @return non-zero if character is lower case, else returns 0
 */
int islower(
	__in int ch
	);

/*
 * Check if character is printable
 * @param ch character to be checked
 * @return non-zero if character is printable, else returns 0
 */
int isprint(
	__in int ch
	);

/*
 * Check if character is punctuation
 * @param ch character to be checked
 * @return non-zero if character is punctuation, else returns 0
 */
int ispunct(
	__in int ch
	);

/*
 * Check if character is whitespace
 * @param ch character to be checked
 * @return non-zero if character is whitespace, else returns 0
 */
int isspace(
	__in int ch
	);

/*
 * Check if character is upper case
 * @param ch character to be checked
 * @return non-zero if character is upper case, else returns 0
 */
int isupper(
	__in int ch
	);

/*
 * Check if character is a hexadecimal digit
 * @param ch character to be checked
 * @return non-zero if character is a hexadecimal digit, else returns 0
 */
int isxdigit(
	__in int ch
	);

/*
 * Convert a character to lower case
 * @param ch character to be converted
 * @return character converted to lower case if such a character exists, 
 * 	else character is unchanged
 */
int tolower(
	__in int ch
	);

/*
 * Convert a character to upper case
 * @param ch character to be converted
 * @return character converted to upper case if such a character exists, 
 * 	else character is unchanged
 */
int toupper(
	__in int ch
	);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // CTYPE_H_
