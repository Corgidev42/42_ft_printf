# ft_printf - Custom printf Implementation in C

## 📌 Description
**ft_printf** is a custom implementation of the standard `printf` function in **C**, developed as part of the **42 School** curriculum. This project aims to reproduce the behavior of `printf` with a limited set of features, focusing on formatting and displaying various types of data.

Supported conversion specifiers:

- **%c** → Character
- **%s** → String
- **%p** → Pointer address
- **%d / %i** → Signed decimal integer
- **%u** → Unsigned decimal integer
- **%x** → Lowercase hexadecimal integer
- **%X** → Uppercase hexadecimal integer
- **%%** → Percent sign

---

## 🎮 Features

- 📝 **Custom number formatting** (signed, unsigned, hexadecimal)
- 🪄 **Null string handling**
- 🖨️ **Pointer address printing** in hexadecimal
- 🧑‍💻 **Modular structure** with utility functions
- ✅ **Error management** through return values

---

## 🛠 Compilation and Usage

### 🔧 **Compilation**
Compile the project with:
```sh
make
```

This will generate the `libftprintf.a` static library.

### ▶️ **Usage**
Link the library to your project and use `ft_printf` as you would with `printf`:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s! You are %d years old.\n", "Vincent", 25);
    return (0);
}
```

Compile your program with:
```sh
gcc main.c -L. -lftprintf
```

---

## 📂 Project Structure

```
ft_printf/
├── ft_printf.c           # Main ft_printf logic
├── ft_printf_utils.c     # Core output functions
├── ft_printf_utils2.c    # Utility functions for number sizing & hex
├── ft_printf.h           # Header file
├── Makefile              # Project compilation
├── README.md             # Project documentation
```

---

## ⌨️ Key Functions

| Function Name    | Description |
|------------------|-------------|
| `ft_printf()`    | Main function to format and print output |
| `ft_putchar()`   | Print a single character |
| `ft_putstr()`    | Print a string (handles NULL) |
| `ft_putnbr()`    | Print a signed integer |
| `ft_putunbr()`   | Print an unsigned integer |
| `ft_putnbrhexlow()` | Print a number in lowercase hexadecimal |
| `ft_putnbrhexup()`  | Print a number in uppercase hexadecimal |
| `ft_putptr()`    | Print a pointer address in hexadecimal |
| `number_size()`  | Get the number of digits in a signed integer |
| `unsigned_number_size()` | Get the number of digits in an unsigned integer |

---

## 📜 Author
- **vbonnard** (<vbonnard@student.42.fr>)

---

## 📌 Note
This project was developed as part of **42 School**. If you find any bugs or have suggestions, feel free to contribute!

