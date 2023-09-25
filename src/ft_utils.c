/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguede <aguede@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 02:13:38 by aguede            #+#    #+#             */
/*   Updated: 2023/09/23 18:58:09 by aguede           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	ft_error(char *str)
{
	ssize_t	result;

	result = write(2, "Error ", 6);
	if (result == -1)
	{
		ft_printf("Error while writing to stderr\n");
		exit (1);
	}
	ft_printf("%s\n", str);
	exit (1);
}

void	ft_check_ber(char *mapfile)
{
	int	i;

	i = 0;
	while (mapfile[i])
		i++;
	i--;
	if (mapfile[i] == 'r' && mapfile[i - 1] == 'e' && mapfile[i - 2] == 'b'
		&& mapfile[i - 3] == '.')
		return ;
	else
		ft_error(E_FILEISSUE);
}

char	*ft_readmap_p2(char *mapfile, int fd, int i)
{
	char	*str;
	ssize_t	bytesread;

	fd = open(mapfile, O_RDONLY);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		ft_error(E_MALLOC);
	bytesread = read(fd, str, i);
	if (bytesread == -1)
		ft_error(E_FILEISSUE);
	str[i] = '\0';
	close(fd);
	return (str);
}

char	*ft_read_map(char *mapfile)
{
	int		fd;
	char	*str;
	int		i;
	char	buffer[1];

	i = 0;
	ft_check_ber(mapfile);
	fd = open(mapfile, O_RDONLY);
	if (fd < 0)
		ft_error(E_FILE);
	while (read(fd, buffer, 1) > 0)
		i++;
	if (i == 0)
		ft_error(E_EMPTYFILE);
	close(fd);
	str = ft_readmap_p2(mapfile, fd, i);
	return (str);
}
