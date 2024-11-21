/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:16:40 by dev               #+#    #+#             */
/*   Updated: 2024/11/21 19:19:17 by dev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

// %c
int	ft_putchar(unsigned char c)
{
	write(1, &c, 1);
	return (1);
}

// %s
int	ft_putstr(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

// %p
int	ft_putptr(unsigned long ptr)
{
	char	buffer[50];
	int		i;
	int		count;
	int		temp;

	i = 0;
	count = 0;
	if (ptr == 0)
		return (ft_putstr("0x0"));
	count += ft_putstr("0x");
	while (ptr > 0)
	{
		temp = ptr % 16;
		if (temp < 10)
			buffer[i++] = '0' + temp;
		else
			buffer[i++] = 'a' + (temp - 10);
		ptr /= 16;
	}
	while (--i >= 0)
		count += ft_putchar(buffer[i]);
	return (count);
}

// %d
int	ft_putnbr(int n)
{
	int	size;

	size = number_size(n);
	if (n == INT_MIN)
		ft_putstr("-2147483648");
	else if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putchar((n % 10) + 48);
	}
	else if (n <= 9 && n != INT_MIN)
		ft_putchar((n % 10) + 48);
	return (size);
}

// %u
int	ft_putunbr(unsigned int n)
{
	int	size;

	size = unsigned_number_size(n);
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putchar((n % 10) + 48);
	}
	else if (n <= 9)
		ft_putchar((n % 10) + 48);
	return (size);
}
