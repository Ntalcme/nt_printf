#ifndef NT_PRINTF
#define NT_PRINTF

# include <stdarg.h>
# include "libnt/libnt.h"

ssize_t nt_printf(const char *str, ...);

#endif