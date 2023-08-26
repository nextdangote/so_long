/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguede <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 21:15:08 by aguede            #+#    #+#             */
/*   Updated: 2022/12/05 21:18:52 by aguede           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*pointeur;
	char	*blessure;
	size_t	toimeme;

	pointeur = (char *) dest;
	blessure = (char *)src;
	toimeme = 0;
	if (!dest && !src)
	{
		return (0);
	}
	while (toimeme < n)
	{
		pointeur[toimeme] = blessure[toimeme];
		toimeme++;
	}
	return (dest);
}

/*int main(void)
{
	char	dest[56];
	char	src[78] = "oh petit con tu te calmes";

	ft_memcpy(dest, src, 6);
	printf("ma version : %s\n", dest);
}*/
