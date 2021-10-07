#include <stdio.h>
#include "./srcs/ft_printf.h"

#define VURA	"|%+d|\n"

int	main(void)
{
	unsigned int num = 0;
	int	i;
	int	j;

	i = printf(VURA, num);
	j = ft_printf(VURA, num);
	if (i == j)
		printf("OK\n");
	else
		printf("KO\n");
	ft_printf("%7.7s%7.7s", "hello", "world");
	ft_printf("%9.2p\n", 1234);
	ft_printf("this %d number", -267);
	ft_printf("%07d", -54);
	ft_printf("%10.5i", -216);
	ft_printf("%5u", 52625);
	ft_printf("%-7x", 33);
	ft_printf("%.4X", 5263);
	ft_printf("%-i", 42);
	ft_printf("%c", 't');
	ft_printf("%+-3.7i", -2375);
	ft_printf("%c %2s %% %-.2d", 0, "asdasd", 34);
	sleep(5);
	return (0);
}

//  make && gcc -Wall -Wextra -Werror main.c libftprintf.a && ./a.out && rm a.out
//	make re && ./test