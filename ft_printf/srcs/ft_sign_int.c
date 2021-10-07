/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sign_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleida <vleida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 13:28:18 by vleida            #+#    #+#             */
/*   Updated: 2021/10/06 13:28:19 by vleida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_help_signint(t_flag *data, int n, int razm, char *rez)
{
	char	c;
	int		i;

	c = '0';
	if (!n && !data->accur && data->f_dot)
		c = ' ';
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

int	ft_razm_di(int c, int sys, t_flag *data)
{
	int	result;

	result = 0;
	if (c < 0 || data->plus)
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

void	ft_str_nbr_di(int nb, int razm, char *sys, t_flag *data)
{
	int	i;

	i = data->sys_len;
	if (nb == -2147483648)
	{
		ft_str_nbr_di(nb / i, razm - 1, sys, data);
		data->rez[razm - 1] = sys[-(nb % i)];
	}
	else if (nb < 0)
	{
		data->rez[0] = '-';
		ft_str_nbr_di(-nb, razm, sys, data);
	}
	else
	{
		if (nb / i)
			ft_str_nbr_di(nb / i, razm - 1, sys, data);
		data->rez[razm - 1] = sys[nb % i];
		if (data->plus && data->nb >= 0)
		{
			data->rez[0] = '+';
			if (!data->nb && !data->accur && !data->numb && data->f_dot)
				data->rez[1] = 0;
		}
	}
}

char	*ft_itoa_m_di(int n, char *sys, t_flag *data)
{
	int		razm;

	razm = ft_razm_di(n, ft_strlen_s(sys, 0), data);
	if (razm < data->accur)
	{
		razm = data->accur;
		if (n < 0)
			razm++;
	}
	if (n < 0 && razm == data->accur)
		razm++;
	if (data->plus && razm <= data->accur)
		razm++;
	data->rez = malloc(sizeof(char) * (razm + 1));
	if (!data->rez)
		return (ft_mal_def(data->rez, data));
	ft_help_signint(data, n, razm, data->rez);
	data->sys_len = ft_strlen_s(sys, 0);
	data->nb = n;
	ft_str_nbr_di(n, razm, sys, data);
	return (data->rez);
}

char	*ft_add_int(int num, t_flag *data)
{
	char	*rez;
	int		i;

	rez = ft_itoa_m_di(num, "0123456789", data);
	if (rez && !data->accur && !num && !data->numb
		&& data->f_dot && !data->plus)
		rez[0] = 0;
	if (rez && !data->accur && !num && data->numb && data->f_dot)
	{
		i = -1;
		while (rez[++i])
		{
			if (rez[i] == '0')
			{
				rez[i] = ' ';
				if (data->f_dot && data->numb && !data->accur && !num)
					rez[i] = 0;
			}
		}
	}
	ft_sign_int_helper(data, num, rez);
	return (rez);
}
