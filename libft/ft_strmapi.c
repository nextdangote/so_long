/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguede <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:13:38 by aguede            #+#    #+#             */
/*   Updated: 2022/12/21 12:17:38 by aguede           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*fmod;
	size_t			len;
	unsigned int	i;

	len = ft_strlen(s);
	i = 0;
	fmod = malloc (sizeof(char) * (len + 1));
	if (!fmod)
		return (NULL);
	while (s[i] != '\0')
	{
		fmod[i] = f(i, s[i]);
		i++;
	}
	fmod[i] = '\0';
	return (fmod);
}

/*int	main(void)
{
	
}*/
