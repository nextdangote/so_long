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
// 🛑🛑🛑🛑🛑🛑🛑comprendre cette fonction
mlx_image_t	*ft_graphics_to_image(mlx_t *mlx, char *img_path)
{
	xpm_t			*xpm;
	mlx_image_t		*img;
	mlx_texture_t	texture;

	if (open_image(img_path) == FALSE)
		ft_error(E_IMAGE);
	xpm = mlx_load_xpm42(img_path);
	if (!xpm)
		printf("\nxpm is null\n");//change to ft_printf
	texture = xpm->texture;
	img = mlx_texture_to_image(mlx, &texture);
	if (!img)
		printf("\nimg is null\n");//change to ft_printf
	mlx_delete_xpm42(xpm);
	return (img);
}

void	ft_load_graphics(t_game *game)
{
	game->graphics.background = ft_graphics_to_image(game->mlx, "./graphics/background.xpm");
    game->graphics.wall = ft_graphics_to_image(game->mlx, "./graphics/wall.xpm");
    game->graphics.collectible = ft_graphics_to_image(game->mlx, "./graphics/collectible.xpm");
    game->graphics.exit = ft_graphics_to_image(game->mlx, "./graphics/exit.xpm");
    game->graphics.character = ft_graphics_to_image(game->mlx, "./graphics/character.xpm");
}

void	ft_clean_old_graphics(t_game *game)
{
	mlx_delete_image(game->mlx, game->last_graphics.background);
	mlx_delete_image(game->mlx, game->last_graphics.wall);
	mlx_delete_image(game->mlx, game->last_graphics.collectible);
	mlx_delete_image(game->mlx, game->last_graphics.exit);
	mlx_delete_image(game->mlx, game->last_graphics.character);
}

