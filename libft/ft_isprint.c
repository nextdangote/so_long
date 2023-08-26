/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguede <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:28:49 by aguede            #+#    #+#             */
/*   Updated: 2022/11/30 16:31:05 by aguede           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "libft.h"

int	ft_isprint(int c)
{
	int	i;

	i = 0;
	if (c >= 32 && c <= 126)
	{
		i = 1;
	}
	return (i);
}

/*int	main(void)
{
	char	a;

	a = 'j';
	printf("%d\n", ft_isprint(a));
	printf("%d\n", ft_isprint('+'));
	printf("%d\n", ft_isprint('2'));
	printf("%d\n", ft_isprint('P'));
	printf("%d\n", ft_isprint('\n'));
}*/
