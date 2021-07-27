/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albzamor <albzamor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 08:51:22 by albzamor          #+#    #+#             */
/*   Updated: 2021/07/25 12:03:31 by albzamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"


/* flag '-' */
int	ft_flag_minus(t_print *tab, const char *format, int pos)
{
	printf("En construcción flag - %s  %d %d", format, pos, tab->plus);
	return(0);
}

/* flag '0' */
int ft_flag_zero(t_print *tab, const char *format, int pos)
{
	printf("En construcción flag 0 %s  %d %d", format, pos, tab->plus);
	return(0);
}

/* flag 'minimun width' */
int ft_flag_width(t_print *tab, const char *format, int pos)
{
	printf("En construcción minimun width %s  %d %d", format, pos, tab->plus);
	return(0);

}

/* flag ' ' */
int ft_flag_space(t_print *tab, const char *format)
{
	printf("En construcción flag espacio %s  %d", format, tab->plus);
	return(0);
}

/* flag '+' */
int ft_flag_plus(t_print *tab, const char *format)
{
	printf("En construcción flag + %d  %s", tab->plus, format);
	return(0);
}