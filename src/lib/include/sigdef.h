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

#ifndef SIGDEF_H_
#define SIGDEF_H_

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

// abort signal
#define SIGABRT 6
#define SIGABRT_STR "Abort"

// floating-point exception signal
#define SIGFPE 8
#define SIGFPE_STR "Floating-point exception"

// illegal operation signal
#define SIGILL 4
#define SIGILL_STR "Illegal operation"

// asyn interrupt signal
#define SIGINT 2
#define SIGINT_STR "Async signal"

// segmentation fault signal
#define SIGSEGV 11
#define SIGSEGV_STR "Segmentation fault"

// termination signal
#define SIGTERM 15
#define SIGTERM_STR "Terminated"

// supported signal range
#define SIGMIN SIGABRT
#define SIGMAX SIGTERM

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // SIGDEF_H_
