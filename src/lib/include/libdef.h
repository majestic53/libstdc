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

// read parameter
#ifndef __in
#define __in
#endif // __in

// write parameter
#ifndef __out
#define __out
#endif // __out

// read/write parameter
#ifndef __inout
#define __inout
#endif // __inout

// library version
#define _lib_maj 0
#define _lib_min 1
#define _lib_rev 2
#define _lib_wk 1534

// library version string
#define _lib_ver \
	_valstr(_lib_maj) "." _valstr(_lib_min) "." \
	_valstr(_lib_wk) "." _valstr(_lib_rev)

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

#endif // LIBDEF_H_
