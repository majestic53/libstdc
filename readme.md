LIBSTDC
=======

LIBSTDC is an implementation of the C89 standard library for x86 processors, with support for some C99 features.

##Supported Headers
* [assert.h](https://github.com/majestic53/libstdc/blob/master/src/lib/include/assert.h) -- assertion routine
* [ctype.h](https://github.com/majestic53/libstdc/blob/master/src/lib/include/ctype.h) -- check character types
* [errno.h](https://github.com/majestic53/libstdc/blob/master/src/lib/include/errno.h) -- access to errno
* [float.h](https://github.com/majestic53/libstdc/blob/master/src/lib/include/float.h) -- floating-point constants
* [iso646.h](https://github.com/majestic53/libstdc/blob/master/src/lib/include/iso646.h) -- alternative operators
* [limits.h](https://github.com/majestic53/libstdc/blob/master/src/lib/include/limits.h) -- various scalar constants
* [locale.h](https://github.com/majestic53/libstdc/blob/master/src/lib/include/locale.h) -- localization settings
* [WIP] [math.h](https://github.com/majestic53/libstdc/blob/master/src/lib/include/math.h) -- math routines
* [setjmp.h](https://github.com/majestic53/libstdc/blob/master/src/lib/include/setjmp.h) -- set/long jump macros
* [signal.h](https://github.com/majestic53/libstdc/blob/master/src/lib/include/signal.h) -- signal handling
* [stdarg.h](https://github.com/majestic53/libstdc/blob/master/src/lib/include/stdarg.h) -- macros for handling variadics
* [stdbool.h](https://github.com/majestic53/libstdc/blob/master/src/lib/include/stdbool.h) *(C99)* -- boolean type definition
* [stddef.h](https://github.com/majestic53/libstdc/blob/master/src/lib/include/stddef.h) -- alternative scalar type definitions
* [WIP] [stdio.h](https://github.com/majestic53/libstdc/blob/master/src/lib/include/stdio.h) -- io routines
* [stdint.h](https://github.com/majestic53/libstdc/blob/master/src/lib/include/stdint.h) *(C99)* -- various scalar type definitions
* [WIP] [stdlib.h](https://github.com/majestic53/libstdc/blob/master/src/lib/include/stdlib.h) -- various routines
* [string.h](https://github.com/majestic53/libstdc/blob/master/src/lib/include/string.h) -- string handling routines
* [time.h](https://github.com/majestic53/libstdc/blob/master/src/lib/include/time.h) -- time routines

Table of Contents
=================

1. [Changelog](https://github.com/majestic53/libstdc#changelog)
2. [License](https://github.com/majestic53/libstdc#license)

Changelog
=========

##Version 0.1.1536
*Updated:9/1/2015*

* Implemented additional math routines

*Updated: 8/31/2015*

* Implemented additional math routines

##Version 0.1.1535
*Updated: 8/30/2015*

* Implemented additional math routines

*Updated: 8/29/2015*

* Implemented additional library header (math (partial), signal)
* Code refactor/cleanup

*Updated: 8/28/2015*

* Implemented additional time routines (complete)
* Minor code cleanup

*Updated: 8/27/2015*

* Implemented additional time routines (partial)

*Updated: 8/26/2015*

* Added extension library
* Further implmented library header (time)

*Updated: 8/25/2015*

* Added library header (setjmp, time (partial))

*Updated: 8/24/2015*

* Added library header (stdarg)

##Version 0.1.1534
*Updated: 8/23/2015*

* Added additional library headers (string, stdarg (partial), stddef)

*Updated: 8/22/2015*

* Added additional library headers (iso646, locale, string (partial))

*Updated: 8/21/2015*

* Added additional library headers (errno, float, limits, stdbool, stdint)

*Updated: 8/20/2015*

* Initial commit

*Changelog truncated (see file history for full log)*

License
=======

Copyright(C) 2015 David Jolly <majestic53@gmail.com>

libstdc is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

libstdc is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
