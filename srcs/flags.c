/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albzamor <albzamor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 08:51:22 by albzamor          #+#    #+#             */
/*   Updated: 2021/07/29 19:26:37 by albzamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/* flag ' ' put a space instead sign*/
int ft_flag_space(t_print *tab, int pos)
{

	pos++;
	tab->space = 1;
	return (pos);

}

/* flag '0' fill with 0*/
int ft_flag_zero(t_print *tab, const char *format, int pos)
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
/* flag '-' */
int	ft_flag_minus(t_print *tab, const char *format, int pos)
{
	printf("En construcción flag - %s  %d %d", format, pos, tab->plus);
	return(0);
}



/* flag 'minimun width' */
int ft_flag_width(t_print *tab, const char *format, int pos)
{
	printf("En construcción minimun width %s  %d %d", format, pos, tab->plus);
	return(0);

}


/* flag '+' */
int ft_flag_plus(t_print *tab, const char *format)
{
	printf("En construcción flag + %d  %s", tab->plus, format);
	return(0);
}