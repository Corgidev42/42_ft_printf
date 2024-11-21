/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:15:24 by dev               #+#    #+#             */
/*   Updated: 2024/11/21 19:07:24 by dev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
void	ft_printf_conversions(char format, va_list *args, int *num);
int		ft_putchar(unsigned char c);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
int		ft_putunbr(unsigned int n);
int		ft_putnbrhexlow(unsigned int n);
int		ft_putnbrhexup(unsigned int n);
int		ft_putptr(unsigned long ptr);
int		number_size(int n);
int		unsigned_number_size(unsigned int n);

#endif
