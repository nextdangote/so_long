/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguede <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:39:18 by aguede            #+#    #+#             */
/*   Updated: 2022/12/21 17:40:34 by aguede           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*d;
	char	*s;

	if (!dst && !src)
		return (NULL);
	d = (char *) dst;
	s = (char *) src;
	i = 0;
	if (d > s)
	{
		while (n-- > 0)
		{
			d[n] = s[n];
		}
	}
	else
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}

/*int	main(void)
{
	void *d = "iiiooo";
	void *s = "abcdef";
	printf("%p", ft_memmove(s, d, 3));
}*/
