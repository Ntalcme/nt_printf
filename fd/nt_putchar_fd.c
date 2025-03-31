# include "nt_fd.h"

int nt_putchar_fd(const char c, const int fd)
{
    return write(fd, &c, 1);
}