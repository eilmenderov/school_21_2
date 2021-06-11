#include "libftprintf.h"

int	ft_avrazm_xuo(unsigned int c, int sys, t_flag *data)
{
	int	result;

	result = 0;
	while (c / sys)
	{
		c = c / sys;
		result++;
	}
	if (!data->f_dot && data->numb > result && data->f_zero)
		result = data->numb - 1;
	return (result + 1);
}

void	ft_avstr_nbr_xuo(unsigned int nb, int razm, char *rez, char *sys)
{
	int	i;

	i = ft_avstrlen_s(sys, 0);
	if (nb / i)
		ft_avstr_nbr_xuo(nb / i, razm - 1, rez, sys);
	rez[razm - 1] = sys[nb % i];
}

char	*ft_avitoa_m_xuo(unsigned int n, char *sys, t_flag *data)
{
	int		razm;
	int		i;
	char	c;
	char	*rez;

	razm = ft_avrazm_xuo(n, ft_avstrlen_s(sys, 0), data);
	if (razm < data->accur)
		razm = data->accur;
	rez = malloc(sizeof(char) * (razm + 1));
	if (!rez)
		return (ft_avmal_def(rez, data));
	if (n == 0 && data->accur == 0 && data->f_dot != 0)
		c = 32;
	else
		c = 48;
	i = -1;
	while (i++ < razm)
		rez[i] = 48;
	rez[razm] = 0;
	ft_avstr_nbr_xuo(n, razm, rez, sys);
	return (rez);
}

char	*ft_avadd_xnum(unsigned int num, t_flag *data)
{
	char	*rez;
	int		i;

	if (data->type == 120)
		rez = ft_avitoa_m_xuo(num, "0123456789abcdef", data);
	if (data->type == 88)
		rez = ft_avitoa_m_xuo(num, "0123456789ABCDEF", data);
	if (data->type == 117)
		rez = ft_avitoa_m_xuo(num, "0123456789", data);
	if (data->type == 111)
		rez = ft_avitoa_m_xuo(num, "01234567", data);
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
