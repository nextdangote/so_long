/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguede <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 21:56:44 by aguede            #+#    #+#             */
/*   Updated: 2022/12/20 22:01:13 by aguede           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int	my_strlen(long number)
{
	int	returnv;

	returnv = 0;
	if (number < 0)
	{
		number = number * -1;
		returnv++;
	}
	if (number == 0)
	{
		return (1);
	}
	while (number > 0)
	{
		number = number / 10;
		returnv++;
	}
	return (returnv);
}

char	*ft_itoa(int n)
{
	char	*result;
	long	number;
	int		i;

	number = n;
	i = my_strlen(number);
	result = (char *)malloc((i + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[i--] = '\0';
	if (number == 0)
	{
		result[0] = 48;
	}
	if (number < 0)
	{
		number *= -1;
		result[0] = '-';
	}
	while (number > 0)
	{
		result[i--] = (number % 10) + '0';
		number = number / 10;
	}
	return (result);
}
