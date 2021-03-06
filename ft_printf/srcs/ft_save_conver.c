/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_conver.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleida <vleida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 13:28:16 by vleida            #+#    #+#             */
/*   Updated: 2021/10/06 13:28:16 by vleida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_strj_help(char **str)
{
	if (*str)
	{
		free (*str);
		*str = NULL;
	}
}

char	*ft_strjoin_m(char *s1, char *s2, int i, int f)
{
	int		k;
	int		j;
	char	*rez;

	if (!s1 || !s2)
		return (NULL);
	k = ft_strlen_s(s1, 0) + ft_strlen_s(s2, 0);
	rez = malloc(sizeof(char) * (k + 1));
	if (!rez)
		return (NULL);
	while (i++ < k && s1[i])
		rez[i] = s1[i];
	j = 0;
	while (*(s2 + j))
	{
		rez[i + j] = *(s2 + j);
		j++;
	}
	rez[i + j] = 0;
	if (s1)
		free (s1);
	if (s2 && f == 1)
		ft_strj_help(&s2);
	return (rez);
}

char	*ft_hop_char(char *str, t_flag *data, int len)
{
	char	*rez;
	char	c;
	int		i;
	int		j;

	rez = malloc(sizeof(char) * (data->numb + 1));
	if (!rez)
	{
		data->fl = -12;
		return (str);
	}
	c = ' ';
	if (data->f_zero && !data->f_minus && (data->type == 99
			|| data->type == 115 || data->type == 37))
		c = '0';
	i = data->numb - len;
	rez[i] = 0;
	j = -1;
	while (j++ < i - 1)
		rez[j] = c;
	if (data->numb < 0 || data->f_minus)
		rez = ft_strjoin_m(str, rez, -1, 1);
	else
		rez = ft_strjoin_m(rez, str, -1, 1);
	return (ft_mal_def(rez, data));
}

void	ft_con_res(t_flag *data, char *buf)
{
	int	len;

	if (!buf || data->fl < 0)
		return ;
	if (data->numb < 0)
	{
		data->f_minus++;
		data->numb = -data->numb;
	}
	if (data->f_dot && data->accur < ft_strlen_s(buf, 0) && data->type == 115)
		buf[data->accur] = 0;
	len = ft_strlen_s(buf, 0);
	if (data->f_num && data->numb > len)
		buf = ft_hop_char(buf, data, len);
	if (len < data->numb)
		len = data->numb;
	write (1, buf, len);
	data->len = data->len + len;
	if (buf)
	{
		free (buf);
		buf = NULL;
	}
}

void	ft_save_conver(t_flag *data, va_list ar)
{
	char	*buf;

	buf = NULL;
	if (data->f_num == -1 && !data->numb)
		data->numb = va_arg(ar, int);
	if (data->f_dot == -1 && !data->accur)
		data->accur = va_arg(ar, int);
	if (ft_def_fl(data))
		return ;
	if (data->type == 99)
		buf = ft_add_char(va_arg(ar, int), data);
	if (data->type == 37)
		buf = ft_add_char_pr(data);
	if (data->type == 115)
		buf = ft_add_str(va_arg(ar, char *), data);
	if (data->type == 100 || data->type == 105)
		buf = ft_add_int(va_arg(ar, int), data);
	if (data->type == 112)
		buf = ft_add_pointer(va_arg(ar, unsigned long long), data);
	if (data->type == 120 || data->type == 88 || data->type == 117
		|| data->type == 111)
		buf = ft_add_xnum(va_arg(ar, unsigned int), data);
	ft_con_res(data, buf);
}
