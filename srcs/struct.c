/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albzamor <albzamor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 08:00:39 by albzamor          #+#    #+#             */
/*   Updated: 2021/08/06 14:07:19 by albzamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
/* initialise tab to 0 + return */
t_print	*ft_initialise_tab(t_print *tab)
{
	tab->width = 0;
	tab->precision = 0;
	tab->zero = 0;
	tab->point = 0;
	tab->sign_negative = 0;
	tab->length_return = 0;
	tab->hashtag = 0;
	tab->percentage = 0;
	tab->space = 0;
	tab->plus = 0;
	tab->minus = 0;
	tab->number_zero = 0;
	return (tab);
}

/* reset tab to 0 NO return */
t_print	*ft_reset_minuslength_tab(t_print *tab)
{
	tab->width = 0;
	tab->precision = 0;
	tab->zero = 0;
	tab->point = 0;
	tab->sign_negative = 0;
	tab->hashtag = 0;
	tab->percentage = 0;
	tab->space = 0;
	tab->plus = 0;
	tab->minus = 0;
	tab->number_zero = 0;
	return (tab);
}
