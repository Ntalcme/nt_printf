#ifndef NT_FD_H
#define NT_FD_H

#define MIN_INT -2147483648
#define ERROR_WRITING -1

# include <unistd.h>
# include "../str_utils/nt_str_utils.h"

int nt_putchar_fd(const char c, const int fd);
int nt_putstr_fd(const char *str, const int fd);

#endif