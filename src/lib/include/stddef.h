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

#ifndef STDDEF_H_
#define STDDEF_H_

#include "libdef.h"

// null definition
#define NULL _null

// TODO: offsetof

// ptrdiff_t defition
#ifndef _PTRDIFF_T
#define _PTRDIFF_T
typedef _ptrdiff_t ptrdiff_t;
#endif // _PTRDIFF_T

// size_t definition
#ifndef _SIZE_T
#define _SIZE_T
typedef _size_t size_t;
#endif // _SIZE_T

// wide character definition
#ifndef _WCHAR_T
#define _WCHAR_T
typedef _wchar_t wchar_t;
#endif // _WCHAR_T

#endif // STDDEF_H_
