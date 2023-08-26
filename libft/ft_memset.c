/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguede <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:59:23 by aguede            #+#    #+#             */
/*   Updated: 2022/12/05 19:01:47 by aguede           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*pointeur;
	size_t	d;

	pointeur = (char *) b;
	d = 0;
	while (d < len)
	{
		pointeur[d] = c;
		d++;
	}
	return (b);
}

/*int	main(void)
{
	char b[25] = "oh sale fou";

	printf("mon texte avant : %s\n", b);
	ft_memset(b, 'g', 4);
	printf("mon texte apres memset : %s", b);
}*/
