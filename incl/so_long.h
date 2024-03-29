/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguede <aguede@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 02:21:33 by aguede            #+#    #+#             */
/*   Updated: 2023/09/23 18:23:54 by aguede           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include "../ft_printf/ft_printf.h"

# define TRUE 1
# define FALSE 0
# define E_MALLOC "Error with malloc.\n"
# define E_ARG "Give one map young human!\n"
# define E_FILE "File can not be opened fam :/\n"
# define E_CHAR "At least one incorrect character in the map dawggg :/\n"
# define E_CHARMISS "Orh sa3bi some characters are missing !\n"
# define E_MAPNOTVALID "DAWG map isnt valid,rectangles fam das easyyy !!! \n"
# define E_PATH "ARGHHH the path is wrong you gotta change that Bruddie\n"
# define E_FORMAT "ION LIKE THIS FORMAT !\n"
# define E_EMPTYFILE "HEYYY ?! DA file is empty fam!\n"
# define E_FILEISSUE "This file as an issue or does not exist\n"
# define E_IMAGE "Issue w the image you want to use familia.\n"
# define E_MAX "Seems like it is too much, I can not handle that calm down...\n"
# define E_WALLS "your walls are WRONG,fix that homo sapiens sapiens...\n"
# define E_INVALIDPATH "there is no way you finish this game fam #invalidpath\n"

typedef struct s_graphics
{
	mlx_image_t	*exit;
	mlx_image_t	*backgrd;
	mlx_image_t	*charac;
	mlx_image_t	*collec;
	mlx_image_t	*wall;
}				t_graphics;

typedef struct s_game
{
	char		**map;
	char		*mapfile;
	void		*win;
	bool		exit_flag;
	int			state;
	int			move_count;
	int			collectibles_count;
	int			pixel_x;
	int			pixel_y;
	mlx_t		*mlx;
	mlx_t		*window;
	t_graphics	graphics;
	t_graphics	last_graphics;
}				t_game;

typedef enum e_state
{
	STATE_NULL = 0,
	STATE_SUCCESS = 1,
	STATE_CLOSING = 2,
	STATE_GAMEOVER = 3,
}				t_state;

void			ft_error(char *str);
void			ft_init_game(t_game *game);
void			ft_validate_map(char *str_map);
int				ft_check_amount_lines(char *str_map);
int				ft_check_line_length(char *str_map);
int				ft_number_of_columns(char **map);
int				ft_number_of_lines(char **map);
void			ft_validate_path(t_game *game);
int				ft_check_collectibles(char **map);
void			ft_validate_2dmap(char **map);
char			*ft_read_map(char *mapfile);
void			ft_load_graphics(t_game *game);
void			ft_clean_old_graphics(t_game *game);
void			ft_update_image(t_game *game);
void			ft_move_up(t_game *game);
void			ft_move_down(t_game *game);
void			ft_move_right(t_game *game);
void			ft_move_left(t_game *game);
void			ft_you_win(t_game *game);
void			ft_message_win(t_game *game);
void			ft_check_collec_and_exit(t_game *game, char c);
void			ft_key_hook(mlx_key_data_t keydata, void *param);
void			ft_free_map(t_game *game);

#endif