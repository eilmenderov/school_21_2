#include "libftprintf.h"

int	ft_avrazm_p(unsigned long long c, int sys)
{
	int	result;

	result = 0;
	while (c / sys)
	{
		c = c / sys;
		result++;
	}
	return (result + 1);
}

void	ft_avstr_nbr_p(unsigned long long nb, int razm, char *rez, char *sys)
{
	int	i;

	i = ft_avstrlen_s(sys, 0);
	if (nb / i)
		ft_avstr_nbr_p(nb / i, razm - 1, rez, sys);
	rez[razm - 1] = sys[nb % i];
}

char	*ft_avitoa_m_p(unsigned long long n, char *sys, t_flag *data)
{
	int		razm;
	int		i;
	char	*rez;

	razm = ft_avrazm_p(n, ft_avstrlen_s(sys, 0)) + 2;
	if (razm < data->accur)
		razm = data->accur + 2;
	rez = malloc(sizeof(char) * (razm + 1));
	if (!rez)
		return (ft_avmal_def(rez, data));
	rez[razm] = 0;
	i = -1;
	while (i++ < razm)
		rez[i] = 48;
	ft_avstr_nbr_p(n, razm, rez, sys);
	rez[razm] = 0;
	rez[0] = '0';
	rez[1] = 'x';
	if (data->f_dot && !data->accur)
		rez[2] = 0;
	return (rez);
}

char	*ft_avadd_pointer(unsigned long long num, t_flag *data)
{
	char	*rez;

	rez = ft_avitoa_m_p(num, "0123456789abcdef", data);
	return (rez);
}
