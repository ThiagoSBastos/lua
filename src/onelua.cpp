/*
** Lua core, libraries, and interpreter in a single file.
** Compiling just this file generates a complete Lua stand-alone
** program:
**
** $ gcc -O2 -std=c99 -o lua onelua.cpp -lm
**
** or
**
** $ gcc -O2 -std=c89 -DLUA_USE_C89 -o lua onelua.cpp -lm
**
*/

/* default is to build the full interpreter */
#ifndef MAKE_LIB
#ifndef MAKE_LUAC
#ifndef MAKE_LUA
#define MAKE_LUA
#endif
#endif
#endif


/*
** Choose suitable platform-specific features. Default is no
** platform-specific features. Some of these options may need extra
** libraries such as -ldl -lreadline -lncurses
*/
#if 0
#define LUA_USE_LINUX
#define LUA_USE_MACOSX
#define LUA_USE_POSIX
#define LUA_ANSI
#endif


/* no need to change anything below this line ----------------------------- */

#include "lprefix.h"

#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <float.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <setjmp.h>
#include <signal.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


/* setup for luaconf.h */
#define LUA_CORE
#define LUA_LIB
#define ltable_c
#define lvm_c
#include "luaconf.h"

/* do not export internal symbols */
#undef LUAI_FUNC
#undef LUAI_DDEC
#undef LUAI_DDEF
#define LUAI_FUNC	static
#define LUAI_DDEC(def)	/* empty */
#define LUAI_DDEF	static

/* core -- used by all */
#include "lzio.cpp"
#include "lctype.cpp"
#include "lopcodes.cpp"
#include "lmem.cpp"
#include "lundump.cpp"
#include "ldump.cpp"
#include "lstate.cpp"
#include "lgc.cpp"
#include "llex.cpp"
#include "lcode.cpp"
#include "lparser.cpp"
#include "ldebug.cpp"
#include "lfunc.cpp"
#include "lobject.cpp"
#include "ltm.cpp"
#include "lstring.cpp"
#include "ltable.cpp"
#include "ldo.cpp"
#include "lvm.cpp"
#include "lapi.cpp"

/* auxiliary library -- used by all */
#include "lauxlib.cpp"

/* standard library  -- not used by luac */
#ifndef MAKE_LUAC
#include "lbaselib.cpp"
#include "lcorolib.cpp"
#include "ldblib.cpp"
#include "liolib.cpp"
#include "lmathlib.cpp"
#include "loadlib.cpp"
#include "loslib.cpp"
#include "lstrlib.cpp"
#include "ltablib.cpp"
#include "lutf8lib.cpp"
#include "linit.cpp"
#endif

/* lua */
#ifdef MAKE_LUA
#include "lua.cpp"
#endif

/* luac */
#ifdef MAKE_LUAC
#include "luac.cpp"
#endif
