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
 * Locate next argument in list
 * @param _AP_ variable argument list
 * @param _TYPE_ argument type name
 */
#define va_arg(_AP_, _TYPE_) \
	(*((_TYPE_) *) (((_AP_) += _VA_SIZEOF(_TYPE_)) - _VA_SIZEOF(_TYPE_)))

/*
 * Uninitialize argument list
 * @param _AP_ variable argument list
 */
#define va_end(_AP_) ((_AP_) = _NULL)

/*
 * Initialize argument list
 * @param _AP_ variable argument list
 * @param _FORMAT_ variable argument format
 */
#define va_start(_AP_, _FORMAT_) \
	((_AP_) = ((va_list) (&(_FORMAT_) + _VA_SIZEOF(_FORMAT_) + 1)))

// variable argument list definition
#ifndef _VA_LIST
#define _VA_LIST
typedef _va_list va_list;
#endif // _VA_LIST

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // STDARG_H_
