# include "nt_conversion.h"


static int hex_digits_needed(unsigned long value) {

    int res;

    if (value <= 15) return (1); 
    
    res = 0;
    while (value) {
        value >>= 4;  
        res++;
    }
    return (res);
}

char* nt_itohex(unsigned long value, char *base) {
    char *res; 
    int digits_needed;
    
    digits_needed = hex_digits_needed(value);

    res = malloc(sizeof(char) * (digits_needed + 3));
    if (!res) return (NULL);

    res[0] = '0';
    res[1] = 'x';
    for (int i = digits_needed + 1; i >= 2; --i) {
        res[i] = base[value & 0xF];  
        value >>= 4;
    }

    res[digits_needed + 2] = '\0';
    return (res);
}