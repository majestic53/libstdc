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

#include "../include/errdef.h"
#include "../include/stdint.h"
#include "../include/string.h"

#define EOF _eof

static char *strerr = NULL;

static char *token = NULL;

void *
memchr(
	__in const void *s,
	__in int c,
	__in size_t n
	)
{
	size_t iter = 0;
	uint8_t *result = (uint8_t *) s;

	for(; iter < n; ++iter, ++result) {

		if(*result == (uint8_t) c) {
			break;
		}
	}

	return (iter >= n) ? NULL : result;
}

int 
memcmp(
	__in const void *s1,
	__in const void *s2,
	__in size_t n
	)
{
	int result = 0;
	size_t iter = 0;
	int8_t *byte1 = (int8_t *) s1, *byte2 = (int8_t *) s2;

	for(; iter < n; ++iter, ++byte1, ++byte2) {

		result = (*byte1 - *byte2);
		if(result) {
			break;
		}
	}

	return (iter >= n) ? 0 : result;
}

void *
memcpy(
	__inout void *s1,
	__in const void *s2,
	__in size_t n
	)
{
	size_t iter = 0;
	uint8_t *byte1 = (uint8_t *) s1, *byte2 = (uint8_t *) s2;

	for(; iter < n; ++iter, ++byte1, ++byte2) {
		*byte1 = *byte2;
	}

	return s1;
}

void *
memmove(
	__inout void *s1,
	__in const void *s2,
	__in size_t n
	)
{
	size_t iter = 0;
	uint8_t *byte1 = (uint8_t *) s1, *byte2 = (uint8_t *) s2;

	for(; iter < n; ++iter, ++byte1, ++byte2) {
		*byte1 = *byte2;
	}

	return s1;
}

void *
memset(
	__inout void *s,
	__in int c,
	__in size_t n
	)
{
	size_t iter = 0;
	uint8_t *byte = (uint8_t *) s;

	for(; iter < n; ++iter, ++byte) {
		*byte = c;
	}

	return s;
}

char *
strcat(
	__inout char *s1,
	__in const char *s2
	)
{
	char *ch1 = (char *) s1, *ch2 = (char *) s2;

	while(*ch1 != EOF) {
		++ch1;
	}

	while(*ch2 != EOF) {
		*ch1 = *ch2;
		++ch1;
		++ch2;
	}

	*ch1 = EOF;

	return s1;
}

char *
strchr(
	__in const char *s,
	__in int c
	)
{
	char *result = (char *) s;

	while(*result != EOF) {

		if(*result == (char) c) {
			break;
		}
	}

	return (*result == EOF) ? NULL : result;
}

size_t 
strcspn(
	__in const char *s1,
	__in const char *s2
	)
{
	size_t result = 0;
	char *ch1 = (char *) s1, *ch2;

	while(*ch1 != EOF) {

		ch2 = (char *) s2;
		while(*ch2 != EOF) {

			if(*ch1 == *ch2) {
				goto exit;
			}

			++ch2;
		}

		++ch1;
		++result;
	}

exit:
	return result;
}

int 
strcmp(
	__in const char *s1,
	__in const char *s2
	)
{
	int result = 0;
	char *ch1 = (char *) s1, *ch2 = (char *) s2;

	while(*ch1 != EOF) {

		result = (*ch1 - *ch2);
		if(result) {
			break;
		}

		++ch1;
		++ch2;
	}

	return (*ch1 == EOF) ? 0 : result;
}

char *
strcpy(
	__inout char *s1,
	__in const char *s2
	)
{
	char *ch1 = (char *) s1, *ch2 = (char *) s2;

	while(*ch2 != EOF) {
		*ch1 = *ch2;
		++ch1;
		++ch2;
	}

	return s1;
}

int 
strcoll(
	__in const char *s1,
	__in const char *s2
	)
{
	return strcmp(s1, s2);
}

char *
strerror(
	__in int errnum
	)
{
	switch(errnum) {
		case EDOM:
			strerr = EDOM_STR;
			break;
		case ERANGE:
			strerr = ERANGE_STR;
			break;
		default:
			strerr = _nullstr;
	}

	return strerr;
}

