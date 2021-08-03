/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv2_x_percentage.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albzamor <albzamor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 09:37:52 by albzamor          #+#    #+#             */
/*   Updated: 2021/08/03 19:05:02 by albzamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_hex_int(t_print *tab, int c)
{
	printf("En construccion: print hexa%d   %d", tab->zero, c);
}

void	ft_percentage(t_print *tab)
{
	if (tab->percentage)
		tab->zero = 1;
	while (tab->zero && !tab->minus && --tab->width > 0)
		tab->length_return += write(1, "0", 1);
	while (!tab->minus && --tab->width > 0)
		tab->length_return += write(1, " ", 1);
	tab->length_return += write(1, "%", 1);
	while (tab->minus && --tab->width > 0)
		tab->length_return += write(1, " ", 1);
}
