/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguede <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:53:26 by aguede            #+#    #+#             */
/*   Updated: 2022/12/14 15:42:21 by aguede           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	len;
	size_t	j;

	j = 0;
	len = ft_strlen(s);
	if (s[j] == (char)c)
	{
		return ((char *) &s[j]);
	}
	while (s[j] != (char)c && j < len)
	{
		j++;
		if (s[j] == (char)c)
		{
			return ((char *) &s[j]);
		}
	}
	return (NULL);
}

/*int	main(void)
{
	const char	s[] = "teste";

	printf("%s", ft_strchr(s, 't' + 256));
}*/
