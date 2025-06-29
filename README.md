# nt_printf - Custom printf Implementation

**nt_printf** is a custom implementation of the standard `printf` function in C, designed to handle various format specifiers and print outputs to the console.

## Features

- Supports the standard format specifiers:
    - `%%` - Literal percent sign (`%`)
    - `%c` - Character
    - `%s` - String
    - `%d` - Decimal integer
    - `%i` - Integer
    - `%u` - Unsigned integer
    - `%x` - Hexadecimal (lowercase) (unsigned integer)
    - `%X` - Hexadecimal (uppercase) (unsigned integer)
    - `%p` - Pointer address
    - `%o` - Octal (unsigned integer)
## Installation (with GCC compiler)

1. Clone this repository:

    ```bash
    git clone https://github.com/Ntalcme/nt_printf.git
    ```

2. Navigate into the project directory:
    ```bash
    cd nt_printf
    ```

3. Build the static library using `make`:
    ```bash
    make
    ```

This will generate a static library file named `libntprintf.a` in the project directory.

4. Include the library in your project:

    - Copy the `libntprintf.a` file to your project's directory or link it during compilation.

    - Include the `nt_printf.h` header file in your C source files.

Example compilation in your project:
```bash
gcc your_program.c -I./path_to_nt_printf -L./path_to_nt_printf -lntprintf -o your_program
```
Where `./path_to_nt_printf` is the path where you placed the libntprintf.a file.

## Usage
Once you've linked the `libntprintf.a` library, you can use it just like the standard printf function. Include the `nt_printf.h` header and call `nt_printf()` with your desired format specifiers:
```c
#include "nt_printf.h"

int main(void)
{
    nt_printf("Hello, %s! Your score is %d.\n", "Ntalcme", 12);
    nt_printf("Displaying percentage: %%\n");
    return 0;
}
```
This will print:
```
Hello, Ntalcme! Your score is 12.
Displaying percentage: %
```

## License
This project is licensed under the BSD-3-Clause License - see the [LICENSE](./LICENSE) file for details.

## Author
[Ntalcme](https://github.com/Ntalcme)

## Acknowledgements
- Inspired by the original printf function in the C standard library.

- Special thanks to [Panda](https://github.com/panda2742) for teaching me !

- Special thanks to the open-source community for inspiration !
