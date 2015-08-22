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

#define NULL _null

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

typedef unsigned int size_t;

void *memchr(
	__in const void *s,
	__in int c,
	__in size_t n
	);

int memcmp(
	__in const void *s1,
	__in const void *s2,
	__in size_t n
	);

void *memcpy(
	__in void *s1,
	__in const void *s2,
	__in size_t n
	);

void *memmove(
	__inout void *s1,
	__in const void *s2,
	__in size_t n
	);

void *memset(
	__inout void *s,
	__in int c,
	__in size_t n
	);

char *strcat(
	__inout char *s1,
	__in const char *s2
	);

char *strchr(
	__in const char *s,
	__in size_t c
	);

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
	__in char *s1,
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
