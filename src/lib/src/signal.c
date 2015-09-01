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

#include "../include/errno.h"
#include "../include/signal.h"
#include "../include/stdio.h"
#include "../include/stdlib.h"

// signal handler list
static sig_hdl_t _sig[SIGMAX + 1] = { (sig_hdl_t) SIG_DFL };

int 
(raise) (
	__in int sig
	)
{
	int result = 0;
	sig_hdl_t hdl = (sig_hdl_t) SIG_DFL;

	// detect invalid signal request
	if(sig > SIGMAX) {
		errno = EINVAL;
		result = _INV(int);
		goto exit;
	}

	hdl = _sig[sig];
	if((hdl != (sig_hdl_t) SIG_ERR) 
			&& (hdl != (sig_hdl_t) SIG_IGN)) {

		// call handler and then set handle to default
		hdl(sig);
		_sig[sig] = (sig_hdl_t) SIG_DFL;
	} else if(hdl != (sig_hdl_t) SIG_IGN) {

		// default handler behavior is to terminate after performing an action
		switch(sig) {
			case SIGABRT:
				//fprintf(stderr, "%s\n", SIGABRT_STR);
				break;
			case SIGFPE:
				//fprintf(stderr, "%s\n", SIGFPE_STR);
				break;
			case SIGILL:
				//fprintf(stderr, "%s\n", SIGILL_STR);
				break;
			case SIGINT:
				//fprintf(stderr, "%s\n", SIGINT_STR);
				break;
			case SIGSEGV:
				//fprintf(stderr, "%s\n", SIGSEGV_STR);
				break;
			case SIGTERM: // fall-through
				break;
			default:
				//fprintf(stderr, "Signal #%i\n", sig);
				break;
		}

		//fprintf(stderr, "%s\n", SIGTERM_STR);
		//exit(sig);
	}

exit:
	return result;
}

sig_hdl_t 
(signal) (
	__in int sig,
	__in sig_hdl_t funct
	)
{
	sig_hdl_t result = funct;

	switch(sig) {
		case SIG_DFL:
		case SIG_IGN:

			// retrieve handler
			result = (sig_hdl_t) sig;
			break;
		default:

			if(sig > SIGMAX) {
				errno = EINVAL;
				result = (sig_hdl_t) SIG_ERR;
				goto exit;
			}

			// set new handler
			_sig[sig] = funct;
			break;
	}

exit:
	return result;
}
