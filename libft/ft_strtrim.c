/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.set                                       :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: aguede <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 20:17:37 by aguede            #+#    #+#             */
/*   Updated: 2022/12/20 20:19:16 by aguede           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "libft.h"

int	ft_checktrim(char s, char const *set)
{
	int	n;

	n = 0;
	while (set[n])
	{
		if (s == set[n])
		{
			return (1);
		}
		n++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		n;
	char	*returnstr;

	n = 0;
	start = 0;
	while (s1[start] && ft_checktrim(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_checktrim(s1[end - 1], set))
		end--;
	returnstr = malloc (sizeof(char) * (end - start + 1));
	if (!returnstr)
		return (NULL);
	while (start < end)
	{
		returnstr[n] = s1[start];
		n++;
		start++;
	}
	returnstr[n] = '\0';
	return (returnstr);
}

/*int	main(void)
{
	printf("%s",ft_strtrim("gmaggamg ohlefou gmaamgamga", "amg"));
}*/
