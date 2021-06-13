#include "libftprintf.h"

char	*ft_avmal_def(char *str, t_flag *data)
{
	if (!str)
	{
		data->fl = -15;
		return (NULL);
	}
	return (str);
}

int	ft_avsave_chars(const char **form, t_flag *data)
{
	int		i;

	i = 0;
	while (**form && **form != '%')
	{
		write (1, *form, 1);
		*form = *form + 1;
		if (**form == 0)
			data->fl = 1;
		i++;
	}
	return (i);
}

int	ft_avparc_param(const char **form, t_flag *data)
{
	int		i;
	char	*prfl;

	*form = *form + 1;
	i = 0;
	while (((char *)*form)[i] && !(ft_avthis_is_convers(((char *)*form)[i])))
		i++;
	if (!(ft_avthis_is_convers(((char *)*form)[i])))
		return (-2);
	prfl = malloc(sizeof(char) * (i + 1));
	if (!prfl)
		return (-1);
	i = 0;
	while (**form && !ft_avthis_is_convers(**form))
	{
		prfl[i] = (char)**form;
		i++;
		*form = *form + 1;
	}
	prfl[i] = 0;
	data->parc_flags = prfl;
	data->type = ft_avthis_is_convers(**form);
	*form = *form + 1;
	return (0);
}

int	ft_avtheend(t_flag *data)
{
	if (data->fl < 0)
	{
		data->len = data->fl;
		return (-1);
	}
	return (data->len);
}

int	ft_printf(const char *form, ...)
{
	va_list	ar;
	t_flag	data;

	ft_avinit_data(&data);
	va_start(ar, form);
	while (*form && !data.fl)
	{
		ft_avclear_data(&data);
		data.len = data.len + ft_avsave_chars(&form, &data);
		if (!data.fl && *form == '%')
		{
			data.fl = ft_avparc_param(&form, &data);
			ft_avnow_flags(&data);
			if (data.fl)
				return (ft_avtheend(&data));
			ft_avsave_conver(&data, ar);
		}
	}
	va_end(ar);
	return (ft_avtheend(&data));
}
