/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:59:13 by dev               #+#    #+#             */
/*   Updated: 2024/11/21 18:02:05 by dev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	number_size(int n)
{
	int	size;

	size = 0;
	if (n == INT_MIN)
		return (11);
	if (n < 0)
	{
		size++;
		n *= -1;
	}
	while (n > 9)
	{
		n /= 10;
		size++;
	}
	size++;
	return (size);
}

int	unsigned_number_size(unsigned int n)
{
	unsigned int	size;

	size = 0;
	while (n > 9)
	{
		n /= 10;
		size++;
	}
	size++;
	return (size);
}

int	ft_putnbrhexlow(unsigned int n)
{
	char	buffer[50];
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (n == 0)
	{
		ft_putchar('0');
		return (1);
	}
	while (n > 0)
	{
		if ((n % 16) < 10)
			buffer[i++] = '0' + (n % 16);
		else
			buffer[i++] = 'a' + (n % 16 - 10);
		n /= 16;
	}
	while (--i >= 0)
		count += ft_putchar(buffer[i]);
	return (count);
}

int	ft_putnbrhexup(unsigned int n)
{
	char	buffer[50];
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (n == 0)
	{
		ft_putchar('0');
		return (1);
	}
	while (n > 0)
	{
		if ((n % 16) < 10)
			buffer[i++] = '0' + (n % 16);
		else
			buffer[i++] = 'A' + (n % 16 - 10);
		n /= 16;
	}
	while (--i >= 0)
		count += ft_putchar(buffer[i]);
	return (count);
}
