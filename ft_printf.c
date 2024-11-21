/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:12:59 by dev               #+#    #+#             */
/*   Updated: 2024/11/21 19:17:58 by dev              ###   ########.fr       */
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

// #include <stdio.h>

// int	main(void)
// {
// 	int	ft_ret;
// 	int	real_ret;

// 	ft_ret = ft_printf("Char: %c\n", 'A');
// 	real_ret = printf("Char: %c\n", 'A');
// 	printf("ft_printf returned: %d, printf returned: %d\n", ft_ret, real_ret);
// 	ft_ret = ft_printf("String: %s\n", "Hello, World!");
// 	real_ret = printf("String: %s\n", "Hello, World!");
// 	printf("ft_printf returned: %d, printf returned: %d\n", ft_ret, real_ret);
// 	ft_ret = ft_printf("Decimal: %d\n", 42);
// 	real_ret = printf("Decimal: %d\n", 42);
// 	printf("ft_printf returned: %d, printf returned: %d\n", ft_ret, real_ret);
// 	ft_ret = ft_printf("Integer: %i\n", -42);
// 	real_ret = printf("Integer: %i\n", -42);
// 	printf("ft_printf returned: %d, printf returned: %d\n", ft_ret, real_ret);
// 	ft_ret = ft_printf("Unsigned: %u\n", 42);
// 	real_ret = printf("Unsigned: %u\n", 42);
// 	printf("ft_printf returned: %d, printf returned: %d\n", ft_ret, real_ret);
// 	ft_ret = ft_printf("Hexadecimal (lowercase): %x\n", 42);
// 	real_ret = printf("Hexadecimal (lowercase): %x\n", 42);
// 	printf("ft_printf returned: %d, printf returned: %d\n", ft_ret, real_ret);
// 	ft_ret = ft_printf("Hexadecimal (uppercase): %X\n", 42);
// 	real_ret = printf("Hexadecimal (uppercase): %X\n", 42);
// 	printf("ft_printf returned: %d, printf returned: %d\n", ft_ret, real_ret);
// 	ft_ret = ft_printf("Pointer: %p\n", (void *)42);
// 	real_ret = printf("Pointer: %p\n", (void *)42);
// 	printf("ft_printf returned: %d, printf returned: %d\n", ft_ret, real_ret);
// 	ft_ret = ft_printf("Percent: %%\n");
// 	real_ret = printf("Percent: %%\n");
// 	printf("ft_printf returned: %d, printf returned: %d\n", ft_ret, real_ret);

// 	ft_printf(" %d ", -1);
// 	ft_printf(" %d ", -9);
// 	ft_printf(" %d ", -10);
// 	ft_printf(" %d ", -11);
// 	ft_printf(" %d ", -14);
// 	ft_printf(" %d ", -15);
// 	ft_printf(" %d ", -16);
// 	ft_printf(" %d ", -99);
// 	ft_printf(" %d ", -100);
// 	ft_printf(" %d ", -101);
// 	ft_printf(" %d ", LONG_MAX);
// 	ft_printf(" %d ", UINT_MAX);
// 	ft_printf(" %d ", ULONG_MAX);
// 	ft_printf(" %d ", 9223372036854775807LL);
// 	ft_printf(" %d %d %d %d %d %d %d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN,
// 		ULONG_MAX, 0, -42);
// 	return (0);
// }
