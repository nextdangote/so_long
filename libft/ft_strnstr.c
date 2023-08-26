/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguede <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:09:47 by aguede            #+#    #+#             */
/*   Updated: 2022/12/19 18:10:27 by aguede           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdio.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	k;

	i = 0;
	if (ft_strlen(needle) == 0)
	{
		return ((char *)haystack);
	}
	while (i < len && haystack[i] != 0 && *needle != 0)
	{
		k = 0;
		while (needle[k] == haystack[i + k] && (i + k) < len)
		{
			if (needle[k + 1] == '\0')
			{
				return ((char *) haystack + i);
			}
			k++;
		}
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	const char	*haystack = "lorem ipsum dolor sit amet";
	const char	*needle = "ipsumm";

	printf("%s", ft_strnstr(haystack, needle, 30));
}*/
