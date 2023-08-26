/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguede <narvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 20:41:59 by aguede            #+#    #+#             */
/*   Updated: 2022/12/05 20:42:29 by aguede           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*pointeur;
	size_t	c;

	pointeur = (char *) s;
	c = 0;
	while (c < n)
	{
		pointeur[c] = 0;
		c++;
	}
}

/*int	nain(void)
{
	char s[25] = "oh sale fou";
	int i;
	i = 0;
	
	printf("non texte avant : %s\n", s);
	ft_bzero(s, 4);
	while(i < 25)
	{
	printf("%c", s[i]);
	i++;
	}
}*/
