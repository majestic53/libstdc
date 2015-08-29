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

#define C_ALPHA 0x1
#define C_CNTRL 0x2
#define C_DIGIT 0x4
#define C_GRAPH 0x8
#define C_LOWER 0x10
#define C_PUNCT 0x20
#define C_SPACE 0x30
#define C_UPPER 0x40
#define C_XDIGIT 0x80

static const char CTYPE_TYPE[] = {
	C_CNTRL, // null
	C_CNTRL, // start of heading
	C_CNTRL, // start of text
	C_CNTRL, // end of text
	C_CNTRL, // end of transmission
	C_CNTRL, // enquiry
	C_CNTRL, // acknowledge
	C_CNTRL, // bell
	C_CNTRL, // backspace
	C_CNTRL | C_SPACE, // horizontal tab
	C_CNTRL | C_SPACE, // new line
	C_CNTRL | C_SPACE, // vertical tab
	C_CNTRL | C_SPACE, // new page
	C_CNTRL | C_SPACE, // carrage return
	C_CNTRL, // shift out
	C_CNTRL, // shift in
	C_CNTRL, // data link escape
	C_CNTRL, // device control 1
	C_CNTRL, // device control 2
	C_CNTRL, // device control 3
	C_CNTRL, // device control 4
	C_CNTRL, // negative acknowledge
	C_CNTRL, // synchronous idle
	C_CNTRL, // end of transmission block
	C_CNTRL, // cancel
	C_CNTRL, // end of medium
	C_CNTRL, // substitute
	C_CNTRL, // escape
	C_CNTRL, // file seperator
	C_CNTRL, // group seperator
	C_CNTRL, // record seperator
	C_CNTRL, // unit seperator
	C_SPACE, // space
	C_GRAPH | C_PUNCT, // !
	C_GRAPH | C_PUNCT, // "
	C_GRAPH | C_PUNCT, // #
	C_GRAPH | C_PUNCT, // $
	C_GRAPH | C_PUNCT, // %
	C_GRAPH | C_PUNCT, // &
	C_GRAPH | C_PUNCT, // '
	C_GRAPH | C_PUNCT, // (
	C_GRAPH | C_PUNCT, // )
	C_GRAPH | C_PUNCT, // *
	C_GRAPH | C_PUNCT, // +
	C_GRAPH | C_PUNCT, // ,
	C_GRAPH | C_PUNCT, // -
	C_GRAPH | C_PUNCT, // .
	C_GRAPH | C_PUNCT, // /
	C_DIGIT | C_GRAPH | C_XDIGIT, // 0
	C_DIGIT | C_GRAPH | C_XDIGIT, // 1
	C_DIGIT | C_GRAPH | C_XDIGIT, // 2
	C_DIGIT | C_GRAPH | C_XDIGIT, // 3
	C_DIGIT | C_GRAPH | C_XDIGIT, // 4
	C_DIGIT | C_GRAPH | C_XDIGIT, // 5
	C_DIGIT | C_GRAPH | C_XDIGIT, // 6
	C_DIGIT | C_GRAPH | C_XDIGIT, // 7
	C_DIGIT | C_GRAPH | C_XDIGIT, // 8
	C_DIGIT | C_GRAPH | C_XDIGIT, // 9
	C_GRAPH | C_PUNCT, // :
	C_GRAPH | C_PUNCT, // ;
	C_GRAPH | C_PUNCT, // <
	C_GRAPH | C_PUNCT, // =
	C_GRAPH | C_PUNCT, // >
	C_GRAPH | C_PUNCT, // ?
	C_GRAPH | C_PUNCT, // @
	C_ALPHA | C_GRAPH | C_UPPER | C_XDIGIT, // A
	C_ALPHA | C_GRAPH | C_UPPER | C_XDIGIT, // B
	C_ALPHA | C_GRAPH | C_UPPER | C_XDIGIT, // C
	C_ALPHA | C_GRAPH | C_UPPER | C_XDIGIT, // D
	C_ALPHA | C_GRAPH | C_UPPER | C_XDIGIT, // E
	C_ALPHA | C_GRAPH | C_UPPER | C_XDIGIT, // F
	C_ALPHA | C_GRAPH | C_UPPER, // G
	C_ALPHA | C_GRAPH | C_UPPER, // H
	C_ALPHA | C_GRAPH | C_UPPER, // I
	C_ALPHA | C_GRAPH | C_UPPER, // J
	C_ALPHA | C_GRAPH | C_UPPER, // K
	C_ALPHA | C_GRAPH | C_UPPER, // L
	C_ALPHA | C_GRAPH | C_UPPER, // M
	C_ALPHA | C_GRAPH | C_UPPER, // N
	C_ALPHA | C_GRAPH | C_UPPER, // O
	C_ALPHA | C_GRAPH | C_UPPER, // P
	C_ALPHA | C_GRAPH | C_UPPER, // Q
	C_ALPHA | C_GRAPH | C_UPPER, // R
	C_ALPHA | C_GRAPH | C_UPPER, // S
	C_ALPHA | C_GRAPH | C_UPPER, // T
	C_ALPHA | C_GRAPH | C_UPPER, // U
	C_ALPHA | C_GRAPH | C_UPPER, // V
	C_ALPHA | C_GRAPH | C_UPPER, // W
	C_ALPHA | C_GRAPH | C_UPPER, // X
	C_ALPHA | C_GRAPH | C_UPPER, // Y
	C_ALPHA | C_GRAPH | C_UPPER, // Z
	C_GRAPH | C_PUNCT, // [
	C_GRAPH | C_PUNCT, // backspace
	C_GRAPH | C_PUNCT, // ]
	C_GRAPH | C_PUNCT, // ^
	C_GRAPH | C_PUNCT, // _
	C_GRAPH | C_PUNCT, // `
	C_ALPHA | C_GRAPH | C_LOWER | C_XDIGIT, // a
	C_ALPHA | C_GRAPH | C_LOWER | C_XDIGIT, // b
	C_ALPHA | C_GRAPH | C_LOWER | C_XDIGIT, // c
	C_ALPHA | C_GRAPH | C_LOWER | C_XDIGIT, // d
	C_ALPHA | C_GRAPH | C_LOWER | C_XDIGIT, // e
	C_ALPHA | C_GRAPH | C_LOWER | C_XDIGIT, // f
	C_ALPHA | C_GRAPH | C_LOWER, // g
	C_ALPHA | C_GRAPH | C_LOWER, // h
	C_ALPHA | C_GRAPH | C_LOWER, // i
	C_ALPHA | C_GRAPH | C_LOWER, // j
	C_ALPHA | C_GRAPH | C_LOWER, // k
	C_ALPHA | C_GRAPH | C_LOWER, // l
	C_ALPHA | C_GRAPH | C_LOWER, // m
	C_ALPHA | C_GRAPH | C_LOWER, // n
	C_ALPHA | C_GRAPH | C_LOWER, // o
	C_ALPHA | C_GRAPH | C_LOWER, // p
	C_ALPHA | C_GRAPH | C_LOWER, // q
	C_ALPHA | C_GRAPH | C_LOWER, // r
	C_ALPHA | C_GRAPH | C_LOWER, // s
	C_ALPHA | C_GRAPH | C_LOWER, // t
	C_ALPHA | C_GRAPH | C_LOWER, // u
	C_ALPHA | C_GRAPH | C_LOWER, // v
	C_ALPHA | C_GRAPH | C_LOWER, // w
	C_ALPHA | C_GRAPH | C_LOWER, // x
	C_ALPHA | C_GRAPH | C_LOWER, // y
	C_ALPHA | C_GRAPH | C_LOWER, // z
	C_GRAPH | C_PUNCT, // {
	C_GRAPH | C_PUNCT, // |
	C_GRAPH | C_PUNCT, // }
	C_GRAPH | C_PUNCT, // ~
	C_CNTRL, // delete
	C_GRAPH | C_PUNCT, // Ç
	C_GRAPH | C_PUNCT, // ü
	C_GRAPH | C_PUNCT, // é
	C_GRAPH | C_PUNCT, // â
	C_GRAPH | C_PUNCT, // ä
	C_GRAPH | C_PUNCT, // à
	C_GRAPH | C_PUNCT, // å
	C_GRAPH | C_PUNCT, // ç
	C_GRAPH | C_PUNCT, // ê
	C_GRAPH | C_PUNCT, // ë
	C_GRAPH | C_PUNCT, // è
	C_GRAPH | C_PUNCT, // ï
	C_GRAPH | C_PUNCT, // î
	C_GRAPH | C_PUNCT, // ì
	C_GRAPH | C_PUNCT, // Ä
	C_GRAPH | C_PUNCT, // Å
	C_GRAPH | C_PUNCT, // É
	C_GRAPH | C_PUNCT, // æ
	C_GRAPH | C_PUNCT, // Æ
	C_GRAPH | C_PUNCT, // ô
	C_GRAPH | C_PUNCT, // ö
	C_GRAPH | C_PUNCT, // ò
	C_GRAPH | C_PUNCT, // û
	C_GRAPH | C_PUNCT, // ù
	C_GRAPH | C_PUNCT, // ÿ
	C_GRAPH | C_PUNCT, // Ö
	C_GRAPH | C_PUNCT, // Ü
	C_GRAPH | C_PUNCT, // ¢
	C_GRAPH | C_PUNCT, // £
	C_GRAPH | C_PUNCT, // ¥
	C_GRAPH | C_PUNCT, // ₧
	C_GRAPH | C_PUNCT, // ƒ
	C_GRAPH | C_PUNCT, // á
	C_GRAPH | C_PUNCT, // í
	C_GRAPH | C_PUNCT, // ó
	C_GRAPH | C_PUNCT, // ú
	C_GRAPH | C_PUNCT, // ñ
	C_GRAPH | C_PUNCT, // Ñ
	C_GRAPH | C_PUNCT, // ª
	C_GRAPH | C_PUNCT, // º
	C_GRAPH | C_PUNCT, // ¿
	C_GRAPH | C_PUNCT, // ⌐
	C_GRAPH | C_PUNCT, // ¬
	C_GRAPH | C_PUNCT, // ½
	C_GRAPH | C_PUNCT, // ¼
	C_GRAPH | C_PUNCT, // ¡
	C_GRAPH | C_PUNCT, // «
	C_GRAPH | C_PUNCT, // »
	C_GRAPH | C_PUNCT, // ░
	C_GRAPH | C_PUNCT, // ▒
	C_GRAPH | C_PUNCT, // ▓
	C_GRAPH | C_PUNCT, // │
	C_GRAPH | C_PUNCT, // ┤
	C_GRAPH | C_PUNCT, // ╡
	C_GRAPH | C_PUNCT, // ╢
	C_GRAPH | C_PUNCT, // ╖
	C_GRAPH | C_PUNCT, // ╕
	C_GRAPH | C_PUNCT, // ╣
	C_GRAPH | C_PUNCT, // ║
	C_GRAPH | C_PUNCT, // ╗
	C_GRAPH | C_PUNCT, // ╝
	C_GRAPH | C_PUNCT, // ╜
	C_GRAPH | C_PUNCT, // ╛
	C_GRAPH | C_PUNCT, // ┐
	C_GRAPH | C_PUNCT, // └
	C_GRAPH | C_PUNCT, // ┴
	C_GRAPH | C_PUNCT, // ┬
	C_GRAPH | C_PUNCT, // ├
	C_GRAPH | C_PUNCT, // ─
	C_GRAPH | C_PUNCT, // ┼
	C_GRAPH | C_PUNCT, // ╞
	C_GRAPH | C_PUNCT, // ╟
	C_GRAPH | C_PUNCT, // ╚
	C_GRAPH | C_PUNCT, // ╔
	C_GRAPH | C_PUNCT, // ╩
	C_GRAPH | C_PUNCT, // ╦
	C_GRAPH | C_PUNCT, // ╠
	C_GRAPH | C_PUNCT, // ═
	C_GRAPH | C_PUNCT, // ╬
	C_GRAPH | C_PUNCT, // ╧
	C_GRAPH | C_PUNCT, // ╨
	C_GRAPH | C_PUNCT, // ╤
	C_GRAPH | C_PUNCT, // ╥
	C_GRAPH | C_PUNCT, // ╙
	C_GRAPH | C_PUNCT, // ╘
	C_GRAPH | C_PUNCT, // ╒
	C_GRAPH | C_PUNCT, // ╓
	C_GRAPH | C_PUNCT, // ╫
	C_GRAPH | C_PUNCT, // ╪
	C_GRAPH | C_PUNCT, // ┘
	C_GRAPH | C_PUNCT, // ┌
	C_GRAPH | C_PUNCT, // █
	C_GRAPH | C_PUNCT, // ▄
	C_GRAPH | C_PUNCT, // ▌
	C_GRAPH | C_PUNCT, // ▐
	C_GRAPH | C_PUNCT, // ▀
	C_GRAPH | C_PUNCT, // α
	C_GRAPH | C_PUNCT, // ß
	C_GRAPH | C_PUNCT, // Γ
	C_GRAPH | C_PUNCT, // π
	C_GRAPH | C_PUNCT, // Σ
	C_GRAPH | C_PUNCT, // σ
	C_GRAPH | C_PUNCT, // µ
	C_GRAPH | C_PUNCT, // τ
	C_GRAPH | C_PUNCT, // Φ
	C_GRAPH | C_PUNCT, // Θ
	C_GRAPH | C_PUNCT, // Ω
	C_GRAPH | C_PUNCT, // δ
	C_GRAPH | C_PUNCT, // ∞
	C_GRAPH | C_PUNCT, // φ
	C_GRAPH | C_PUNCT, // ε
	C_GRAPH | C_PUNCT, // ∩
	C_GRAPH | C_PUNCT, // ≡
	C_GRAPH | C_PUNCT, // ±
	C_GRAPH | C_PUNCT, // ≥
	C_GRAPH | C_PUNCT, // ≤
	C_GRAPH | C_PUNCT, // ⌠
	C_GRAPH | C_PUNCT, // ⌡
	C_GRAPH | C_PUNCT, // ÷
	C_GRAPH | C_PUNCT, // ≈
	C_GRAPH | C_PUNCT, // °
	C_GRAPH | C_PUNCT, // ∙
	C_GRAPH | C_PUNCT, // ·
	C_GRAPH | C_PUNCT, // √
	C_GRAPH | C_PUNCT, // ⁿ
	C_GRAPH | C_PUNCT, // ²
	C_GRAPH | C_PUNCT, // ■
	C_GRAPH | C_PUNCT, //
	};

