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
#ifndef T3_CONFIG_ERRORS_H
#define T3_CONFIG_ERRORS_H

#include "config_api.h"

/** @file */
/** @addtogroup t3config_other */
/** @{ */

/** @name Error codes (T3 generic) */
/*@{*/
#ifndef T3_ERR_SUCCESS
/** Error code: success */
#define T3_ERR_SUCCESS 0
/** Error code: see @c errno. */
/* Use large negative value, such that we don't have to number each and
   every value. */
#define T3_ERR_ERRNO (-128)
/** Error code: end of file reached. */
#define T3_ERR_EOF (-127)
/** Error code: unkown error. */
#define T3_ERR_UNKNOWN (-126)
/** Error code: bad argument. */
#define T3_ERR_BAD_ARG (-125)
/** Error code: out of memory. */
#define T3_ERR_OUT_OF_MEMORY (-124)
/** Error code: no information found for the terminal in the terminfo database. */
#define T3_ERR_TERMINFODB_NOT_FOUND (-123)
/** Error code: the file descriptor is a hard-copy terminal. */
#define T3_ERR_HARDCOPY_TERMINAL (-122)
/** Error code: terminal provides too limited possibilities for the library to function. */
#define T3_ERR_TERMINAL_TOO_LIMITED (-121)
/** Error code: no terminal given and @c TERM environment variable not set. */
#define T3_ERR_NO_TERM (-120)
/** Error code: internal error in the library. */
#define T3_ERR_INTERNAL (-119)
/** Warning code: the smallest value returned as warning. */
#define T3_WARN_MIN (-16)
#endif
/*@}*/

/* Each extension of the list of common errors should be done with an ifdef
   such that when several different versions of the config error header are
   included each symbol will be defined and only defined once. */

/** @} */

/** @internal
	@brief strerror routine for generic errors.

	Should only be called from the library's strerror function for all errors
	that are not defined specifically by the library itself.
*/
T3_CONFIG_LOCAL const char *t3_config_strerror_base(int error);

#endif
