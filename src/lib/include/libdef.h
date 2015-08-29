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

#ifndef LIBDEF_H_
#define LIBDEF_H_

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

// common types
#define _bool unsigned char
#define _clock_t long
#define _int8_t signed char
#define _int16_t signed short
#define _int32_t signed long
#define _jmp_buf unsigned int
#define _ptrdiff_t int
#define _size_t unsigned int
#define _time_t long
#define _tm int
#define _uint8_t unsigned char
#define _uint16_t unsigned short
#define _uint32_t unsigned long
#define _va_list unsigned char *
#define _wchar_t unsigned short

// common values
#define _eof '\0'
#define _null ((void *) 0)
#define _nullstr ""
#define _unknown "?"

// environment values
#define _ascstr_len 26
#define _clocks_per_sec 1000000
#define _jmp_buf_len 8
#define _tzone_len 4

// parameter flags
#ifndef __in
#define __in
#endif // __in
#ifndef __inout
#define __inout
#endif // __inout
#ifndef __out
#define __out
#endif // __out

// library version
#define _lib_maj 0
#define _lib_min 1
#define _lib_rev 6
#define _lib_wk 1535

// library version string
#define _lib_ver \
	_valstr(_lib_maj) "." _valstr(_lib_min) "." \
	_valstr(_lib_wk) "." _valstr(_lib_rev)

/*
 * Invalid type value
 * @param type scalar type
 */
#define _inv(type) ((type) -1)

/* 
 * Reference parameter
 * @param param identifier
 */
#define _ref(param) (void) param

/*
 * String concatination
 * @param param identifier
 */
#define _str(param) # param

/*
 * Value to string conversion
 * @param param identifier
 */
#define _valstr(param) _str(param)

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // LIBDEF_H_
