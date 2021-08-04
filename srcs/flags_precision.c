/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albzamor <albzamor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 18:00:43 by albzamor          #+#    #+#             */
/*   Updated: 2021/08/04 14:49:39 by albzamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/* "." number of digits/char after point */
int	ft_precision(t_print *tab, const char *format, int pos)
{
	int	i;

	i = 0;
	pos++;
	tab->point = 1;
	if (ft_isalpha(format[pos]) || format[pos] == '%')
		ft_check_precision(tab);
	while (format[pos] == '0' || ft_check_minus_point(format[pos]))
	{
		pos++;
		ft_check_precision(tab);
	}
	if (ft_isdigit(format[pos]))
	{
		i = ft_atoi(&format[pos]);
		pos += ft_length_number(i);
	}
	tab->precision = i;
	return (pos);
}

/* flag '#' put sign invisible */
int	ft_flag_hashtag(t_print *tab, int pos)
{
	pos++;
	tab->hashtag = 1;
	return (pos);
}
