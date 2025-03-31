# include "nt_fd.h"

int nt_putstr_fd(const char *str, const int fd)
{
    return write(fd, str, nt_strlen(str));
}