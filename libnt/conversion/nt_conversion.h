#ifndef NT_CONVERSION
#define NT_CONVERSION

# include <stdlib.h>
# include "../str_utils/nt_str_utils.h"

#define MIN_INT -2147483648
#define MIN_INT_STR "-2147483648"
#define HEX_LOWER "0123456789abcdef"
#define HEX_UPPER "0123456789ABCDEF"

char nt_itochar(const int n);
char* nt_itoa(int n);
char* nt_itohex(unsigned long value, char *base);

#endif