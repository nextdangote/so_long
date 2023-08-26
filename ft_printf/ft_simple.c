/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguede <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 23:49:13 by aguede            #+#    #+#             */
/*   Updated: 2023/02/07 23:49:19 by aguede           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
	{
		while (str[i])
		{
			write(1, &str[i], 1);
			i++;
		}
	}
	return (i);
}

int	ft_putnbr(int nb)
{
	int		i;

	i = 0;
	if (nb == -2147483648)
	{
		return (ft_putstr("-2147483648"));
	}
	else if (nb < 0)
	{
		i += ft_putchar('-');
		i += ft_putnbr(nb * -1);
	}
	else if (nb >= 10)
	{
		i += ft_putnbr(nb / 10);
		i += ft_putnbr(nb % 10);
	}
	else if (nb < 10)
	{
		i += ft_putchar(nb + '0');
	}
	return (i);
}

int	ft_putunsignednbr(unsigned int nb)
{
	int		i;

	i = 0;
	if (nb >= 10)
	{
		i += ft_putnbr(nb / 10);
		i += ft_putnbr(nb % 10);
	}
	else if (nb < 10)
	{
		i += ft_putchar(nb + '0');
	}
	return (i);
}

int	ft_puthex(unsigned int to_hex, const char typeoslm)
{
	int	i;

	i = 0;
	if (to_hex >= 16)
	{
		i += ft_puthex((to_hex / 16), typeoslm);
		i += ft_puthex((to_hex % 16), typeoslm);
	}
	else
	{
		if (to_hex <= 9)
			i += ft_putchar(to_hex + '0');
		else if (typeoslm == 'x')
			i += ft_putchar(to_hex - 10 + 'a');
		else if (typeoslm == 'X')
			i += ft_putchar(to_hex - 10 + 'A');
	}
	return (i);
}
