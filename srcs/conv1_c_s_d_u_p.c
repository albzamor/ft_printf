/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv1_c_s_d_u_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albzamor <albzamor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 09:37:48 by albzamor          #+#    #+#             */
/*   Updated: 2021/08/05 10:35:38 by albzamor         ###   ########.fr       */
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
	long	j;
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
		j = ft_negative_sign(tab, j);
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
	int				i;
	unsigned int	j;
	char			*num;
	int				len;

	i = 0;
	j = va_arg(tab->args, int);
	if (!j)
	{
		ft_write_zero(tab);
		return ;
	}
	num = ft_unsigned_itoa(j);
	if (!num)
		return ;
	len = ft_length_number(j);
	ft_prepare_tab(tab, len);
	ft_print_right_i_d_u_p_x(tab);
	while (num[i])
		tab->length_return += write(1, &num[i++], 1);
	ft_print_left_i_d_u_p_x(tab);
	free(num);
}

void	ft_print_pointer(t_print *tab)
{
	unsigned long	j;
	int				l;

	l = 2;
	j = (unsigned long)va_arg(tab->args, void *);
	if (!j && tab->point && tab->precision > 0)
	{
		ft_write_null_pointer(tab);
		return ;
	}
	if (!(!j && tab->point))
		l += ft_numlen_base(j, 16);
	if (!tab->precision || tab->width > tab->precision)
	{
		ft_prepare_tab(tab, l);
		ft_print_right_i_d_u_p_x(tab);
	}
	else
		tab->precision = tab->precision + 2 - l;
	tab->length_return += write(1, "0x", 2);
	while (tab->precision-- > 0)
		tab->length_return += write(1, "0", 1);
	if (!(!j && tab->point))
		tab->length_return += ft_putnbr_base(j, "0123456789abcdef");
	ft_print_left_i_d_u_p_x(tab);
}
