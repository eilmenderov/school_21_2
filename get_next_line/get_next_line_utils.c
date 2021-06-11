#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_cheker(char *ost)
{
	if (!ost)
		return (1);
	while (*ost && *ost != '\n')
		ost++;
	if (*ost == '\n')
		return (0);
	return (1);
}

int	ft_helper(char *buf, int *rdr, int fd)
{
	*rdr = read(fd, buf, BUFFER_SIZE);
	if (*rdr == -1)
	{
		free (buf);
		return (1);
	}
	buf[*rdr] = 0;
	return (0);
}

int	ft_helper_dop(char **buf, char **ost, char ***line, int *fl)
{
	free (*buf);
	**line = ft_format_line(*ost);
	if (!(**line))
		return (1);
	*fl = 0;
	*ost = ft_saver(*ost, fl);
	if (!fl && !(*ost))
		return (1);
	return (0);
}
