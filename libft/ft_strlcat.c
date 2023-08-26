/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguede <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:36:53 by aguede            #+#    #+#             */
/*   Updated: 2022/12/07 13:37:06 by aguede           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	m;
	size_t	n;

	m = 0;
	n = 0;
	while (dst[m] && m < size)
	{
		m++;
	}
	while (src[n] && size > (m + n + 1))
	{
		dst[m + n] = src[n];
		n++;
	}
	if (m < size)
		dst[m + n] = 0;
	return (m + ft_strlen(src));
}
