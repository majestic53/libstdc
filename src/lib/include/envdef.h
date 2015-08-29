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

#ifndef ENVDEF_H_
#define ENVDEF_H_

#include "libdef.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/*
 * longjmp assembly
 * @param env environment to restore
 * @param val predicate to be evaluated
 * ---
 * mov edi, dword ptr [env]		; set data index
 * mov eax, dword ptr [edi+0x00]	; restore eax
 * mov ebx, dword ptr [edi+0x04]	; restore ebx
 * mov ecx, dword ptr [edi+0x08]	; restore ecx
 * mov ecx, dword ptr [edi+0x08]	; restore ecx
 * mov esp, dword ptr [edi+0x1c]	; restore esp
 * mov edx, dword ptr [edi+0x20]	; retrieve return address
 * mov dword ptr [esp], edx		; restore return address
 * mov edx, dword ptr [edi+0x0c]	; restore edx
 * mov esi, dword ptr [edi+0x10]	; restore esi
 * mov ebp, dword ptr [edi+0x18]	; restore ebp
 * mov edi, dword ptr [edi+0x14]	; restore edi
 * mov eax, val				; set eax to val
 * test 0x0, eax			; check if val is 0
 * jnz done				; if val is non-zero, jump to done
 * mov eax, 0x1				; 	set eax to 1
 * done:				; done
 */
#define env_asm_longjmp(env, val) \
	__asm__ volatile ( \
		"movl $0, %%edi\n\t" \
		"movl +0x00(%%edi), %%eax\n\t" \
		"movl +0x04(%%edi), %%ebx\n\t" \
		"movl +0x08(%%edi), %%ecx\n\t" \
		"movl +0x1c(%%edi), %%esp\n\t" \
		"movl +0x20(%%edi), %%edx\n\t" \
		"movl %%edx, (%%esp)\n\t" \
		"movl +0x0c(%%edi), %%edx\n\t" \
		"movl +0x10(%%edi), %%esi\n\t" \
		"movl +0x18(%%edi), %%ebp\n\t" \
		"movl +0x14(%%edi), %%edi\n\t" \
		"movl $1, %%eax\n\t" \
		"test %%eax, 0x00000000\n\t" \
		"jnz done\n\t" \
		"movl 0x00000001, %%eax\n\t" \
		"done:\n\t" \
		:: "l" (&env), "l" (val) \
		: "edi" \
	);

/*
 * Save current environment
 * @param env environment to save
 * ---
 * push edi				; keep previous edi value
 * mov edi, dword ptr[env]		; set data index
 * mov dword ptr [edi+0x00], eax	; save eax
 * mov dword ptr [edi+0x04], ebx	; save ebx
 * mov dword ptr [edi+0x08], ecx	; save ecx
 * mov dword ptr [edi+0x0c], edx	; save edx
 * mov dword ptr [edi+0x10], esi	; save esi
 * pop eax				; retrieve previous edi value
 * mov dword ptr [edi+0x14], eax	; save edi
 * mov dword ptr [edi+0x18], ebp	; save ebp
 * mov dword ptr [edi+0x1c], esp	; save esp
 * mov edx, dword ptr [esp]		; retrieve return address
 * mov dword ptr [edi+0x20], edx	; save return address
 * xor eax, eax				; zero eax
 */
#define env_asm_setjmp(env) \
	__asm__ volatile ( \
		"pushl %%edi\n\t" \
		"movl $0, %%edi\n\t" \
		"movl %%eax, +0x00(%%edi)\n\t" \
		"movl %%ebx, +0x04(%%edi)\n\t" \
		"movl %%ecx, +0x08(%%edi)\n\t" \
		"movl %%edx, +0x0c(%%edi)\n\t" \
		"movl %%esi, +0x10(%%edi)\n\t" \
		"popl %%eax\n\t" \
		"movl %%eax, +0x14(%%edi)\n\t" \
		"movl %%ebp, +0x18(%%edi)\n\t" \
		"movl %%esp, +0x1c(%%edi)\n\t" \
		"movl (%%esp), %%edx\n\t" \
		"movl %%edx, +0x20(%%edi)\n\t" \
		"xorl %%eax, %%eax\n\t" \
		:: "l" (&env) \
		: "edi" \
	);

// empty environment
#define env_empty { 0, 0, 0, 0, 0, 0, 0, 0, }

// environment container
#ifndef _ENV
#define _ENV
struct env {
	_jmp_buf eax; // accumulator
	_jmp_buf ebx; // base
	_jmp_buf ecx; // counter
	_jmp_buf edx; // data
	_jmp_buf esi; // source index
	_jmp_buf edi; // destination index
	_jmp_buf ebp; // base pointer
	_jmp_buf esp; // stack pointer
};
#endif // _ENV

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // ENVDEF_H_
