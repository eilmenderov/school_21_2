#include "libftprintf.h"
#include <stdio.h>

#define INT_MIN -2147483648

int	main(void)
{
//	char	*str = "asdasdasd";
//	int		df = 24;
//	int		dot = 2;
//	int		len = 10;
	// int	i;
	// int	j;

	// i =    printf("|%10.5.5d|\n", 30);
	// j = ft_printf("|%10.5.5d|\n", 30);
//	write(1, "1\0001\n", 4);
//	sleep (20);
	int	a = 123123;
	char	*str = "AB = %d\n";
	ft_printf(str, a);
	printf(str, a);
	return (0);
}
