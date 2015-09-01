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

// common types
#define _bool unsigned char
#define _clock_t long
#define _err int
#define _int8_t signed char
#define _int16_t signed short
#define _int32_t signed long
#define _jmp_buf unsigned int
#define _lc char
#define _ptrdiff_t int
#define _sig_atomic_t int
#define _sig_hdl_t(_NAME_) void (*(_NAME_))(int)
#define _size_t unsigned int
#define _time_t long
#define _tm int
#define _uint8_t unsigned char
#define _uint16_t unsigned short
#define _uint32_t unsigned long
#define _va_list unsigned char *
#define _wchar_t unsigned short

// common values
#define _EOF '\0'
#define _NULL ((void *) 0)
#define _NULLSTR ""
#define _SUCCESS "Success"
#define _UNKNOWN "?"

// environment values
#define _ASCSTR_LEN 26
#define _CLOCKS_PER_SEC 1000000
#define _FACT_TBL_MAX 30
#define _JMPBUF_LEN 8

// library version
#define _LIB_MAJ 0
#define _LIB_MIN 1
#define _LIB_REV 1
#define _LIB_WK 1536

// library version string
#define _LIB_VER \
	_VALSTR(_LIB_MAJ) "." _VALSTR(_LIB_MIN) "." \
	_VALSTR(_LIB_WK) "." _VALSTR(_LIB_REV)

/*
 * Invalid type value
 * @param _TYPE_ scalar type
 */
#define _INV(_TYPE_) ((_TYPE_) -1)

/* 
 * Reference parameter
 * @param _PARAM_ identifier
 */
#define _REF(_PARAM_) (void) _PARAM_

/*
 * String concatination
 * @param _PARAM_ identifier
 */
#define _STR(_PARAM_) # _PARAM_

/*
 * Determine variable argument byte length
 * @param _TYPE_ argument type name
 */
#define _VA_SIZEOF(_TYPE_) \
	((sizeof(_TYPE_) + (sizeof(int) - 1)) & ~(sizeof(int) - 1))

/*
 * Value to string conversion
 * @param _PARAM_ identifier
 */
#define _VALSTR(_PARAM_) _STR(_PARAM_)

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // LIBDEF_H_
