/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguede <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:07:15 by aguede            #+#    #+#             */
/*   Updated: 2022/12/19 16:07:24 by aguede           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*retour;
	unsigned char		d;
	size_t				t;

	retour = s;
	d = c;
	t = 0;
	while (t < n)
	{
		if (*retour == d)
		{
			return ((void *)retour);
		}
		retour++;
		t++;
	}
	return (NULL);
}

/*int main(void)
{
	const void *s = "sale chien";
	int c = 'k';
	size_t n = 7;
	printf("%p", ft_memchr(s, c, n));
}*/
