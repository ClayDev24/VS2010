/* socket++/config.h.  Generated automatically by configure.  */
/* socket++/config.h.in.  Generated automatically from configure.in by autoheader.  */

/* Define if you have <sys/wait.h> that is POSIX.1 compatible.  */
#define HAVE_SYS_WAIT_H 1

/* Define if you have <vfork.h>.  */
/* #undef HAVE_VFORK_H */

/* Define to `int' if <sys/types.h> doesn't define.  */
/* #undef pid_t */

/* Define as the return type of signal handlers (int or void).  */
#define RETSIGTYPE void

/* Define if you have the ANSI C header files.  */
#define STDC_HEADERS 1

/* Define if `sys_siglist' is declared by <signal.h>.  */
/* #undef SYS_SIGLIST_DECLARED */

/* Define vfork as fork if vfork does not work.  */
#define vfork fork

/* Define if extern "C" is needed arround include files */
#define EXTERN_C_BEGIN 
#define EXTERN_C_END 

/* Define either as _sys_siglist or sys_siglist */
#define SYS_SIGLIST sys_siglist

/* Define the argument type for signal handler function */
#define SIGHND_ARGTYPE ...

/* Define either as _sys_errlist or sys_errlist */
#define SYS_ERRLIST sys_errlist

/* Define SYS_ERRLIST_DECLARED if extern char* SYS_ERRLIST []; is found */
#define SYS_ERRLIST_DECLARED 1

/* Define if you have libg++ */
#define _S_LIBGXX 1

/* Configuration Options */
/* #undef ENABLE_DEBUG */

/* Define if you have the select function.  */
#define HAVE_SELECT 1

/* Define if you have the <memory.h> header file.  */
#define HAVE_MEMORY_H 1

/* Define if you have the <sstream> header file.  */
#define HAVE_SSTREAM 1

/* Define if you have the <string> header file.  */
#define HAVE_STRING 1

/* Define if you have the <string.h> header file.  */
#define HAVE_STRING_H 1

/* Name of package */
#define PACKAGE "socket++"

/* Version number of package */
#define VERSION "1.12.10"

#include "local.h"
