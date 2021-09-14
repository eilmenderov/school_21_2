#include "libftprintf.h"

char	*ft_avadchr_helper(char c, t_flag *data, char x)
{
	x = ' ';
	if (data->f_zero && !data->f_minus)
		x = '0';
	if (data->f_minus)
	{
		write(1, &c, 1);
		while (data->numb-- > 1)
		{
			write(1, &x, 1);
			data->len = data->len + 1;
		}
	}
	else
	{
		while (data->numb-- > 1)
		{
			write(1, &x, 1);
			data->len = data->len + 1;
		}
		write(1, &c, 1);
	}
	data->len = data->len + 1;
	return (NULL);
}

char	*ft_avadd_char(char c, t_flag *data)
{
	char	*rez;

	if (data->numb == 0)
		data->numb = 1;
	if (c == 0 && data->numb < 0)
	{
		data->numb = -data->numb;
		data->f_minus++;
	}
	if (c == 0)
		return (ft_avadchr_helper(c, data, 0));
	rez = malloc(sizeof(char) * 2);
	if (!rez)
		return (ft_avmal_def(rez, data));
	rez[0] = c;
	rez[1] = 0;
	return (rez);
}

char	*ft_avadd_char_pr(t_flag *data)
{
	char	*rez;

	if (data->numb == 0)
		data->numb = 1;
	rez = malloc(sizeof(char) * 2);
	if (!rez)
		return (ft_avmal_def(rez, data));
	rez[0] = '%';
	rez[1] = 0;
	return (rez);
}

char	*ft_avadd_str(char *str, t_flag *data)
{
	char	*rez;
	char	*buf;
	int		i;

	if (!str)
	{
		buf = "(null)";
		rez = malloc(sizeof(char) * 7);
		if (!rez)
			return (ft_avmal_def(rez, data));
		i = -1;
		while (i++ < 7)
			rez[i] = buf[i];
		return (rez);
	}
	i = ft_avstrlen_s(str, 0) + 1;
	rez = malloc(sizeof(char) * i);
	if (!rez)
		return (ft_avmal_def(rez, data));
	while (--i != -1)
		rez[i] = str[i];
	return (rez);
}
