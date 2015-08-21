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

#include "../include/ctype.h"

enum {
	c_alpha = 0x1,
	c_cntrl = 0x2,
	c_digit = 0x4,
	c_graph = 0x8,
	c_lower = 0x10,
	c_punct = 0x20,
	c_space = 0x30,
	c_upper = 0x40,
	c_xdigit = 0x80,
};

static const char ctype_type[] = {
	c_cntrl, // null
	c_cntrl, // start of heading
	c_cntrl, // start of text
	c_cntrl, // end of text
	c_cntrl, // end of transmission
	c_cntrl, // enquiry
	c_cntrl, // acknowledge
	c_cntrl, // bell
	c_cntrl, // backspace
	c_cntrl | c_space, // horizontal tab
	c_cntrl | c_space, // new line
	c_cntrl | c_space, // vertical tab
	c_cntrl | c_space, // new page
	c_cntrl | c_space, // carrage return
	c_cntrl, // shift out
	c_cntrl, // shift in
	c_cntrl, // data link escape
	c_cntrl, // device control 1
	c_cntrl, // device control 2
	c_cntrl, // device control 3
	c_cntrl, // device control 4
	c_cntrl, // negative acknowledge
	c_cntrl, // synchronous idle
	c_cntrl, // end of transmission block
	c_cntrl, // cancel
	c_cntrl, // end of medium
	c_cntrl, // substitute
	c_cntrl, // escape
	c_cntrl, // file seperator
	c_cntrl, // group seperator
	c_cntrl, // record seperator
	c_cntrl, // unit seperator
	c_space, // space
	c_graph | c_punct, // !
	c_graph | c_punct, // "
	c_graph | c_punct, // #
	c_graph | c_punct, // $
	c_graph | c_punct, // %
	c_graph | c_punct, // &
	c_graph | c_punct, // '
	c_graph | c_punct, // (
	c_graph | c_punct, // )
	c_graph | c_punct, // *
	c_graph | c_punct, // +
	c_graph | c_punct, // ,
	c_graph | c_punct, // -
	c_graph | c_punct, // .
	c_graph | c_punct, // /
	c_digit | c_graph | c_xdigit, // 0
	c_digit | c_graph | c_xdigit, // 1
	c_digit | c_graph | c_xdigit, // 2
	c_digit | c_graph | c_xdigit, // 3
	c_digit | c_graph | c_xdigit, // 4
	c_digit | c_graph | c_xdigit, // 5
	c_digit | c_graph | c_xdigit, // 6
	c_digit | c_graph | c_xdigit, // 7
	c_digit | c_graph | c_xdigit, // 8
	c_digit | c_graph | c_xdigit, // 9
	c_graph | c_punct, // :
	c_graph | c_punct, // ;
	c_graph | c_punct, // <
	c_graph | c_punct, // =
	c_graph | c_punct, // >
	c_graph | c_punct, // ?
	c_graph | c_punct, // @
	c_alpha | c_graph | c_upper | c_xdigit, // A
	c_alpha | c_graph | c_upper | c_xdigit, // B
	c_alpha | c_graph | c_upper | c_xdigit, // C
	c_alpha | c_graph | c_upper | c_xdigit, // D
	c_alpha | c_graph | c_upper | c_xdigit, // E
	c_alpha | c_graph | c_upper | c_xdigit, // F
	c_alpha | c_graph | c_upper, // G
	c_alpha | c_graph | c_upper, // H
	c_alpha | c_graph | c_upper, // I
	c_alpha | c_graph | c_upper, // J
	c_alpha | c_graph | c_upper, // K
	c_alpha | c_graph | c_upper, // L
	c_alpha | c_graph | c_upper, // M
	c_alpha | c_graph | c_upper, // N
	c_alpha | c_graph | c_upper, // O
	c_alpha | c_graph | c_upper, // P
	c_alpha | c_graph | c_upper, // Q
	c_alpha | c_graph | c_upper, // R
	c_alpha | c_graph | c_upper, // S
	c_alpha | c_graph | c_upper, // T
	c_alpha | c_graph | c_upper, // U
	c_alpha | c_graph | c_upper, // V
	c_alpha | c_graph | c_upper, // W
	c_alpha | c_graph | c_upper, // X
	c_alpha | c_graph | c_upper, // Y
	c_alpha | c_graph | c_upper, // Z
	c_graph | c_punct, // [
	c_graph | c_punct, // backspace
	c_graph | c_punct, // ]
	c_graph | c_punct, // ^
	c_graph | c_punct, // _
	c_graph | c_punct, // `
	c_alpha | c_graph | c_lower | c_xdigit, // a
	c_alpha | c_graph | c_lower | c_xdigit, // b
	c_alpha | c_graph | c_lower | c_xdigit, // c
	c_alpha | c_graph | c_lower | c_xdigit, // d
	c_alpha | c_graph | c_lower | c_xdigit, // e
	c_alpha | c_graph | c_lower | c_xdigit, // f
	c_alpha | c_graph | c_xdigit, // g
	c_alpha | c_graph | c_xdigit, // h
	c_alpha | c_graph | c_xdigit, // i
	c_alpha | c_graph | c_xdigit, // j
	c_alpha | c_graph | c_xdigit, // k
	c_alpha | c_graph | c_xdigit, // l
	c_alpha | c_graph | c_xdigit, // m
	c_alpha | c_graph | c_xdigit, // n
	c_alpha | c_graph | c_xdigit, // o
	c_alpha | c_graph | c_xdigit, // p
	c_alpha | c_graph | c_xdigit, // q
	c_alpha | c_graph | c_xdigit, // r
	c_alpha | c_graph | c_xdigit, // s
	c_alpha | c_graph | c_xdigit, // t
	c_alpha | c_graph | c_xdigit, // u
	c_alpha | c_graph | c_xdigit, // v
	c_alpha | c_graph | c_xdigit, // w
	c_alpha | c_graph | c_xdigit, // x
	c_alpha | c_graph | c_xdigit, // y
	c_alpha | c_graph | c_xdigit, // z
	c_graph | c_punct, // {
	c_graph | c_punct, // |
	c_graph | c_punct, // }
	c_graph | c_punct, // ~
	c_cntrl, // delete
	c_graph | c_punct, // Ç
	c_graph | c_punct, // ü
	c_graph | c_punct, // é
	c_graph | c_punct, // â
	c_graph | c_punct, // ä
	c_graph | c_punct, // à
	c_graph | c_punct, // å
	c_graph | c_punct, // ç
	c_graph | c_punct, // ê
	c_graph | c_punct, // ë
	c_graph | c_punct, // è
	c_graph | c_punct, // ï
	c_graph | c_punct, // î
	c_graph | c_punct, // ì
	c_graph | c_punct, // Ä
	c_graph | c_punct, // Å
	c_graph | c_punct, // É
	c_graph | c_punct, // æ
	c_graph | c_punct, // Æ
	c_graph | c_punct, // ô
	c_graph | c_punct, // ö
	c_graph | c_punct, // ò
	c_graph | c_punct, // û
	c_graph | c_punct, // ù
	c_graph | c_punct, // ÿ
	c_graph | c_punct, // Ö
	c_graph | c_punct, // Ü
	c_graph | c_punct, // ¢
	c_graph | c_punct, // £
	c_graph | c_punct, // ¥
	c_graph | c_punct, // ₧
	c_graph | c_punct, // ƒ
	c_graph | c_punct, // á
	c_graph | c_punct, // í
	c_graph | c_punct, // ó
	c_graph | c_punct, // ú
	c_graph | c_punct, // ñ
	c_graph | c_punct, // Ñ
	c_graph | c_punct, // ª
	c_graph | c_punct, // º
	c_graph | c_punct, // ¿
	c_graph | c_punct, // ⌐
	c_graph | c_punct, // ¬
	c_graph | c_punct, // ½
	c_graph | c_punct, // ¼
	c_graph | c_punct, // ¡
	c_graph | c_punct, // «
	c_graph | c_punct, // »
	c_graph | c_punct, // ░
	c_graph | c_punct, // ▒
	c_graph | c_punct, // ▓
	c_graph | c_punct, // │
	c_graph | c_punct, // ┤
	c_graph | c_punct, // ╡
	c_graph | c_punct, // ╢
	c_graph | c_punct, // ╖
	c_graph | c_punct, // ╕
	c_graph | c_punct, // ╣
	c_graph | c_punct, // ║
	c_graph | c_punct, // ╗
	c_graph | c_punct, // ╝
	c_graph | c_punct, // ╜
	c_graph | c_punct, // ╛
	c_graph | c_punct, // ┐
	c_graph | c_punct, // └
	c_graph | c_punct, // ┴
	c_graph | c_punct, // ┬
	c_graph | c_punct, // ├
	c_graph | c_punct, // ─
	c_graph | c_punct, // ┼
	c_graph | c_punct, // ╞
	c_graph | c_punct, // ╟
	c_graph | c_punct, // ╚
	c_graph | c_punct, // ╔
	c_graph | c_punct, // ╩
	c_graph | c_punct, // ╦
	c_graph | c_punct, // ╠
	c_graph | c_punct, // ═
	c_graph | c_punct, // ╬
	c_graph | c_punct, // ╧
	c_graph | c_punct, // ╨
	c_graph | c_punct, // ╤
	c_graph | c_punct, // ╥
	c_graph | c_punct, // ╙
	c_graph | c_punct, // ╘
	c_graph | c_punct, // ╒
	c_graph | c_punct, // ╓
	c_graph | c_punct, // ╫
	c_graph | c_punct, // ╪
	c_graph | c_punct, // ┘
	c_graph | c_punct, // ┌
	c_graph | c_punct, // █
	c_graph | c_punct, // ▄
	c_graph | c_punct, // ▌
	c_graph | c_punct, // ▐
	c_graph | c_punct, // ▀
	c_graph | c_punct, // α
	c_graph | c_punct, // ß
	c_graph | c_punct, // Γ
	c_graph | c_punct, // π
	c_graph | c_punct, // Σ
	c_graph | c_punct, // σ
	c_graph | c_punct, // µ
	c_graph | c_punct, // τ
	c_graph | c_punct, // Φ
	c_graph | c_punct, // Θ
	c_graph | c_punct, // Ω
	c_graph | c_punct, // δ
	c_graph | c_punct, // ∞
	c_graph | c_punct, // φ
	c_graph | c_punct, // ε
	c_graph | c_punct, // ∩
	c_graph | c_punct, // ≡
	c_graph | c_punct, // ±
	c_graph | c_punct, // ≥
	c_graph | c_punct, // ≤
	c_graph | c_punct, // ⌠
	c_graph | c_punct, // ⌡
	c_graph | c_punct, // ÷
	c_graph | c_punct, // ≈
	c_graph | c_punct, // °
	c_graph | c_punct, // ∙
	c_graph | c_punct, // ·
	c_graph | c_punct, // √
	c_graph | c_punct, // ⁿ
	c_graph | c_punct, // ²
	c_graph | c_punct, // ■
	c_graph | c_punct, //
	};

