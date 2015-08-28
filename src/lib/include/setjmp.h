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

#ifndef SETJMP_H_
#define SETJMP_H_

#include "libdef.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/*
 * Restore previous saved environment
 * @param env environment to restore
 * @param val predicate to be evaluated
 */
#define longjmp(env, val) _longjmp(env, val)

/*
 * Save current environment
 * @param env environment to save
 */
#define setjmp(env) _setjmp(env)

// jump buffer definition
#ifndef _JMP_BUF
#define _JMP_BUF
typedef _jmp_buf jmp_buf;
#endif // _JMP_BUF

/*
 * Restore previous saved environment
 * @param env environment to restore
 * @param val predicate to be evaluated
 */
void _longjmp(
	__in jmp_buf env,
	__in int val
	);
	
/*
 * Save current environment
 * @param env environment to save
 * @return first invocation returns 0, else returns value 
 * 	passed into longjmp (if value is 0, returns 1)
 */
int _setjmp(
	__inout jmp_buf env
	);

// jump buffer container
extern jmp_buf _evn[_jmp_buf_len];
	
#ifdef __cplusplus
}
#endif // __cplusplus

#endif // SETJMP_H_
