/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albzamor <albzamor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 11:21:30 by albzamor          #+#    #+#             */
/*   Updated: 2021/07/25 17:09:51 by albzamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
/* define strut */
typedef struct s_print
{

	va_list args;			// arg imprimir
	int	perc;				// %
	int	length_return;		// return
	int	is_zero;			// found 0;
	int	sign;				//	sign;
	int	minus;				// - 	left
	int	zero;				// 0
	int	width;				// 	minimum fuekd Widh?
	int	hash;				// #	+ invisible
	int	spc;				// " "  space
	int	plus;				// +	sign +

}				t_print;

t_print *ft_initialise_tab(t_print *tab);
int	ft_eval_flags(t_print *tab, const char *format, int pos);
int 	ft_eval_csdiupx(t_print *tab, const char *format, int pos);
t_print *ft_reset_minuslength_tab(t_print *tab);
int	ft_isalpha(int c);
int	ft_flag_minus(t_print *tab, const char *format, int pos);
int ft_flag_zero(t_print *tab, const char *format, int pos);
int ft_flag_width(t_print *tab, const char *format, int pos);
int ft_flag_space(t_print *tab, const char *format);
int ft_flag_plus(t_print *tab, const char *format);
int	ft_isdigit(int c);
void	ft_print_char(t_print *tab);
int	ft_print_string(t_print *tab);
int	ft_print_int(t_print *tab);
int	ft_print_unsigned_int(t_print *tab);
int	ft_print_pointer(t_print *tab);
int	ft_print_hex_int(t_print *tab, int c);
int	ft_percentage(t_print *tab);
int ft_printf(const char *format, ...);
void	ft_prepare_tab(t_print *tab, int len);
void	ft_print_char(t_print *tab);

#endif

