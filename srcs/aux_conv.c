/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albzamor <albzamor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 20:53:44 by albzamor          #+#    #+#             */
/*   Updated: 2021/08/05 10:34:51 by albzamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_string_point(t_print *tab)
{
	ft_prepare_tab_string(NULL, tab, 0);
	while (tab->width--)
		tab->length_return += write(1, " ", 1);
}

int	ft_prepare_tab_string(char *s, t_print *tab, int len)
{
	if (s)
		len = ft_strlen(s);
	if (tab->precision > 0 && len > tab->precision)
		len = tab->precision;
	return (len);
}

void	ft_write_null_pointer(t_print *tab)
{
	if (tab->width > tab->precision)
	{
		while (tab->width-- > (tab->precision + 2))
			tab->length_return += write(1, " ", 1);
	}
	tab->length_return += write(1, "0x", 2);
	while (tab->precision-- > 0)
		tab->length_return += write(1, "0", 1);
}

long	ft_negative_sign(t_print *tab, long j)
{
	tab->sign = 1;
	tab->space = 0;
	//if (j == -2147483648)
		//j = 2147483648;
	return (j * -1);
}
