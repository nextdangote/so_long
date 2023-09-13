#include "../incl/so_long.h"

void	hook(void *param)
{
	t_game	*game;

	game = param;
	ft_update_image(game);
}

void ft_init_game(t_game *game)
{
    game->exit_flag = FALSE;
    game->state = STATE_NULL;
    game->move_count = '\0';
}

int main(int argc, char **argv)
{
    t_game game;
    char *str_map;
    game.mapfile = argv[1];
    if(argc != 2)
        ft_error(E_ARG);
    str_map = ft_read_map(game.mapfile);
    printf("str_map is\n%s\n", str_map); //to delete
    // 📛 Pas oublier que j'ai malloc la str_map et qu'il faudra free un moment
    //fct pour initialiser le t_game game #if the return value is NULL because the file name does not end with ber what should be done ?
    ft_init_game(&game);
    //file de plusieurs fct pour valider la map : uniquement char autorisé, uniquement le nombre des char autorisé, verifier map de max 128 lignes ou limites perso, verifier que les lignes font bien toutes la meme longueur.
    ft_validate_map(str_map);
    //utiliser ft_split pour creer une 2d array avec la str qui contient la map
    game.map = ft_split(str_map, '\n');
    free(str_map);
    ft_validate_2dmap(game.map);
    //creer un gros file pour valider le path, floodfill sera necessaire
    ft_validate_path(&game, game.map);
    printf("map and path are okay\n"); //to delete
    game.pixel_x = ft_number_of_columns(game.map) * 64;
    game.pixel_y = ft_number_of_lines(game.map) * 64;
    game.mlx = mlx_init(game.pixel_x, game.pixel_y, "MLX42", FALSE);
    if(!game.mlx)
        exit(EXIT_FAILURE);
    //j'ouvre et load les images
    ft_load_graphics(&game);
    //mlx_loop_hook je sais pas vraiment ça fait quoi
    mlx_loop_hook(game.mlx, &hook, &game);
    //fonction pour gerer les evenements en fonction des touches
    //mlx_key_hook(game.mlx, &ft_key_hook, NULL);
    mlx_loop(game.mlx);//une fonction loop je ne sais pas pourquoi ❓❓❓❓❓❓❓❓
    //ft_free_map(game.map);//une fonction qui free la map2d
    mlx_terminate(game.mlx);//une fonction qui terminate
    return(EXIT_SUCCESS);
}