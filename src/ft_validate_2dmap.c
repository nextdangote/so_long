/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_2dmap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguede <aguede@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 03:11:29 by aguede            #+#    #+#             */
/*   Updated: 2023/09/23 20:10:23 by aguede           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

int	ft_number_of_lines(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return (i);
}

int	ft_number_of_columns(char **map)
{
	int	i;

	i = 0;
	while (map[0][i])
		i++;
	return (i);
}

int	ft_wall_check(char **map, int n_columns, int n_lines)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < n_lines)
	{
		x = 0;
		while (x < n_columns)
		{
			if (x == 0 && map[y][x] != '1')
				ft_error(E_WALLS);
			if (y == 0 && map[y][x] != '1')
				ft_error(E_WALLS);
			if (x == n_columns - 1 && map[y][x] != '1')
				ft_error(E_WALLS);
			if (y == n_lines - 1 && map[y][x] != '1')
				ft_error(E_WALLS);
			x++;
		}
		y++;
	}
	return (1);
}

void	ft_validate_2dmap(char **map)
{
	int	number_of_lines;
	int	number_of_columns;

	number_of_lines = ft_number_of_lines(map);
	number_of_columns = ft_number_of_columns(map);
	if (!ft_wall_check(map, number_of_columns, number_of_lines))
	{
		free(map);
		exit(1);
	}
}
