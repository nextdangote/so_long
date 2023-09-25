/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguede <aguede@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 02:14:45 by aguede            #+#    #+#             */
/*   Updated: 2023/09/23 20:36:59 by aguede           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	ft_free_map(t_game *game)
{
	int	x;

	x = 0;
	while (game->map[x] != NULL)
	{
		free(game->map[x]);
		x++;
	}
	free(game->map);
}

void	hook(void *param)
{
	t_game	*game;

	game = param;
	ft_update_image(game);
}

void	ft_init_game(t_game *game)
{
	game->exit_flag = FALSE;
	game->state = STATE_NULL;
	game->move_count = '\0';
}

int	main(int argc, char **argv)
{
	t_game	game;
	char	*str_map;

	game.mapfile = argv[1];
	if (argc != 2)
		ft_error(E_ARG);
	str_map = ft_read_map(game.mapfile);
	ft_init_game(&game);
	ft_validate_map(str_map);
	game.map = ft_split(str_map, '\n');
	free(str_map);
	ft_validate_2dmap(game.map);
	ft_validate_path(&game);
	game.pixel_x = ft_number_of_columns(game.map) * 64;
	game.pixel_y = ft_number_of_lines(game.map) * 64;
	game.mlx = mlx_init(game.pixel_x, game.pixel_y, "GO SWIM LAZY A**", TRUE);
	if (!game.mlx)
		exit(EXIT_FAILURE);
	ft_load_graphics(&game);
	mlx_loop_hook(game.mlx, &hook, &game);
	mlx_key_hook(game.mlx, &ft_key_hook, &game);
	mlx_loop(game.mlx);
	ft_free_map(&game);
	mlx_terminate(game.mlx);
	return (EXIT_SUCCESS);
}
