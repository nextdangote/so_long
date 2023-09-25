/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguede <aguede@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 03:18:15 by aguede            #+#    #+#             */
/*   Updated: 2023/09/23 19:56:29 by aguede           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	ft_restore(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[x] != NULL)
	{
		y = 0;
		while (map[x][y] != '\0')
		{
			if (map[x][y] == 'c')
				map[x][y] = 'C';
			if (map[x][y] == 'o')
				map[x][y] = '0';
			y++;
		}
		x++;
	}
}

void	ft_floodfill(t_game *game, int *count_collectible, int x, int y)
{
	if (game->map[x][y] == 'c' || game->map[x][y] == 'o'
		|| game->map[x][y] == '1' || game->map[x][y] == 'E' || x <= 0 || y <= 0)
	{
		if (game->map[x][y] == 'E')
			game->exit_flag = TRUE;
		return ;
	}
	if (game->map[x][y] == 'C')
	{
		game->map[x][y] = 'c';
		(*count_collectible)--;
	}
	if (game->map[x][y] == '0')
		game->map[x][y] = 'o';
	ft_floodfill(game, count_collectible, x, y + 1);
	ft_floodfill(game, count_collectible, x, y - 1);
	ft_floodfill(game, count_collectible, x + 1, y);
	ft_floodfill(game, count_collectible, x - 1, y);
}

int	ft_check_collectibles(char **map)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	while (map[x] != NULL)
	{
		y = 0;
		while (map[x][y] != '\0')
		{
			if (map[x][y] == 'C')
				i++;
			y++;
		}
		x++;
	}
	return (i);
}

void	ft_validate_path(t_game *game)
{
	int	collectible_count;
	int	x;
	int	y;

	x = 0;
	collectible_count = ft_check_collectibles(game->map);
	while (game->map[x] != NULL)
	{
		y = 0;
		while (game->map[x][y] != '\n' && game->map[x][y] != '\0')
		{
			if (game->map[x][y] == 'P')
			{
				ft_floodfill(game, &collectible_count, x, y);
				break ;
			}
			y++;
		}
		x++;
	}
	if (collectible_count != 0 || game->exit_flag == FALSE)
		ft_error(E_INVALIDPATH);
	ft_restore(game->map);
	game->collectibles_count = ft_check_collectibles(game->map);
	game->exit_flag = FALSE;
}
