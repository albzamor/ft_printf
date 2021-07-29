/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv1_c_s_d_u_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albzamor <albzamor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 09:37:48 by albzamor          #+#    #+#             */
/*   Updated: 2021/07/29 10:59:43 by albzamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_char(t_print *tab)
{
	char c;

	c = va_arg(tab->args, int);
	ft_prepare_tab(tab, 1);
	//if (tab->width && !tab->minus)
		//ft_right_cs(tab, 0);
	tab->length_return += write(1, &c, 1);
	//if (tab->width && tab->minus)
		//ft_left_cs(tab, 0);
}

int	ft_print_string(t_print *tab)
{
	printf("En construccion: print string%d", tab->zero);
	return(0);
}
int	ft_print_int(t_print *tab)
{
	printf("En construccion: print int%d", tab->zero);
	return(0);
}
int	ft_print_unsigned_int(t_print *tab)
{
	printf("En construccion: print unsigned_int%d", tab->zero);
	return(0);
}
int	ft_print_pointer(t_print *tab)
{
	printf("En construccion: print pointer%d", tab->zero);
	return(0);
}
