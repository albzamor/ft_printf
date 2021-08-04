/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv2_x_percentage.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albzamor <albzamor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 09:37:52 by albzamor          #+#    #+#             */
/*   Updated: 2021/08/04 21:30:45 by albzamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_hex_int(t_print *tab, int c)
{
	unsigned int	j;
	int				len;
	char			*num;

	j = va_arg(tab->args, unsigned int);
	if (!j)
	{
		ft_write_zero(tab);
		return ;
	}
	len = ft_numlen_base(j, 16);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return ;
	num = ft_itoa_base(num, j, 16, c);
	ft_prepare_tab(tab, len);
	ft_print_right_i_d_u_p_x(tab);
	while (num && len-- > 0)
		tab->length_return += write(1, &num[len], 1);
	ft_print_left_i_d_u_p_x(tab);
	free(num);
}

void	ft_percentage(t_print *tab)
{
	if (tab->percentage)
		tab->zero = 1;
	while (tab->zero && !tab->minus && --tab->width > 0)
		tab->length_return += write(1, "0", 1);
	while (!tab->minus && --tab->width > 0)
		tab->length_return += write(1, " ", 1);
	tab->length_return += write(1, "%", 1);
	while (tab->minus && --tab->width > 0)
		tab->length_return += write(1, " ", 1);
}

char	*ft_itoa_base(char *str, unsigned long n, int base, int c)
{
	int		i;

	i = 0;
	if (n == 0)
		str[i++] = '0';
	while (n > 0)
	{
		if (base > 10 && (n % base >= 10))
			str[i++] = (n % base) - 10 + c;
		else
			str[i++] = (n % base) + '0';
		n /= base;
	}
	str[i] = '\0';
	return (str);
}