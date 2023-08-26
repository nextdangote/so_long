/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguede <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:27:32 by aguede            #+#    #+#             */
/*   Updated: 2022/12/19 17:28:23 by aguede           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s3;
	unsigned char	*s4;

	s3 = (unsigned char *) s1;
	s4 = (unsigned char *) s2;
	i = 0;
	if (n == 0)
		return (0);
	while (*s3 == *s4 && ++i < n)
	{
		s3++;
		s4++;
	}
	return ((int)(*s3 - *s4));
}

/*int	main(void)
{
	//const void *s1 = "jenesai";
	//const void *s2 = "jenes";
	printf("%d", ft_memcmp("abcdefghij", "abcdefgxyz", 7));
}*/
