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

#ifndef STDBOOL_H_
#define STDBOOL_H_

#ifndef __cplusplus

// bool type is defined
#define __bool_true_false_are_defined 1

// bool type
#define bool _BOOL

// bool values
#define false 0
#define true 1

// define bool type
typedef unsigned char _Bool;
#else

// use predefined bool type
typedef bool _Bool;
#endif // __cplusplus

#endif // STDBOOL_H_
