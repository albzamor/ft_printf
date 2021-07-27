/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albzamor <albzamor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 16:35:49 by albzamor          #+#    #+#             */
/*   Updated: 2021/07/25 17:09:22 by albzamor         ###   ########.fr       */
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
	if (tab->perc > 0)
		tab->zero = 0;
	if (tab->width && tab->width >= tab->perc)
	{
		if (tab->perc > len)
			tab->perc -= len;
		else
			tab->perc = 0;
		if (!tab->is_zero)
			tab->width = tab->width - tab->perc - len;
	}
	else if (tab->perc > tab->width)
	{
		tab->width = 0;
		tab->perc -= len;
	}
}