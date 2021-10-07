/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleida <vleida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 13:28:07 by vleida            #+#    #+#             */
/*   Updated: 2021/10/06 13:28:07 by vleida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_data(t_flag *data)
{
	data->f_minus = 0;
	data->f_zero = 0;
	data->f_num = 0;
	data->numb = 0;
	data->f_dot = 0;
	data->accur = 0;
	data->f_space = 0;
	data->resh = 0;
	data->plus = 0;
	data->parc_flags = NULL;
	data->type = 0;
	data->fl = 0;
	data->len = 0;
}

void	ft_clear_data(t_flag *data)
{
	data->f_minus = 0;
	data->f_zero = 0;
	data->f_num = 0;
	data->numb = 0;
	data->f_dot = 0;
	data->accur = 0;
	data->f_space = 0;
	data->resh = 0;
	data->plus = 0;
	data->type = 0;
}

int	ft_this_is_convers(char c)
{
	int	i;

	if (c == 'c')
		return (99);
	if (c == 's')
		return (115);
	if (c == 'p')
		return (112);
	if (c == 'd')
		return (100);
	if (c == 'i')
		return (105);
	if (c == 'u')
		return (117);
	if (c == 'x')
		return (120);
	if (c == 'X')
		return (88);
	if (c == '%')
		return (37);
	if (c == 'o')
		return (111);
	i = 0;
	return (i);
}

int	ft_strlen_s(const char *str, char c)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

int	ft_helper(t_flag *data, const char ***form, char **rez)
{
	int	i;

	if (!*form || !data)
		return (-1);
	i = ft_strlen_s(**form, '%');
	*rez = malloc(sizeof(char) * (i + 1));
	if (!(*rez))
		return (-3);
	return (i);
}
