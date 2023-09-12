#include "../incl/so_long.h"

int	ft_number_of_lines(char **map)
{
	int	i;

	i = 0;
	while(map[i] != NULL)
		i++;
	return(i);
}

int	ft_number_of_columns(char **map)
{
	int	i;

	i = 0;
	while(map[0][i])
		i++;
	return (i);
}

int ft_wall_check(char **map, int n_columns, int n_lines)
{
	int	x;
	int	y;

	x = 0;
	y = 0;

	while(y < n_lines)
	{
		x = 0;
		while (x < n_columns)
		{
			if (x == 0 && map[y][x] != '1')
			{
				printf("x is %d and y is %d and it is option 1\n", x, y);
				ft_error(E_WALLS);
			}
			if (y == 0 && map[y][x] != '1')
			{
				printf("y is %d and x is %d and it is option 2\n", y, x);
				ft_error(E_WALLS);
			}
			if (x == n_columns - 1 && map[y][x] != '1')
			{
				printf("x is %d and y is %d and it is option 3\n", x, y);
				ft_error(E_WALLS);
			}
			if (y == n_lines - 1 && map[y][x] != '1')
			{
				printf("y is %d and x is %d and it is option 4\n", y, x);
				ft_error(E_WALLS);
			}
			x++;
		}
		y++;
	}
	return (1);
}

void	ft_validate_2dmap(char **map)
{
	int number_of_lines;
	int number_of_columns;
	//int	x;
	//int	y;
	//check le nombre de ligne et set ça à la valeur contenu dans la struct game
	number_of_lines = ft_number_of_lines(map);
	printf("number of lines is %d\n", number_of_lines);
	//meme chose pour le nombre de colonnes
	number_of_columns = ft_number_of_columns(map);
	printf("number of columns is %d\n", number_of_columns);
	//check that the walls are only 1's
	//en gros en checkant uniquement les parois en utilisant les indexes de la 2d array, ça se fait alz en vrai
	if (!ft_wall_check(map, number_of_columns, number_of_lines))
	{
		free(map);
		exit(1);
	}
}