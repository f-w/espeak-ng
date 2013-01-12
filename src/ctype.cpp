/* ctype-style APIs.
 *
 * Copyright (C) 2012-2013 Reece H. Dunn
 *
 * This file is part of ucd-tools.
 *
 * ucd-tools is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * ucd-tools is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with ucd-tools.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "ucd/ucd.h"

int ucd::isalnum(codepoint_t c)
{
	switch (lookup_category(c))
	{
	case Ll: case Lm: case Lo: case Lt: case Lu:
	case Nd: case Nl: case No:
		return 1;
	default:
		return 0;
	}
}

int ucd::isalpha(codepoint_t c)
{
	switch (lookup_category(c))
	{
	case Ll: case Lm: case Lo: case Lt: case Lu:
		return 1;
	default:
		return 0;
	}
}

int ucd::iscntrl(codepoint_t c)
{
	return lookup_category(c) == Cc;
}

int ucd::isdigit(codepoint_t c)
{
	switch (lookup_category(c))
	{
	case Nd: case Nl: case No:
		return 1;
	default:
		return 0;
	}
}

int ucd::isgraph(codepoint_t c)
{
	switch (lookup_category(c))
	{
	case Cc: case Cf: case Cn: case Co: case Cs:
	case Zl: case Zp: case Zs:
	case Ii:
		return 0;
	default:
		return 1;
	}
}

int ucd::islower(codepoint_t c)
{
	return lookup_category(c) == Ll;
}

int ucd::isprint(codepoint_t c)
{
	switch (lookup_category(c))
	{
	case Cc: case Cf: case Cn: case Co: case Cs:
	case Ii:
		return 0;
	default:
		return 1;
	}
}

int ucd::ispunct(codepoint_t c)
{
	switch (lookup_category(c))
	{
	case Pc: case Pd: case Pe: case Pf: case Pi: case Po: case Ps:
		return 1;
	default:
		return 0;
	}
}

int ucd::isspace(codepoint_t c)
{
	switch (lookup_category(c))
	{
	case Zl: case Zp: case Zs:
		return 1;
	case Cc:
		switch (c) // Some control characters are also whitespace characters:
		{
		case 0x09: // U+0009 : CHARACTER TABULATION
		case 0x0A: // U+000A : LINE FEED
		case 0x0B: // U+000B : LINE TABULATION
		case 0x0C: // U+000C : FORM FEED
		case 0x0D: // U+000D : CARRIAGE RETURN
		case 0x85: // U+0085 : NEXT LINE
			return 1;
		}
	default:
		return 0;
	}
}

int ucd::isupper(codepoint_t c)
{
	return lookup_category(c) == Lu;
}
