/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguede <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 22:37:26 by aguede            #+#    #+#             */
/*   Updated: 2023/02/09 22:37:32 by aguede           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned long long ptr_to_hex)
{
	int	i;

	i = 0;
	if (ptr_to_hex >= 16)
	{
		i += ft_putptr(ptr_to_hex / 16);
		i += ft_putptr(ptr_to_hex % 16);
	}
	else
	{
		if (ptr_to_hex <= 9)
			i += ft_putchar(ptr_to_hex + '0');
		else
			i += ft_putchar(ptr_to_hex - 10 + 'a');
	}
	return (i);
}

int	ft_add0x_putpointer(unsigned long long ptr_to_hex)
{
	int	i;

	i = 0;
	if (!ptr_to_hex)
		i += ft_putstr("(nil)");
	if (ptr_to_hex)
	{
		i += ft_putstr("0x");
		i += ft_putptr(ptr_to_hex);
	}
	return (i);
}
