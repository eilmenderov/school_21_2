#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# define FD_SIZE 100000
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*get_next_line(int fd);
int		ft_gnl(int fd, char **line);
size_t	ft_strlen(const char *str);
int		ft_cheker(char *ost);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_format_line(char *data);
char	*ft_saver(char *ost, int *fl);
int		ft_helper(char *buf, int *rdr, int fd);
int		ft_helper_dop(char **buf, char **ost, char ***line, int *fl);

#endif
