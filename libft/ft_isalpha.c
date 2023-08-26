/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalpha.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguede <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:08:05 by aguede            #+#    #+#             */
/*   Updated: 2022/11/30 15:22:43 by aguede           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "libft.h"

int	ft_isalpha(int c)
{
	int	i;

	i = 0;
	if (c >= 65 && c <= 90)
	{
		i = 1;
	}
	if (c >= 97 && c <= 122)
	{
		i = 2;
	}
	return (i);
}

/*int	main(void)
{
	char	a;

	a = 'j';
	printf("%d\n", ft_isalpha(a));
	printf("%d\n", ft_isalpha('+'));
	printf("%d\n", ft_isalpha('2'));
	printf("%d\n", ft_isalpha('P'));
}*/
