/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albzamor <albzamor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 08:00:39 by albzamor          #+#    #+#             */
/*   Updated: 2021/07/27 19:43:49 by albzamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
/* initialise tab to 0 + return */
t_print *ft_initialise_tab(t_print *tab)
{
tab->width = 0;
tab->zero = 0;
tab->sign = 0;
tab->length_return = 0;
tab->is_zero = 0;
tab->hash = 0;
tab->perc = 0;
tab->spc = 0;
tab->plus = 0;
tab->minus = 0;//comp minus y hash
return (tab);
}
/* reset tab to 0 NO return */
t_print *ft_reset_minuslength_tab(t_print *tab)
{
tab->width = 0;
tab->zero = 0;
tab->sign = 0;
tab->is_zero = 0;
tab->hash = 0;
tab->perc = 0;
tab->spc = 0;
tab->plus = 0;
tab->minus = 0;
return (tab);
}