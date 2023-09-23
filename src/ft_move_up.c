/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_up.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguede <aguede@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:17:37 by aguede            #+#    #+#             */
/*   Updated: 2023/09/23 18:17:38 by aguede           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	ft_perform_up_move(t_game *game, int y, int x)
{
	game->map[y - 1][x] = 'P';
	game->map[y][x] = '0';
	game->move_count++;
	printf("Move numba %d\n", game->move_count);
}

int	ft_check_up_move(t_game *game, int y, int x)
{
	if (game->map[y - 1][x] == '0' || game->map[y - 1][x] == 'C' || game->map[y
		- 1][x] == 'E')
	{
		if (game->map[y - 1][x] == 'C' || game->map[y - 1][x] == 'E')
			ft_check_collec_and_exit(game, game->map[y - 1][x]);
		if ((game->map[y - 1][x] == 'E' && game->collectibles_count == 0)
			|| game->map[y - 1][x] != 'E')
			return (1);
	}
	return (0);
}

void	ft_move_up(t_game *game)
{
	int	n_columns;
	int	n_lines;
	int	y;
	int	x;

	n_columns = ft_number_of_columns(game->map);
	n_lines = ft_number_of_lines(game->map);
	y = 0;
	while (y < n_lines)
	{
		x = 0;
		while (x < n_columns)
		{
			if (game->map[y][x] == 'P')
			{
				if (ft_check_up_move(game, y, x))
				{
					ft_perform_up_move(game, y, x);
					return ;
				}
			}
			x++;
		}
		y++;
	}
}
