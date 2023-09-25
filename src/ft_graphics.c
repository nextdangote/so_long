/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphics.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguede <aguede@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 02:21:41 by aguede            #+#    #+#             */
/*   Updated: 2023/09/23 18:56:49 by aguede           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

bool	open_image(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (FALSE);
	close(fd);
	return (TRUE);
}

mlx_image_t	*ft_graph_img(mlx_t *mlx, char *img_path)
{
	xpm_t			*xpm;
	mlx_image_t		*img;
	mlx_texture_t	texture;

	if (open_image(img_path) == FALSE)
		ft_error(E_IMAGE);
	xpm = mlx_load_xpm42(img_path);
	if (!xpm)
		ft_printf("\nxpm is null\n");
	texture = xpm->texture;
	img = mlx_texture_to_image(mlx, &texture);
	if (!img)
		ft_printf("\nimg is null\n");
	mlx_delete_xpm42(xpm);
	return (img);
}

void	ft_load_graphics(t_game *game)
{
	game->graphics.backgrd = ft_graph_img(game->mlx, "./graphics/Water.xpm42");
	game->graphics.wall = ft_graph_img(game->mlx, "./graphics/Wall.xpm42");
	game->graphics.collec = ft_graph_img(game->mlx, "./graphics/collec.xpm42");
	game->graphics.exit = ft_graph_img(game->mlx, "./graphics/Exit.xpm42");
	game->graphics.charac = ft_graph_img(game->mlx, "./graphics/charac.xpm42");
	if (game->collectibles_count == 0)
		game->graphics.exit = ft_graph_img(game->mlx, "./graphics/exitn.xpm42");
}

void	ft_clean_old_graphics(t_game *game)
{
	mlx_delete_image(game->mlx, game->last_graphics.backgrd);
	mlx_delete_image(game->mlx, game->last_graphics.wall);
	mlx_delete_image(game->mlx, game->last_graphics.collec);
	mlx_delete_image(game->mlx, game->last_graphics.exit);
	mlx_delete_image(game->mlx, game->last_graphics.charac);
}
