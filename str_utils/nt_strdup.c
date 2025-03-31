# include "nt_str_utils.h"

char *nt_strdup(const char *str)
{
        char    *res;
        int     reslen;  
        int     i;

        reslen = nt_strlen(str);
        res = malloc(sizeof(char) * (reslen + 1));

        if (!res)
        {
            return (NULL);
        }

        i = 0;
        while (i < reslen)
        {
            res[i] = str[i];
            i++;
        }
        res[i] = '\0';

        return (res);
}