size_t 
strlen(
	__in const char *s
	)
{
	size_t result = 0;
	char *ch = (char *) s;

	while(*ch != EOF) {
		++result;
		++ch;
	}

	return result;
}

char *
strncat(
	__inout char *s1,
	__in const char *s2,
	__in size_t n
	)
{
	char *ch1 = (char *) s1, *ch2 = (char *) s2;

	while(*ch1 != EOF) {
		++ch1;
	}

	while((*ch2 != EOF) && n) {
		*ch1 = *ch2;
		++ch1;
		++ch2;
		--n;
	}

	*ch1 = EOF;

	return s1;
}

int 
strncmp(
	__in const char *s1,
	__in const char *s2,
	__in size_t n
	)
{
	int result = 0;
	char *ch1 = (char *) s1, *ch2 = (char *) s2;

	while((*ch1 != EOF) && n) {

		result = (*ch1 - *ch2);
		if(result) {
			break;
		}

		++ch1;
		++ch2;
		--n;
	}

	return (*ch1 == EOF) ? 0 : result;
}

char *
strncpy(
	__inout char *s1,
	__in const char *s2,
	__in size_t n
	)
{
	char *ch1 = (char *) s1, *ch2 = (char *) s2;

	while(*ch2 != EOF) {
		*ch1 = *ch2;
		++ch1;
		++ch2;
	}

	while(n) {
		*ch1 = EOF;
		++ch1;
		--n;
	}

	return s1;
}

char *
strpbrk(
	__in const char *s1,
	__in const char *s2
	)
{
	char *ch1 = (char *) s1, *ch2;

	while(*ch1 != EOF) {

		ch2 = (char *) s2;
		while(*ch2 != EOF) {

			if(*ch1 == *ch2) {
				goto exit;
			}

			++ch2;
		}

		++ch1;
	}

exit:
	return (*ch1 == EOF) ? NULL : ch1;
}

char *
strrchr(
	__in const char *s,
	__in int c
	)
{
	char *ch = (char *) s, *result = NULL;

	while(*ch != EOF) {

		if(*ch == (char) c) {
			result = ch;
		}

		++ch;
	}

	return result;
}

size_t 
strspn(
	__in const char *s1,
	__in const char *s2
	)
{
	size_t result = 0;
	char *ch1 = (char *) s1, *ch2;

	while(*ch1 != EOF) {

		ch2 = (char *) s2;
		while(*ch2 != EOF) {

			if(*ch1 == *ch2) {
				++result;
				break;
			}

			++ch2;
		}

		if(*ch2 == EOF) {
			goto exit;
		}

		++ch1;
	}

exit:
	return result;
}

#include <stdio.h>

char *
strstr(
	__in const char *s1,
	__in const char *s2
	)
{
	char *ch1 = (char *) s1, *ch2, *chk1;

	while(*ch1 != EOF) {

		ch2 = (char *) s2;
		if(*ch1 == *ch2) {

			chk1 = ch1;
			while(chk1 != EOF) {

				if(*chk1 != *ch2) {
					break;
				}

				++ch2;
				if(*ch2 == EOF) {
					goto exit;
				}

				++chk1;
			}
		}

		++ch1;
	}

exit:
	return (*ch1 == EOF) ? NULL : ch1;
}

char *
strtok(
	__inout char *s1,
	__in const char *s2
	)
{
	char *result = NULL;

	if(s1) {
		token = s1;
	}

	token += strspn(token, s2);
	if(*token == EOF) {
		token = NULL;
		goto exit;
	}

	result = token;
	token = strpbrk(token, s2);
	*token = EOF;
	++token;

exit:
	return result;
}

size_t 
strxfrm(
	__inout char *s1,
	__in const char *s2,
	__in size_t n
	)
{
	size_t result = 0;

	if(!s1 && n) {
		result = strlen(s2);
		goto exit;
	}

	if(strncpy(s1, s2, n)) {
		result = strlen(s1);
	}

exit:
	return result;
}
