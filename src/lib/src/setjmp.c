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

#include "../include/envdef.h"
#include "../include/setjmp.h"

jmp_buf _env[] = ENV_EMPTY;

void 
_longjmp(
	__in jmp_buf env,
	__in int val
	)
{
	ENV_LONGJMP(env, val);
}

int 
_setjmp(
	__inout jmp_buf env
	)
{
	ENV_SETJMP(env);
	return 0;
}
