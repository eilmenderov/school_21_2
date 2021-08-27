The aim of this project is to make you code a function that returns a line ending with a newline,
read from a file descriptor.

Goals

This project will not only allow you to add a very convenient function to your collection,
but it will also allow you to learn a highly interesting new concept in C programming: static variables.

test gnl:

gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 test.c get_next_line.c get_next_line_utils.c && ./a.out | cat -e && rm a.out
