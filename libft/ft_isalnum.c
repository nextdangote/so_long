/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalnum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguede <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:16:44 by aguede            #+#    #+#             */
/*   Updated: 2022/11/30 16:17:10 by aguede           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "libft.h"

int	ft_isalnum(int c)
{
	int	i;

	i = 0;
	if (c >= 48 && c <= 57)
	{
		i = 1;
	}
	if (c >= 65 && c <= 90)
	{
		i = 1;
	}
	if (c >= 97 && c <= 122)
	{
		i = 1;
	}
	return (i);
}

/*int	main(void)
{
	char	a;

	a = 'j';
	printf("%d\n", ft_isalnum(a));
	printf("%d\n", ft_isalnum('+'));
	printf("%d\n", ft_isalnum('2'));
	printf("%d\n", ft_isalnum('P'));
}*/
