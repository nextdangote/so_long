#include "../incl/so_long.h"

void ft_message_win(t_game *game)
{
    if (game->state == STATE_SUCCESS)
    {
        printf("CONGRATS LIL SASSY BEING YOU WON !\n");
        printf("You won in %d moves!\n", game->move_count);
        printf("Press ESC to exit\n");
    }
    //🛑🛑🛑🛑🛑🛑🛑maybe writing other cases for the other states
}

void ft_you_win(t_game *game)
{
    //clean les graphics
    ft_clean_old_graphics(game);
    //t_graphics last graphics devient t_graphics graphics
    game->last_graphics = game->graphics;
    //clean les graphics de nouveau , ❓❓❓❓❓❓❓ pourquoi on fait ça ?
    ft_clean_old_graphics(game);
    //on change le statut du jeu a STATE_SUCCESS
    game->state = STATE_SUCCESS;
    //fonction qui va afficher un message de victoire et dire le nombre de mouvements
    ft_message_win(game);
    //on close la window avec une fonction mlx
    mlx_close_window(game->mlx);
}

void    ft_put_image_to_window(t_game *game, int x, int y)
{
    if (x != 0 || y != 0)
        mlx_image_to_window(game->mlx, game->graphics.background, x * 64, y * 64);
    if (game->map[y][x] == '1')
        mlx_image_to_window(game->mlx, game->graphics.wall, x * 64, y * 64);
    else if(game->map[y][x] == 'C')
        mlx_image_to_window(game->mlx, game->graphics.collectible, x * 64, y * 64);
    else if(game->map[y][x] == 'E')
        mlx_image_to_window(game->mlx, game->graphics.exit, x * 64, y * 64);
    else if(game->map[y][x] == 'P')
        mlx_image_to_window(game->mlx, game->graphics.character, x * 64, y * 64);
    
    if (x == 0 && y == 0)
        mlx_image_to_window(game->mlx, game->graphics.background, x * 64, y * 64);
    //depending on the value at the current position of the map, we will put the corresponding image in the window
}
void    ft_update_image(t_game *game)
{
    //on lance procedure si le statut du jeu est STATE_NULL
    int x;
    int y;

    x = 0;
    y = 0;
    if(game->state == STATE_NULL)
    {
        ft_clean_old_graphics(game);
        game->graphics = game->last_graphics;
        ft_load_graphics(game);
        while(y < (game->pixel_y / 64))
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
    return;
    //unload les anciens graphiques
    //puis set les nouveaux graphiques comme last graphics
    //ensuite load les nouveaux graphiques
    //ensuite position par position on va draw chacune des tiles
    //ça va se passer dans une while loop
    //on va call une fonction appeler qui va mettre les images dans la window(on utilisera mlx_image_to_window)
    //❓❓❓❓❓❓❓ comment on fait pour le background car les collectibles sont transparents
    //ensuite a la fin de la while loop on check le statut de l'exit, si c'est true le player a gagné, si oui on lance une fonction : ft_you_win(game)
    //a la sortie 
}