#define ctype_chktype(_C_, _TYPE_) (((ctype_type[_C_] & (_TYPE_)) > 0) ? 1 : 0)

static const char ctype_lower[] = {
	'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
	'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
	'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
	'y', 'z',
	};

#define ctype_tolower(_C_) \
	((((_C_) < 'A') || ((_C_) > 'Z')) ? (_C_) : \
	(ctype_lower[(_C_) - 'A'] & 0xff))

static const char ctype_upper[] = {
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
	'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
	'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
	'Y', 'Z',
	};

#define ctype_toupper(_C_) \
	((((_C_) < 'a') || ((_C_) > 'z')) ? (_C_) : \
	ctype_upper[(_C_) - 'a'])

int isalnum(
	__in int c
	)
{
	return ctype_chktype(c & 0xff, c_alpha | c_digit);
}

int isalpha(
	__in int c
	)
{
	return ctype_chktype(c & 0xff, c_alpha);
}

int iscntrl(
	__in int c
	)
{
	return ctype_chktype(c & 0xff, c_cntrl);
}

int isdigit(
	__in int c
	)
{
	return ctype_chktype(c & 0xff, c_digit);
}

int isgraph(
	__in int c
	)
{
	return ctype_chktype(c & 0xff, c_graph);
}

int islower(
	__in int c
	)
{
	return ctype_chktype(c & 0xff, c_lower);
}

int isprint(
	__in int c
	)
{
	return ctype_chktype(c & 0xff, c_alpha | c_digit | c_punct | c_space);
}

int ispunct(
	__in int c
	)
{
	return ctype_chktype(c & 0xff, c_punct);
}

int isspace(
	__in int c
	)
{
	return ctype_chktype(c & 0xff, c_space);
}

int isupper(
	__in int c
	)
{
	return ctype_chktype(c & 0xff, c_upper);
}

int isxdigit(
	__in int c
	)
{
	return ctype_chktype(c & 0xff, c_xdigit);
}

int tolower(
	__in int c
	)
{
	return ctype_tolower(c & 0xff);
}

int toupper(
	__in int c
	)
{
	return ctype_toupper(c & 0xff);
}
