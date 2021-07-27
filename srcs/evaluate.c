/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evaluate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albzamor <albzamor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 07:54:52 by albzamor          #+#    #+#             */
/*   Updated: 2021/07/25 17:00:04 by albzamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*ft_eval_flags

while not udcsupxX%
if (format[pos] == '.')
tab->pnt = 1; # we set it to true, 1
pos++;
if (format[pos] == '-')
tab->dash = 1;
pos++; */

/* evaluate is !alphanumeric or !% : - 0 number spc + */
int	ft_eval_flags(t_print *tab, const char *format, int pos)
{
	while (!(ft_isalpha(format[pos]) || format[pos] == '%'))
	{
		if (format[pos] == '-')
			pos = ft_flag_minus(tab, format, pos);
		if (format[pos] == '0')
			pos = ft_flag_zero(tab, format, pos);
		if (ft_isdigit(format[pos]))
			pos = ft_flag_width(tab, format, pos);
		if (format[pos] == ' ')
			pos = ft_flag_space(tab, format);
		if (format[pos] ==  '+')
			pos = ft_flag_plus(tab, format);
	}
	ft_eval_csdiupx(tab, format, pos);
	ft_reset_minuslength_tab(tab);
	return (pos);
}

/* evaluate witch csdiupx conversion*/
int 	ft_eval_csdiupx(t_print *tab, const char *format, int pos)

{
	if (format[pos] == 'c')
		ft_print_char(tab);
	else if (format[pos] == 's')
		ft_print_string(tab);
	else if (format[pos] == 'd' || format[pos] == 'i')
		ft_print_int(tab);
	else if (format[pos] == 'u')
		ft_print_unsigned_int(tab);
	else if (format[pos] == 'p')
		ft_print_pointer(tab);
	else if (format[pos] == 'x' || format[pos] == 'X')
		ft_print_hex_int(tab, format[pos] - 23);
	else if (format[pos] == '%')
		ft_percentage(tab);
	return (pos);
}