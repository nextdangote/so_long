#ifndef SO_LONG_H
 #define SO_LONG_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "../ft_printf/ft_printf.h"
# include "MLX42/include/MLX42/MLX42.h"

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

typedef struct s_map
{
    int     width;
    int     height;
    char    **map;
}               t_map;

typedef struct s_game
{
    t_map   map;
    void    *mlx;
    void    *win;
}               t_game;

#endif