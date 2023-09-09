#include "../incl/so_long.h"

void    ft_restore(char **map)
{
    int     x;
    int     y;

    x = 0;
    y = 0;
    while (map[x] != NULL)
    {
        y = 0;
        while(map[x][y] != '\0')
        {
            if(map[x][y] == 'c')
                map[x][y] = 'C';
            if(map[x][y] == 'o')
                map[x][y] = '0';
            y++;
        }
        x++;
    }
}

void    ft_floodfill(t_game *game, char **map, int *count_collectible, int x, int y)
{
    //checker si case deja passée, collectible collectée, la valeur de x est negative, y negatif, mur, on est à la sortie
    if(map[x][y] == 'c' || map[x][y] == 'o' || map[x][y] == '1' || map[x][y] == 'E' || x <= 0 || y <= 0)
    {
        if(map[x][y] == 'E')
            game->exit_flag = TRUE;
        return;
    }
    //si c'est le cas on check si la condition est la sortie et si oui on change le statut de l'exit_flag, ensuite on return
    //apres si aucune des cond preced. sont remplies on continue et on verifie si la case est un collectible si oui deduit un du total des collectibles. On transforme aussi le C en c.
    if(map[x][y] == 'C')
    {
        map[x][y] = 'c';
        count_collectible--;
    }
    //apres on verifie si la case est un 0 si oui on transforme la case en o.
    if(map[x][y] == '0')
        map[x][y] = 'o';
    //ensuite on a tous nos call de floodfill avec y+1, y-1, x+1, x-1
    ft_floodfill(game, map, count_collectible, x, y + 1);
    ft_floodfill(game, map, count_collectible, x, y - 1);
    ft_floodfill(game, map, count_collectible, x + 1, y);
    ft_floodfill(game, map, count_collectible, x - 1, y);
}

int ft_check_collectibles(char **map)
{
    int i;
    int x;
    int y;

    i = 0;
    x = 0;
    y = 0;

    while (map[x] != NULL)
    {
        y = 0;
        while(map[x][y] != '\0')
        {
            if(map[x][y] == 'C')
                i++;
            y++;
        }
        x++;
    }
    return (i);
}

void ft_validate_path(t_game *game, char **map)
{
    int collectible_count;
    int x;
    int y;

    x = 0;
    y = 0;
    //check le nombre de collectibles et store la value
    collectible_count = ft_check_collectibles(map);
    //chercher le player dans la map
    while (map[x] != NULL)
    {
        y = 0;
        while(map[x][y] != '\0')
        {
            if(map[x][y] == 'P')
            {
                ft_floodfill(game, map, &collectible_count, x, y);
                break;
            }
            y++;
        }
        x++;
    }
    //quand il est trouvé on lance le ft_floodfill
    //après le flood_fill checker si le compte de collectibles est 0 si ! ft_error(invalidpath)
    if (collectible_count != 0)
        ft_error(E_INVALIDPATH);// 📛📛📛📛 et dans ce cas ne dois je pas free ma map et tout ce qui a été malloc ??? 📛📛📛📛
    //ensuite on a une fonction qui restore la map en mettant les majuscules ( Pas sur car j'envoie pas de pointeur donc la map ne devrait pas ê modifiée)
    ft_restore(map);
}
