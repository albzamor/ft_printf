/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_alignment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albzamor <albzamor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 18:32:22 by albzamor          #+#    #+#             */
/*   Updated: 2021/08/03 19:57:05 by albzamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_right_c_s(t_print *tab, int len)
{
	while (tab->zero && tab->width-- > len)
		tab->length_return += write(1, "0", 1);
	if (!tab->zero && tab->precision && tab->precision < len)
		while (tab->width-- > tab->precision)
			tab->length_return += write(1, " ", 1);
	else
		while (!tab->zero && tab->width-- > len)
			tab->length_return += write(1, " ", 1);
}

void	ft_print_left_c_s(t_print *tab, int len)
{
	while (tab->zero && tab->width-- > len)
		tab->length_return += write(1, "0", 1);
	while (!tab->zero && tab->width-- > len)
		tab->length_return += write(1, " ", 1);
}

void	ft_print_right_i_d_u_p_x(t_print *tab)
{
	if (tab->space)
		tab->length_return += write(1, " ", 1);
	if (tab->sign && (tab->zero || tab->minus
			|| (!tab->width && !tab->precision)))
	{
		tab->length_return += write(1, "-", 1);
		tab->sign = 0;
	}
	if (!tab->minus)
	{
		while (!tab->zero && --tab->width > -1)
			tab->length_return += write(1, " ", 1);
		while (tab->zero && --tab->width > -1)
			tab->length_return += write(1, "0", 1);
		if (tab->sign)
			tab->length_return += write (1, "-", 1);
	}
	while (--tab->precision > -1)
		tab->length_return += write(1, "0", 1);
}

void	ft_print_left_i_d_u_p_x(t_print *tab)
{
	if (tab->minus)
	{
		while (tab->minus && tab->zero && --tab->precision > -1)
			tab->length_return += write(1, "0", 1);
		while (tab->minus && --tab->width > -1)
			tab->length_return += write(1, " ", 1);
	}
}