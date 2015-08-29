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

#ifndef SIGNAL_H_
#define SIGNAL_H_

#include "libdef.h"
#include "sigdef.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

enum {
	SIG_ERR = -1, // error on signal
	SIG_DFL, // default on signal
	SIG_IGN, // ignore signal
};

/*
 * Raise a synchronous signal
 * @param sig signal value
 * @return zero if signal was raised successfully, else returns non-zero
 */
int raise(
	__in int sig
	);

#ifndef _SIG_HDL_T
#define _SIG_HDL_T
typedef _sig_hdl_t(sig_hdl_t);
#endif // _SIG_HDL_T

/*
 * Set asynchronous signal handler
 * @param sig signal value
 * @param funct signal handler
 * @return a valid pointer to funct, else SIG_ERR and errno set
 */
sig_hdl_t signal(
	__in int sig,
	__in sig_hdl_t funct
	);

#ifndef _SIG_ATOMIC_T
#define _SIG_ATOMIC_T
typedef _sig_atomic_t sig_atomic_t;
#endif // _SIG_ATOMIC_T

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // SIGNAL_H_
