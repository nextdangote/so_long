/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguede <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:40:51 by aguede            #+#    #+#             */
/*   Updated: 2022/12/14 16:41:09 by aguede           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*petitmerdeux;
	int		i;

	petitmerdeux = (char *) s;
	i = 0;
	while (*petitmerdeux != '\0')
	{
		petitmerdeux++;
		i++;
	}
	while (*petitmerdeux != (char)c && i != 0)
	{
		i--;
		petitmerdeux--;
	}
	if (*petitmerdeux == (char)c)
	{
		return (petitmerdeux);
	}
	return (NULL);
}

/*int	main(void)
{
	const char	salepetitcon[] = "ohtuarreates";

	printf("%s", ft_strchr(salepetitcon, 97));
}*/
