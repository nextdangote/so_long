/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguede <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:01:19 by aguede            #+#    #+#             */
/*   Updated: 2023/01/03 17:02:33 by aguede           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	ch;

	if (n == -2147483648)
	{
		write(fd, "-", 1);
		write(fd, "2", 1);
		ft_putnbr_fd(147483648, fd);
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_fd((n * -1), fd);
	}
	else if (n >= 0 && n < 10)
	{
		ch = n + '0';
		write(fd, &ch, 1);
		return ;
	}
	else if (n >= 10 && n <= 2147483647)
	{
		ft_putnbr_fd((n / 10), fd);
		ft_putnbr_fd((n % 10), fd);
	}
}

/*int	main(void)
{
}*/
