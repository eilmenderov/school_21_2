#include "libftprintf.h"

void	ft_avhelp_signint(t_flag *data, int n, int razm, char *rez)
{
	char	c;
	int		i;

	if (n == 0 && data->accur == 0 && data->f_dot != 0)
		c = 32;
	else
		c = 48;
	i = 0;
	while (i < razm)
	{
		rez[i] = c;
		i++;
	}
	rez[razm] = 0;
	if (data->f_space && data->accur >= data->numb && n >= 0)
	{
		write(1, " ", 1);
		data->len = data->len + 1;
	}
}

int	ft_avrazm_di(int c, int sys, t_flag *data)
{
	int	result;

	result = 0;
	if (c < 0)
		result++;
	while (c / sys)
	{
		c = c / sys;
		result++;
	}
	if (!data->f_dot && data->numb > result && data->f_zero)
		result = data->numb - 1;
	return (result + 1);
}

void	ft_avstr_nbr_di(int nb, int razm, char *rez, char *sys)
{
	int	i;

	i = ft_avstrlen_s(sys, 0);
	if (nb == -2147483648)
	{
		ft_avstr_nbr_di(nb / i, razm - 1, rez, sys);
		rez[razm - 1] = sys[-(nb % i)];
	}
	else if (nb < 0)
	{
		rez[0] = 45;
		ft_avstr_nbr_di(-nb, razm, rez, sys);
	}
	else
	{
		if (nb / i)
			ft_avstr_nbr_di(nb / i, razm - 1, rez, sys);
		rez[razm - 1] = sys[nb % i];
	}
}

char	*ft_avitoa_m_di(int n, char *sys, t_flag *data)
{
	int		razm;
	char	*rez;

	razm = ft_avrazm_di(n, ft_avstrlen_s(sys, 0), data);
	if (razm < data->accur)
	{
		razm = data->accur;
		if (n < 0)
			razm++;
	}
	if (n < 0 && razm == data->accur)
		razm++;
	rez = malloc(sizeof(char) * (razm + 1));
	if (!rez)
		return (ft_avmal_def(rez, data));
	ft_avhelp_signint(data, n, razm, rez);
	ft_avstr_nbr_di(n, razm, rez, sys);
	return (rez);
}

char	*ft_avadd_int(int num, t_flag *data)
{
	char	*rez;
	int		i;

	rez = ft_avitoa_m_di(num, "0123456789", data);
	if (rez && data->accur == 0 && num == 0 && data->numb == 0
		&& data->f_dot != 0)
		rez[0] = 0;
	if (rez && data->accur == 0 && num == 0 && data->numb != 0
		&& data->f_dot != 0)
	{
		i = -1;
		while (rez[++i])
		{
			if (rez[i] == '0')
				rez[i] = ' ';
		}
	}
	return (rez);
}
