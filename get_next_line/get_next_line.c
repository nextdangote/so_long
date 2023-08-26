/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguede <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:53:26 by aguede            #+#    #+#             */
/*   Updated: 2023/02/15 14:53:34 by aguede           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_extract(char *stock)
{
	int		x;
	char	*retour;

	x = 0;
	if (!stock[x])
		return (NULL);
	while (stock[x] != '\n' && stock[x])
		x++;
	retour = (char *)malloc((x + 2) * sizeof(char));
	if (!retour)
		return (NULL);
	x = 0;
	while (stock[x] != '\n' && stock[x])
	{
		retour[x] = stock[x];
		x++;
	}
	if (stock[x] == '\n')
	{
		retour[x] = stock[x];
		x++;
	}
	retour[x] = '\0';
	return (retour);
}

char	*ft_empty(char *stock)
{
	int		i;
	int		j;
	char	*rest_stock;

	i = 0;
	while (stock[i] && stock[i] != '\n')
		i++;
	if (!stock[i])
	{
		free(stock);
		return (NULL);
	}
	rest_stock = (char *)malloc(sizeof(char) * (ft_strlen(stock) - i + 1));
	if (!rest_stock)
		return (NULL);
	i++;
	j = 0;
	while (stock[i])
		rest_stock[j++] = stock[i++];
	rest_stock[j] = '\0';
	free(stock);
	return (rest_stock);
}

char	*ft_lire_stock(int fd, char *stock)
{
	char		*buffer;
	int			nbr_bytes;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	nbr_bytes = 1;
	while (!ft_strchr(stock, '\n') && nbr_bytes != 0)
	{
		nbr_bytes = read(fd, buffer, BUFFER_SIZE);
		if (nbr_bytes == -1)
		{
			free(buffer);
			free(stock);
			return (NULL);
		}
		buffer[nbr_bytes] = '\0';
		stock = ft_strjoin(stock, buffer);
	}
	free(buffer);
	return (stock);
}

char	*get_next_line(int fd)
{
	char		*retour;
	static char	*stock;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	stock = ft_lire_stock(fd, stock);
	if (!stock)
		return (NULL);
	retour = ft_extract(stock);
	stock = ft_empty(stock);
	return (retour);
}

/*int	main(void)
{
	int		fd;
	char	*ligne;

	fd = open("read_error.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	while (1)
	{
		ligne = get_next_line(fd);
		if (ligne == NULL)
			break ;
		printf("%s", ligne);
		free(ligne);
	}
	return (0);
}*/
