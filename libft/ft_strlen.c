/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguede <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:46:17 by aguede            #+#    #+#             */
/*   Updated: 2022/12/01 11:57:38 by aguede           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	s = (char *) s;
	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

/*int	main(void)
{
	printf("%d", ft_strlen("nikzebi"));
}*/
