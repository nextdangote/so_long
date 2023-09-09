#ifndef SO_LONG_H
 #define SO_LONG_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>
# include "../libft/libft.h"
//# include "../get_next_line/get_next_line.h"
# include "../ft_printf/ft_printf.h"
# include "../MLX42/include/MLX42/MLX42.h"

# define TRUE 1
# define FALSE 0
# define E_MALLOC "Error with malloc.\n"
# define E_ARG "Give one map young human!\n"
# define E_FILE "File can not be opened fam :/\n"
# define E_CHAR "At least one incorrect character in the map dawggg :/\n"
# define E_CHARMISS "Orh sa3bi some characters are missing !\n"
# define E_MAPNOTVALID "DAWGGG the map is not valid, rectangles fam das easyyy !!! \n"
# define E_PATH "ARGHHH the path is wrong you gotta change that Bruddie oder Schwestie :(\n"
# define E_FORMAT "ION LIKE THIS FORMAT !\n"
# define E_EMPTYFILE "HEYYY ?! DA file is empty fam!\n"
# define E_IMAGE "Issue w the image you want to use familia.\n"
# define E_MAX "Seems like it is too much, I can not handle that calm down...\n"
# define E_WALLS "your walls are liabilities, fix that homo sapiens sapiens...\n"
# define E_INVALIDPATH "there is no way you finish this game fam #invalidpath\n"

typedef struct s_game
{
    char    **map;
    void    *mlx;
    void    *win;
    bool    exit_flag;
    int     state;
    int     move_count;
    int     pixel_x;
    int     pixel_y;
}               t_game;

typedef enum e_state
{
	STATE_NULL = 0,
	STATE_SUCCESS = 1,
	STATE_CLOSING = 2,
	STATE_GAMEOVER = 3,
}   t_state;

void	ft_error(char *str);
void	ft_init_game(t_game *game);
void	ft_validate_map(char *str_map);
int		ft_number_of_columns(char **map);
int     ft_number_of_lines(char **map);
void	ft_validate_path(t_game *game, char **map);
int		ft_check_collectibles(char **map);
void	ft_validate_2dmap(char **map);
char	*ft_read_map(char *mapfile);

#endif