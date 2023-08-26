/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguede <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:16:37 by aguede            #+#    #+#             */
/*   Updated: 2023/02/06 13:16:46 by aguede           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putpercent(void)
{
	write(1, "%", 1);
	return (1);
}

int	ft_whichtype(char a, va_list arguments)
{
	int	compteur;

	compteur = 0;
	if (a == 'c')
		compteur += ft_putchar(va_arg(arguments, int));
	if (a == '%')
		compteur += ft_putpercent();
	if (a == 'd')
		compteur += ft_putnbr(va_arg(arguments, int));
	if (a == 'i')
		compteur += ft_putnbr(va_arg(arguments, int));
	if (a == 's')
		compteur += ft_putstr(va_arg(arguments, char *));
	if (a == 'u')
		compteur += ft_putunsignednbr(va_arg(arguments, unsigned int));
	if (a == 'x' || a == 'X')
		compteur += ft_puthex(va_arg(arguments, unsigned int), a);
	if (a == 'p')
		compteur += ft_add0x_putpointer(va_arg(arguments, unsigned long long));
	return (compteur);
}

int	ft_printf(const char *stringficelle, ...)
{
	int		i;
	int		compteur;
	va_list	argumentos;

	if (stringficelle == NULL)
		return (0);
	i = 0;
	compteur = 0;
	va_start(argumentos, stringficelle);
	while (stringficelle[i] != '\0')
	{
		if (stringficelle[i] == '%')
		{
			compteur += ft_whichtype(stringficelle[i + 1], argumentos);
			i++;
		}
		else
			compteur += ft_putchar(stringficelle[i]);
		i++;
	}
	va_end(argumentos);
	return (compteur);
}

int	main(void)
{
	char c;
	int mine;
	int std;

	c = 'a';
	mine = ft_printf(" amadou %d %c %s %u %x %X %p %% \n", -2147483648, 'b', "chacal", 14565855, 16, 16, &c);
	ft_printf("%d\n", mine);
	std = printf(" amadou %d %c %s %u %x %X %p %% \n", -2147483647, 'b', "chacal", 14565855, 16, 16, &c);
	printf("%d\n", std);
}
