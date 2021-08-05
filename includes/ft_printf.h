/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albzamor <albzamor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 11:21:30 by albzamor          #+#    #+#             */
/*   Updated: 2021/08/05 21:03:39 by albzamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_print
{
	va_list	args;
	int		length_return;
	int		percentage;
	int		sign;
	int		precision;
	int		minus;
	int		zero;
	int		width;
	int		hashtag;
	int		space;
	int		point;
	int		plus;
	int		number_zero;
}				t_print;

t_print	*ft_initialise_tab(t_print *tab);
int		ft_eval_flags(t_print *tab, const char *format, int pos);
int		ft_eval_csdiupx(t_print *tab, const char *format, int pos);
t_print	*ft_reset_minuslength_tab(t_print *tab);
int		ft_isalpha(int c);
int		ft_flag_minus(t_print *tab, const char *format, int pos);
int		ft_flag_zero(t_print *tab, const char *format, int pos);
int		ft_flag_width(t_print *tab, const char *format, int pos);
int		ft_flag_space(t_print *tab, int pos);
int		ft_flag_plus(t_print *tab, int pos);
int		ft_flag_hashtag(t_print *tab, int pos);
int		ft_isdigit(int c);
void	ft_print_char(t_print *tab);
void	ft_print_string(t_print *tab);
void	ft_print_int(t_print *tab);
void	ft_print_unsigned_int(t_print *tab);
void	ft_print_pointer(t_print *tab);
void	ft_print_hex_int(t_print *tab, int c);
void	ft_percentage(t_print *tab);
int		ft_printf(const char *format, ...);
void	ft_prepare_tab(t_print *tab, int len);
void	ft_print_char(t_print *tab);
int		ft_atoi(const char *str);
int		ft_flag_zero(t_print *tab, const char *format, int pos);
int		ft_length_number(long n);
void	ft_before_zero(t_print *tab);
void	ft_write_zero(t_print *tab);
char	*ft_itoa(long nbr);
int		ft_precision(t_print *tab, const char *format, int pos);
void	ft_check_precision(t_print *tab);
int		ft_check_minus_point(char c);
void	ft_print_before_c_s(t_print *tab, int len);
void	ft_print_after_c_s(t_print *tab, int len);
void	ft_print_before_i_d_u_p_x(t_print *tab);
void	ft_print_after_i_d_u_p_x(t_print *tab);
long	ft_negative_sign(t_print *tab, long j);
int		ft_width(t_print *tab, const char *format, int pos);
size_t	ft_strlen(const char *s);
void	ft_string_point(t_print *tab);
int		ft_prepare_tab_string(char *s, t_print *tab, int len);
void	ft_print_string(t_print *tab);
char	*ft_unsigned_itoa(unsigned int nb);
void	ft_write_null_pointer(t_print *tab);
int		ft_numlen_base(unsigned long n, int base);
int		ft_putnbr_base(unsigned long n, char *base);
char	*ft_itoa_base(char *str, unsigned long n, int base, int c);

#endif
