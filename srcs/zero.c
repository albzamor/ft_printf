/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albzamor <albzamor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 19:50:24 by albzamor          #+#    #+#             */
/*   Updated: 2021/08/03 19:27:00 by albzamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_write_zero(t_print *tab)
{
	tab->zero = 1;
	if ((tab->width && tab->zero))
	{
		ft_right_zero(tab);
		return ;
	}
	ft_prepare_tab(tab, 1);
	while (!tab->minus && --tab->width > 0)
		tab->length_return += write(1, " ", 1);
	tab->length_return += write(1, "0", 1);
	while (tab->minus && --tab->width > 0)
		tab->length_return += write(1, " ", 1);
}

void	ft_right_zero(t_print *tab)
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