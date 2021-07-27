/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv1_c_s_d_u_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albzamor <albzamor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 09:37:48 by albzamor          #+#    #+#             */
/*   Updated: 2021/07/25 17:10:16 by albzamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_char(t_print *tab)
{
	char c;

	c = va_arg(tab->args, int);
	ft_prepare_tab(tab, 1);
	//if (tab->width && !tab->hash)
		//ft_right_cs(tab, 0);
	tab->length_return += write(1, &c, 1);
	//if (tab->width && tab->hash)
		//ft_left_cs(tab, 0);
}

/* void	ft_output_char(t_print *tab)
{
	char	a;

	a = va_arg(tab->args, int);
	ft_update_tab(tab, 1);
	if (tab->wdt && !tab->dash)
		ft_right_cs(tab, 0);
	tab->tl += write(1, &a, 1);
	if (tab->wdt && tab->dash)
		ft_left_cs(tab, 0);
} */


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
