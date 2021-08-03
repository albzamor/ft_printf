/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albzamor <albzamor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 16:35:49 by albzamor          #+#    #+#             */
/*   Updated: 2021/08/03 21:15:30 by albzamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_prepare_tab(t_print *tab, int len)
{
	if (tab->sign)
	{
		if (tab->width)
			tab->width -= 1;
	}
	if (tab->precision > 0)
		tab->zero = 0;
	if (tab->width && tab->width >= tab->precision)
	{
		if (tab->precision > len)
			tab->precision -= len;
		else
			tab->precision = 0;
		if (!tab->zero)
			tab->width = tab->width - tab->precision - len;
	}
	else if (tab->precision > tab->width)
	{
		tab->width = 0;
		tab->precision -= len;
	}
}

void	ft_check_precision(t_print *tab)
{
	if (tab->precision == 0 && tab->zero == 1)
	{
		tab->zero = 0;
		tab->percentage = 1;
	}
	if (tab->precision < 0)
	{
		tab->precision = 0;
		tab->point = 0;
	}
}

int	ft_check_minus_point(char c)
{
	if (c == '-' || c == '.')
		return (1);
	return (0);
}

int	ft_check_sign(t_print *tab, int j)
{
	tab->sign = 1;
	tab->space = 0;
	return (j * -1);
}
