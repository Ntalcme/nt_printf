# include "nt_printf.h"

static ssize_t manage_flags(char flg, va_list args)
{
    char *tmp;
    int tmpError;

    if (!flg)
    {
        return (0);
    }

    switch (flg)
    {
        case 'c':
           return nt_putchar_fd(va_arg(args, int), STDOUT_FILENO);
        case 'd':
            return nt_putnbr_fd(va_arg(args, int), STDOUT_FILENO);
        case 'i':
            return nt_putnbr_fd(va_arg(args, int), STDOUT_FILENO);
        case '%':
            return nt_putchar_fd('%', STDOUT_FILENO);
        case 's':
            return nt_putstr_fd((char*) va_arg(args, void*), STDOUT_FILENO);
        case 'p':
            tmp = nt_itohex((unsigned long)va_arg(args, void*), HEX_LOWER);
            if (!tmp) return (ERROR_WRITING);
            tmpError = nt_putstr_fd(tmp, STDOUT_FILENO);
            free(tmp);
            return tmpError;
        default:
            return (ERROR_WRITING);
    }
}

static ssize_t parsestr(const char *str, va_list args)
{
    ssize_t char_prtd;
    int tmp;
    int i;
    int error;

    i = 0;
    char_prtd = 0;
    tmp = 0;
    error = 0;
    while (str[i])
    {
        if (str[i] == '%')
        {
            tmp = manage_flags(str[i+1], args);
            if (tmp == ERROR_WRITING) 
            {
                error = 1;
            }
            char_prtd += tmp;
            i += 2;
            continue;
        }
        tmp = nt_putchar_fd(str[i++], STDOUT_FILENO);
        if (tmp == ERROR_WRITING) 
        {
            error = 1;
        }
        char_prtd += tmp;
    }

    return (error ? ERROR_WRITING : char_prtd);
}

/**
 * Remake of the printf function
 * Display a text in the standart output
 * @param str The character string (can't be NULL or empty)
 * @param ... Variable list of arguments corresponding to the format specifiers in `str`.
 * @return Return the number of bytes written (-1 if there has been any error)
*/
ssize_t nt_printf(const char *str, ...) 
{
    va_list args;
    ssize_t strlen;

    if (!str || !*str) 
    {
        return (ERROR_WRITING);
    }

    va_start(args, str);
    strlen = parsestr(str, args);
    va_end(args);
    
    return (strlen);
}