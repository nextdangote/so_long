/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguede <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:45:54 by aguede            #+#    #+#             */
/*   Updated: 2023/01/03 16:47:45 by aguede           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "libft.h"

static int	ft_nbr_words(char const *s, char c)
{
	int	announce;
	int	n;

	n = 0;
	announce = 0;
	while (*s)
	{
		if (*s != c && announce == 0)
		{
			announce = 1;
			n++;
		}
		else if (*s == c)
			announce = 0;
		s++;
	}
	return (n);
}

static char	*ft_cutter(char const *s, int begin, int end)
{
	char	*str;
	int		n;

	n = 0;
	str = malloc (sizeof(char) * (end - begin + 1));
	while (begin < end)
	{
		str[n++] = s[begin++];
	}
	str[n] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str_arr;
	size_t	i;
	size_t	j;
	int		index;

	str_arr = malloc (sizeof(char *) * (ft_nbr_words(s, c) + 1));
	if (!str_arr || !s)
		return (NULL);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			str_arr[j++] = ft_cutter(s, index, i);
			index = -1;
		}
		i++;
	}
	str_arr[j] = 0;
	return (str_arr);
}
/*int	main(void)
{
	ft_split("pour tester", t);
}*/
