/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguede <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 23:33:33 by aguede            #+#    #+#             */
/*   Updated: 2022/12/19 23:33:44 by aguede           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*nouveau;
	int		i;
	int		longueur;

	i = 0;
	longueur = ft_strlen(s1);
	nouveau = (char *) malloc (sizeof(char) * (longueur + 1));
	if (!nouveau)
	{
		return (NULL);
	}
	while (s1[i] != '\0')
	{
		nouveau[i] = s1[i];
		i++;
	}
	nouveau[i] = '\0';
	return (nouveau);
}

/*int	main(void)
{
	char	*s1;
	char	*newstring;

	s1 = "franchement";
	newstring = ft_strdup(s1);
	printf("%s", newstring);
}*/
