Introduction

The versatility of the printf function in C represents a great exercise in programming for us. This project is of moderate difficulty. It will enable you to discover variadic functions in C.
The key to a successful ft_printf is a well-structured and good extensible code.

conversions:	"cspdiuxX%"

flags:	'-0.*'

test libftprintf:

make re && make clean && gcc -Wall -Wextra main.c libftprintf.a && ./a.out | cat -e && make fclean && rm a.out
