/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamourgh <jamourgh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 20:57:59 by jamourgh          #+#    #+#             */
/*   Updated: 2025/11/11 11:07:21 by jamourgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_flag(int flag, int sign)
{
	if (sign == 0 && flag == ' ')
		return (write(1, " 0", 2));
	else if (sign == 0 && flag == '+')
		return (write(1, "+0", 2));
	else if (flag == ' ' && sign >= 0)
		return (write(1, " ", 1));
	else if (flag == '+' && sign >= 0)
		return (write(1, "+", 1));
	return (0);
}

int	ft_putstr(char *str)
{
	int	i;

	if (!str)
		return (write(1, "(null)", 6));
	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr(int nbr, int bonus, char flag)
{
	char	buffer[33];
	long	lnbr;
	int		counter;
	int		i;

	if (nbr == 0 && !bonus)
		return (write(1, "0", 1));
	lnbr = nbr;
	if (lnbr < 0)
		lnbr = -lnbr;
	i = 0;
	while (lnbr > 0)
	{
		buffer[i++] = (lnbr % 10) + '0';
		lnbr /= 10;
	}
	if (nbr < 0)
		buffer[i++] = '-';
	counter = i;
	if (bonus)
		counter += ft_print_flag(flag, nbr);
	while (--i >= 0)
		write(1, &buffer[i], 1);
	return (counter);
}

int	ft_puthex(unsigned int x, char base, int bonus, int modulo)
{
	char	buffer[33];
	char	*bases;
	int		i;

	if (!x)
		return (write(1, "0", 1));
	if (base == 'x')
		bases = "0123456789abcdef";
	else
		bases = "0123456789ABCDEF";
	if (bonus)
	{
		write(1, "0", 1);
		write(1, &base, 1);
	}
	i = 0;
	while (x > 0)
	{
		buffer[i++] = bases[x % modulo];
		x /= modulo;
	}
	bonus = i + bonus + bonus;
	while (--i >= 0)
		write(1, &buffer[i], 1);
	return (bonus);
}

int	ft_putaddress(unsigned long address)
{
	char	buffer[33];
	char	*bases;
	int		counter;
	int		i;

	if (!address)
		return (write(1, "(nil)", 5));
	bases = "0123456789abcdef";
	write(1, "0x", 2);
	i = 0;
	while (address > 0)
	{
		buffer[i++] = bases[address % 16];
		address /= 16;
	}
	counter = i + 2;
	while (--i >= 0)
		write(1, &buffer[i], 1);
	return (counter);
}
