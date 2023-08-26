/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguede <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:36:52 by aguede            #+#    #+#             */
/*   Updated: 2022/12/20 17:37:45 by aguede           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s_new;
	size_t	s_new_len;
	int		s_len;

	s_len = ft_strlen((char *)s);
	if (start >= ft_strlen((char *)s))
	{
		s_new = malloc (sizeof(char));
		if (!s_new)
			return (NULL);
		*s_new = '\0';
		return (s_new);
	}
	if (len <= s_len - start)
		s_new_len = len;
	else
		s_new_len = s_len - start;
	s_new = malloc (sizeof(char) * s_new_len + 1);
	if (s_new == NULL)
		return (0);
	ft_strlcpy(s_new, &s[start], s_new_len + 1);
	return (&s_new[0]);
}
