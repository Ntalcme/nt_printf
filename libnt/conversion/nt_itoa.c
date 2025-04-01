# include "nt_conversion.h"

/**
 * Return the number of digits of an integer 
 * @param n The integer
 * @return The number of digit
 */
static int digits_size(int n)
{
    int res;

    res = 0;
    if (n < 0)
    {
        res++;
        n *= -1;
    }

    while (n)
    {
        n /= 10;
        res++;
    }

    return (res);
}

/**
 * Convert an integer to a character string
 * @param n - The integer
 * @return  A char pointer to the converted integer
 */
char *nt_itoa(int n)
{
    char *res;
    int i;

    if (n == 0)
    {
        return nt_strdup("0");
    }

    if (n == MIN_INT)
    {
        return nt_strdup(MIN_INT_STR);
    }

    i = digits_size(n);
    res = malloc(sizeof(char) * (i+1));

    if (!res) 
    {
        return (NULL);
    }

    res[i--] = '\0';
    if (n < 0)
    {
        res[0] = '-';
        n *= -1;
    }

    while (n)
    {
        res[i--] = nt_itochar(n % 10);
        n /= 10;
    }

    return (res);
}