#include "get_next_line_bonus.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	i;
	char	*rez;

	len = ft_strlen(s1) + ft_strlen(s2);
	rez = malloc(sizeof(char) * (len + 1));
	if (!rez || !s2)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		rez[i] = s1[i];
		i++;
	}
	while (*s2)
	{
		rez[i] = *s2;
		i++;
		s2++;
	}
	rez[i] = 0;
	if (s1)
		free ((char *)s1);
	return (rez);
}

char	*ft_format_line(char *data)
{
	int		i;
	char	*rez;

	if (!data)
		return (NULL);
	i = 0;
	while (data[i] != '\n' && data[i])
		i++;
	rez = malloc(sizeof(char) * (i + 1));
	if (!rez)
	{
		free (data);
		return (NULL);
	}
	rez[i] = 0;
	i = 0;
	while (data[i] && data[i] != '\n')
	{
		rez[i] = data[i];
		i++;
	}
	return (rez);
}

char	*ft_saver(char *ost, int *fl)
{
	char	*rez;
	int		i;
	int		j;

	i = 0;
	while (ost[i] && ost[i] != '\n')
		i++;
	if (!ost[i])
	{
		*fl = 1;
		free (ost);
		return (NULL);
	}
	rez = malloc(sizeof(char) * (ft_strlen(ost) - i + 1));
	if (!rez)
	{
		free (ost);
		return (NULL);
	}
	j = 0;
	while (ost[i++])
		rez[j++] = ost[i];
	rez[j] = 0;
	free (ost);
	return (rez);
}

int	ft_gnl(int fd, char **line)
{
	char		*buf;
	static char	*ost[FD_SIZE];
	int			rdr;
	int			fl;

	if (fd > FD_SIZE || fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (-1);
	rdr = 1;
	while (ft_cheker(ost[fd]) && rdr)
	{
		if (ft_helper(buf, &rdr, fd))
			return (-1);
		ost[fd] = ft_strjoin(ost[fd], buf);
	}
	if (ft_helper_dop(&buf, &ost[fd], &line, &fl))
		return (-1);
	if (!rdr && fl)
		return (0);
	return (1);
}

char	*get_next_line(int fd)
{
	char	*line;
	int		answ;

	line = NULL;
	answ = ft_gnl(fd, &line);
	if (answ == -1)
	{
		if (line)
			free(line);
		return (NULL);
	}
	if (line && answ)
		return (ft_strjoin(line, "\n"));
	if (line && line[0])
		return (line);
	if (line)
		free(line);
	return (NULL);
}
