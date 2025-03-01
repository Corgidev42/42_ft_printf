/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:12:59 by dev               #+#    #+#             */
/*   Updated: 2024/12/14 14:38:53 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_conversions(char format, va_list *args, int *num)
{
	if (format == 'c')
		*num += ft_putchar((unsigned char)va_arg(*args, int));
	else if (format == '%')
		*num += ft_putchar('%');
	else if (format == 's')
		*num += ft_putstr(va_arg(*args, char *));
	else if (format == 'd' || format == 'i')
		*num += ft_putnbr(va_arg(*args, int));
	else if (format == 'u')
		*num += ft_putunbr(va_arg(*args, unsigned int));
	else if (format == 'x')
		*num += ft_putnbrhexlow(va_arg(*args, unsigned int));
	else if (format == 'X')
		*num += ft_putnbrhexup(va_arg(*args, unsigned int));
	else if (format == 'p')
		*num += ft_putptr((unsigned long)va_arg(*args, void *));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		print_size;

	print_size = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ft_printf_conversions(*format, &args, &print_size);
		}
		else
			print_size += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (print_size);
}
