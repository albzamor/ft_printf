/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv1_c_s_d_u_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albzamor <albzamor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 09:37:48 by albzamor          #+#    #+#             */
/*   Updated: 2021/08/03 21:12:43 by albzamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_char(t_print *tab)
{
	char	c;

	c = va_arg(tab->args, int);
	ft_prepare_tab(tab, 1);
	if (tab->width && !tab->minus)
		ft_print_right_c_s(tab, 0);
	tab->length_return += write(1, &c, 1);
	if (tab->width && tab->minus)
		ft_print_left_c_s(tab, 0);
}

void	ft_print_string(t_print *tab)
{
	char	*s;
	int		i;
	int		len;

	i = 0;
	len = 0;
	s = va_arg(tab->args, char *);
	if (!s)
		s = "(null)";
	if (s && tab->point == 1 && tab->precision == 0)
		return (ft_string_point(tab));
	len = ft_prepare_tab_string(s, tab, len);
	if (!tab->minus && tab->width > len)
		ft_print_right_c_s(tab, len);
	if (tab->precision > 0)
		while (s[i] && tab->precision--)
			tab->length_return += write(1, &s[i++], 1);
	else
		while (s[i])
			tab->length_return += write(1, &s[i++], 1);
	if (s && tab->minus && tab->width)
		ft_print_left_c_s(tab, len);
}

void	ft_print_int(t_print *tab)
{
	int		i;
	int		j;
	char	*num;
	int		len;

	i = 0;
	j = va_arg(tab->args, int);
	if (!j)
	{
		ft_write_zero(tab);
		return ;
	}
	if (j < 0)
		j = ft_check_sign(tab, j);
	num = ft_itoa(j);
	if (!num)
		return ;
	len = ft_strlen(num);
	ft_prepare_tab(tab, len);
	ft_print_right_i_d_u_p_x(tab);
	while (j && num[i])
		tab->length_return += write(1, &num[i++], 1);
	ft_print_left_i_d_u_p_x(tab);
	free(num);
}

void	ft_print_unsigned_int(t_print *tab)
{
	printf("En construccion: print unsigned_int%d", tab->zero);
}

void	ft_print_pointer(t_print *tab)
{
	printf("En construccion: print pointer%d", tab->zero);
}
