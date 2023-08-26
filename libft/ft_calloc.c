/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguede <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 20:43:43 by aguede            #+#    #+#             */
/*   Updated: 2022/12/19 20:44:56 by aguede           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*cacalloc;
	size_t	regarde;

	regarde = 0;
	if ((count * size) > 2147483647)
	{
		return (NULL);
	}
	cacalloc = malloc (count * size);
	if (cacalloc == NULL)
	{
		return (NULL);
	}
	while (regarde < (count * size))
	{
		((char *)cacalloc)[regarde] = 0;
		regarde++;
	}
	return (cacalloc);
}

/*int	main(void)
{
	void	*cacalloc = calloc(6, sizeof(int));
	printf("%p", cacalloc);
}*/
