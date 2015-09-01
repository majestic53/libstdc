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

#ifndef STRING_H_
#define STRING_H_

#include "libdef.h"

// null definition
#define NULL _NULL

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

// size_t definition
#ifndef _SIZE_T
#define _SIZE_T
typedef _size_t size_t;
#endif // _SIZE_T

/*
 * Locate byte in memory block
 * @param src valid pointer to memory block
 * @param byte byte value to locate
 * @param max number of bytes to search
 * @return a valid pointer to the first occurance of the byte
 * 	in the memory block, else returns NULL
 */
void *memchr(
	__in const void *src,
	__in int byte,
	__in size_t max
	);

/*
 * Compare two memory blocks
 * @param src1 valid pointer to first memory block
 * @param src2 valid pointer to second memory block
 * @param max number of bytes to compare
 * @return 0 if both memory blocks are equal, else return non-zero:
 * 	<0 if non-matching byte s1[N] < s2[N]
 * 	>0 if non-matching byte s1[N] > s2[N]
 */
int memcmp(
	__in const void *src1,
	__in const void *src2,
	__in size_t max
	);

/*
 * Copy one memory block into another
 * @param dest valid pointer to destination memory block
 * @param src valid pointer to source memory block
 * @param max number of bytes to copy
 * @return valid pointer to destination memory block
 */
void *memcpy(
	__inout void *dest,
	__in const void *src,
	__in size_t max
	);

/*
 * Move one memory block into another
 * @param dest valid pointer to destination memory block
 * @param src valid pointer to source memory block
 * @param max number of bytes to move
 * @return valid pointer to destination memory block
 */
void *memmove(
	__inout void *dest,
	__in const void *src,
	__in size_t max
	);

/*
 * Fill memory block with byte value
 * @param dest valid pointer to memory block
 * @param byte byte value to fill
 * @param max number of bytes to fill
 * @return valid pointer to memory block
 */
void *memset(
	__inout void *dest,
	__in int byte,
	__in size_t max
	);

/*
 * Concatinate two strings
 * @param dest valid pointer to destination string
 * @param src valid pointer to source string
 * @return valid pointer to destination string
 */
char *strcat(
	__inout char *dest,
	__in const char *src
	);

/*
 * Locate character in string
 * @param src valid pointer to string
 * @param ch character to locate
 * @return a valid pointer to the first occurance of the character
 * 	in the string, else returns NULL
 */
char *strchr(
	__in const char *src,
	__in int ch
	);

/*
 * Determine span to character in string
 * @param src1 valid pointer to first string
 * @param src2 valid pointer to second string
 * @return length of the first string not contained in the second
 */
size_t strcspn(
	__in const char *src1,
	__in const char *src2
	);

/*
 * Compare two strings
 * @param src1 valid pointer to first string
 * @param src2 valid pointer to second string
 * @return 0 if both strings are equal, else return non-zero:
 * 	<0 if non-matching character s1[N] < s2[N]
 * 	>0 if non-matching character s1[N] > s2[N]
 */
int strcmp(
	__in const char *src1,
	__in const char *src2
	);

/*
 * Copy one string into another
 * @param dest valid pointer to destination string
 * @param src valid pointer to source string
 * @return valid pointer to destination string
 */
char *strcpy(
	__inout char *dest,
	__in const char *src
	);

/*
 * Compare two strings using locale
 * @param src1 valid pointer to first string
 * @param src2 valid pointer to second string
 * @return 0 if both strings are equal, else return non-zero:
 * 	<0 if non-matching character s1[N] < s2[N]
 * 	>0 if non-matching character s1[N] > s2[N]
 */
int strcoll(
	__in const char *src1,
	__in const char *src2
	);

/*
 * Retrieve a string representation of an error code
 * @param err error code to retrieve
 * @return valid pointer to string representation of errnum
 */
char *strerror(
	__in int err
	);

/*
 * Determine the character length of a string
 * @param src valid pointer to string
 * @return character length of string
 */
size_t strlen(
	__in const char *src
	);

/*
 * Append a string to another
 * @param dest valid pointer to destination string
 * @param src valid pointer to source string
 * @param max maximum number of character to copy, up to terminating character
 * @return valid pointer to destination string
 */
char *strncat(
	__inout char *dest,
	__in const char *src,
	__in size_t max
	);

/*
 * Compare two strings
 * @param src1 valid pointer to first string
 * @param src2 valid pointer to second string
 * @param max maximum number of character to compare, up to terminating character
 * @return 0 if both strings are equal, else return non-zero:
 * 	<0 if non-matching character s1[N] < s2[N]
 * 	>0 if non-matching character s1[N] > s2[N]
 */
int strncmp(
	__in const char *src1,
	__in const char *src2,
	__in size_t max
	);

/*
 * Copy one string into another
 * @param dest valid pointer to destination string
 * @param src valid pointer to source string
 * @param max maximum number of characters to copy, up to terminating character
 * @return valid pointer to destination string
 */
char *strncpy(
	__inout char *dest,
	__in const char *src,
	__in size_t max
	);

/*
 * Locate first occurrence of character in string
 * @param src1 valid pointer to first string
 * @param src2 valid pointer to second string
 * @return valid pointer to first occurrence of character, else returns NULL
 */
char *strpbrk(
	__in const char *src1,
	__in const char *src2
	);

/*
 * Locate last occurrence of character in string
 * @param src valid pointer to string
 * @param ch character to locate
 * @return valid pointer to last occurrence of character, else returns NULL
 */
char *strrchr(
	__in const char *src,
	__in int ch
	);

/*
 * Determine span to character in string
 * @param src1 valid pointer to first string
 * @param src2 valid pointer to second string
 * @return length of the first string contained in the second
 */
size_t strspn(
	__in const char *src1,
	__in const char *src2
	);

/*
 * Locate a substring in string
 * @param src1 valid pointer to string
 * @param src2 valid pointer to matching string
 * @return valid pointer to substring, else return NULL
 */
char *strstr(
	__in const char *src1,
	__in const char *src2
	);

/*
 * Split string into tokens using supplied delimiter
 * @param src valid pointer to string
 * @param delim valid pointer to delimiter string
 * @return valid pointer to token substring, else return NULL
 */
char *strtok(
	__inout char *src,
	__in const char *delim
	);

/*
 * Transform string using locale
 * @param dest valid pointer to destination string
 * @param src valid pointer to source string
 * @param max maximum number of characters to copy
 * @return length of the destination string
 */
size_t strxfrm(
	__inout char *dest,
	__in const char *src,
	__in size_t max
	);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // STRING_H_
