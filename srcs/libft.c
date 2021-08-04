/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albzamor <albzamor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 08:19:15 by albzamor          #+#    #+#             */
/*   Updated: 2021/08/04 23:03:13 by albzamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		sign;
	int		i;
	long	number;

	i = 0;
	sign = 1;
	number = 0;
	while (str[i] == '\f' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\t' || str[i] == '\v' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	if (str[i] == '+' || str[i] == '-')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + (str[i++] - 48);
		if ((number * sign) > INT_MAX)
			return (-1);
		if ((number * sign) < INT_MIN)
			return (0);
	}
	return (number * sign);
}

int	ft_length_number(long nbr)
{
	int	len;

	len = 0;
	if (nbr <= 0)
		++len;
	while (nbr != 0)
	{
		++len;
		nbr = nbr / 10;
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	char			*number;
	long long		len;
	int				sign;

	sign = 1;
	if (nbr < 0)
		sign = -1;
	len = ft_length_number(nbr);
	number = malloc(sizeof(char) * (len + 1));
	if (number == NULL)
		return (NULL);
	if (nbr < 0)
		number[0] = '-';
	else if (nbr == 0)
		number[0] = '0';
	number[len] = '\0';
	while (nbr != 0)
	{
		--len;
		number[len] = sign * (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	return (number);
}
