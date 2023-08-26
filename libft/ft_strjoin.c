/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguede <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:27:52 by aguede            #+#    #+#             */
/*   Updated: 2022/12/20 19:38:01 by aguede           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int	the_strlen(const char *s1)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*renvoiecetruc;
	int		sizes1;

	sizes1 = the_strlen(s1);
	i = sizes1 + the_strlen(s2) + 1;
	j = 0;
	renvoiecetruc = malloc (i * sizeof(char));
	if (renvoiecetruc == NULL)
		return (NULL);
	while (j < sizes1)
	{
		renvoiecetruc[j] = *s1;
		j++;
		s1++;
	}
	while (j < i)
	{
		renvoiecetruc[j] = *s2;
		j++;
		s2++;
	}
	return (renvoiecetruc);
}
/*int	main(void)
{
	printf("%s", ft_strjoin("lorem ipsum","dolor sit amet"));
}*/
