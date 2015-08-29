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

#ifndef ASSERT_H_
#define ASSERT_H_

#include "libdef.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#ifndef NDEBUG

/*
 * Abort if predicate expression is false
 * Assertion in the form: 
 *	"<FILE>:<LINE>: <FUNCT>: Assertion \'<EXPR>\' failed."
 * @param _EXPR_ predicate expression to be checked
 */
#define assert(_EXPR_) {\
	if(!(_EXPR_)) {\
	_assert(__FILE__ ":" _VALSTR(__LINE__) ": " __funct__ \
	": Assertion \'" _VALSTR(_EXPR_) "\' failed.") \
	} \
	}
#else

// assert ignored when NDEBUG is defined
#define assert(_IGNORE_) ((void) 0)
#endif // NDEBUG

/*
 * Assert if predicate expression is false
 * @param expr predicate string
 */
void _assert(
	__in const char *expr
	);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // ASSERT_H_
