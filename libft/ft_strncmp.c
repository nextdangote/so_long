/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguede <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:55:57 by aguede            #+#    #+#             */
/*   Updated: 2022/12/14 16:56:16 by aguede           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*t;
	unsigned char	*u;

	t = (unsigned char *)s1;
	u = (unsigned char *)s2;
	i = 0;
	while (n--)
	{
		if (t[i] != u[i] || t[i] == 0 || u[i] == 0)
			return (t[i] - u[i]);
		i++;
	}
	return (0);
}

/*int	main(void)
{
	char	array1[] = "test\200";
	char	array2[] = "test\0";
	unsigned int	stopcond = 6;

	printf ("difference de longueur = %d\n", ft_strncmp(array1, array2, stopcond));
}*/
