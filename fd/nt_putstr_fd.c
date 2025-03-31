# include "nt_fd.h"

/**
 * Write a character string in a file
 * @param str - The character string's pointer
 * @param fd - The file descriptor
 * @return The number of bytes written (-1 if there was an error)
 */
ssize_t nt_putstr_fd(const char *str, const int fd)
{
    return write(fd, str, nt_strlen(str));
}