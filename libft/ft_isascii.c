/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguede <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:23:46 by aguede            #+#    #+#             */
/*   Updated: 2022/11/30 16:24:12 by aguede           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "libft.h"

int	ft_isascii(int c)
{
	int	i;

	i = 0;
	if (c >= 0 && c <= 127)
	{
		i = 1;
	}
	return (i);
}

/*int	main(void)
{
	char	a;

	a = 'j';
	printf("%d\n", ft_isascii(a));
	printf("%d\n", ft_isascii('+'));
	printf("%d\n", ft_isascii('2'));
	printf("%d\n", ft_isascii('P'));
	printf("%d\n", ft_isascii('\n'));
}*/
