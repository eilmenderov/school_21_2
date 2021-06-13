#include "libftprintf.h"

int	ft_avfind_number(t_flag *data, char ***str)
{
	unsigned long long	res;

	data->f_num++;
	res = 0;
	while (***str && ***str >= '0' && ***str <= '9' && res <= 2147483647)
	{
		res = res * 10 + (***str - 48);
		**str = **str + 1;
	}
	if (data->numb || res > 2147483647)
		data->fl = -10;
	data->numb = (int)res;
	if (data->numb == 0 && ***str == '*')
	{
		data->f_num = -1;
		if (*(**str + 1) != 0 && *(**str + 1) != '.')
			data->fl = -4;
	}
	if (***str != 0 && ***str != '.' && ***str != '*')
		data->fl = -5;
	return (0);
}

int	ft_avfind_accur(t_flag *data, char ***str)
{
	unsigned long long	res;

	**str = **str + 1;
	data->f_dot++;
	res = 0;
	while (***str && res <= 2147483647 && ***str >= '0' && ***str <= '9')
	{
		res = res * 10 + (***str - 48);
		**str = **str + 1;
	}
	if ((***str != 0 && ***str != '*') || res > 2147483647 || data->accur)
	{
		data->fl = -11;
		return (0);
	}
	data->accur = (int)res;
	if (data->accur == 0 && ***str == '*')
	{
		data->f_dot = -1;
		if (*(**str + 1) != 0)
			data->fl = -6;
	}
	return (0);
}

int	ft_avthis_is_flag(char **st, t_flag *data)
{
	if ((**st < '-' || **st > '9' || **st == 47) && **st != 32 && **st != 42)
		return (1);
	if ((**st >= '1' && **st <= '9') || **st == '*')
		ft_avfind_number(data, &st);
	if (**st == '.')
		ft_avfind_accur(data, &st);
	if (**st == '-')
		data->f_minus++;
	if (**st == ' ')
		data->f_space++;
	if (**st == '0')
		data->f_zero++;
	return (0);
}

int	ft_avdef_fl(t_flag *data)
{
	if (data->accur >= 2147483632 || data->accur <= -2147483632
		|| data->numb >= 2147483632 || data->numb <= -2147483632)
	{
		data->fl = -1;
		return (1);
	}
	if (data->accur < 0)
	{
		data->f_dot = 0;
		data->accur = 0;
	}
	if ((data->type == 100 || data->type == 105) && data->f_zero
		&& !data-> f_dot && !data->accur && data->numb && data->f_minus)
	{
		data->accur = 0;
		data->f_dot = 0;
		data->f_zero = 0;
	}
	return (0);
}

void	ft_avnow_flags(t_flag *data)
{
	char	*prfl;

	if (!data->parc_flags)
		return ;
	if (data->fl)
	{
		free (data->parc_flags);
		return ;
	}
	prfl = data->parc_flags;
	while (*prfl && !data->fl)
	{
		if (ft_avthis_is_flag(&prfl, data))
			data->fl = -3;
		if (*prfl)
			prfl++;
	}
	free (data->parc_flags);
	data->parc_flags = NULL;
}
