/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isdigit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguede <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:02:36 by aguede            #+#    #+#             */
/*   Updated: 2022/11/30 16:02:49 by aguede           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "libft.h"

int	ft_isdigit(int c)
{
	int	i;

	i = 0;
	if (c >= 48 && c <= 57)
	{
		i = 1;
	}
	return (i);
}

/*int	main(void)
{
	char	a;

	a = 'j';
	printf("%d\n", ft_isdigit(a));
	printf("%d\n", ft_isdigit('+'));
	printf("%d\n", ft_isdigit('2'));
	printf("%d\n", ft_isdigit('P'));
}*/
