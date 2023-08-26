/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguede <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:50:38 by aguede            #+#    #+#             */
/*   Updated: 2022/12/07 11:55:03 by aguede           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	if (size == 0)
	{
		return (i);
	}
	while (j < size - 1 && src[j] != '\0')
	{
		dst[j] = src[j];
		j++;
	}
	dst[j] = '\0';
	return (i);
}

/*int	main(void)
{
	char	dst[] = "sale petit morveux";
	const char	src[] = "idk I just want to test";

	printf("la longueur de ce que je veux copier %d\n", ft_strlcpy(dst, src, 21));
	printf("ma destination apres ft_strlcpy est : %s", dest);
}*/
