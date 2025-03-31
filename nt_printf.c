# include "nt_printf.h"

static ssize_t manage_flags(char flg, va_list args)
{
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
        case '%':
            return nt_putchar_fd('%', STDOUT_FILENO);
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

int main(void)
{
    nt_printf("Test : %d\n", 12);
    return 0;
}