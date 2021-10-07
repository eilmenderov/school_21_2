/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleida <vleida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 13:28:04 by vleida            #+#    #+#             */
/*   Updated: 2021/10/06 13:28:05 by vleida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_razm_p(unsigned long long c, int sys)
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

void	ft_str_nbr_p(unsigned long long nb, int razm, char *rez, char *sys)
{
	int	i;

	i = ft_strlen_s(sys, 0);
	if (nb / i)
		ft_str_nbr_p(nb / i, razm - 1, rez, sys);
	rez[razm - 1] = sys[nb % i];
}

char	*ft_itoa_m_p(unsigned long long n, char *sys, t_flag *data)
{
	int		razm;
	int		i;
	char	*rez;

	razm = ft_razm_p(n, ft_strlen_s(sys, 0)) + 2;
	if (razm < data->accur)
		razm = data->accur + 2;
	rez = malloc(sizeof(char) * (razm + 1));
	if (!rez)
		return (ft_mal_def(rez, data));
	rez[razm] = 0;
	i = -1;
	while (i++ < razm)
		rez[i] = 48;
	ft_str_nbr_p(n, razm, rez, sys);
	rez[razm] = 0;
	rez[0] = '0';
	rez[1] = 'x';
	if (data->f_dot && !data->accur)
		rez[2] = 0;
	return (rez);
}

char	*ft_add_pointer(unsigned long long num, t_flag *data)
{
	char	*rez;

	rez = ft_itoa_m_p(num, "0123456789abcdef", data);
	return (rez);
}

void	ft_write_len(t_flag *data, int fl)
{
	write(1, " ", 1);
	data->len++;
	if (fl)
		data->numb--;
}
