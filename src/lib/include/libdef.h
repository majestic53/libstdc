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

// read parameter macro
#ifndef __in
#define __in
#endif // __in

// write parameter macro
#ifndef __out
#define __out
#endif // __out

// read/write parameter macro
#ifndef __inout
#define __inout
#endif // __inout

// library version macros
#define _lib_maj 0
#define _lib_min 1
#define _lib_rev 1
#define _lib_wk 1534

// library version string macro
#define _lib_ver \
	_valstr(_lib_maj) "." _valstr(_lib_min) "." \
	_valstr(_lib_wk) "." _valstr(_lib_rev)

/* 
 * Reference parameter macro
 * @param _param_ identifier
 */
#define _ref(_param_) (void) _param_

/*
 * String concatination macro
 * @param _param_ identifier
 */
#define _str(_param_) # _param_

/*
 * Value to string conversion macro
 * @param _param_ identifier
 */
#define _valstr(_param_) _str(_param_)

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // LIBDEF_H_
