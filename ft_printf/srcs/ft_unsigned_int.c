/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleida <vleida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 13:28:21 by vleida            #+#    #+#             */
/*   Updated: 2021/10/06 13:28:22 by vleida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_razm_xuo(unsigned int c, int sys, t_flag *data)
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

void	ft_str_nbr_xuo(unsigned int nb, int razm, char *rez, char *sys)
{
	int	i;

	i = ft_strlen_s(sys, 0);
	if (nb / i)
		ft_str_nbr_xuo(nb / i, razm - 1, rez, sys);
	rez[razm - 1] = sys[nb % i];
	rez[razm] = 0;
}

char	*ft_itoa_m_xuo(unsigned int n, char *sys, t_flag *data, int i)
{
	int		razm;
	char	c;
	char	*rez;

	razm = ft_razm_xuo(n, ft_strlen_s(sys, 0), data);
	if (razm < data->accur)
		razm = data->accur;
	if ((data->type == 'x' || data->type == 'X') && data->resh
		&& n && data->numb != razm)
		razm = razm + 2;
	rez = malloc(sizeof(char) * (razm + 1));
	if (!rez)
		return (ft_mal_def(rez, data));
	c = 48;
	if (n == 0 && data->accur == 0 && data->f_dot != 0)
		c = 32;
	while (i++ < razm)
		rez[i] = '0';
	ft_str_nbr_xuo(n, razm, rez, sys);
	if ((data->type == 'x' || data->type == 'X') && data->resh && n)
	{
		rez[0] = '0';
		rez[1] = data->type;
	}
	return (rez);
}

char	*ft_add_xnum(unsigned int num, t_flag *data)
{
	char	*rez;
	int		i;

	if (data->type == 120)
		rez = ft_itoa_m_xuo(num, "0123456789abcdef", data, -1);
	if (data->type == 88)
		rez = ft_itoa_m_xuo(num, "0123456789ABCDEF", data, -1);
	if (data->type == 117)
		rez = ft_itoa_m_xuo(num, "0123456789", data, -1);
	if (data->type == 111)
		rez = ft_itoa_m_xuo(num, "01234567", data, -1);
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

void	ft_sign_int_helper(t_flag *data, int num, char *rez)
{
	if (!data->f_dot && !data->accur && data->numb && num >= 0 && data->f_space
		&& data->f_zero && !data->f_minus && ft_strlen_s(rez, 0) >= data->numb)
	{
		if (rez[0] == '0')
			rez[0] = ' ';
		else
			ft_write_len(data, 0);
	}
	if (data->f_space && !data->f_dot && !data->accur && data->numb && num > 0
		&& ft_strlen_s(rez, 0) >= data->numb && !data->f_zero)
		ft_write_len(data, 0);
	if (!data->f_dot && !data->accur && data->f_space && data->f_minus
		&& data->numb && num >= 0 && ft_strlen_s(rez, 0) < data->numb)
		ft_write_len(data, 1);
	if (data->f_dot && data->numb && data->accur && data->f_space && num >= 0
		&& !data->f_zero && data->f_minus && ft_strlen_s(rez, 0) < data->numb)
		ft_write_len(data, 1);
}
