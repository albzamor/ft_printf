/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albzamor <albzamor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 11:21:30 by albzamor          #+#    #+#             */
/*   Updated: 2021/08/03 21:16:31 by albzamor         ###   ########.fr       */
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
	int		percentage;
	int		length_return;
	int		sign;
	int		precision;
	int		minus;
	int		zero;
	int		width;
	int		hash;
	int		space;
	int		point;
	int		plus;
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
void	ft_right_zero(t_print *tab);
void	ft_write_zero(t_print *tab);
char	*ft_itoa(int nbr);
int		ft_precision(t_print *tab, const char *format, int pos);
void	ft_check_precision(t_print *tab);
int		ft_check_minus_point(char c);
void	ft_print_right_c_s(t_print *tab, int len);
void	ft_print_left_c_s(t_print *tab, int len);
void	ft_print_right_i_d_u_p_x(t_print *tab);
void	ft_print_left_i_d_u_p_x(t_print *tab);
int		ft_check_sign(t_print *tab, int j);
int		ft_width(t_print *tab, const char *format, int pos);
size_t	ft_strlen(const char *s);
void	ft_string_point(t_print *tab);
int		ft_prepare_tab_string(char *s, t_print *tab, int len);
void	ft_print_string(t_print *tab);

#endif
