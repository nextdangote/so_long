/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguede <aguede@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 02:21:38 by aguede            #+#    #+#             */
/*   Updated: 2023/09/23 03:08:32 by aguede           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	ft_message_win(t_game *game)
{
	if (game->state == STATE_SUCCESS)
	{
		printf("CONGRATS LIL SASSY BEING YOU WON !\n");
		printf("You won in %d moves!\n", game->move_count);
		mlx_close_window(game->mlx);
	}
}

void	ft_you_win(t_game *game)
{
	ft_clean_old_graphics(game);
	game->last_graphics = game->graphics;
	ft_clean_old_graphics(game);
	game->state = STATE_SUCCESS;
	ft_message_win(game);
}

void	ft_put_image_to_window(t_game *game, int x, int y)
{
	if (x != 0 || y != 0)
		mlx_image_to_window(game->mlx, game->graphics.backgrd, x * 64, y * 64);
	if (game->map[y][x] == '1')
		mlx_image_to_window(game->mlx, game->graphics.wall, x * 64, y * 64);
	else if (game->map[y][x] == 'C')
		mlx_image_to_window(game->mlx, game->graphics.collec, x * 64, y * 64);
	else if (game->map[y][x] == 'E')
		mlx_image_to_window(game->mlx, game->graphics.exit, x * 64, y * 64);
	else if (game->map[y][x] == 'P')
		mlx_image_to_window(game->mlx, game->graphics.charac, x * 64, y * 64);
	if (x == 0 && y == 0)
		mlx_image_to_window(game->mlx, game->graphics.backgrd, x * 64, y * 64);
}

void	ft_update_image(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (game->state == STATE_NULL)
	{
		ft_clean_old_graphics(game);
		game->graphics = game->last_graphics;
		ft_load_graphics(game);
		while (y < (game->pixel_y / 64))
		{
			x = 0;
			while (x < game->pixel_x / 64)
			{
				ft_put_image_to_window(game, x, y);
				x++;
			}
			y++;
		}
	}
	if (game->exit_flag == TRUE)
		ft_you_win(game);
	return ;
}
