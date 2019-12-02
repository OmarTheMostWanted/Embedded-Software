/* Copyright (C) 2011 G.P. Halkes
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License version 3, as
   published by the Free Software Foundation.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "config.h"
#include "config_errors.h"

#include <string.h>
#include <errno.h>

#ifndef T3_DONT_CHECK_VERSION
/* The array is embedded in a struct, such that compilers don't complain about
   unused static variables. */
struct _t3_assert_version_check {
	int static_assert_version_not_0[T3_CONFIG_VERSION > 0 ? 1 : -1];
};
#endif

#ifdef USE_GETTEXT
#include <libintl.h>
#define _(x) dgettext("LIBT3", (x))
#else
#define _(x) (x)
#endif

const char *t3_config_strerror_base(int error) {
	switch (error) {
		case T3_ERR_SUCCESS:
			return _("success");
		case T3_ERR_ERRNO:
			return strerror(errno);
		case T3_ERR_EOF:
			return _("end of file");
		default: /* FALLTHROUGH */
		case T3_ERR_UNKNOWN:
			return _("unknown error");
		case T3_ERR_BAD_ARG:
			return _("bad argument passed to function");
		case T3_ERR_OUT_OF_MEMORY:
			return _("out of memory");
		case T3_ERR_TERMINFODB_NOT_FOUND:
			return _("no information found in terminfo database for terminal");
		case T3_ERR_HARDCOPY_TERMINAL:
			return _("terminal is a hard-copy terminal");
		case T3_ERR_TERMINAL_TOO_LIMITED:
			return _("terminal provides too limited functionality");
		case T3_ERR_NO_TERM:
			return _("no terminal given and TERM environment variable not set");
		case T3_ERR_INTERNAL:
			return _("internal error");
	}
}
