/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamourgh <jamourgh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 20:55:45 by jamourgh          #+#    #+#             */
/*   Updated: 2025/11/11 11:02:59 by jamourgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_includes(char p)
{
	if (p == 'c' || p == 's' || p == 'p' || p == 'd'
		|| p == 'i' || p == 'u' || p == 'x' || p == 'X' || p == '%')
		return (1);
	return (0);
}

int	ft_bonus_flags(char b)
{
	return (b == '#' || b == ' ' || b == '+');
}

int	ft_format(const char **format, va_list list)
{
	int	counter;
	int	bonus;

	bonus = ft_bonus_flags(**format);
	if (bonus)
		(*format)++;
	counter = 0;
	if (**format == 'c')
		counter += ft_putchar(va_arg(list, int));
	else if (**format == 's')
		counter += ft_putstr(va_arg(list, char *));
	else if (**format == 'd' || **format == 'i')
		counter += ft_putnbr(va_arg(list, int), bonus, *(*format - 1));
	else if (**format == 'u')
		counter += ft_puthex(va_arg(list, unsigned int), **format, bonus, 10);
	else if (**format == 'x' || **format == 'X')
		counter += ft_puthex(va_arg(list, unsigned int), **format, bonus, 16);
	else if (**format == 'p')
		counter += ft_putaddress(va_arg(list, unsigned long));
	else
		counter += write(1, &(**format), 1);
	return (counter);
}

int	ft_printf(const char *format, ...)
{
	va_list	list;
	int		counter;

	if (!format)
		return (-1);
	va_start(list, format);
	counter = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (!*format)
				return (-1);
			if (ft_includes(*format) || ft_bonus_flags(*format))
				counter += (ft_format(&format, list));
			else
				counter += write(1, format, 1);
		}
		else
			counter += write(1, format, 1);
		format++;
	}
	va_end(list);
	return (counter);
}
