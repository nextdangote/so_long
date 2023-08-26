/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguede <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 19:26:07 by aguede            #+#    #+#             */
/*   Updated: 2022/12/19 19:26:12 by aguede           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "libft.h"

int	allerenvoiechacal(char *s, int i)
{
	int	renvoie;

	renvoie = 0;
	while (s[i] >= 48 && s[i] <= 57)
	{
		renvoie = renvoie * 10 + s[i] - 48;
		i++;
	}
	return (renvoie);
}

int	ft_atoi(const char *str)
{
	int		sign;
	int		i;
	int		fdp;
	char	*s;

	s = (char *)str;
	sign = 1;
	i = 0;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
	{
		i++;
	}
	if (s[i] == 45 || s[i] == 43)
	{
		if (s[i] == 45)
		{
			sign *= -1;
		}
		i++;
	}
	fdp = allerenvoiechacal(s, i);
	return (fdp * sign);
}

/*int	main(void)
{
	char	str[] = "     -15478e gjg567";
	char	str1[] = "     -15478e gjg567";
	
	printf("%d\n", ft_atoi(str));
	printf("%d",atoi(str1));
}*/
