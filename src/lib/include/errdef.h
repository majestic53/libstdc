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

#ifndef ERRDEF_H_
#define ERRDEF_H_

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

// domain error
#define EDOM 1
#define EDOM_STR "Domain error"

// range error
#define ERANGE 2
#define ERANGE_STR "Range error"

// invalid argument error
#define EINVAL 22
#define EINVAL_STR "Invalid argument"

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // ERRDEF_H_
