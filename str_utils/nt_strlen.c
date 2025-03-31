# include "nt_str_utils.h"

size_t nt_strlen(const char *str)
{
    size_t res;

    res = 0;
    while (str[res])
    {
        res++;
    }
    return (res);
}