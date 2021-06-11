#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_flag
{
	int		f_minus;
	int		f_zero;
	int		f_num;
	int		numb;
	int		f_dot;
	int		accur;
	int		f_space;
	char	*parc_flags;
	int		type;
	int		len;
	int		fl;
}				t_flag;

char	*ft_avadchr_helper(char c, t_flag *data, char x);
char	*ft_avadd_char(char c, t_flag *data);
char	*ft_avadd_char_pr(t_flag *data);
char	*ft_avadd_str(char *str, t_flag *data);

int		ft_avfind_number(t_flag *data, char ***str);
int		ft_avfind_accur(t_flag *data, char ***str);
int		ft_avthis_is_flag(char **st, t_flag *data);
int		ft_avdef_fl(t_flag *data);
void	ft_avnow_flags(t_flag *data);

int		ft_avrazm_p(unsigned long long c, int sys);
void	ft_avstr_nbr_p(unsigned long long nb, int razm, char *rez, char *sys);
char	*ft_avitoa_m_p(unsigned long long n, char *sys, t_flag *data);
char	*ft_avadd_pointer(unsigned long long num, t_flag *data);

void	ft_avinit_data(t_flag *data);
void	ft_avclear_data(t_flag *data);
int		ft_avthis_is_convers(char c);
int		ft_avstrlen_s(const char *str, char c);
int		ft_avhelper(t_flag *data, const char ***form, char **rez);

char	*ft_avmal_def(char *str, t_flag *data);
int		ft_avsave_chars(const char **form, t_flag *data);
int		ft_avparc_param(const char **form, t_flag *data);
int		ft_avtheend(t_flag *data);
int		ft_printf(const char *form, ...);

void	ft_avstrj_help(char **str);
char	*ft_avstrjoin_m(char *s1, char *s2, int i, int f);
char	*ft_avhop_char(char *str, t_flag *data, int len);
void	ft_avcon_res(t_flag *data, char *buf);
void	ft_avsave_conver(t_flag *data, va_list ar);

void	ft_avhelp_signint(t_flag *data, int n, int razm, char *rez);
int		ft_avrazm_di(int c, int sys, t_flag *data);
void	ft_avstr_nbr_di(int nb, int razm, char *rez, char *sys);
char	*ft_avitoa_m_di(int n, char *sys, t_flag *data);
char	*ft_avadd_int(int num, t_flag *data);

int		ft_avrazm_xuo(unsigned int c, int sys, t_flag *data);
void	ft_avstr_nbr_xuo(unsigned int nb, int razm, char *rez, char *sys);
char	*ft_avitoa_m_xuo(unsigned int n, char *sys, t_flag *data);
char	*ft_avadd_xnum(unsigned int num, t_flag *data);

#endif
