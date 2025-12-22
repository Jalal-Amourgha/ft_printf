/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamourgh <jamourgh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 11:32:31 by jamourgh          #+#    #+#             */
/*   Updated: 2025/11/11 10:56:35 by jamourgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_format(const char **format, va_list list);
int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_putnbr(int nbr, int bonus, char flag);
int	ft_puthex(unsigned int x, char base, int bonus, int modulo);
int	ft_putaddress(unsigned long address);

#endif