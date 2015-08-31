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

#define EOF _EOF

static char *strerr = NULL;
static char *token = NULL;

void *
memchr(
	__in const void *src,
	__in int byte,
	__in size_t max
	)
{
	size_t iter = 0;
	uint8_t *result = (uint8_t *) src;

	for(; iter < max; ++iter, ++result) {

		if(*result == (uint8_t) byte) {
			break;
		}
	}

	return (iter >= max) ? NULL : result;
}

int 
memcmp(
	__in const void *src1,
	__in const void *src2,
	__in size_t max
	)
{
	int result = 0;
	size_t iter = 0;
	int8_t *byte1 = (int8_t *) src1, *byte2 = (int8_t *) src2;

	for(; iter < max; ++iter, ++byte1, ++byte2) {

		result = (*byte1 - *byte2);
		if(result) {
			break;
		}
	}

	return (iter >= max) ? 0 : result;
}

void *
memcpy(
	__inout void *dest,
	__in const void *src,
	__in size_t max
	)
{
	size_t iter = 0;
	uint8_t *byte1 = (uint8_t *) dest, *byte2 = (uint8_t *) src;

	for(; iter < max; ++iter, ++byte1, ++byte2) {
		*byte1 = *byte2;
	}

	return dest;
}

void *
memmove(
	__inout void *dest,
	__in const void *src,
	__in size_t max
	)
{
	size_t iter = 0;
	uint8_t *byte1 = (uint8_t *) dest, *byte2 = (uint8_t *) src;

	for(; iter < max; ++iter, ++byte1, ++byte2) {
		*byte1 = *byte2;
	}

	return dest;
}

void *
memset(
	__inout void *dest,
	__in int byte,
	__in size_t max
	)
{
	size_t iter = 0;
	uint8_t *byte1 = (uint8_t *) dest;

	for(; iter < max; ++iter, ++byte1) {
		*byte1 = byte;
	}

	return dest;
}

char *
strcat(
	__inout char *dest,
	__in const char *src
	)
{
	char *ch1 = (char *) dest, *ch2 = (char *) src;

	while(*ch1 != EOF) {
		++ch1;
	}

	while(*ch2 != EOF) {
		*ch1 = *ch2;
		++ch1;
		++ch2;
	}

	*ch1 = EOF;

	return dest;
}

char *
strchr(
	__in const char *src,
	__in int ch
	)
{
	char *result = (char *) src;

	while(*result != EOF) {

		if(*result == (char) ch) {
			break;
		}
	}

	return (*result == EOF) ? NULL : result;
}

size_t 
strcspn(
	__in const char *src1,
	__in const char *src2
	)
{
	size_t result = 0;
	char *ch1 = (char *) src1, *ch2;

	while(*ch1 != EOF) {

		ch2 = (char *) src2;
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
	__in const char *src1,
	__in const char *src2
	)
{
	int result = 0;
	char *ch1 = (char *) src1, *ch2 = (char *) src2;

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
	__inout char *dest,
	__in const char *src
	)
{
	char *ch1 = (char *) dest, *ch2 = (char *) src;

	while(*ch2 != EOF) {
		*ch1 = *ch2;
		++ch1;
		++ch2;
	}

	return dest;
}

int 
strcoll(
	__in const char *src1,
	__in const char *src2
	)
{
	return strcmp(src1, src2);
}

char *
strerror(
	__in int err
	)
{
	switch(err) {
		case 0:
			strerr = _SUCCESS;
			break;
		case EDOM:
			strerr = EDOM_STR;
			break;
		case ERANGE:
			strerr = ERANGE_STR;
			break;
		case EINVAL:
			strerr = EINVAL_STR;
			break;
		default:
			strerr = _NULLSTR;
			break;
	}

	return strerr;
}

size_t 
strlen(
	__in const char *src
	)
{
	size_t result = 0;
	char *ch = (char *) src;

	while(*ch != EOF) {
		++result;
		++ch;
	}

	return result;
}

char *
strncat(
	__inout char *dest,
	__in const char *src,
	__in size_t max
	)
{
	char *ch1 = (char *) dest, *ch2 = (char *) src;

	while(*ch1 != EOF) {
		++ch1;
	}

	while((*ch2 != EOF) && max) {
		*ch1 = *ch2;
		++ch1;
		++ch2;
		--max;
	}

	*ch1 = EOF;

	return dest;
}

int 
strncmp(
	__in const char *src1,
	__in const char *src2,
	__in size_t max
	)
{
	int result = 0;
	char *ch1 = (char *) src1, *ch2 = (char *) src2;

	while((*ch1 != EOF) && max) {

		result = (*ch1 - *ch2);
		if(result) {
			break;
		}

		++ch1;
		++ch2;
		--max;
	}

	return (*ch1 == EOF) ? 0 : result;
}

char *
strncpy(
	__inout char *dest,
	__in const char *src,
	__in size_t max
	)
{
	char *ch1 = (char *) dest, *ch2 = (char *) src;

	while(*ch2 != EOF) {
		*ch1 = *ch2;
		++ch1;
		++ch2;
	}

	while(max) {
		*ch1 = EOF;
		++ch1;
		--max;
	}

	return dest;
}

char *
strpbrk(
	__in const char *src1,
	__in const char *src2
	)
{
	char *ch1 = (char *) src1, *ch2;

	while(*ch1 != EOF) {

		ch2 = (char *) src2;
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
	__in const char *src,
	__in int ch
	)
{
	char *ch1 = (char *) src, *result = NULL;

	while(*ch1 != EOF) {

		if(*ch1 == (char) ch) {
			result = ch1;
		}

		++ch1;
	}

	return result;
}

size_t 
strspn(
	__in const char *src1,
	__in const char *src2
	)
{
	size_t result = 0;
	char *ch1 = (char *) src1, *ch2;

	while(*ch1 != EOF) {

		ch2 = (char *) src2;
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

char *
strstr(
	__in const char *src1,
	__in const char *src2
	)
{
	char *ch1 = (char *) src1, *ch2, *chk1;

	while(*ch1 != EOF) {

		ch2 = (char *) src2;
		if(*ch1 == *ch2) {

			chk1 = ch1;
			while(*chk1 != EOF) {

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
	__inout char *src,
	__in const char *delim
	)
{
	char *result = NULL;

	if(src) {
		token = src;
	}

	token += strspn(token, delim);
	if(*token == EOF) {
		token = NULL;
		goto exit;
	}

	result = token;
	token = strpbrk(token, delim);
	*token = EOF;
	++token;

exit:
	return result;
}

size_t 
strxfrm(
	__inout char *dest,
	__in const char *src,
	__in size_t max
	)
{
	size_t result = 0;

	if(!dest && max) {
		result = strlen(src);
		goto exit;
	}

	if(strncpy(dest, src, max)) {
		result = strlen(dest);
	}

exit:
	return result;
}
