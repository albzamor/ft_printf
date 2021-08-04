/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_spc_zero_-_width_+.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albzamor <albzamor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 08:51:22 by albzamor          #+#    #+#             */
/*   Updated: 2021/08/04 17:30:21 by albzamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/* flag ' ' put a space instead sign*/
int	ft_flag_space(t_print *tab, int pos)
{
	pos++;
	tab->space = 1;
	return (pos);
}

/* flag '0' fill with 0*/
int	ft_flag_zero(t_print *tab, const char *format, int pos)
{
	int	i;

	i = 0;
	pos++;
	tab->zero = 1;
	while (format[pos] == '0')
		pos++;
	if (ft_isdigit(format[pos]))
	{
		i = ft_atoi(&format[pos]);
		pos += ft_length_number(i);
	}
	tab->width = i;
	return (pos);
}

/* flag '-' left adjustment*/
int	ft_flag_minus(t_print *tab, const char *format, int pos)
{
	pos++;
	if (tab->minus == 1)
	{
		while (format[pos] == '-' || format[pos] == '0')
			pos++;
		return (pos);
	}
	tab->minus = 1;
	tab->zero = 0;
	while (format[pos] == '-' || format[pos] == '0')
		pos++;
	pos = ft_width(tab, format, pos);
	return (pos);
}

/* flag 'minimun width' nº<width 0s left*/
int	ft_width(t_print *tab, const char *format, int pos)
{
	int	i;

	i = 0;
	if (ft_isdigit(format[pos]))
	{
		i = ft_atoi(&format[pos]);
		pos += ft_length_number(i);
	}
	tab->width = i;
	if (format[pos] == '.')
		pos = ft_precision(tab, format, pos);
	return (pos);
}

/* flag '+' put sign always*/
int	ft_flag_plus(t_print *tab, int pos)
{
	pos++;
	tab->plus = 1;
	return (pos);
}