#define CTYPE_CHKTYPE(_CH_, _TYPE_) \
	(((CTYPE_TYPE[_CH_] & (_TYPE_)) > 0) ? 1 : 0)

#define CTYPE_TOLOWER(_CH_) \
	((((_CH_) < 'A') || ((_CH_) > 'Z')) ? (_CH_) : \
	((((_CH_) - 'A') + 'a') % 0xff))

#define CTYPE_TOUPPER(_CH_) \
	((((_CH_) < 'a') || ((_CH_) > 'z')) ? (_CH_) : \
	((((_CH_) - 'a') + 'A') % 0xff))

int isalnum(
	__in int ch
	)
{
	return CTYPE_CHKTYPE(ch & 0xff, C_ALPHA | C_DIGIT);
}

int isalpha(
	__in int ch
	)
{
	return CTYPE_CHKTYPE(ch & 0xff, C_ALPHA);
}

int iscntrl(
	__in int ch
	)
{
	return CTYPE_CHKTYPE(ch & 0xff, C_CNTRL);
}

int isdigit(
	__in int ch
	)
{
	return CTYPE_CHKTYPE(ch & 0xff, C_DIGIT);
}

int isgraph(
	__in int ch
	)
{
	return CTYPE_CHKTYPE(ch & 0xff, C_GRAPH);
}

int islower(
	__in int ch
	)
{
	return CTYPE_CHKTYPE(ch & 0xff, C_LOWER);
}

int isprint(
	__in int ch
	)
{
	return CTYPE_CHKTYPE(ch & 0xff, C_ALPHA | C_DIGIT | C_PUNCT | C_SPACE);
}

int ispunct(
	__in int ch
	)
{
	return CTYPE_CHKTYPE(ch & 0xff, C_PUNCT);
}

int isspace(
	__in int ch
	)
{
	return CTYPE_CHKTYPE(ch & 0xff, C_SPACE);
}

int isupper(
	__in int ch
	)
{
	return CTYPE_CHKTYPE(ch & 0xff, C_UPPER);
}

int isxdigit(
	__in int ch
	)
{
	return CTYPE_CHKTYPE(ch & 0xff, C_XDIGIT);
}

int tolower(
	__in int ch
	)
{
	return CTYPE_TOLOWER(ch & 0xff);
}

int toupper(
	__in int ch
	)
{
	return CTYPE_TOUPPER(ch & 0xff);
}
