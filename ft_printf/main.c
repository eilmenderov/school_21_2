#include "./srcs/libftprintf.h"
#include <stdio.h>

#define INT_MIN -2147483648

int	main(void)
{
	int		i;
	int		j;
	char	*str;

	str = "HELLO WORLD!";
	i =    printf("orig[i] - |%5.5d| |%s|\n", 30, str);
	j = ft_printf("mine[j] - |%5.5d| |%s|\n", 30, str);
	printf("i = %d j = %d\n", i, j);
	return (0);
}
