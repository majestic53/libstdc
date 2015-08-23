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
#define NULL _null

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

// size_t definition
typedef __SIZE_TYPE__ size_t;

/*
 * Locate byte in memory block
 * @param s valid pointer to memory block
 * @param c byte value to locate
 * @param n number of bytes to search
 * @return a valid pointer to the first occurance of the byte
 * 	in the memory block, else returns NULL
 */
void *memchr(
	__in const void *s,
	__in int c,
	__in size_t n
	);

/*
 * Compare two memory blocks
 * @param s1 valid pointer to first memory block
 * @param s2 valid pointer to second memory block
 * @param n number of bytes to compare
 * @return 0 if both memory blocks are equal, else return non-zero:
 * 	<0 if non-matching byte s1[N] < s2[N]
 * 	>0 if non-matching byte s1[N] > s2[N]
 */
int memcmp(
	__in const void *s1,
	__in const void *s2,
	__in size_t n
	);

/*
 * Copy one memory block into another
 * @param s1 valid pointer to destination memory block
 * @param s2 valid pointer to source memory block
 * @param n number of bytes to copy
 * @return valid pointer to destination memory block
 */
void *memcpy(
	__inout void *s1,
	__in const void *s2,
	__in size_t n
	);

/*
 * Move one memory block into another
 * @param s1 valid pointer to destination memory block
 * @param s2 valid pointer to source memory block
 * @param n number of bytes to move
 * @return valid pointer to destination memory block
 */
void *memmove(
	__inout void *s1,
	__in const void *s2,
	__in size_t n
	);

/*
 * Fill memory block with byte value
 * @param s valid pointer to memory block
 * @param c byte value to fill
 * @param n number of bytes to fill
 * @return valid pointer to memory block
 */
void *memset(
	__inout void *s,
	__in int c,
	__in size_t n
	);

/*
 * Concatinate two strings
 * @param s1 valid pointer to a string
 * @param s2 valid pointer to a string
 * @return valid pointer to string
 */
char *strcat(
	__inout char *s1,
	__in const char *s2
	);

/*
 * Locate character in string
 * @param s valid pointer to a string
 * @param c character to locate
 * @return a valid pointer to the first occurance of the character
 * 	in the string, else returns NULL
 */
char *strchr(
	__in const char *s,
	__in int c
	);

/*
 * Determine span to character in string
 * @param s1 valid pointer to a string
 * @param s2 valid pointer to a string
 * @return length of the first string not contained in the second
 */
size_t strcspn(
	__in const char *s1,
	__in const char *s2
	);

int strcmp(
	__in const char *s1,
	__in const char *s2
	);

char *strcpy(
	__inout char *s1,
	__in const char *s2
	);

int strcoll(
	__in const char *s1,
	__in const char *s2
	);

char *strerror(
	__in int errnum
	);

size_t strlen(
	__in const char *s
	);

char *strncat(
	__inout char *s1,
	__in const char *s2,
	__in size_t n
	);

int strncmp(
	__in const char *s1,
	__in const char *s2,
	__in size_t n
	);

char *strncpy(
	__inout char *s1,
	__in const char *s2,
	__in size_t n
	);

char *strpbrk(
	__in const char *s1,
	__in const char *s2
	);

char *strrchr(
	__in const char *s,
	__in int c
	);

size_t strspn(
	__in const char *s1,
	__in const char *s2
	);

char *strstr(
	__in const char *s1,
	__in const char *s2
	);

char *strtok(
	__inout char *s1,
	__in const char *s2
	);

size_t strxfrm(
	__inout char *s1,
	__in const char *s2,
	__in size_t n
	);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // STRING_H_
