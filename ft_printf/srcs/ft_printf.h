/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleida <vleida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 13:28:13 by vleida            #+#    #+#             */
/*   Updated: 2021/10/06 13:28:13 by vleida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

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
	int		resh;
	int		plus;
	char	*rez;
	int		sys_len;
	int		nb;
	char	*parc_flags;
	int		type;
	int		len;
	int		fl;
}				t_flag;

char	*ft_adchr_helper(char c, t_flag *data, char x);
char	*ft_add_char(char c, t_flag *data);
char	*ft_add_char_pr(t_flag *data);
char	*ft_add_str(char *str, t_flag *data);

int		ft_find_number(t_flag *data, char ***str);
int		ft_find_accur(t_flag *data, char ***str);
int		ft_this_is_flag(char **st, t_flag *data);
int		ft_def_fl(t_flag *data);
void	ft_now_flags(t_flag *data);

int		ft_razm_p(unsigned long long c, int sys);
void	ft_str_nbr_p(unsigned long long nb, int razm, char *rez, char *sys);
char	*ft_itoa_m_p(unsigned long long n, char *sys, t_flag *data);
char	*ft_add_pointer(unsigned long long num, t_flag *data);
void	ft_write_len(t_flag *data, int fl);

void	ft_init_data(t_flag *data);
void	ft_clear_data(t_flag *data);
int		ft_this_is_convers(char c);
int		ft_strlen_s(const char *str, char c);
int		ft_helper(t_flag *data, const char ***form, char **rez);

char	*ft_mal_def(char *str, t_flag *data);
int		ft_save_chars(const char **form, t_flag *data);
int		ft_parc_param(const char **form, t_flag *data);
int		ft_theend(t_flag *data);
int		ft_printf(const char *form, ...);

void	ft_strj_help(char **str);
char	*ft_strjoin_m(char *s1, char *s2, int i, int f);
char	*ft_hop_char(char *str, t_flag *data, int len);
void	ft_con_res(t_flag *data, char *buf);
void	ft_save_conver(t_flag *data, va_list ar);

void	ft_help_signint(t_flag *data, int n, int razm, char *rez);
int		ft_razm_di(int c, int sys, t_flag *data);
void	ft_str_nbr_di(int nb, int razm, char *sys, t_flag *data);
char	*ft_itoa_m_di(int n, char *sys, t_flag *data);
char	*ft_add_int(int num, t_flag *data);

int		ft_razm_xuo(unsigned int c, int sys, t_flag *data);
void	ft_str_nbr_xuo(unsigned int nb, int razm, char *rez, char *sys);
char	*ft_itoa_m_xuo(unsigned int n, char *sys, t_flag *data, int i);
char	*ft_add_xnum(unsigned int num, t_flag *data);
void	ft_sign_int_helper(t_flag *data, int num, char *rez);

#endif
