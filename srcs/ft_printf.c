/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albzamor <albzamor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 10:49:43 by albzamor          #+#    #+#             */
/*   Updated: 2021/07/29 11:01:48 by albzamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
/* main funtion ft_printf */
int ft_printf(const char *format, ...)
{
	t_print *tab;
	int i;
	int ret;
	if (!format)
		return (0);
	tab = (t_print *)malloc(sizeof(t_print));
	if (!tab)
		return (-1);
	ft_initialise_tab(tab);
	va_start(tab->args, format);
	i = -1;
	ret = 0;
	while (format[++i])
	{
		if (format[i] == '%')
			i = ft_eval_flags(tab, format, i + 1);
			//printf("conversion requerida");
		else
			ret += write(1, &format[i], 1);
	}
	va_end(tab->args);
	ret += tab->length_return;
	free (tab);
	return (ret);
}

