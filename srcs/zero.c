/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albzamor <albzamor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 19:50:24 by albzamor          #+#    #+#             */
/*   Updated: 2021/08/05 21:20:00 by albzamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/* write 0 or " " to adjust width and precision */
void	ft_write_zero(t_print *tab)
{
	tab->number_zero = 1;
	if ((tab->width && tab->zero))
	{
		ft_before_zero(tab);
		return ;
	}
	ft_prepare_tab(tab, 1);
	while (!tab->minus && --tab->width > 0)
		tab->length_return += write(1, " ", 1);
	while (--tab->precision > -2)
		tab->length_return +=  write(1, "0", 1);
	while (tab->minus && --tab->width > 0)
		tab->length_return += write(1, " ", 1);
}

void	ft_before_zero(t_print *tab)
{
	if (tab->width && (tab->zero))
	{
		if (!tab->percentage)
		{
			while (tab->zero && tab->width-- > 0)
				tab->length_return += write(1, "0", 1);
			while (!tab->zero && tab->width-- > 0)
				tab->length_return += write(1, " ", 1);
		}
		else
		{
			tab->width -= tab->percentage;
			while (tab->minus && tab->percentage-- > 0)
				tab->length_return += write(1, "0", 1);
			while (tab->width-- > 0)
				tab->length_return += write(1, " ", 1);
			while (!tab->minus && tab->percentage-- > 0)
				tab->length_return += write(1, "0", 1);
		}
	}
}
