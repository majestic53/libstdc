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

#include "../include/libdef.h"
#include "../include/stdint.h"
#include "../include/string.h"

#define EOF _eof

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
	size_t iter = 0;
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
