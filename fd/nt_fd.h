#ifndef NT_FD_H
#define NT_FD_H

#define MIN_INT -2147483648
#define ERROR_WRITING -1

# include <unistd.h>

int nt_putchar_fd(const char c, const int fd);

#endif