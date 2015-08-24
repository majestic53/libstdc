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

#ifndef STDARG_H_
#define STDARG_H_

#include "libdef.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/*
 * Determine variable argument byte length
 * @param arg variable argument
 */
#define _va_arg_len(arg) \
	((sizeof(arg) + (sizeof(int) - 1)) & ~(sizeof(int) - 1))

/*
 * Locate next argument in list
 * @param ap variable argument list
 * @param type argument type name
 */
#define va_arg(ap, type) // TODO

/*
 * Initialize argument list
 * @param ap variable argument list
 * @param format variable argument format
 */
#define va_start(ap, format) \
	(ap = (va_list) (((char *) &format) + _va_arg_len(format)))

/*
 * Uninitialize argument list
 * @param ap variable argument list
 */
#define va_end(ap) (ap = _null)

// variable argument list definition
#ifndef _VA_LIST
#define _VA_LIST
typedef void *va_list;
#endif // _VA_LIST

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // STDARG_H_
